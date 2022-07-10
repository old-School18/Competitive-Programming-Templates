// Time Complexity: O(|V| + |E|log V)
// Shortest path weighted graph


typedef long long ll;
const ll MAX = 1e5 + 5;
vector<ll> adj[MAX];
void dijkstra(ll src, ll V, ll dist[])
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; // minheap
    for (ll i = 1; i <= V; i++)
        dist[i] = -1;
    dist[src] = 0;
    pq.push(make_pair(dist[src], src));
    while (!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();
        for (auto &p : adj[u])
        {
            ll v = p.first, weight = p.second;
            if (dist[v] == -1 || dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                pred[v] = u;
            }
        }
    }
    return;
}
