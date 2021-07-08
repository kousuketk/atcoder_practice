#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}


// for (int i = 0; i < T; i++) table[i] = 0;
// for (int i = 0; i < C; i++) {
//   // 時刻 S[i] から E[i] - 1 までのそれぞれについてカウントを 1 増やす
//   for (int j = S[i]; j < E[i]; j++) {
//     table[j]++;
//   }
// }
// // 最大値を調べる
// M = 0;
// for (int i = 0; i < T; i++) {
//   if (M < table[i]) M = table[i];
// }

for (int i = 0; i < T; i++) table[i] = 0;
for (int i = 0; i < C; i++) {
  table[S[i]]++;  // 入店処理: カウントを 1 増やす
  table[E[i]]--;  // 出店処理: カウントを 1 減らす
}
// シミュレート
for (int i = 0; i < T; i++) {
  if (0 < i) table[i] += table[i - 1];
}
// 最大値を調べる
M = 0;
for (int i = 0; i < T; i++) {
  if (M < table[i]) M = table[i];
}