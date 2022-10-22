#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

template <typename T>
bool next_combination(const T first, const T last, int k)
{
  const T subset = first + k;
  // empty container | k = 0 | k == n
  if (first == last || first == subset || last == subset)
  {
    return false;
  }
  T src = subset;
  while (first != src)
  {
    src--;
    if (*src < *(last - 1))
    {
      T dest = subset;
      while (*src >= *dest)
      {
        dest++;
      }
      iter_swap(src, dest);
      rotate(src + 1, dest + 1, last);
      rotate(subset, subset + (last - dest) - 1, last);
      return true;
    }
  }
  // restore
  rotate(first, subset, last);
  return false;
}

int n;
int a[1000000], a_sum[1000000];

int digit(int n, int k)
{
  int d = 1;
  REP(i, k)
  d *= 10;
  return (n % d) / (d / 10);
}

int main()
{
  cin >> n;
  REP(i, n)
  cin >> a[i];

  REP(i, n)
  a_sum[a[i]]++;

  REP(i, 1000000)
  {
    vector<int> digits;
    FOR(j, 1, 7)
    {

      if (digit(i, j))
      {
        int d = 1;
        REP(k, j - 1)
        d *= 10;
        digits.push_back(d);
        //a_sum[i] += a_sum[i - d];
      }
    }
    int asum = 0;
    int siz = digits.size();
    FOR(k, 1, siz + 1)
    {
      sort(ALL(digits));
      do
      {
        int sum = 0;
        REP(j, k)
        sum += digits[j];
        asum += k % 2 ? a_sum[i - sum] : -a_sum[i - sum];
      } while (next_combination(digits.begin(), digits.end(), k));
    }

    a_sum[i] += asum;
  }

  //REP(i, 50)
  //cerr << a_sum[i] << " " << endl;

  LL ret = 0;
  REP(i, n)
  ret += a_sum[999999 - a[i]];

  REP(i, n)
  {
    FOR(j, 1, 7)
    {
      if (digit(a[i], j) >= 5)
      {
        break;
      }
      if (j == 6)
        ret -= 1;
    }
  }

  cout << ret / 2 << endl;
}