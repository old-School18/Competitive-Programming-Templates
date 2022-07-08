//Time Complexity: O(log(max(a,b)))

typedef long long ll;
ll d, x, y;
void extendedEuclid(ll a, ll b)
{
    if (b == 0)
    {
        d = a;
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
