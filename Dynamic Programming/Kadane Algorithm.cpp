// Time Complexity: O(n)
// Maximum subarray sum

typedef ll long long;
ll kadane(ll a[], ll n)
{
    ll max_total = 0, max_now = 0;
    for (ll i = 0; i < n; i++)
    {
        max_now = max_now + a[i];
        if (max_now < 0)
            max_now = 0;
        else if (max_total < max_now)
            max_total = max_now;
    }
    if (max_total > 0)
        return max_total;
    else
    {
        ll *z = max_element(a, a + n);
        ll k = *z;
        return k;
    }
}
