#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int t,n;
int l[100];

int array_find(int begin,int end,int elem){
    FOR(i,begin,end){
        if(l[i]==elem)return i;
    }
    return -1;
}

void solve_one(int problem_num){
    cin>>n;
    REP(i,n)cin>>l[i];
    int ret=0;
    REP(i,n-1){
        int min_index=array_find(0,n,i+1);
        ret+=min_index-i+1;
        REP(j,(min_index-i+1)/2)swap(l[i+j],l[min_index-j]);
    }

    cout<<"Case #"<<problem_num<<": "<<ret<<endl;
}

int main(){
    cin>>t;
    REP(i,t)solve_one(i+1);
    return 0;
}
