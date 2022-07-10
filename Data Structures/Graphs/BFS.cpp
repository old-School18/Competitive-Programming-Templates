// Time Complexity: O(V+E)

typedef long long ll;
const ll MAX = 1e5 + 5;
vector<ll> adj[MAX];
bool vis[MAX];
void bfs(ll s)
{
    queue<ll> qe;
    qe.push(s);
    vis[s] = true;
    while (!qe.empty())
    {
        ll p = qe.front();
        qe.pop();
        for (auto &z : adj[p])
        {
            if (!vis[z])
            {
                vis[z] = true;
                qe.push(z);
            }
        }
    }
    return;
}
