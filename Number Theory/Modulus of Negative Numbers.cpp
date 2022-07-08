// Time Complexity: O(1)
// To find a % b when either or both of a and b are negative

typedef long long ll;
ll mod_neg(ll a, ll b)
{
    return a - (a / b) * b;
}
