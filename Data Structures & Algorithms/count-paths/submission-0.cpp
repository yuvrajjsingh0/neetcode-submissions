class Solution {
public:
    vector<vector<int>> dp;
    int ways(int m, int n) {
        if(m <= 1 || n <= 1) return 1;
        if(dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = ways(m - 1, n) + ways(m, n - 1);
    }
    int ways_tabulation(int m, int n) {
        for(int i = 2; i <= m; i++) {
            for(int j = 2; j <= n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
        // dp = vector<vector<int>>(m+1, vector<int>(n+1, -1));
        dp = vector<vector<int>>(m+1, vector<int>(n+1, 1));
        return ways_tabulation(m, n);
    }
};