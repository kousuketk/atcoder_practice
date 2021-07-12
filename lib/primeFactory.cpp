#include <iostream>
#include <vector>
using namespace std;

vector<pair<long long, long long> > prime_factorize(long long N) {
  vector<pair<long long, long long> > res;
  for (long long a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    long long ex = 0; // 指数

    // 割れる限り割り続ける
    while (N % a == 0) {
      ++ex;
      N /= a;
    }

    // その結果を push
    res.push_back({a, ex});
  }

  // 最後に残った数について
  if (N != 1) res.push_back({N, 1});
  return res;
}

int main() {
  long long N;
  cin >> N;
  const auto &res = prime_factorize(N);
  cout << N << ":";
  for (auto p : res) {
      for (int i = 0; i < p.second; ++i) cout << " " << p.first;
  }
  cout << endl;
}

// これでいい
// int main() {
//   int N; cin >> N;
//   vector<int> vec;
//   int tmp_N = N;
//   for(int i = 2; i*i <= N; i++) {
//     while(tmp_N % i == 0) {
//       vec.push_back(i);
//       tmp_N = tmp_N/i;
//     }
//   }
//   if(N != 1) vec.push_back(N);
//   printVec(vec);
// }


#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

// N <= 10^5で、
// O(N√N)で解かせる問題があった、10^8とかだからギリ回せる
// int main() {
//   // min_val ~ max_valの累積和を取っておく
//   // S[i+1]:iまでの2017と似た数の総和
//   vector<int> S(100001);
//   for(int i = 2; i <= 100000; i++) {
//     if(i % 2 == 0) {
//       S[i+1] = S[i];
//       continue;
//     }
//     // iが素数かどうかの判定
//     bool flag = true;
//     for(int j = 2; j*j <= i; j++) {
//       if(i % j == 0) {
//         flag = false;
//         break;
//       }
//     }
//     if(!flag) {
//       S[i+1] = S[i];
//       continue;
//     }
//     // (i+1)/2が素数かどうかの判定
//     for(int j = 2; j*j <= i; j++) {
//       if((i+1)/2 % j == 0) {
//         flag = false;
//         break;
//       }
//     }
//     if(flag) S[i+1] += S[i] + 1;
//     else S[i+1] = S[i];
//   }
//   int Q; cin >> Q;
//   for(int i = 0; i < Q; i++) {
//     int l, r; cin >> l >> r;
//     cout << (S[r+1] - S[l]) << endl;
//   }
// }