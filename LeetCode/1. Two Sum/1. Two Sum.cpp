class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>> indexed;
        int i = 0, lval, rval, sum;
        for(int n : nums)
        {
            indexed[n].push_back(i);
            i++;
        }
        map<int, vector<int>>::iterator left = indexed.begin();
        map<int, vector<int>>::iterator right = indexed.end();
        right--;
        do
        {
            lval = left->first;
            rval = right->first;
            sum = lval + rval;

            if(sum == target)
                return vector<int> {
                    left->second.front(),
                    right->second.back()
                };
            if(sum > target)
                right--;
            else
                left++;
        }
        while(true);
        // This should never happen
        return vector<int>{};
    }
};