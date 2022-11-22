class Solution {
private:
    int memo[10001];
    int minPerfectSquareSum(vector<int> &selections, int n)
    {
        if(~memo[n])
            return memo[n];
        
        int i = lower_bound(selections.begin(), selections.end(), n) - selections.begin();
        i -= (selections[i] > n);
        
        int res = ~(1<<31), pf;
        while(i >= 0)
        {
            pf = selections[i--];            
            res = min(
                res,
                minPerfectSquareSum(selections, n % pf) + n / pf
            );
        }
        return memo[n] = res;
    }
public:
    int numSquares(int n) {
        vector<int> ps;
        for(int i = 1; i * i <= 10000; i++)
            ps.push_back(i * i);
        
        memset(memo, -1, sizeof(memo));
        memo[0] = 0;
        
        return minPerfectSquareSum(ps, n);
    }
};
