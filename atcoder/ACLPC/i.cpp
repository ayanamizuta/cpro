#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long


string s;

int main(){
    cin>>s;
    auto sa = atcoder::suffix_array(s);
    auto la = atcoder::lcp_array(s,sa);
    LL ret = 0;
    REP(i,s.size())ret+=(i+1);
    REP(i,la.size())ret-=la[i];
    cout<<ret<<endl;
}