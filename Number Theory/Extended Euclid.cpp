// Time Complexity: O(log(max(a,b)))
// Determines the coefficients 'x'and 'y' in ax + by = gcd(a, b). 

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
