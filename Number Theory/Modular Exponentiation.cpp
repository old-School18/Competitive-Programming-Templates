// Time Complexity: O(log y)
// (x^y) % M

typedef long long ll;
ll modexponent(ll x, ll y, ll M)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return modexponent((x * x) % M, y / 2, M);
    else
        return (x * modexponent((x * x) % M, (y - 1) / 2, M)) % M;
}
