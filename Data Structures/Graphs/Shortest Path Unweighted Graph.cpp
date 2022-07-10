// Time Complexity: O(V + E)

typedef long long ll;
const ll MAX = 1e5 + 5;
vector<ll> adj[MAX];
void shortest_path(ll src, ll V, ll pred[], ll dist[])
{
    queue<ll> qe;
    for (ll i = 1; i <= V; i++)
        dist[i] = -1;
    dist[src] = 0;
    qe.push(src);
    while (!qe.empty())
    {
        ll u = qe.front();
        qe.pop();
        for (auto &p : adj[u])
        {
            if (dist[p] == -1)
            {
                dist[p] = dist[u] + 1;
                pred[p] = u;
                qe.push(p);
            }
        }
    }
    return;
}
