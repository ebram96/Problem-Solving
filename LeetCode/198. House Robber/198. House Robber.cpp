class Solution {
private:
    int memo[100];

    int maxRobbery(const vector<int> &nums, const int &n, int i)
    {
        if(i >= n)
            return 0;
        
        if(~memo[i])
            return memo[i];
        
        return memo[i] = max(
            maxRobbery(nums, n, i + 1),
            maxRobbery(nums, n, i + 2) + nums[i]
        );
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        memset(memo, -1, sizeof(memo));

        return maxRobbery(nums, n, 0);
    }
};
