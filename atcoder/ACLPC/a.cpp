#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int main(){
    int n,q;
    cin>>n>>q;
    auto uf = atcoder::dsu(n);
    REP(i,q){
        int m,u,v;
        cin>>m>>u>>v;
        if(m==0){
            uf.merge(u, v);
        }else{
            if(uf.same(u,v)){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
    
}