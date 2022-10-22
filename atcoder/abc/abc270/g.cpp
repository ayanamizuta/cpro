#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int t, p, a, b, s, g;
mint inv_, apow, apowinv;

mint calc_x(LL i)
{
  mint a_ = mint(a);
  if (a == 1)
  {
    return mint(s) + mint(b) * i;
  }
  return apow * s + mint(b) * (mint(1) - apow) * inv_;
}

mint calc_x_inv(LL i)
{
  if (a == 1)
  {
    return mint(g) - mint(b) * i;
  }
  return (mint(g) - mint(b) * (mint(1) - apow) * inv_) * apowinv;
}

void solve()
{
  cin >> p >> a >> b >> s >> g;
  if (s == g)
  {
    cout << 0 << endl;
    return;
  }
  if (a == 0)
  {
    if (s == g)
    {
      cout << 0 << endl;
    }
    else if (b == g)
    {
      cout << 1 << endl;
    }
    else
    {
      cout << -1 << endl;
    }

    return;
  }
  mint::set_mod(p);
  if (a != 1)
    inv_ = (mint(1) - mint(a)).inv();
  LL root = 0;
  LL lb = 0, ub = p;
  while (lb < ub)
  {
    LL mid = (lb + ub) / 2;
    if (mid * mid < p)
    {
      lb = mid + 1;
    }
    else
    {
      ub = mid;
    }
  }
  root = lb + 10;
  map<LL, LL> mp;
  mint ainv = mint(a).inv();
  apow = mint(1);
  apowinv = mint(1);
  FOR(i, 1, root)
  {
    apow *= a;
    auto val_ = calc_x(i).val();
    if (mp[val_] == 0)
      mp[val_] = i;
    else
      continue;
  }
  LL ret = 1000000000000000;
  mint apowerroot = mint(a).pow(root);
  mint ainvroot = apowerroot.inv();

  apow = mint(1);
  apowinv = mint(1);
  FOR(i, 0, root)
  {
    auto try_ = calc_x_inv(root * i);
    auto try_value = mp[try_.val()];
    apow *= apowerroot;
    apowinv *= ainvroot;
    if (try_value == 0)
      continue;
    ret = min(ret, root * i + try_value);
  }
  if (ret == 1000000000000000)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << ret << endl;
  }
}

int main()
{
  cin >> t;
  REP(i, t)
  solve();
}