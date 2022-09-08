// Time Complexity: O(n*m)
// Minimum insert/delete/replace operations to transform given string to target string

typedef long long ll;
ll edit_distance(string s, string t)
{
    ll n = s.size(), m = t.size();
    ll dp[n + 1][m + 1];
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
                continue;
            }
            if (j == 0)
            {
                dp[i][j] = i;
                continue;
            }
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + dp[i - 1][j - 1];
            dp[i][j] = min(dp[i][j], 1 + min(dp[i][j - 1], dp[i - 1][j]));
        }
    }
    return dp[n][m];
}
