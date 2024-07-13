#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define neg cout << -1 << endl
#define pb push_back
#define ss second
#define ff first

const int mod = 1e9 + 7;
//const int N = 2e5 + 5;
const int INF = 1e18;
int md = 998244353;


void dfs(int node, int parent, const vector<vector<pair<int, int>>>& adj, vector<int>& dist)
{
    for (const auto& neighbor : adj[node])
    {
        int nextNode = neighbor.first;
        int roadLength = neighbor.second;
        if (nextNode != parent)
        {
            dist[nextNode] = dist[node] + roadLength;
            dfs(nextNode, node, adj, dist);
        }
    }
}



void solve()
{
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n + 1);
    int sumOfEdges = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
        sumOfEdges += c;
    }

    // First DFS to find the furthest node from node 1
    vector<int> dist(n + 1, 0);
    dfs(1, -1, adj, dist);

    // Find the furthest node from node 1
    int furthestNode = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (dist[i] > dist[furthestNode])
        {
            furthestNode = i;
        }
    }

    // Second DFS from the furthest node found to determine the longest path in the tree
    dist.assign(n + 1, 0);
    dfs(furthestNode, -1, adj, dist);

    // Find the longest path in the tree
    int longestPath = *max_element(dist.begin(), dist.end());

    // The result is the sum of all edge lengths * 2 - the longest path
    int result = 2 * sumOfEdges - longestPath;

    cout << result << endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test=1;
    //cin >> test;
    for (int tc = 1; tc <= test; tc++)
    {
        solve();
    }

    return 0;
}

