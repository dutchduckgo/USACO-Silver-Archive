#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

ll fact(const ll& p) {
    if (p <= 1)
        return 1;
    return p * fact(p - 1);
}

bool isPrime(const ll& p) {
    if (p == 4)
    return false;
 
    ll a = fact(p - 1) % p;
    if (a == p - 1)
        return true;
    return false;
}

int main() {
    //freopen("circularBarn.in", "r", stdin);
    //freopen("filename.out", "w", stdout);
    //cin.tie(0) -> sync_with_stdio(0);
    //cout.tie(0);

    int T;
    ll n;
    vl cows;
    cin >> T;
    while (T --) {
        cin >> n;
        cows.resize(n);
        for (ll i = 0; i < n; i ++) cin >> cows[i];
        for (ll i = 0; i < n; i ++) {
            if(isPrime(cows[i])  || cows[i] == 1) {
                cout << "Farmer John" << "\n";
                break;
            }
            else {
                if ((cows[i] - 3) % 4 == 0 || (cows[i] - 2) % 4 == 0 || (cows[i] - 1) % 4 == 0) {
                    
                }
            }
            
        }
        

    }
    
    
}

