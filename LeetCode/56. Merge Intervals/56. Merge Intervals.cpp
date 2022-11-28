class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int start, end, sz = intervals.size();
        vector<vector<int>> res;

        for(int i = 0; i < sz; i++)
        {
            start = intervals[i][0];
            end = intervals[i][1];

            while(i < sz && end >= intervals[i][0])
            {
                end = max(end, intervals[i][1]);
                i++;
            }
            i--;
            
            res.push_back({start, end});
        }
        
        return res;
    }
};
