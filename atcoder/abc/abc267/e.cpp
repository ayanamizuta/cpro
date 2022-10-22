#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n, m;
LL a[200000], sums_original[200000], sums[200000];
vector<vector<int>> edges;
bool deleted[200000];

void dfs(int v, LL thres)
{
  if (thres < sums[v] || deleted[v])
    return;
  deleted[v] = true;
  for (auto next_v : edges[v])
  {
    sums[next_v] -= a[v];
  }
  for (auto next_v : edges[v])
  {
    dfs(next_v, thres);
  }
}

bool ok(LL val)
{
  REP(i, n)
  {
    deleted[i] = false;
    sums[i] = sums_original[i];
  }
  REP(i, n)
  {
    dfs(i, val);
  }
  REP(i, n)
  {
    if (!deleted[i])
      return false;
  }
  return true;
}

int main()
{
  cin >> n >> m;
  edges.resize(n);
  REP(i, n)
  cin >> a[i];
  REP(i, m)
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
    for (auto v : edges[i])
    {
      sums_original[i] += a[v];
    }
  }
  LL lb = 0, ub = 100000000000000000;
  while (lb < ub)
  {
    LL mid = (lb + ub) / 2;
    if (ok(mid))
    {
      ub = mid;
    }
    else
    {
      lb = mid + 1;
    }
  }
  cout << lb << endl;
}