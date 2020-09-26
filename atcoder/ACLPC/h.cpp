#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n;
LL d;
LL x[1000],y[1000];

int main(){
    cin>>n>>d;
    auto ts = atcoder::two_sat(2*n);
    REP(i,n){
        cin>>x[i]>>y[i];
        ts.add_clause(i,true,n+i,true);
        REP(j,i){
            if(abs(x[i]-x[j]) < d)ts.add_clause(i,false,j,false);
            if(abs(x[i]-y[j]) < d)ts.add_clause(i,false,n+j,false);
            if(abs(y[i]-x[j]) < d)ts.add_clause(n+i,false,j,false);
            if(abs(y[i]-y[j]) < d)ts.add_clause(n+i,false,n+j,false);
        }
    }
    if(ts.satisfiable()){
        cout<<"Yes"<<endl;
        auto ta = ts.answer();
        REP(i,n){
            if(ta[i])cout<<x[i]<<endl;
            else cout<<y[i]<<endl;
        }
    }else{
       cout<<"No"<<endl;
    }
}