class Solution {
public:
    vector<vector<int>> dp;

    bool solve(string& s, string& p, int i, int j) {

        // Pattern completely processed
        if (j == p.size()) {
            return i == s.size();
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Does current character match?
        bool firstMatch =
            (i < s.size() &&
             (s[i] == p[j] || p[j] == '.'));

        // Next character is '*'
        if (j + 1 < p.size() && p[j + 1] == '*') {

            // Option 1: use '*' zero times
            bool skip = solve(s, p, i, j + 2);

            // Option 2: use '*' one or more times
            bool use =
                firstMatch &&
                solve(s, p, i + 1, j);

            return dp[i][j] = skip || use;
        }

        // Normal character or '.'
        if (firstMatch) {
            return dp[i][j] = solve(s, p, i + 1, j + 1);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        dp.assign(
            s.size() + 1,
            vector<int>(p.size() + 1, -1)
        );

        return solve(s, p, 0, 0);
    }
};