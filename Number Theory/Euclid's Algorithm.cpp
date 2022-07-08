//Time Complexity: O(log(min(a,b)))

typedef long long ll;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
