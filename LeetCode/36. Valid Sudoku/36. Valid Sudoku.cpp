class Solution {
private:
    bool validSubBox(vector<vector<char>>& board, int i, int j)
    {
        bool seen[10] = {false};
        for(int r = i; r < i + 3; r++)
            for(int c = j; c < j + 3; c++)
                if(board[r][c] != '.')
                {
                    if(seen[board[r][c] - '0'])
                        return false;
                    seen[board[r][c] - '0'] = true;
                }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool seen[10];
        for(int i = 0; i < 9; i++)
        {
            memset(seen, false, sizeof(seen));
            for(int j = 0; j < 9; j++)
                if(board[i][j] != '.')
                {
                    if(seen[board[i][j] - '0'])
                        return false;
                    seen[board[i][j] - '0'] = true;
                }
            
            memset(seen, false, sizeof(seen));
            for(int j = 0; j < 9; j++)
                if(board[j][i] != '.')
                {
                    if(seen[board[j][i] - '0'])
                        return false;
                    seen[board[j][i] - '0'] = true;
                }
        }
        
        for(int i = 0; i < 9; i += 3)
            for(int j = 0; j < 9; j += 3)
                if(!validSubBox(board, i, j))
                    return false;
        return true;
    }
};
