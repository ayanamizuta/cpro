#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

using S = int;

struct F
{
  int m;
};

S op(S l, S r) { return max(l, r); }

S e() { return 0; }

S mapping(F l, S r) { return max(r, l.m); }

F composition(F l, F r) { return F{max(l.m, r.m)}; }

F id() { return F{0}; }

int n;
int p[200000], q[200000], rev_q[200000], table[200000];

int main()
{
  cin >> n;
  REP(i, n) { cin >> p[i]; }
  REP(i, n) { cin >> q[i]; }
  REP(i, n) { rev_q[q[i] - 1] = i; }
  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);

  REP(i, n)
  {
    int x = p[i];
    int div = x;

    vector<int> idces;
    while (div <= n)
    {
      int idx_q = rev_q[div - 1];
      idces.push_back(idx_q);
      div += x;
    }
    sort(ALL(idces), greater<int>());

    REP(i, idces.size())
    {
      int idx_q = idces[i];
      if (idx_q)
      {
        seg.set(idx_q, seg.prod(0, idx_q) + 1);
      }
      else
      {
        seg.set(0, 1);
      }
    }
  }
  cout << seg.prod(0, n) << endl;
}