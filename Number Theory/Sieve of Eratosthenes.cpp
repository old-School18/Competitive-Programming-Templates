// Time Complexity: O(n log log n)
// Determine prime numbers from 1 to n.

typedef long long ll;
void sieve(ll n)
{
    bool isPrime[n + 1];
    for (ll i = 0; i <= n; i++)
    {
        if (i % 2 != 0)
            isPrime[i] = true;
        else
            isPrime[i] = false;
    }
    isPrime[1] = false;
    isPrime[2] = true;

    for (ll i = 2; i * i <= n; i++)
    {
        if (isPrime[i] == true)
        {
            for (ll j = i * i; j <= n; j += 2 * i)
                isPrime[j] = false;
        }
    }
}
