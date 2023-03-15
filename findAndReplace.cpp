#include <bits/stdc++.h>
#include <map>
#include <iostream>
using namespace std;
map<char, char> inp1;

bool loopfound(char nextc){
    if(inp1.count(nextc) == 1){
        if( inp1[nextc] == nextc || inp1[nextc] == '-') return false;
        if( inp1[nextc] == '|') return true;
        char tmp = inp1[nextc];
        inp1[nextc] = '|';
        return loopfound(tmp);
    }
    else
        return false;
}

int main(){
    int T;
    int *otp;
    cin >> T;
    otp = new int[T];
    string temp;

    map<char, char>::iterator it;
    char *str1;
    char *str2;
    for(int i = 0; i < T; i++){
        inp1.clear();
        cin >> temp;
        int a = temp.length();
        str1 = new char[a];
        strcpy(str1, temp.c_str());
        cin >> temp;
        int b = temp.length();
        str2 = new char[b];

        strcpy(str2, temp.c_str());

        if(a != b){
            otp[i] = -1;
            continue;
        }

        for(int k = 0; k < a; k++){
            if(inp1.find(str1[k]) == inp1.end()){ // This is right
                inp1[str1[k]] = str2[k];
            }
            else{
                if(inp1[str1[k]] != str2[k]){
                    otp[i] = -1;
                    break;
                }
            }
        }
        if(otp[i] == -1) continue;
        int t1 = 0;
        for(it = inp1.begin(); it != inp1.end(); it++){
            if(it->first == it->second) continue;
            t1++;
        }

        for(it = inp1.begin(); it != inp1.end(); it++){
            if(it->first == it->second) continue;
            if(it->second == '-') continue;

            bool lp = loopfound(it->first);

            if(lp) t1++;
            for(map<char, char>::iterator it1 = inp1.begin(); it1 != inp1.end(); it1++)
            {
                if( it1->second == '|') inp1[it1->first] = '-';
            }

        }
        otp[i] = t1;
    }

    for(int i = 0; i < T; i++){
        cout << otp[i] << "\n";
    }
}