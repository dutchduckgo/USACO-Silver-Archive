#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main() {
    //freopen("filename.in", "r", stdin);
    //freopen("filename.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;

    vector<bool> used (n, false);
    vector<int> orig;
    orig.resize(n);
    for (int i = 1; i < n + 1; i ++) 
        orig[i] = i;
    
    vector <vector<int>> pref;
    pref.resize(n);
    for (int i = 0; i < n; i ++) {
        pref[i].resize(n);
        for (int j = 0; j < n; j ++) 
            cin >> pref[i][j];
    }
    /*
    1 2 3 4
    1 3 2 4
    1 2 3 4
    1 2 3 4
    */

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
                pref[i][j] = 0;g=
                cout << pref[i][j] << '\n';
                break;
            }


        }

    }

    
}