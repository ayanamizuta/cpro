#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

string s;

int cnt[26];

int ctoi(char c){
    return c - 'a';
}

int main(){
    cin>>s;
    LL ret = 0;
    int n = s.size();
    char c = s[n-1];
    cnt[ctoi(c)]++;
    c = s[n-2];
    cnt[ctoi(c)]++;
    REP(i_,n-2){
        //cerr<<ret<<" "<<i_<<endl;
        int i=n-i_-3;
        if(s[i] == c){
            ret += i_-(cnt[ctoi(c)]-2);
            REP(j,26){
                cnt[j] = (j==ctoi(c))?i_+2:0;
            }
        }
        cnt[ctoi(s[i])]++;
        c = s[i];
    }
    cout<<ret<<endl;
    return 0;
}