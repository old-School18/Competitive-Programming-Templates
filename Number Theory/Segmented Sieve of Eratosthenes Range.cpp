// Time Complexity: O(n)
// Determine prime numbers in a given range.

typedef long long ll;
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
vector<ll> segmented_sieve_range(ll lo, ll hi)
{
    ll limit = floor(sqrt(hi)) + 1;
    vector<ll> prime;
    sieve(limit, prime);
    vector<ll> prime_in_range;
    bool is_prime[hi - lo + 1];
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
            prime_in_range.push_back(i);
    return prime_in_range;
}
