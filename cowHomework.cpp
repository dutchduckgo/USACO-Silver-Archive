#include <iostream>
#include <fstream>
using namespace std;
 long long score[100000];
long long sSum[100000];
long long sMin[100000];
long long best_num, best_den;

int main() {
  
  freopen("homework.in", "r", stdin);
  freopen("homework.out", "w", stdout);
  
  int N;
  
  cin >> N;
  for (int i=1; i<=N; i++) 
    cin >> score[i];
  
  sSum[N] = score[N];
  sMin[N] = score[N];
  for (int i= N- 1; i >= 1; i --) {
    sSum[i] = sMin[i+1] + score[i];
    sMin[i] = min(sMin[i+1], score[i]);
  }
 
  best_num = 0;
  best_den = 1;
  
  for (int i = 1; i <= N - 2; i ++) 
    if ((sSum[i + 1] - sMin[i + 1]) * best_den > best_num * (N - i - 1)) {
      best_num = sSum[i + 1] - sMin[i + 1];
      best_den = N - i - 1;
    }
  
  for (int i = 1; i <= N-2; i++) 
    if ((sSum[i+1] - sMin[i+1]) * best_den == best_num * (N - i - 1)) 
      cout << i << "\n";
  
}