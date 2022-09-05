// Time Complexity: O(nlogn)
// Longest Increasing Subsequence in O(nlongn) time

typedef long long ll;
ll greater_than_equal_to(vector<ll> a, ll lo, ll hi, ll key, ll n)
{
    if (lo >= hi)
    {
        if (lo < n && a[lo] < key)
            lo++;
        return lo;
    }
    ll mid = lo + (hi - lo) / 2;
    if (a[mid] >= key)
        return greater_than_equal_to(a, lo, mid, key, n);
    else
        return greater_than_equal_to(a, mid + 1, hi, key, n);
}

ll lis_optimised(ll a[], ll n)
{
    vector<ll> lengthwise(n, 0);
    lengthwise[0] = a[0];
    ll length = 1;
    for (ll i = 1; i < n; i++)
    {
        if (a[i] < lengthwise[0])
        {
            lengthwise[0] = a[0];
        }
        else if (a[i] > lengthwise[length - 1])
        {
            lengthwise[length++] = a[i];
        }
        else
        {
            lengthwise[greater_than_equal_to(lengthwise, 0, length - 1, a[i], length)] = a[i];
        }
    }
    return length;
}
