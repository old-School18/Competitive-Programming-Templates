// Time Complexity: O(E.V)
// Shortest path in negative weights graphs

typedef long long ll;
const ll INF = 1e15;
const ll MAX = 1e5 + 5;
vector<pair<ll, ll>> edge; // edge list
bool bellman_ford(ll src, ll V, ll E)
{
    ll dist[V + 1];
    for (ll i = 1; i <= V; i++)
        dist[i] = INF;
    dist[src] = 0;
    for (ll i = 1; i <= V; i++)
    {
        for (ll j = 0; j < E; j++)
        {
            ll u = edge[j].first.first;
            ll v = edge[j].first.second;
            ll wt = edge[j].second;
            if (dist[u] != INF && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }

    for (ll i = 0; i < E; i++)
    {
        ll u = edge[i].first.first;
        ll v = edge[i].first.second;
        ll wt = edge[i].second;
        if (dist[u] != INF && dist[u] + wt < dist[v])
            return false; // negative cycle exists
    }

    // No negative cycle. Shortest path exists
    return true;
}
