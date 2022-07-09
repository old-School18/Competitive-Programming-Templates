// Time Complexity: O(log(max(a,b)))
// Count the number of solutions of ax + by = c if
// x is in the range of [minx, maxy] and y in [miny, maxy].

typedef long long ll;
ll g, x, y;
void extendedEuclid(ll a, ll b)
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

void shift_solution(ll a, ll b, ll cnt)
{
    x += cnt * b;
    y -= cnt * a;
}

bool find_any_solution(ll a, ll b, ll c)
{
    extendedEuclid(abs(a), abs(b));
    if (a == 0 && b == 0 && c == 0)
    {
        return true;
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

ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy)
{
    if (!find_any_solution(a, b, c))
        return 0;
    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shift_solution(a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(a, b, sign_b);
    if (x > maxx)
        return 0;
    ll lx1 = x;

    shift_solution(a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(a, b, -sign_b);
    ll rx1 = x;

    shift_solution(a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(a, b, -sign_a);
    if (y > maxy)
        return 0;
    ll lx2 = x;

    shift_solution(a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(a, b, sign_a);
    ll rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}
