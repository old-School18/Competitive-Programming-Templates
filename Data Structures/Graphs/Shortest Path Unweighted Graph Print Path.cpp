// Time Complexity: O(V + E)
// Print the shortest path from source to destination 
//in a weighted graph

typedef long long ll;
const ll MAX = 1e5 + 5;
vector<ll> adj[MAX];
bool shortest_path(ll src, ll dest, ll V, ll pred[], ll dist[])
{
    queue<ll> qe;
    for (ll i = 1; i <= V; i++)
    {
        dist[i] = -1;
        pred[i] = -1;
    }
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
    return (dist[dest] != -1);
}

vector<ll> print_shortest_path(ll src, ll dest, ll V)
{
    vector<ll> path;
    ll pred[V + 1], dist[V + 1];
    if((shortest_path(src,dest,V,pred,dist)==false){
        cout << "No path\n";
        return path;
    }
    
    ll final=dest;
    while(pred[final]!=-1){
        path.pb(final);
        final = pred[final];
    }
    reverse(path.begin(),path.end());
    return;
}
