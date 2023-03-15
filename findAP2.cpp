#include <iostream>
#include <vector>
using namespace std;

vector<char> X, Y;
int c_cnt;

int input() {
    cout << "First string: ";
    string x;
    cin >> x;
    cout << "Second string: ";
    string y;
    cin >> y;

    X.clear();
    Y.clear();
    for (int i = 0; i < x.length(); i++) {
        X.push_back(x[i]);
        Y.push_back(y[i]);
    }

    // feasibility check
    if (X.size() != Y.size()) {
        cout << "Different length!" << endl;
        return 0;
    }
    for (int i = 0; i < X.size(); i++) {
        for (int j = i + 1; j < Y.size(); j++) {
            if (X[i] == X[j] && Y[i] != Y[j]) {
                cout << "Not possible" << endl;
                return 0;
            }
        }
    }
    c_cnt = 0;
    return 1;
}

int last_change() {
    for (int i = 0; i < X.size(); i++) {
        if (X[i] == Y[i]) {
            continue;
        }

        int found = 1;

        for (int j = 0; j < Y.size(); j++) {
            if (Y[i] != X[j]) {
                continue;
            }
            if (X[j] == Y[j]) {
                continue;
            }
            found = 0;
            break;
        }

        if (found) {
            return i;
        }
    }
    return -1;
}

vector<char> P;
int find_circle(int k) {
    for (int i = 0; i < X.size(); i++) {
        if (X[i] != P[k - 1]) {
            continue;
        }
        if (X[i] == Y[i]) {
            return -1;
        }
        if (Y[i] == P[0]) {
            cout << "found circle:";
            for (int j = 0; j < k; j++) {
                cout << P[j];
            }
            cout << endl;
            return k;
        }

        P.push_back(Y[i]);
        int r = find_circle(k + 1);
        if (r >= 0) {
            return r;
        }
    }
    return -1;
}

void break_circle(int cir_len) {
    for (int i = 0; i < cir_len; i++) {
        char a = P[i];
        char b = (i + 1 == cir_len) ? P[0] : P[i + 1];

        for (int j = 0; j < X.size(); j++) {
            if (X[j] != a) {
                continue;
            }
            if (Y[j] != b) {
                continue;
            }

            char d = X[j];
            for (int k = 0; k < X.size(); k++) {
                if (X[k] == a) {
                    X[k] = d;
                }
            }

            return;
        }
        for (int i = 0; i < X.size(); i++) {
            if (X[i] == P[0]) {
                X[i] = c_cnt;
            }
        }
        c_cnt++;
    }
}


