#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int main()
{
  int q;
  cin >> q;
  map<long, long> mp;
  REP(i, q)
  {
    int type;
    cin >> type;
    if (type == 0)
    {
      long k, v;
      cin >> k >> v;
      mp[k] = v;
    }
    else
    {
      long k;
      cin >> k;
      cout << mp[k] << endl;
    }
  }
  return 0;
}
