// Time Complexity: O(n*W)
// Fill a knapsack with given weights such that the sum of values of the chosen weights is maximum. A weight can be
// added only once. The sum of the chosen weights is less than or equal to the capacity of the knapsack W. 


// 2D DP

typedef long long ll;
ll zerone_knapsack(ll w[], ll v[], ll n, ll W)
{
    ll dp[n + 1][W + 1];
    memset(dp, 0, sizeof(dp));
    for (ll i = 0; i <= n; i++)
        for (ll j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= w[i])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    return dp[n - 1][W];
}

// 1D DP Style A

typedef long long ll;
ll zerone_knapsack(ll w[], ll v[], ll n, ll W)
{
    ll dp[2][W + 1];
    ll flag = 0;
    memset(dp, 0, sizeof(dp));
    for (ll i = 0; i < n; i++)
    {
        flag = 1 - flag;
        for (ll j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[flag][j] = 0;
            else
            {
                dp[flag][j] = dp[1 - flag][j];
                if (j >= w[i])
                    dp[flag][j] = max(dp[flag][j], dp[1 - flag][j - w[i]] + v[i]);
            }
        }
    }
    return dp[flag][W];
}

// 1D DP Style B

typedef long long ll;
ll zerone_knapsack(ll w[], ll v[], ll n, ll w)
{
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    for (ll i = 0; i < n; i++)
        for (ll j = W; j >= w[i]; j--)
            dp[j] = dp[j - w[i]] + v[i];
    return dp[W];
}
