#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,m;

int main() {
    cin>>n>>m;
    vector<LL> a(n),b(m);
    REP(i,n)cin>>a[i];
    REP(i,m)cin>>b[i];
    auto c = atcoder::convolution<998244353>(a,b);
    REP(i,c.size())cout<<c[i]<<" ";
    cout<<endl;
}