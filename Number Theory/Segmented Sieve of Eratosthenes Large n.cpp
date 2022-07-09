// Time Complexity: O(sqrt(n))
// Determine prime numbers from 1 to n if n is large.

void sieve(ll n, vector<ll> &prime)
{
    bool is_prime[n + 1];
    for (ll i = 0; i <= n; i++)
    {
        if (i % 2)
            is_prime[i] = true;
        else
            is_prime[i] = false;
    }
    is_prime[1] = false;
    is_prime[2] = true;

    for (ll i = 2; i * i <= n; ++i)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
            for (int j = i * i; j <= n; j += 2 * i)
                is_prime[j] = false;
        }
    }

    for (ll i = 0; i <= n; i++)
    {
        if (is_prime[i])
            prime.push_back(i);
    }
    return;
}
vector<ll> segmented_sieve_large_n(ll n)
{
    ll limit = floor(sqrt(n)) + 1ll;
    vector<ll> prime;
    sieve(limit, prime);
    vector<ll> prime_till_n = prime;
    bool is_prime[limit + 1];
    ll lo = limit, hi = 2ll * limit;
    while (lo < n)
    {
        if (hi >= n)
            hi = n;
        memset(is_prime, true, sizeof(is_prime));

        for (ll i = 0; i < (ll) prime.size(); i++)
        {
            ll lo_lim = floor(lo / prime[i]) * prime[i];
            if (lo_lim < lo)
                lo_lim += prime[i];
            for (ll j = lo_lim; j <= hi; j += prime[i])
                is_prime[j - lo] = false;
        }
        for (ll i = lo; i <= hi; i++)
            if (is_prime[i - lo] == true)
                prime_till_n.push_back(i);

        lo += limit;
        hi += limit;
    }
    return prime_till_n;
}
