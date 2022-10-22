#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int t;

bool all_same(string s){
    int n = s.size();
    REP(i,n){
        if(s[0] != s[i])return false;
    }
    return true;
}

int iso_right(string s){
    int n = s.size();
    int ret = 0;
    REP(i,n){
        if(s[n-1-i]=='a')return ret;
        ret++;
    }
}

string bbbaaa(string s){
    int n = s.size(),chance=0,clus=0,cnta=0,cntb=0;
    REP(i,n){
        if(s[i]=='a')cnta++;
        else cntb++;
        if(i!=0){
            if(s[i-1]!='b' && s[i] == 'b')clus++;
            if(i>1 && s[i-2]=='b' && s[i-1]!='b' && s[i] == 'b')chance++;
            if(i==1 && s[i-1]!='b' && s[i] == 'b')chance++;
        }
    }
    string retb(cntb,'b');
    string reta(cnta-2*(clus-chance/2),'a');
    return retb+reta;
}

string all_b(string s){
    int n = s.size(),chance=0,clus=0,cnta=0,cntb=0;
    REP(i,n){
        if(s[i]=='a')cnta++;
        else cntb++;
    }
    string ret(cntb,'b');
    return ret;
}

string bbba(string s){
    int n = s.size(),cnta=0,cntb=0;
    REP(i,n){
        if(s[i]=='a')cnta++;
        else cntb++;
    }
    if(cnta%2){
        string ret(cntb,'b');
        return ret + 'a';
    }else{
        string ret(cntb,'b');
        return ret;
    }
}

int main(){
    cin>>t;
    string s;
    REP(i,t){
        cin>>s;
        if(all_same(s)){
            cout<<s<<endl;
            continue;
        }
        int isor = iso_right(s);
        string allb = all_b(s);
        if(isor){
            string s_left = s.substr(0,s.size()-isor),s_right=s.substr(s.size()-isor,isor);
            if(isor<=2){
                if(allb < bbba(s_left) + s_right)allb=bbba(s_left) + s_right;
                cout << allb<<endl;
                continue;
            }else{
                if(all_same(s_left)){
                    int n = s.size(),cnta=0;
                    REP(i,n){
                        if(s_left[i]=='a')cnta++;
                    }
                    cout<<((cnta%2)?"a":"")+s_right<<endl;
                    continue;
                }
                s_left = bbbaaa(s_left);
                if(s_left[s_left.size()-1] == 'a'){
                    s_right = s_right.substr(0,isor-2);
                    if(allb < s_right + s_left || s_left[s_left.size()-2] != 'a')allb = s_right + s_left;
                    cout << allb << endl;
                }else{
                    if(allb < s_right + s_left)allb = s_right + s_left;
                    cout << allb << endl;
                }
                continue;
            }
        }else{
            cout << bbbaaa(s) << endl;
            continue;
        }

    }
}