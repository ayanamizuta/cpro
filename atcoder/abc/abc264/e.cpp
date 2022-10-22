#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n, m, e, q;
int u[500000], v[500000];
int x[500000];
bool tied[500000];

class UnionFind
{
private:
  std::vector<int> par;
  std::vector<int> rnk;
  std::vector<bool> power;

public:
  std::vector<int> cnt;
  UnionFind(int n) : par(n), rnk(n), cnt(n), power(n)
  {
    for (int i = 0; i < n; i++)
    {
      par[i] = i;
      rnk[i] = 0;
      cnt[i] = 1;
      power[i] = false;
    }
  }

  int find(int x)
  {
    if (par[x] == x)
      return x;
    else
      return find(par[x]);
  }

  bool powered(int x)
  {
    return x >= n || power[find(x)];
  }

  void unite(int x, int y)
  {
    bool powered_ = x >= n || y >= n;
    x = find(x);
    y = find(y);
    powered_ = powered_ || power[x] || power[y];
    if (x == y)
      return;

    if (rnk[x] < rnk[y])
    {
      par[x] = y;
      cnt[y] += cnt[x];
    }
    else
    {
      par[y] = x;
      cnt[x] += cnt[y];
      if (rnk[x] == rnk[y])
        rnk[x]++;
    }
    power[find(x)] = power[find(x)] || powered_;
  }

  bool same(int x, int y)
  {
    return find(x) == find(y);
  }
};

int main()
{
  cin >> n >> m >> e;
  UnionFind uf(n + m);
  REP(i, e)
  {
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
  }
  REP(i, e)
  {
    tied[i] = true;
  }
  cin >> q;
  REP(i, q)
  {
    cin >> x[i];
    x[i]--;
    tied[x[i]] = false;
  }
  REP(i, e)
  {
    if (tied[i])
    {
      uf.unite(u[i], v[i]);
    }
  }
  vector<int> ans_reverse(q);
  int current = 0;
  REP(i, n)
  current += uf.powered(i) ? 1 : 0;
  ans_reverse[0] = current;
  REP(i, q - 1)
  {
    int u_ = u[x[q - 1 - i]], v_ = v[x[q - 1 - i]];
    if (uf.powered(u_) && uf.powered(v_))
    {
      ans_reverse[i + 1] = current;
    }
    else if ((!uf.powered(u_)) && (!uf.powered(v_)))
    {
      uf.unite(u_, v_);
      ans_reverse[i + 1] = current;
    }
    else if (!uf.powered(u_))
    {
      current += uf.cnt[uf.find(u_)];
      ans_reverse[i + 1] = current;
      uf.unite(u_, v_);
    }
    else if (!uf.powered(v_))
    {
      current += uf.cnt[uf.find(v_)];
      ans_reverse[i + 1] = current;
      uf.unite(u_, v_);
    }
  }

  REP(i, q)
  cout << ans_reverse[q - 1 - i] << endl;
}