#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int start, vector<int> adj[], int visited[], vector<int> &result)
    {
        visited[start] = 1;
        result.push_back(start);
        for (auto it : adj[start])
        {
            if (!visited[it])
            {
                dfs(it, adj, visited, result);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        int start = 0;
        vector<int> result;
        dfs(start, adj, visited, result);
        return result;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
