// Time Complexity: O(V+E)

typedef long long ll;
const ll MAX = 1e5 + 5;
vector<ll> adj[MAX];
void dfs(ll s)
{
    vis[s] = true;
    for (auto &p : adj[s])
    {
        if (!vis[p])
            dfs(p);
    }
    return;
}
