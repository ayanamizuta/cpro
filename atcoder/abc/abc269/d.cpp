#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n;
int x[1000], y[1000];
int main()
{
  cin >> n;
  REP(i, n)
  cin >> x[i] >> y[i];
  auto uf = atcoder::dsu(n);

  REP(i, n)
  {
    int xi = x[i], yi = y[i];
    FOR(j, i + 1, n)
    {
      int xj = x[j], yj = y[j];
      if (xi - 1 == xj && yi - 1 == yj || xi - 1 == xj && yi == yj || xi == xj && yi - 1 == yj || xi == xj && yi + 1 == yj || xi + 1 == xj && yi == yj || xi + 1 == xj && yi + 1 == yj){
        uf.merge(i,j);
      }
    }
  }
  cout<<uf.groups().size()<<endl;
}