#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

template<int mod>
struct ModInt{
	int x;
	ModInt () : x(0) {}
	ModInt (int64_t x) : x(x >= 0 ? x % mod : (mod - -x % mod) % mod) {}
	ModInt &operator += (const ModInt &p){
		if ((x += p.x) >= mod) x -= mod;
		return *this;
	}
	ModInt &operator -= (const ModInt &p) {
		if ((x += mod - p.x) >= mod) x -= mod;
		return *this;
	}
	ModInt &operator *= (const ModInt &p) {
		x = (int64_t) x * p.x % mod;
		return *this;
	}
	ModInt &operator /= (const ModInt &p) {
		*this *= p.inverse();
		return *this;
	}
	ModInt &operator ^= (int64_t p) {
		ModInt res = 1;
		for (; p; p >>= 1) {
			if (p & 1) res *= *this;
			*this *= *this;
		}
		return *this = res;
	}
	ModInt operator - () const { return ModInt(-x); }
	ModInt operator + (const ModInt &p) const { return ModInt(*this) += p; }
	ModInt operator - (const ModInt &p) const { return ModInt(*this) -= p; }
	ModInt operator * (const ModInt &p) const { return ModInt(*this) *= p; }
	ModInt operator / (const ModInt &p) const { return ModInt(*this) /= p; }
	ModInt operator ^ (int64_t p) const { return ModInt(*this) ^= p; }
	bool operator == (const ModInt &p) const { return x == p.x; }
	bool operator != (const ModInt &p) const { return x != p.x; }
	explicit operator int() const { return x; }
	ModInt &operator = (const int p) { x = p; return *this;}
	ModInt inverse() const {
		int a = x, b = mod, u = 1, v = 0, t;
		while (b > 0) {
			t = a / b;
			a -= t * b;
			std::swap(a, b);
			u -= t * v;
			std::swap(u, v);
		}
		return ModInt(u);
	}
	friend std::ostream & operator << (std::ostream &stream, const ModInt<mod> &p) {
		return stream << p.x;
	}
	friend std::istream & operator >> (std::istream &stream, ModInt<mod> &a) {
		int64_t x;
		stream >> x;
		a = ModInt<mod>(x);
		return stream;
	}
};
// typedef ModInt<1000000007> mint;

template<int mod> struct MComb {
	using mint = ModInt<mod>;
	std::vector<mint> fact;
	std::vector<mint> inv;
	MComb (int n) { // O(n + log(mod))
		fact = std::vector<mint>(n + 1, 1);
		for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * mint(i);
		inv.resize(n + 1);
		inv[n] = fact[n] ^ (mod - 2);
		for (int i = n; i--; ) inv[i] = inv[i + 1] * mint(i + 1);
	}
	mint ncr(int n, int r) {
		return fact[n] * inv[r] * inv[n - r];
	}
	mint npr(int n, int r) {
		return fact[n] * inv[n - r];
	}
	mint nhr(int n, int r) {
		assert(n + r - 1 < (int) fact.size());
		return ncr(n + r - 1, r);
	}
};


template<int mod, int proot> struct NTT { // mint version
	using mint = ModInt<mod>;
	int get_mod() { return mod; }
	void ntt(std::vector<mint> &a, bool inverse) const {
		int n = a.size();
		assert((n & -n) == n);
		mint h = mint(proot) ^ ((mod - 1) / n);
		if (inverse) h = h.inverse();
		
		for (int i = 0, j = 1; j < n - 1; j++) {
			for (int k = n >> 1; k > (i ^= k); k >>= 1);
			if (j < i) std::swap(a[i], a[j]);
		}
		for (int i = 1; i < n; i <<= 1) {
			mint base = h ^ (n / i / 2);
			mint w = 1;
			
			std::vector<mint> ws(i);
			for (int j = 0; j < i; j++) ws[j] = w, w *= base;
			
			for (int j = 0; j < n; j += i << 1) {
				for (int k = 0; k < i; k++) {
					mint u = a[k + j];
					mint d = a[k + j + i] * ws[k];
					a[k + j] = u + d;
					a[k + j + i] = u - d;
				}
			}
		}
		if (inverse) {
			mint ninv = mint(a.size()).inverse();
			for (auto &i : a) i *= ninv;
		}
	}
	std::vector<mint> convolve_self(std::vector<mint> a) const {
		if (!a.size()) return {};
		size_t n_ = a.size();
		size_t size = 1;
		for (; size < n_ + n_; size <<= 1);
		a.resize(size);
		ntt(a, false);
		for (auto &i : a) i *= i;
		ntt(a, true);
		a.resize(n_ + n_ - 1);
		return a;
	}
	std::vector<mint> convolve(const std::vector<mint> &a_, const std::vector<mint> &b_) const {
		if (!a_.size() || !b_.size()) return {};
		if (&a_ == &b_) return convolve_self(a_);
		std::vector<mint> a = a_, b = b_;
		size_t size = 1;
		for (; size < a_.size() + b_.size(); size <<= 1);
		a.resize(size);
		b.resize(size);
		ntt(a, false);
		ntt(b, false);
		for (size_t i = 0; i < size; i++) a[i] *= b[i];
		ntt(a, true);
		a.resize(a_.size() + b_.size() - 1);
		return a;
	}
};
template<int mod> struct Polynomial {
	using mint = ModInt<mod>;
	static constexpr std::pair<int, int> proot_map[] = {
		{998244353, 3},
		{1224736769, 3},
		{897581057, 3}
	};
	static constexpr int proot_map_size = sizeof(proot_map) / sizeof(*proot_map);
	static constexpr int get_proot(int index = 0) {
		return index == proot_map_size ? throw 0 :
			proot_map[index].first == mod ? proot_map[index].second : get_proot(index + 1);
	}
	static const NTT<mod, get_proot()> ntt;
	std::vector<mint> data;
	Polynomial () = default;
	template<class T> Polynomial (const std::vector<T> &data) {
		this->data.resize(data.size());
		for (size_t i = 0; i < data.size(); i++) this->data[i] = data[i];
	}
	Polynomial & operator += (const Polynomial &rhs) {
		data.resize(std::max(data.size(), rhs.data.size()));
		for (size_t i = 0; i < rhs.size(); i++) data[i] += rhs[i];
		return *this;
	}
	Polynomial & operator -= (const Polynomial &rhs) {
		data.resize(std::max(data.size(), rhs.data.size()));
		for (size_t i = 0; i < rhs.size(); i++) data[i] -= rhs[i];
		return *this;
	}
	Polynomial & operator *= (const Polynomial &rhs) {
		data = ntt.convolve(data, rhs.data);
		return *this;
	}
	Polynomial operator + (const Polynomial &rhs) const { return Polynomial(*this) += rhs; }
	Polynomial operator - (const Polynomial &rhs) const { return Polynomial(*this) -= rhs; }
	Polynomial operator * (const Polynomial &rhs) const { return Polynomial(*this) *= rhs; }
	mint & operator [] (int i) { return data[i]; }
	const mint & operator [] (int i) const { return data[i]; }
	std::string to_string() {
		std::string res = "";
		for (int i = 0; i < (int) data.size(); i++) {
			if (i) res += " ";
			res += std::to_string(data[i].x);
		}
		return res;
	}
};
typedef Polynomial<998244353> Poly;

int main() {
	int n = ri(), m = ri();
	std::vector<int> a(n), b(m);
	for (auto &i : a) i = ri();
	for (auto &i : b) i = ri();
	printf("%s\n", (Poly(a) * Poly(b)).to_string().c_str());
	return 0;
}