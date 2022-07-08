//Time Complexity: O(sqrt(n) log(n))

typedef ll long long;
// count of numbers from 1 to n that are co-prime with n.
ll euler_totient(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            result -= result / i;
        while (n % i == 0)
            n /= i;
    }
    if (n > 1)
        result -= result / n;
    return result;
}
