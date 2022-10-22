#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

bool isPrime(LL number)
{

  if (number < 2)
    return false;
  if (number == 2)
    return true;
  if (number % 2 == 0)
    return false;
  for (int i = 3; (i * i) <= number; i += 2)
  {
    if (number % i == 0)
      return false;
  }
  return true;
}

int n;
LL a[100], b[100];
int main()
{
  cin >> n;
  REP(i, n)
  cin >> a[i] >> b[i];
  LL ret = 0;
  REP(i, n)
  {
    FOR(j, i + 1, n)
    {
      if (a[i] == 1 || a[j] == 1)
        continue;
      if (isPrime(a[i] + a[j]))
      {
        auto b_ = min(b[i], b[j]);
        ret += b_;
        b[i] -= b_;
        b[j] -= b_;
      }
    }
  }
  REP(i, n)
  {
    FOR(j, i + 1, n)
    {
      if (isPrime(a[i] + a[j]))
      {
        auto b_ = min(b[i], b[j]);
        ret += b_;
        b[i] -= b_;
        b[j] -= b_;
      }
    }
  }
  REP(i, n)
  {
    if (a[i] == 1)
      ret += b[i] / 2;
  }
  cout << ret << endl;
}