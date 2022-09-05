// Recursion
// Time Complexity: O(2^n)
// Space complexity: O(1)

typedef long long ll;
ll fibonacci(ll n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Tabulation
// Time Complexity: O(n)
// Space complexity: O(n)

typedef long long ll;
ll table[n + 1];
ll fibonacci(ll n)
{
    table[0] = 0, table[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table[n];
}

// Memoization
// Time Complexity: O(n)
// Space complexity: O(n)

typedef long long ll;
ll table[n + 1] = {0};
ll fibonacci(ll n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (table[n] != 0)
        return table[n];
    return table[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

// Space optimised strategy
// Time Complexity: O(n)
// Space complexity: O(1)

typedef long long ll;
ll fibonacci(ll n)
{
    ll a = 0, b = 1, sum;
    if (n == 0)
        return a;
    for (ll i = 2; i <= n; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    return b;
}
