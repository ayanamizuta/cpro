#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int n;
LL height[300000];
vector<pair<LL, LL>> a[300000];

vector<pair<LL, LL>> merge(vector<pair<LL, LL>> &v1, vector<pair<LL, LL>> &v2, int index)
{
    vector<pair<LL, LL>> ret;
    LL v1r = v1[0].first, v1l = v1[1].first;
    LL v2r = v2[0].first, v2l = v2[1].first;
    ret.push_back({max(v1r, v2r), 1});
    height[index] = height[index * 2] + height[index * 2 + 1];
    if (v1r < v2l || v2r < v1l)
    {
        height[index] += max(v2l - v1r, v1l - v2r);
    }

    auto it1 = v1.begin() + 1;
    auto it2 = v2.begin() + 1;
    LL acm1 = 0, acm2 = 0;
    while (!(it1 == v1.end() && it2 == v2.end()))
    {
        if (it1 == v1.end())
        {
            while (it2 != v2.end())
            {
                ret.push_back({(*it2).first, (*it2).second + acm1});
                it2++;
            }
            break;
        }
        if (it2 == v2.end())
        {
            while (it1 != v1.end())
            {
                ret.push_back({(*it1).first, (*it1).second + acm2});
                it1++;
            }
            break;
        }
        if ((*it1).first == (*it2).first)
        {
            ret.push_back({(*it1).first, (*it1).second + (*it2).second});
            it1++;
            it2++;
            acm1 = (*it1).second;
            acm2 = (*it2).second;
            continue;
        }
        if ((*it1).first > (*it2).first)
        {
            ret.push_back({(*it1).first, (*it1).second + acm2});
            it1++;
            acm1 = (*it1).second;
            continue;
        }
        if ((*it1).first < (*it2).first)
        {
            ret.push_back({(*it2).first, (*it2).second + acm1});
            it2++;
            acm2 = (*it2).second;
            continue;
        }
    }
    return ret;
}

int main()
{
    cin >> n;
    REP(i, (1 << n))
    {
        int l, r;
        cin >> l >> r;
        a[i].push_back({r, 1});
        a[i].push_back({l, -1});
    }

    REP(i, n)
    {
        REP(j, 1 << (n - i - 1))
        {
            a[j] = merge(a[2 * j], a[2 * j + 1], j);
        }
    }
    LL ans = height[0];
    LL ans_min = ans;
    LL pt = a[0][0].first, second = 0;
    FOR(i, 1, a[0].size())
    {
        ans -= second * (pt - a[0][i].first);
        ans_min = min(ans, ans_min);
        second = a[0][i].second;
        pt = a[0][i].first;
    }
    cout << ans_min << endl;
}