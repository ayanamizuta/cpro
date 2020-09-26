#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int t;

int main(){
    cin>>t;
    REP(i,t){
        LL n,m,a,b;
        cin>>n>>m>>a>>b;
        cout<<atcoder::floor_sum(n,m,a,b)<<endl;
    }
}