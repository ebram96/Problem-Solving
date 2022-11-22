class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        int cnt[101] = {0};
        for(const int &n : nums)
        {
            res += cnt[n];
            cnt[n]++;
        }
        return res;
    }
};
