// Time Complexity: O(V^3)
// All pairs shortest path

typedef long long ll;
const ll INF = 1e15;
ll V;
bool floyd_warshall(ll adj_mat[][V], ll dist[][V])
{
    ll i, j, k;

    for (i = 1; i <= V; i++)
        for (j = 1; j <= V; j++)
            dist[i][j] = adj_mat[i][j];

    for (k = 1; k <= V; k++)
    {
        for (i = 1; i <= V; i++)
        {
            for (j = 1; j <= V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (ll i = 1; i <= V; i++)
        if (dist[i][i] < 0)
            return false;
    return true;
}

int main()
{
    ll adj_mat[V][V] =  { {0   , 1   , INF , INF}, 
                        {INF , 0   , -1  , INF}, 
                        {INF , INF , 0   ,  -1}, 
                        {-1  , INF , INF ,   0}}; 
    ll dist[V][V];
    floydWarshall(adj_mat, dist);
}
