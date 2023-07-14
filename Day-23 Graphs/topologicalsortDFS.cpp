#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, int V, vector<int> &visited, vector<int> adj[], stack<int> &st)
    {
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (!visited[it])
                dfs(it, V, visited, adj, st);
        }
        st.push(node);
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, V, visited, adj, st);
            }
        }
        vector<int> res;
        for (int i = 0; i < V; i++)
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};

int check(int V, vector<int> &res, vector<int> adj[])
{
    if (V != res.size())
        return 0;
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;
        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);
        cout << check(N, res, adj) << endl;
    }
    return 0;
}
