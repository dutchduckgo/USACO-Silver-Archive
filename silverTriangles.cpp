#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

struct Point {
	int x, y;
    int fSum;
    int bSum;

};

bool cmp (Point p1, Point p2) {
    return p1.x != p2.x ? p1.x < p2.x : p1.y < p2.y;
}
/*
void update (vector<Point> &v) { //pass by reference
    for (int i = 0; i < N; i ++) {
            int j = i + 1;
            while (v[i].x == v[j].x) { //same x-axis
                ; //add dif in y-axis
            }
            j = i + 1;
            while (xy[j].s == xy[i].s) { //same y-axis
                sumY[xy[i].f][xy[i].s] - xy[i].f; //add dif in x-axis
            }
        }
}

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int N;
    cin >> N;
    vector<Point> vx(N), vy(N);

    for (int i = 0; i < N; i ++) {
        cin >> vx[i].x >> vy[i].y;
        vy[i].x = vx[i].y;
        vy[i].y = vx[i].x;
    }

    sort(vx.begin(), vx.end(), cmp);
    sort(vy.begin(), vy.end(), cmp);

    update(vx);
    update(vy);
    
}

*/