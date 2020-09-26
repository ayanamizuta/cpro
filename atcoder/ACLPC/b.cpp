#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,q;


int main(){
    cin>>n>>q;
    auto fw = atcoder::fenwick_tree<long long>(n);
    REP(i,n){
        LL a;
        cin>>a;
        fw.add(i, a);
    }
    REP(i,q){
        LL a,c;
        int b;
        cin>>a>>b>>c;
        if(a==0){
            fw.add(b,c);
        }else{
            cout<<fw.sum(b,(int)c)<<endl;
        }
    }
}