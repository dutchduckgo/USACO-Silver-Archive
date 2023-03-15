#include <bits/stdc++.h>
using namespace std;

// Check if a number is prime
bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Solve the game for a single test case
string solve(int n, vector<int> cows) {
    // Iterate through each room
    for (int i = 0; i < n; i++) {
        // Calculate the number of cows that Farmer John needs to remove
        int needed;
        if (cows[i] % 2 == 0) {
            needed = cows[i] / 2;
        } else {
            needed = (cows[i] - 1) / 2;
        }
        // Check if it is possible for Farmer John to remove the needed number of cows
        if (cows[i] < needed || (!is_prime(needed) && needed != 1)) {
            return "Farmer Nhoj";
        }
        // Remove the needed number of cows
        cows[i] -= needed;
    }
    // If the game has not ended, then Farmer John wins
    return "Farmer John";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> cows(n);
        for (int i = 0; i < n; i++) {
            cin >> cows[i];
        }
        cout << solve(n, cows) << endl;
    }
    return 0;
}
