class Solution {
public:
    int memo[100];
    int numDecodings(string s) {
        memset(memo, -1, sizeof(memo));
        int mx = s.size();
        return count(s, 0, mx);
    }
    int count(string& s, int i, int& mx)
    {
        if(i == mx)
            return 1;
        if(~memo[i])
            return memo[i];
        int one_char = (s[i] != '0' ? count(s, i + 1, mx) : 0);
        int two_chars = 
            (
                i < mx - 1 &&
                (
                    s[i] == '1' ||
                    (s[i] == '2' && s[i+1] < '7')
                )
                ? count(s, i + 2, mx) : 0
            );
        return memo[i] = one_char + two_chars;
    }
};
