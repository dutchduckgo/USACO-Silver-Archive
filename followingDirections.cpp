#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vi vector<int>

int n;
vi down;
vi right1;
vi swapA;
vi swapB;
vector<vector<int>> cows;
char ** dir;

void findR() {
    for(int i = 0; i < n; i ++) 
        for(int j = 0; j < n; j++){
            if(dir[i][j] == 'R')
                cows[i][j+1] += cows[i][j];
            else
                cows[i+1][j] += cows[i][j];
        }
}

int findCost(int c) {
    for(int i = 0; i < n; i ++){
        c += cows[i][n] * right1[i];
        c += cows[n][i] * down[i];
    
    }
    return c;
}

int main() {
     //dir = arr
    dir = new char*[n];
    cin >> n;
    down.resize(n);
    right1.resize(n);
    cows.resize(n + 1);

    for (int i = 0; i < n + 1; i ++) 
        cows[i].resize(n + 1);
    
    for (int i = 0; i < n; i ++) 
       dir[i] = new char[n];
    
    for(int i = 0; i < n; i++){
        cin >> dir[i];
        cin >> right1[i];
    }

    for(int i = 0; i < n; i++)
        cin >> down[i];
        
    int days;
    cin >> days;
    swapA.resize(days);
    swapB.resize(days);
    for(int i = 0; i < days; i++){
        cin >> swapA[i] >> swapB[i];
    }
    
    
    for(int i = 0; i <= n; i ++) 
        for(int j = 0; j <= n; j ++)
            cows[i][j] = 1;
        
    
    for(int i = 0; i <= n; i ++) {
        cows[i][n] = 0;
        cows[n][i] = 0;
    }
    //fill in Rs
    findR();
        
    int cost = 0;
    cost += findCost(cost);
    
    cout << cost << "\n";
    char init;
    int rslt = 0;
    int first, last;
    
    int i = 0;
    while (i < days) {
        init = dir[swapA[i] - 1][swapB[i] - 1];
        first = swapA[i] - 1;
        last = swapB[i] - 1;
       
        rslt = cows[first][last];
        char tempChar;
        while(last < n && first < n){
            tempChar = dir[first][last];
            if(tempChar == 'R'){
                cows[first][last+1] -= rslt;
                last ++;
            }
            else{
                cows[first + 1][last] -= rslt;
                first ++;
                
            
            }
            
        }
        
        if (init == 'R'){
            dir[swapA[i]-1][swapB[i]-1] = 'D';
        }
        else {
            dir[swapA[i]-1][swapB[i]-1] = 'R';
        }
        
       
        first = swapA[i]-1;
        last = swapB[i]-1;
        while(first < n && last < n){
            tempChar = dir[first][last];
            //cout <<tempChar << endl;
            if(tempChar == 'R'){
                cows[first][last + 1] += rslt;
                last ++;
            }
            else{
                cows[first + 1][last] += rslt;
                first ++;
            }
            
        }
        
        cost = 0;
        cost += findCost(0); 
        cout << cost << "\n";
        i ++;
    }
}