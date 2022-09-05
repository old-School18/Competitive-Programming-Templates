// Time Complexity: O(n*m)
// Printing the Longest Common Subsequence of two given strings

typedef long long ll;
#define sz(s) (ll) s.size()
string lcs_printing(string s, string t)
{
    string lcs = "";
    lld n = sz(s), m = sz(t);
    lld dp[n + 1][m + 1];
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    lld x = n, y = m;
    while (x > 0 && y > 0)
    {
        if (s[x - 1] == t[y - 1])
        {
            lcs.pb(s[x - 1]);
            x--, y--;
        }
        else if (dp[x][y - 1] > dp[x - 1][y])
            y--;
        else
            x--;
    }
    reverse(all(lcs));
    return lcs;
}
