#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long
int n, m;
int a[210000], b[210000];
struct ss
{
  int v_next;
  int index;
};
vector<vector<ss>> edges;
bool visited[210000];
bool mylock[210000];
int table[210000];
void dfs(int v)
{
  if (mylock[v])
    return;
  mylock[v] = true;
  REP(i, edges[v].size())
  {
    ss s = edges[v][i];
    if (visited[s.index])
      continue;
    visited[s.index] = true;
    table[s.index] = v == a[s.index] ? 1 : 0;
    dfs(s.v_next);
  }
  mylock[v] = false;
}

int main()
{
  cin >> n >> m;
  REP(i, m)
  {
    cin >> a[i];
    a[i]--;
  }
  REP(i, m)
  {
    cin >> b[i];
    b[i]--;
  }
  edges.resize(n);
  REP(i, m)
  {
    edges[a[i]].push_back({b[i], i});
    edges[b[i]].push_back({a[i], i});
    visited[i] = false;
  }
  REP(i, n)
  mylock[i] = false;

  REP(i, n)
  dfs(i);

  REP(i, m)
  cout << table[i];
  cout << endl;
}