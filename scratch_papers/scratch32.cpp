#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <climits>
using namespace std;

int findRec(vector<vector<int>>& graph, int last, int steps, set<int>& s1, map<pair<int, int>, int>& m) {
    if (s1.empty())
        return steps;
    int newSteps = INT_MAX;

    for (unsigned int i = 0; i < graph[last].size(); ++i) {
        set<int> s2 = s1;
        map<pair<int, int>, int> m2 = m;
        auto it = s2.find(graph[last][i]);

        if (m2[{last, graph[last][i]}] == 0)
            continue;

        m2[{last, graph[last][i]}] = 0;

        if (it != s2.end()) {
            s2.erase(it);
        }

        newSteps = min(newSteps, findRec(graph, graph[last][i], steps + 1, s2, m2));
        s2.insert(graph[last][i]);
        m2[{last, graph[last][i]}] = 1;
    }

    return newSteps;
}

int shortestPathLength(vector<vector<int>>& graph) {
    set<int> s1;
    int ans = INT_MAX;

    for (unsigned int i = 0; i < graph.size(); ++i) {
        s1.insert(i);
    }

    map<pair<int, int>, int> m;

    for (unsigned int i = 0; i < graph.size(); ++i) {
        for (unsigned int j = 0; j < graph[i].size(); ++j) {
            m[{i, graph[i][j]}] = 1;
        }
    }

    for (unsigned int i = 0; i < graph.size(); ++i) {
        auto it = s1.find(i);

        if (it != s1.end()) {
            s1.erase(it);
        }

        ans = min(ans, findRec(graph, i, 0, s1, m));
        s1.insert(i);
    }

    return ans;
}

int main() {
    vector<vector<int>> v = {{1},{0,2,4},{1,3,4},{2},{1,2}};

    cout << shortestPathLength(v);

    return 0;
}