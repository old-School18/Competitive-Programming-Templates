//Time Complexity: O(sqrt(n) log n)

typedef long long ll;
ll prime_factors[n + 1];
void prime_factorize(ll n)
{
    while(n % 2 == 0)
    {
        prime_factors[2]++;
        n /= 2;
    }
    for (ll i = 3; i * i <= n; i+=2)
    {
        while (n % i == 0)
        {
            prime_factors[i]++;
            n /= i;
        }
    }
    if (n > 1)
        prime_factors[n]++;
    return;
}
ll count_factors(ll n)
{
    prime_factorize(n);
    ll ans = 1;

    for (ll i = 1; i <= n; i++)
    {
        ans *= (prime_factors[i] + 1ll);
    }
    return ans;
}
