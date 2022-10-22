#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n;
int a[5000], b[5000];

int main()
{
  cin >> n;
  REP(i, n)
  cin >> a[i];
  REP(i, n)
  cin >> b[i];

  REP(i, n * 10)
  {
    REP(j, n - 2)
    {
      int m = min(a[j], min(a[j + 1], a[j + 2]));
      while (a[j] != m)
      {
        int tmp0 = a[j], tmp1 = a[j + 1], tmp2 = a[j + 2];
        a[j] = tmp1;
        a[j + 1] = tmp2;
        a[j + 2] = tmp0;
      }

      if (a[j] == a[j + 2])
      {
        swap(a[j + 1], a[j + 2]);
      }
    }
  }

  REP(i, n * 10)
  {
    REP(j, n - 2)
    {
      int m = min(b[j], min(b[j + 1], b[j + 2]));
      while (b[j] != m)
      {
        int tmp0 = b[j], tmp1 = b[j + 1], tmp2 = b[j + 2];
        b[j] = tmp1;
        b[j + 1] = tmp2;
        b[j + 2] = tmp0;
      }
      if (b[j] == b[j + 2])
      {
        swap(b[j + 1], b[j + 2]);
      }
    }
  }

  REP(i, n)
  {
    if (a[i] != b[i])
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}