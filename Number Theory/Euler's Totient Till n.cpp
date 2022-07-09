// Time Complexity: O(n log log n)
// Euler Totient of numbers from 1 to n where 
// Euler Totient(k) = count of numbers from 1 to k 
// that are co-prime with k.

typedef long long ll;
void euler_totient_till_n(ll n)
{
    vector<ll> phi(n + 1);
    for (ll i = 0; i <= n; i++)
        phi[i] = i;

    for (ll i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
