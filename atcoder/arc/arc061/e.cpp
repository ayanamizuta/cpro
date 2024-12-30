

#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

int p[200000], q[200000], c[200000];
int dist[100000];
set<int> company[100000];

struct E
{
    int from;
    int to;
    int company;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<E>> vec(n);
    REP(i, m)
    {
        cin >> p[i] >> q[i] >> c[i];
        p[i]--;
        q[i]--;
        vec[p[i]].push_back({p[i], q[i], c[i]});
        vec[q[i]].push_back({q[i], p[i], c[i]});
    }
    auto pq = priority_queue<pair<int, int>>();
    pq.push({0, 0});
    FOR(i, 1, n)
    {
        dist[i] = 1000000000;
    }
    while (!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        for (auto e : vec[v.second])
        {
            auto cost = company[e.from].find(e.company) != company[e.from].end() ? 0 : 1;
            if (dist[e.to] > dist[e.from] + cost)
            {
                dist[e.to] = dist[e.from] + cost;
                company[e.to] = set<int>({e.company});
                pq.push({dist[e.to], e.to});
            }
            else if (dist[e.to] == dist[e.from] + cost)
            {
                if (company[e.to].find(e.company) == company[e.to].end())
                {
                    company[e.to].insert(e.company);
                    pq.push({dist[e.to], e.to});
                }
            }
        }
    }
    cout << (dist[n - 1] == 1000000000 ? -1 : dist[n - 1]) << endl;
    return 0;
}
