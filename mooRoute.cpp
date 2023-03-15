#include <bits/stdc++.h>
#include <iostream>
#define ll int
#define vl vector<int>
using namespace std;

ll sum = 0, dir = 0, x = 0, n;

int main() {
    vl ray;
    
    cin >> n;
    ray.resize(n);
    string rslt = "";
    for(ll i = 0; i < n; i ++){
        cin >> ray[i];
        sum += ray[i];
    }

    //cout << sum;S
    for(ll i = 0; i < sum; i ++){
        
        if(dir == 0) {
            if (x < n && ray[x] > 0) {
                rslt += "R";
                ray[x] --;
                x ++;
            }
            else {
                dir = 1;
                rslt += "L";
                ray[x-1] --;
                x --;
            }
        }

        else if(ray[x-1] > 1 || ray[x] == 0) {
            rslt += "L";
            ray[x-1] --;
            x --;
            
        }
        else {
            dir = 0;
            rslt += "R";
            ray[x] --;
            x ++;
        }
        
    }
    cout << rslt;
    return 0;
}