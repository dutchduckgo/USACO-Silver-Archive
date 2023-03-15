#include <bits/stdc++.h>
using namespace std;

map<char, char> map_;


bool cycle(char node) {
    if (map_.count(node)) {
        if (map_[node] == node || map_[node] == '!') 
            return false;
        
        char temp = map_[node];
        if (map_[node] == '.') 
            return true;
        
        int count = 0;
        for (auto i : map_) 
            if (i.second == temp && i.first != temp) 
                count ++;
            
        
        if (count > 1) return false;
    
        map_[node] = '.';
        return cycle(temp);
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T --) {
        map_.clear();
        bool shouldStop = false;
        string start;
        string end;
        cin >> start >> end;

        for (int i = 0; i < start.length(); i++) {
            if (!map_.count(start[i])) {
                map_[start[i]] = end[i];
            } 
            else if (map_[start[i]] != end[i]) {
                shouldStop = true;
                break;
            }
        }
        int different = 0;
        for (auto it : map_) {
            if (it.first != it.second) different ++;
        }

        for (auto i : map_) {
            if (i.first == i.second) 
                continue;
            
            if (i.second == '!') 
                continue;
            
            bool cyc = cycle(i.first);
            if (cyc) 
                different ++;
            
            for (auto &e2 : map_) {
                if (e2.second == '.') 
                    e2.second = '!';
                
            }
        }
        if (shouldStop) 
            cout << -1 << endl;
        else 
            cout << different << endl;
        
    }
    return 0;
}
