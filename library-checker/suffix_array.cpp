#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

vector<int> SA_IS(vector<int> str, int var) {
    if(str.size() == 1) {
        vector<int> ret(1,0);
        return ret;
    }
    str.push_back(0);
    int si = str.size();
    vector<int> st(var, 0), en(var, 0);
    vector<int> SL(si, 0); //s..0, l..1
    vector<int> SA(si, -1);
    vector<int> LMS;
    vector<int> is_LMS(si, -1);
    REP(i,str.size()) en[str[i]]++;
    for(int i = 1; i < var; i++) en[i] += en[i-1];
    for(int i = 1; i < var; i++) st[i] = en[i-1];
    SL[str.size()-1] = 0;
    for(int i = str.size()-2; i >= 0; i--) {
        if(str[i] == str[i+1]) {
            SL[i] = SL[i+1];
            continue;
        }
        if(str[i] > str[i+1]) SL[i] = 1;
        else SL[i] = 0;
    }
    for(int i = 1; i < str.size(); i++) {
        if(SL[i] == 0 && SL[i-1] == 1) {
            SA[--en[str[i]]] = i;
            LMS.push_back(i);
            is_LMS[i] = 1;
        }
    }
    REP(i,var-1) en[i] = st[i+1];
    en[var-1] = str.size();
    
    REP(i,str.size()) if(SA[i] > 0 && SL[SA[i]-1] == 1) { SA[st[str[SA[i]-1]]++] = SA[i]-1; }
    st[0] = 0;
    for(int i = 1; i < var; i++) st[i] = en[i-1];
    
    for(int i = 1; i < str.size(); i++) if(SA[i] != -1 && SL[SA[i]] == 0) { SA[i] = -1; }
    
    for(int i = str.size()-1; i >= 1; i--) if(SA[i] > 0 && SL[SA[i]-1] == 0) { SA[--en[str[SA[i]-1]]] = SA[i]-1; }
    REP(i,var-1) en[i] = st[i+1];
    en[var-1] = str.size();
    
    int counter = 0;
    vector<int> pre_sa, new_sa;
    REP(i,SA.size()) if(is_LMS[SA[i]] != -1) {
        is_LMS[SA[i]] = ++counter; 
        
        new_sa.clear();
        for(int j = SA[i]; j < SA.size(); j++) {
            new_sa.push_back(str[j]);
            if(j != SA[i] && is_LMS[j] != -1) {
                break;
            }
        }
        if(pre_sa == new_sa) {
            is_LMS[SA[i]] = --counter;
        }
        pre_sa = new_sa;
    }
    
    vector<int> new_str;
    vector<int> rev((int)LMS.size()+1, 0);
    counter = 0;
    REP(i,is_LMS.size()) {
        if(is_LMS[i] != -1) {
            new_str.push_back(is_LMS[i]);
            rev[counter++] = i;
        }
    }
    vector<int> rec = SA_IS(new_str, new_str.size()+1);
    
    REP(i,SA.size()) SA[i] = -1;
    
    for(int i = rec.size()-1; i >= 0; i--) { SA[--en[str[rev[rec[i]]]]] = rev[rec[i]]; }
    REP(i,var-1) en[i] = st[i+1];
    en[var-1] = str.size();
    
    REP(i,str.size()) if(SA[i] > 0 && SL[SA[i]-1] == 1) { SA[st[str[SA[i]-1]]++] = SA[i]-1; }
    
    for(int i = 1; i < str.size(); i++) if(SA[i] != -1 && SL[SA[i]] == 0) { SA[i] = -1; }
    
    for(int i = str.size()-1; i >= 1; i--) if(SA[i] > 0 && SL[SA[i]-1] == 0) { SA[--en[str[SA[i]-1]]] = SA[i]-1; }
    
    SA.erase(SA.begin());
    return SA;
}

string s;

int main(){
  cin>>s;
  vector<int> num;
  REP(i,s.size()) num.push_back(s[i]-'a'+1);
  auto v = SA_IS(num,30);
  for(auto i : v)cout<<i<<" ";
  cout<<endl;
  return 0;
}
