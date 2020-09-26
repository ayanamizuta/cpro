#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/maxflow>

#define amax(a, b) a = max(a, b)
#define amin(a, b) a = min(a, b)

using ll = long long;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    atcoder::mf_graph<int> graph(n * m + 2);
    int start = n * m, goal = n * m + 1;
    for (auto &si:s) std::cin >> si;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int idx = i * m + j;
            if (s[i][j] == '#') continue;
            if ((i + j) % 2) {
                if (i > 0)   graph.add_edge(idx, idx-m, s[i-1][j] == '.');
                if (i < n-1) graph.add_edge(idx, idx+m, s[i+1][j] == '.');
                if (j > 0)   graph.add_edge(idx, idx-1, s[i][j-1] == '.');
                if (j < m-1) graph.add_edge(idx, idx+1, s[i][j+1] == '.');

                graph.add_edge(start, idx, 1);
            } else {
                graph.add_edge(idx,  goal, 1);
            }
        }
    }
    std::cout << graph.flow(start, goal) << '\n';
    for (auto [from, to, cap, flow]:graph.edges()) {
        // std::cerr << from << ' ' << to << ' ' << cap << ' ' << flow << std::endl;
        if (flow == 0 || from == start || to == goal) continue;
        if (from > to) std::swap(from, to);
        s[from / m][from % m] = (from / m == to / m ? '>' : 'v');
        s[to   / m][to   % m] = (from / m == to / m ? '<' : '^');
    }
    for (auto &si:s) std::cout << si << '\n';
    return 0;
}
