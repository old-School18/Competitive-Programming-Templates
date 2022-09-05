// Time Complexity: O(n)
// Printing the Longest Increasing Subsequence

typedef long long ll;
vector<ll> lis(ll a[], ll n)
{
    vector<ll> li;
    ll lis[n], prev[n];
    memset(lis, 0, sizeof(lis));
    for (ll i = 0; i < n; i++)
    {
        lis[i] = 1;
        prev[i] = -1;
        for (ll j = 0; j < i; j++)
        {
            if (a[j] < a[i] && lis[j] + 1 > [i])
                lis[i] = lis[j] + 1, prev[i] = j;
        }
    }
    ll ans = 0ll, ind = 0;
    for (ll i = 0; i < n; i++)
    {
        if (ans < lis[i])
            ans = lis[i], ind = i;
    }
    while (ind != -1)
    {
        lis.pb(a[i]);
        ind = prev[ind];
    }

    return li;
}
