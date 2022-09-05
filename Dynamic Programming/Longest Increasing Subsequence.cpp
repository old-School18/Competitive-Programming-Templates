// Time Compleixty: O(n^2)

typedef long long ll;
ll lis(ll a[], ll n)
{
    ll lis[n];
    memset(lis, 0, sizeof(lis));
    for (ll i = 0; i < n; i++)
    {
        lis[i] = 1;
        for (ll j = 0; j < i; j++)
        {
            if (a[j] < a[i] && lis[j] + 1 > [i])
                lis[i] = lis[j] + 1;
        }
    }
    ll ans = 0ll;
    for (ll i = 0; i < n; i++)
        ans = max(ans, lis[i]);
    return ans;
}
