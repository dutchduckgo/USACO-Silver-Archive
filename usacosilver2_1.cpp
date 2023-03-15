#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char ** arr;
    int * right;
    int * bottom;
    int ** cows;
    int days;
    int * flipi;
    int * flipj;
    
    cin >> n;
    bottom = new int[n];
    right = new int[n];
    arr = new char*[n];
    cows = new int*[n+1];
    for(int r = 0; r < n; r++){
        arr[r] = new char[n];
        cin >> arr[r];
        cin >> right[r];
        
    }
    for(int r = 0; r < n; r++){
        cin >> bottom[r];
        
    }
    cin >> days;
    flipi = new int[days];
    flipj = new int[days];
    for(int i = 0; i < days; i++){
        cin >> flipi[i] >> flipj[i];
    }
    
    
    for(int r = 0; r <= n; r++){
        cows[r] = new int[n+1];
        for(int c = 0; c <= n; c++){
            cows[r][c] = 1;
        }
    }
    for(int r = 0; r <=n; r++){
        cows[r][n] = 0;
        cows[n][r] = 0;
    }
    
    for(int r = 0; r < n; r++){
        
        for(int c = 0; c < n; c++){
            if(arr[r][c] == 'R'){
                cows[r][c+1] += cows[r][c];
            }
            else{
                cows[r+1][c] += cows[r][c];
                
            }
        }
        
    }
    
    int cost = 0;
    for(int i = 0; i < n; i++){
        cost+=cows[i][n] * right[i];
        cost+=cows[n][i] * bottom[i];
        
    }
    cout << cost << "\n";
    char og;
    int val=0;
    int a, b;
    
    for(int i = 0; i < days; i++){
        og = arr[flipi[i]-1][flipj[i]-1];
        a = flipi[i]-1;
        b = flipj[i]-1;
        //cout << a << b << og;
       
        val = cows[a][b];
        char og1;
        while(b < n && a < n){
            og1 = arr[a][b];
            if(og1 == 'R'){
                cows[a][b+1] -= val;
                b++;
            }
            else{
                cows[a+1][b] -= val;
                a++;
                
            
            }
            
        }
        
        if(og == 'R'){
            arr[flipi[i]-1][flipj[i]-1] = 'D';
        }
        else{
            arr[flipi[i]-1][flipj[i]-1] = 'R';
        }
        
       
        a = flipi[i]-1;
        b = flipj[i]-1;
        //cout << a << b << og;
        while(a < n && b < n){
            og1 = arr[a][b];
            if(og1 == 'R'){
                cows[a][b+1] += val;
                b++;
            }
            else{
                cows[a+1][b] += val;
                a++;
            }
            
        }
        
        cost = 0;
        for(int k = 0; k < n; k++){
            cost+=cows[k][n] * right[k];
            cost+=cows[n][k] * bottom[k];
        }   
        cout << cost << "\n";
    }
}