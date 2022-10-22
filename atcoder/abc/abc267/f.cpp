#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n;
vector<vector<int>> edges;
vector<vector<pair<int, int>>> que;
int q;
int main()
{
  cin >> n;
  edges.resize(n);
  que.resize(n);
  REP(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  cin >> q;
  REP(i, q)
  {
    int u, k;
    cin >> u >> k;
    u--;
    que[u].push_back({k, i});
  }
  auto dist = [&](int init)
  {
    vector<int> d(n, -1);
    d[init] = 0;
    vector<int> stack({init});
    while (!stack.empty())
    {
      auto v = stack.back();
      stack.pop_back();
      for (auto next_v : edges[v])
      {
        if (d[next_v] >= 0)
          continue;
        d[next_v] = d[v] + 1;
        stack.push_back(next_v);
      }
    }
    return max_element(ALL(d)) - d.begin();
  };
  int l = dist(0);
  int r = dist(l);
  vector<int> ans(q, -1);
  for (int root : {l, r})
  {
    vector<int> path;
    vector<int> stack;
    auto dfs = [&](auto &&dfs, int v, int from) -> void
    {
      path.push_back(v);
      if (v == 2)
      {
        cerr << root << " ";
        REP(i, path.size())
        {
          cerr << path[i] << " ";
        }
        cerr << endl;
      }
      for (const auto &[k, qi] : que[v])
      {
        if (path.size() > k)
        {
          ans[qi] = path[path.size() - k - 1] + 1;
        }
      }
      for (auto next_v : edges[v])
      {
        if (from != next_v)
          dfs(dfs, next_v, v);
      }
      path.pop_back();
    };
    dfs(dfs, root, -1);
  }
  REP(i, q)
  {
    cout << ans[i] << endl;
  }
}