#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long 

int n,m;

int main(){
    cin>>n>>m;
    auto g = atcoder::scc_graph(n);
    REP(i,m){
        int a,b;
        cin>>a>>b;
        g.add_edge(a,b);
    }
    auto scc = g.scc();
    cout<<scc.size()<<endl;
    REP(i,scc.size()){
        cout<<scc[i].size()<<" ";
        REP(j,scc[i].size()){
            cout<<scc[i][j]<<" ";
        }
        cout<<endl;
    }
}