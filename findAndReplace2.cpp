#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

string x;
string y;
int len;

int main() {
    //freopen("filename.in", "r", stdin);
    //freopen("filename.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> rslt;
    rslt.resize(n);

    while (n --) {
        
        cin >> x;
        cin >> y;
        len = x.size();

        for (int i = 0; i < len; i ++) 
            if (x[i] == y[i]) 
                for (int j = 0; j < len; j ++) 
                    if (x[j] == x[i] && y[j] != y[i]) 
                        rslt[i] = -1;
        
        
            
        
    }
    


}

int lastChange() { //find last letter
    for (int i = 0; i < len; i ++) {
        if (x[i] == y[i]) continue;
        bool success = true;
        for (int j = 0; j != i && j < len; j ++) {
            if (y[i] != x[j]) continue;
            if (y[i] == y[j]) continue;
            success = false;
            break;
        }
        if (success) return x[i];
    }
    return -1;
}