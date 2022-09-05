// Time Complexity: O(n*W)
// Fill a knapsack with given weights such that the sum of values of the chosen weights is maximum. A weight can be
// added only once.

typedef long long ll;
ll zerone_knapsack(ll w[], ll v[], ll n, ll W)
{
    ll dp[n][W + 1];
    memset(dp, -1, sizeof(dp));
    for (ll i = 0; i < n; i++)
        for (ll j = w[i]; j <= W; j++)
            if (i == 0)
                dp[i][j] = max(dp[i][j], v[i]);
            else if (dp[i - 1][j - w[i]] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
}
