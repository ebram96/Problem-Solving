class Solution {
private:
    static const int DIRECTIONS_COUNT = 4;
    static constexpr int dI[DIRECTIONS_COUNT] = {-1, 0, 1, 0};
    static constexpr int dJ[DIRECTIONS_COUNT] = {0, 1, 0, -1};

    struct Location
    {
        int i, j;
    };

    struct TraversalNode
    {
        int level;
        Location loc;
    };

    bool validLocation(const Location& loc, const int& n)
    {
        return loc.i >= 0 && loc.j >= 0 && loc.i < n && loc.j < n;
    }

    void multiSourceBfs(vector<Location> thieves, vector<vector<int>>& cellSafenessFactor, const int& n, vector<vector<int>>& grid)
    {
        vector<vector<bool>> enqueued(n, vector<bool>(n));
        queue<TraversalNode> q;
        for(Location &loc : thieves)
        {
            q.push({0, loc});
            enqueued[loc.i][loc.j] = true;
        }
        while(!q.empty())
        {
            TraversalNode& node = q.front();
            cellSafenessFactor[node.loc.i][node.loc.j] = node.level;
            Location newLocation;
            for(int d = 0, newI, newJ; d < DIRECTIONS_COUNT; d++)
            {
                newLocation.i = node.loc.i + dI[d];
                newLocation.j = node.loc.j + dJ[d];
                if(validLocation(newLocation, n) && !enqueued[newLocation.i][newLocation.j])
                {
                    q.push({node.level + 1, newLocation});
                    enqueued[newLocation.i][newLocation.j] = true;
                }
            }
            q.pop();
        }
    }

    void calculateCellsSafenessFactor(vector<vector<int>>& cellSafenessFactor, const int& n, vector<vector<int>>& grid)
    {
        vector<Location> thieves;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j])
                    thieves.push_back({i, j});
        multiSourceBfs(thieves, cellSafenessFactor, n, grid);
    }

    bool destinationReachable(Location loc, vector<vector<bool>>& visited, const int& minSafenessFactorAllowed, const int& n, vector<vector<int>>& cellSafenessFactor)
    {
        if(loc.i == n - 1 && loc.j == n - 1)
            return true;
        
        visited[loc.i][loc.j] = true;
        Location newLocation;
        bool subResult = false;
        for(int d = 0; d < DIRECTIONS_COUNT && !subResult; d++)
        {
            newLocation.i = loc.i + dI[d];
            newLocation.j = loc.j + dJ[d];
            if(
                validLocation(newLocation, n) &&
                !visited[newLocation.i][newLocation.j] &&
                cellSafenessFactor[newLocation.i][newLocation.j] >= minSafenessFactorAllowed
            )
                subResult = destinationReachable(newLocation, visited, minSafenessFactorAllowed, n, cellSafenessFactor);
        }
        return subResult;
    }

    int binarySearch(const int& n, vector<vector<int>>& cellSafenessFactor)
    {
        int left = 0, middle, right = (n << 1) - 2, result;
        Location startingLocation{0, 0};
        while(left <= right)
        {
            vector<vector<bool>> visited(n, vector<bool>(n));
            middle = (left + right) >> 1;
            if(
				cellSafenessFactor[0][0] >= middle &&
				destinationReachable(startingLocation, visited, middle, n, cellSafenessFactor)
			)
            {
                result = middle;
                left = middle + 1;
            }
            else
                right = middle - 1;
        }
        return result;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return 0;
        vector<vector<int>> cellSafenessFactor(n, vector<int>(n, INT_MAX));
        calculateCellsSafenessFactor(cellSafenessFactor, n, grid);
        return binarySearch(n, cellSafenessFactor);
    }
};
