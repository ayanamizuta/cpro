LL powmod(LL a, LL e) {
  ll sum = 1;
  ll cur = a;
  while (e > 0) {
    if (e % 2) {
      sum = sum * cur % mod;
    }
    cur = cur * cur % mod;
    e /= 2;
  }
  return sum;
}
void add(ll &x, ll y) {
  x = (x + y) % mod;
}
 
const int N;
LL fac[N], invfac[N];
void init(void) {
  fac[0] = 1;
  FOR(i, 1, N) fac[i] = fac[i - 1] * i % mod;
  invfac[N - 1] = powmod(fac[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; --i) invfac[i] = invfac[i + 1] * (i + 1) % mod;
}
