// Time Complexity: O(W*n)
// Fill a knapsack with given weights such that the sum of values of the chosen weights is maximum. A weight can be added more than once.

typedef long long ll;
ll integer_knapsack(ll w[], ll v[], ll n, ll W)
{
    ll dp[W + 1] = {0};
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (ll i = 0; i <= W; i++)
        for (ll j = 0; j < n; j++)
            if (i >= w[j] && dp[i – w[j]] != -1)
                dp[i] = max(dp[i], dp[i - w[j]] + v[j]);
    return dp[W];
}
