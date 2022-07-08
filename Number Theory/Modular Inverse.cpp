// Time Complexity: O(log(max(a,M))
// determine 'inv' where (a * inv) % M = 1

typedef long long ll;
ll g, x, y;
void extended_euclid(ll a, ll b)
{
    if (b == 0)
    {
        g = a;
        x = 1;
        y = 0;
    }
    else
    {
        extendedEuclid(b, a % b);
        ll temp = x;
        x = y;
        y = temp - (a / b) * y;
    }
}
ll mod_inverse(ll a, ll M)
{
    extendedEuclid(a, M);
    return (x % M + M) % M;
}
