#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

using fps = vector<mint>;
fps operator*(const fps &a, const fps &b) { return atcoder::convolution(a, b); }
fps operator+(const fps &a, const fps &b)
{
  fps c{a};
  if (a.size() < b.size())
    c.resize(b.size());
  for (int i = 0; i < (int)b.size(); i++)
    c[i] += b[i];
  return c;
}

int n, x, y;
vector<vector<int>> edges;
bool visited[200001];
vector<int> res;

bool dfs(int v)
{
  if (visited[v])
    return false;
  visited[v] = true;
  if (v == x)
  {
    res.push_back(v);
    return true;
  }
  for (auto next : edges[v])
  {
    auto next_res = dfs(next);
    if (next_res)
    {
      res.push_back(v);
      return true;
    }
  }
  return false;
}

int main()
{
  cin >> n >> x >> y;
  edges.resize(n);
  REP(i, n - 1)
  {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  x--;
  y--;
  dfs(y);
  for (auto v : res)
  {
    cout << v + 1 << " ";
  }
  cout << endl;
}