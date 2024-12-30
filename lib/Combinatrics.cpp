
#define MOD 1000000007
#define FACT_MAX 1000000

LL fact[FACT_MAX], fact_inv[FACT_MAX];

class Combinatrics
{
private:
  long long mod = MOD;
  int fact_max = FACT_MAX;

public:
  Combinatrics()
  {
    fact[0] = 1;
    for (int i = 1; i < fact_max; i++)
    {
      fact[i] = (fact[i - 1] * i) % mod;
      fact_inv[i] = inv(fact[i]);
    }
  }

  long long power(long long n, long long e)
  {
    long long ret = 1;
    long long b = n;
    while (e)
    {
      if (e % 2 != 0)
        ret *= b;
      ret %= mod;
      b *= b;
      b %= mod;
      e /= 2;
    }
    return ret;
  }

  long long inv(long long n)
  {
    return power(n, mod - 2);
  }

  long long div(long long n1, long long n2)
  {
    return n1 * power(n2, mod - 2) % mod;
  }

  long long nck(int n, int k)
  {
    if (k > n || k < 0)
      return 0LL;
    if (k == n || k == 0)
      return 1LL;
    return (fact[n] * fact_inv[n - k] % mod) * fact_inv[k] % mod;
  }
};

long long gcd(long long a, long long b)
{
  if (b == 0)
    return a;
  if (a < b)
    return gcd(b, a);
  return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
  return a * b / gcd(a, b);
}

// lcm of several variables
long long lcm_n(int n, long long *a)
{
  LL ret = a[0];
  for (int i = 0; i < n - 1; i++)
  {
    ret = lcm(ret, a[i + 1]);
  }
  return ret;
}

// output the smallest non-negative integer N s.t. N%quots[i]=rems[i]
// if contradiction occurs, output -1
long long reminder(int n, long long *rems, long long *quots)
{
  if (n == 1)
    return rems[0];
  long long x1, x2, y1, y2;
  x1 = rems[0];
  y1 = quots[0];
  for (int i = 0; i < n - 1; i++)
  {
    x2 = rems[i + 1];
    y2 = quots[i + 1];
    for (int j = 0; j < y2; j++)
    {
      if ((x1 + j * y1) % y2 == x2)
      {
        x1 = (x1 + j * y1) % lcm(y1, y2);
        y1 = lcm(y1, y2);
        break;
      }
      if (j == y2 - 1)
        return -1;
    }
  }
  return x1;
}

// return the number of 1<=a<=n s.t. (a,n)==1
long long euler_phi(long long n)
{
  LL ret = n;
  for (LL k = 2; k * k < n + 2; k++)
  {
    if (n % k == 0)
    {
      ret -= ret / k;
      while (n % k == 0)
        n /= k;
    }
  }
  if (n != 1)
    ret -= ret / n;
  return ret;
}
