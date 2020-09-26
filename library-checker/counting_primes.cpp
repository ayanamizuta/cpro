#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

#define SQRT_L 1000000

//https://judge.yosupo.jp/problem/counting_primes

vector<long long> primes;
long long prime_num[SQRT_L+10];
bool sieve[SQRT_L+10];

map< pair<long long, long long> ,long long> phi_cache;
long long phi(long long x, long long a){
  if(a==1 || x<=0){
    return (x+1)/2;
  }

  auto xap = make_pair(x,a);
  if( phi_cache.find(xap) == phi_cache.end() ){
    phi_cache[xap] = phi(x,a-1)-phi(x/primes[a],a-1);
  }
  return phi_cache[xap];
}

long long pi(long long x){
  if(x <= SQRT_L){
    return prime_num[x-1];
  }
  long long a = pi(pow(x, 1.0/4.0));
  long long b = pi(sqrt(x));
  long long c = pi(pow(x, 1.0/3.0));
  long long sum = phi(x, a) + (b+a-2)*(b-a+1)/2;
  for(long long i=a+1; i<=b; i++){
    long long w = x/primes[i];
    sum -= pi(w);
    if(i <= c){
      for(long long j=i; j<=pi(sqrt(w)); j++){
        sum += j - 1 - pi(w/primes[j]);
      }
    }
  }
  return sum;
}


void do_sieve(){
  for(long long i=1; i<SQRT_L; i++){
    if(!sieve[i]){
      long long j = (i+1)*(i+1) - 1;
      while(j < SQRT_L){
        sieve[j] = true;
        j+=i+1;
      }
    }
  }
}

LL l;

int main(){
  cin>>l;
  do_sieve();
  primes.push_back(0); // Dummy Prime
  long long pn = 0;
  prime_num[0] = 0;
  for(long long i=1; i<SQRT_L; i++){
    if(!sieve[i]){
      primes.push_back(i+1);
      pn++;
    }
    prime_num[i] = pn;
  }
  cout << pi(l) << endl;
}