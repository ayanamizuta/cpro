#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
string s,t;
int n;

int main(){
    cin>>n>>s>>t;
    int cnt1=0,cnt2=0;
    REP(i,n){
        if(s[i]=='1')cnt1++;
        if(t[i]=='1')cnt2++;
    }
    if(abs(cnt1-cnt2)%2 || cnt1 < cnt2){
        cout<<-1<<endl;
        return 0;
    }
    LL ret = 0;
    int cur_1=0,cur_2=0,dept1=0,dept2=0;
    while(cur_1 < n || cur_2 < n){
        //cerr<<cur_1<<" "<<cur_2<<" "<<dept1<<" "<<dept2<<" "<<cnt1<<" "<<cnt2<<" "<<ret<<endl;
        if(s[cur_1] == t[cur_2]){
            ret+=dept1+dept2;
            cur_1++;
            cur_2++;
            continue;
        }
        if(s[cur_1] == '1'){
            if(dept1){
                dept1--;
                cnt1-=2;
            }else if(dept2)dept2--;
            else dept1++;
            if(dept1 && cnt1==cnt2){
                cout<<-1<<endl;
                return 0;
            }
        }
        if(t[cur_2] == '1'){
            dept2++;
        }
        ret+=dept1+dept2;
        cur_1++;
        cur_2++;
    }
    cout<<ret<<endl;
}