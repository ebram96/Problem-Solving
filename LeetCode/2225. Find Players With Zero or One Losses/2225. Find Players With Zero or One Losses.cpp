class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lossesCount;
        map<int, bool> playedAtLeastOnce;
        
        for(const auto &match : matches)
        {
            playedAtLeastOnce[match[0]] = playedAtLeastOnce[match[1]] = true;
            lossesCount[match[1]]++;
        }
        
        vector<vector<int>> res;
        vector<int> neverLost, lostExactlyOnce;
        int team;
        bool played;
        for(map<int, bool>::iterator it = playedAtLeastOnce.begin(); it != playedAtLeastOnce.end(); it++)
        {
            team = it->first;
            played = it->second;
            
            if(lossesCount[team] == 0)
                neverLost.push_back(team);
            else if(lossesCount[team] == 1)
                lostExactlyOnce.push_back(team);
        }
        
        res.push_back(neverLost);
        res.push_back(lostExactlyOnce);
        
        return res;
    }
};
