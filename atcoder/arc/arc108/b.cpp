#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n;
string s;
int stack_[200010];
int ptr = 0;
int main(){
    cin>>n>>s;
    REP(i,200010)stack_[i]=0;
    int ret = 0;
    REP(i,n){
        if(s[i] == 'f'){
            ptr++;
            stack_[ptr]=1;
        }else if(s[i] == 'o'){
            if(stack_[ptr] != 1)ptr++;
            else stack_[ptr]=2;
        }else if(s[i] == 'x'){
            if(stack_[ptr]==2){
                stack_[ptr]=0;
                ret++;
                ptr--;
            }else ptr++;
        }else{
            ptr++;
        }
    }
    cout<<n-ret*3<<endl;
}