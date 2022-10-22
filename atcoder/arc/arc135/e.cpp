#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

using mint = atcoder::modint998244353;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int t;
LL n, x;

void solve()
{
  cin >> n >> x;
  mint ret = mint(x);
  LL a_before = x, a_after;
  LL index = 2;
  if (x == 1)
  {
    ret = (mint(n) * mint(n + 1) / mint(2));
    cout << ret.val() << endl;
    return;
  }
  bool boosted = false;
  while (index <= n)
  {
    a_after = a_before + (index - a_before % index);
    if (!boosted && a_before / (index - 1) - 1 == a_after / index)
    {
      cerr << index << " " << a_after << endl;
      boosted = true;
      LL div = a_after / index;
      LL boost = max((LL)1, (div - index) / 2 - 2);
      ret += mint(index) * mint(div) * mint(boost + 1);
      ret += mint(div) * mint(boost) * mint(1 + boost) / mint(2);
      ret -= mint(index) * mint(boost) * mint(1 + boost) / mint(2);
      ret -= mint(boost) * mint(boost + 1) * mint(2 * boost + 1) / mint(6);
      a_before = (index + boost) * (div - boost);
      index += boost + 1;
      continue;
    }
    if (a_after == index * index)
    {
      ret += mint(index) * (mint(n + index) * mint(n - index + 1) / mint(2));
      break;
    }
    a_before = a_after;
    ret += mint(a_after);
    index += 1;
  }
  cout << ret.val() << endl;
}

int main()
{
  cin >> t;
  REP(i, t)
  solve();
}