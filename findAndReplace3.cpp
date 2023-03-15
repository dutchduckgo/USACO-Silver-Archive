#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

map<char, char> m1;
set<char> visited;
int T;
int count = 0;

void dfs(char node, char parent) {
    if (visited.count(node)) return;
    visited.insert(node);
    if (m1.count(node) == 0) return;
    if (m1[node] == parent) count++;
}

int main() {
    cin >> T;
    while (T --) {
        m1.clear();
        visited.clear();
        count = 0;
        string init, end;
        cin >> init >> end;

        bool stop = false;
        for (int i = 0; i < init.length(); i++) {
            if (m1.count(init[i]) != 0) {
                if (m1[init[i]] != end[i]) {
                    stop = true;
                    break;
                }
            }
            else {
                m1[init[i]] = end[i];
            }
        }
        if (stop) {
            cout << -1 << endl;
        }
        else {
            int sum = m1.size();
            for (auto k : m1) dfs(k.first, 0);
            cout << sum << endl;
        }
    }
    return 0;
}
