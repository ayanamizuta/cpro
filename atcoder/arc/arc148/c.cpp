#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n, q;
int ps[200001];
vector<vector<int>> edges;
bool table[200001];
int sizes[200001];
vector<int> query;

void solve(int m)
{
  int ret = 0;
  for (auto v : query)
  {
    table[v] = true;
    sizes[ps[v]] += 1;
  }
  for (auto v : query)
  {
    if (!table[ps[v]])
      ret += 1;
  }
  for (auto v : query)
  {
    /*for (auto next_v : edges[v])
    {
      if (table[v] != table[next_v])
      {
        ret += 1;
      }
    }*/
    ret += edges[v].size() - sizes[v] - 1;
  }
  // ret += 1;
  cout << ret << endl;
  for (auto v : query)
  {
    table[v] = false;
    sizes[ps[v]] = 0;
  }
}

int main()
{
  cin >> n >> q;
  edges.resize(n + 1);
  edges[0].push_back(1);
  edges[1].push_back(0);
  REP(i, n + 1)
  table[i] = false;
  REP(i, n - 1)
  {
    int p;
    cin >> p;
    ps[i + 2] = p;
    edges[p].push_back(i + 2);
    edges[i + 2].push_back(p);
  }

  REP(i, q)
  {
    int m;
    cin >> m;
    query.resize(m);
    REP(i, m)
    cin >> query[i];
    solve(m);
  }
}