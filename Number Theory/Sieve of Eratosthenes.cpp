// Time Complexity: O(n log log n)
// Determine prime numbers from 1 to n.

typedef long long ll;
void sieve(ll n)
{
    bool is_prime[n + 1];
    for (ll i = 0; i <= n; i++)
    {
        if (i % 2 != 0)
            is_prime[i] = true;
        else
            is_prime[i] = false;
    }
    is_prime[1] = false;
    is_prime[2] = true;

    for (ll i = 2; i * i <= n; i++)
    {
        if (is_prime[i] == true)
        {
            for (ll j = i * i; j <= n; j += 2 * i)
                is_prime[j] = false;
        }
    }
}
