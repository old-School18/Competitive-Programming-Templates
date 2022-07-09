// Time Complexity: O(log(max(a,b)))
// Determines if there's a solution to the equation ax + by = c.

typedef long long ll;
ll g, x, y;
void extendedEuclid(ll A, ll B)
{
    if (B == 0)
    {
        g = A;
        x = 1;
        y = 0;
    }
    else
    {
        extendedEuclid(B, A % B);
        ll temp = x;
        x = y;
        y = temp - (A / B) * y;
    }
}

bool find_any_solution(ll a, ll b, ll c)
{
    extendedEuclid(abs(a), abs(b));
    if (a == 0 && b == 0 && c == 0)
    {
        return true; // infinite solutions
    }
    if (a == 0 && b == 0)
    {
        return true;
    }
    if (c % g)
    {
        return false;
    }

    x *= c / g;
    y *= c / g;
    if (a < 0)
        x = -x;
    if (b < 0)
        y = -y;
    return true;
}
