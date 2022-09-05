// Time Complexity: O(n)
// Maximum subarray sum

typedef long long ll;
ll kadane_with_dp(ll a[], ll n)
{
    ll dp[n] = {0};
    dp[0] = a[0];
    for (ll i = 0; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
    }
    ll max_overall = LLONG_MIN;
    for (ll i = 0; i < n; i++)
        max_overall = max(max_overall, dp[i]);
    return max_overall;
}
