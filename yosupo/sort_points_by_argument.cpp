#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

bool lower(pair<long, long> a)
{
    return a.second < 0 || a.second == 0 && a.first >= 0;
}

int main()
{
    vector<pair<long, long>> v;
    int n;
    cin >> n;
    REP(i, n)
    {
        pair<long, long> p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    sort(ALL(v), [](pair<long, long> a, pair<long, long> b)
         {
        if(lower(a) ^ lower(b)){
            return lower(a);
        }
        cerr<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<endl;
        return -a.second*b.first+a.first*b.second>0; });
    REP(i, n)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}
