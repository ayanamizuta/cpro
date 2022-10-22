#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n, q;
queue<int> edge_vertices;
vector<int> parents;
int cluster[200000], cluster2[200000], visited[200000];
vector<vector<int>> edges;

void dfs(int v, int color)
{
  cluster[v] = color;
  for (auto nv : edges[v])
  {
    if (!visited[nv] || cluster[nv])
      continue;
    dfs(nv, color);
  }
}

int main()
{
  cin >> n;
  edges.resize(n);
  REP(i, n)
  {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  REP(i, n)
  {
    if (edges[i].size() == 1)
    {
      edge_vertices.push(i);
    }
  }
  while (!edge_vertices.empty())
  {
    int v = edge_vertices.front();
    visited[v] = visited[v] ? visited[v] : 1;
    edge_vertices.pop();
    int non_visited_cnt = 0, non_visited_v = -1;
    for (auto next_v : edges[v])
    {
      if (visited[next_v] == 2)
      {
        non_visited_cnt++;
        continue;
      }
      if (!visited[next_v])
      {
        non_visited_cnt++;
        non_visited_v = next_v;
      }
      if (non_visited_cnt >= 2)
      {
        break;
      }
    }
    // cerr << v << " " << non_visited_cnt << " " << non_visited_v << endl;
    if (non_visited_cnt < 2)
    {
      if (visited[v] != 2)
        parents.push_back(v);
      visited[v] = 2;
    }
    else
    {
      if (non_visited_v != -1 && !visited[non_visited_v])
        edge_vertices.push(non_visited_v);
    }
  }

  int color = 1;
  for (auto v : parents)
  {
    visited[v] = 0;
    // cerr << v << endl;
  }
  for (auto v : parents)
  {
    dfs(v, color);
    color++;
  }
  cin >> q;
  REP(i, q)
  {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (cluster[x] == cluster[y] && cluster[x] != 0)
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
}