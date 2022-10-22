#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int atcg[4][5000][5000];

int n;
string s;

int main() {
    cin>>n>>s;
    REP(i,n){
        if(s[i] == 'A')atcg[0][i][i] = 1;
        else if(s[i] == 'T')atcg[1][i][i] = 1;
        else if(s[i] == 'C')atcg[2][i][i] = 1;
        else atcg[3][i][i] = 1;
        FOR(j,i+1,n){
            atcg[0][i][j] = atcg[0][i][j-1];
            atcg[1][i][j] = atcg[1][i][j-1];
            atcg[2][i][j] = atcg[2][i][j-1];
            atcg[3][i][j] = atcg[3][i][j-1];
            if(s[j] == 'A')atcg[0][i][j] = atcg[0][i][j-1]+1;
            else if(s[j] == 'T')atcg[1][i][j] = atcg[1][i][j-1]+1;
            else if(s[j] == 'C')atcg[2][i][j] = atcg[2][i][j-1]+1;
            else atcg[3][i][j] = atcg[3][i][j-1]+1;
        }
    }
    LL ret = 0;
    REP(i,n){
        FOR(j,i+1,n){
            if(atcg[0][i][j] == atcg[1][i][j] && atcg[2][i][j] == atcg[3][i][j])ret++;
        }
    }
    cout<<ret<<endl;
}