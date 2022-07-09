// Time Complexity: O(sqrt(n) log n)

typedef long long ll;
set<ll> prime_factors(ll n)
{
    set<ll> pf;
    while (n % 2 == 0)
    {
        pf.insert(2);
        n /= 2;
    }
    for (ll x = 3; x * x <= n; x += 2)
    {
        while (n % x == 0)
        {
            pf.insert(x);
            n /= x;
        }
    }
    if (n > 1)
        pf.insert(n);
    return pf;
}
