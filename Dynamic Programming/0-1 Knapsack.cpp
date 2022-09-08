// Time Complexity: O(n*W)
// Fill a knapsack with given weights such that the sum of values of the chosen weights is maximum. A weight can be
// added only once.


// 2D DP

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
    return dp[n-1][W];
}

// 1D DP Style A

typedef long long ll;
ll zerone_knapsack(ll w[], ll v[], ll n, ll W)
{
    ll dp[2][W + 1];
    ll flag = 0;
    memset(dp, -1, sizeof(dp));
    for (ll i = 0; i < n; i++)
    {
        flag = 1 - flag;
        for (ll j = w[i]; j <= W; j++)
            if (i == 0)
                dp[flag][j] = max(dp[flag][j], v[i]);
            else if (dp[1 - flag][j - w[i]] != -1)
                dp[flag][j] = max(dp[flag][j], dp[1 - flag][j - w[i]] + v[i]);
    }
    return dp[flag][W];
}

// 1D DP Style B

typedef long long ll;
ll zerone_knapsack(ll w[], ll v[], ll n, ll w)
{
    ll dp[n + 1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (ll i = 0; i < n; i++)
        for (ll j = W; j >= w[i]; j--)
            if (dp[j - w[i]] != -1)
                dp[j] = dp[j - w[i]] + v[i];
    return dp[W];
}
