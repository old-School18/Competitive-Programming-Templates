// Time Complexity: O(|V| + |E|log V)
// Print the shortest path from source to destination 
//in a weighted graph

typedef long long ll;
const ll MAX = 1e5 + 5;
vector<ll> adj[MAX];
bool dijkstra(ll src, ll dest, ll V, ll pred[], ll dist[])
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (ll i = 1; i <= V; i++)
    {
        dist[i] = -1;
        pred[i] = -1;
    }
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
                pred[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return (dist[dest] != -1);
}

vector<ll> print_shortest_path(ll src, ll dest, ll V)
{
    ll pred[V + 1], dist[V + 1];
    vector<ll> path;
    if((shortestpath(src,dest,V,pred,dist)==false){
        cout << "No path\n";
        return path;
    }
    ll final=dest;
    while(pred[final]!=-1){
        path.pb(final);
        final = pred[final];
    }
    reverse(path.begin(),path.end());
	return path;
}
