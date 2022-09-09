// Time Complexity: O(W*n)
// Fill a knapsack with given weights such that the sum of values of the chosen weights is maximum. A weight can be
// added more than once. The sum of the chosen weights is less than or equal to the capacity of the knapsack W.

typedef long long ll;
ll integer_knapsack(ll w[], ll v[], ll n, ll W)
{
    ll dp[W + 1];
    memset(dp, 0, sizeof(dp));
    for (ll i = 0; i <= W; i++)
        for (ll j = 0; j < n; j++)
        {
            if (i >= w[j])
                dp[i] = max(dp[i], dp[i - w[j]] + v[j]);
        }
    return dp[W];
}
