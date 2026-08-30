class Solution {
public:
    int dp[21][21];
    bool solve(int i, int j, string& s, string& p){
        if(i == s.size() && j == p.size())
            return dp[i][j] = true;

        if(j == p.size())
            return dp[i][j] = false;

        if(i == s.size()){
            if(j + 1 < p.size() && p[j + 1] == '*')
                return dp[i][j] = solve(i, j + 2, s, p);

            return dp[i][j] = false;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        // If current character is followed by *
        if(j + 1 < p.size() && p[j + 1] == '*'){
            if(s[i] == p[j] || p[j] == '.'){
                return dp[i][j] = solve(i, j + 2, s, p) ||
                       solve(i + 1, j, s, p);
            }
            else{
                return dp[i][j] = solve(i, j + 2, s, p);
            }
        }

        if(s[i] == p[j]){
            return dp[i][j] = solve(i + 1, j + 1, s, p);
        }

        if(p[j] == '.'){
            return dp[i][j] = solve(i + 1, j + 1, s, p);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, p);
    }
};