// Time Complexity: O(log y)
// x^y

typedef long long ll;
ll exponent(ll x, ll y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return exponent(x * x, y / 2);
    else
        return (x * exponent(x * x, (y - 1) / 2));
}
