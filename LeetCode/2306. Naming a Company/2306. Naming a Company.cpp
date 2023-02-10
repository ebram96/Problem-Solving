class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int sz = ideas.size(), couplables[26][26];
        bool couples[50000][26];
        memset(couplables, 0, sizeof(couplables));
        memset(couples, false, sizeof(couples));

        unordered_set<string> words(ideas.begin(), ideas.end());
        char c;
        
        for(int i = 0; i < sz; i++)
        {
            c = ideas[i][0];
            for(int j = 0; j < 26; j++)
            {
                ideas[i][0] = 'a' + j;
                if(words.find(ideas[i]) == words.end())
                {
                    couples[i][j] = true;
                    couplables[j][c - 'a']++;
                }
            }
            ideas[i][0] = c;
        }

        long long res = 0;
        for(int i = 0; i < sz; i++)
            for(int j = 0; j < 26; j++)
                if(couples[i][j])
                    res += couplables[ideas[i][0] - 'a'][j];
        return res;
    }
};
