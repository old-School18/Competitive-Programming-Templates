//Time Complexity: O(k)

typedef long long ll;
// ncr
ll binomial_coefficient(ll n, ll r)
{
    ll res = 1;
    if (r > n - r)
        r = n - r;
    for (ll i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
