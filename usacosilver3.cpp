#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define vl vector<ll>
using namespace std;

int main() {
    int sum = 0;
    int dir = 0;
    int pos = 0;
    int n;
    vector<int> nums;
    
    cin >> n;
    nums.resize(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
        sum += nums[i];
        
    }
    //cout << sum;S
    for(int i = 0; i < sum; i++){
        
        if(dir == 0 && pos < n && nums[pos] > 0){
            cout << 'R';
            nums[pos]--;
            pos++;
        }
        else if(dir == 0){
            dir = 1;
            cout << 'L';
            nums[pos-1]--;
            pos--;
        }
        else if(nums[pos-1] > 1 || nums[pos] == 0){
            cout << 'L';
            nums[pos-1]--;
            pos--;
            
        }
        else{
            dir = 0;
            cout << 'R';
            nums[pos]--;
            pos++;
        }
        
    }
    return 0;
}