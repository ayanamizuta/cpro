

#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define LL long long

string s[2000];
bool path[2001][10001];
string longest_strings[2001];
bool prefixes[2001][10001];

int main()
{
    int n, k;
    cin >> n >> k;
    REP(i, n)
    cin >> s[i];
    path[n][k] = true;
    REP(i, n)
    {
        REP(j, k + 1)
        {
            if (k >= j)
                path[n - i - 1][k - j] |= path[n - i][k - j];
            if (k - j - s[n - i - 1].size() >= 0)
                path[n - i - 1][k - j - s[n - i - 1].size()] |= path[n - i][k - j];
        }
    }
    prefixes[0][0] = true;
    FOR(i, 1, n)
    {
        auto lcp = atcoder::z_algorithm(s[i] + longest_strings[i - 1]);
        int longest_size = -1;
        bool is_longest_concated = false;
        REP(j, k + 1)
        {
            if (!prefixes[i - 1][j])
                continue;
            if (path[i][j])
            {
                if (longest_size == -1)
                {
                    longest_size = j;
                    is_longest_concated = false;
                }
                else
                {
                }
            }
            if (j + s[i].size() <= k && path[i][j + s[i].size()])
            {
                if (longest_size == -1)
                {
                    longest_size = j;
                    is_longest_concated = true;
                }
                else
                {
                }
            }
        }
        longest_strings[i] = longest_strings[i - 1].substr(0, longest_size) + (is_longest_concated ? s[i] : "");
        REP(j, k + 1)
        {
            if (!prefixes[i - 1][j])
                continue;
            if (path[i][j])
            {
                if (lcp[s[i].size() + longest_size] >= j - longest_size)
                {
                    prefixes[i][j] = true;
                }
            }
            if (j + s[i].size() <= k && path[i][j + s[i].size()])
            {
                if (lcp[s[i].size() + j])
            }
        }
    }
    cout << longest_strings[n] << endl;
    return 0;
}
