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

int main() {
  // min_val ~ max_valの累積和を取っておく
  // S[i+1]:iまでの2017と似た数の総和
  vector<int> S(100001);
  for(int i = 2; i <= 100000; i++) {
    if(i % 2 == 0) {
      S[i+1] = S[i];
      continue;
    }
    // iが素数かどうかの判定
    bool flag = true;
    for(int j = 2; j*j <= i; j++) {
      if(i % j == 0) {
        flag = false;
        break;
      }
    }
    if(!flag) {
      S[i+1] = S[i];
      continue;
    }
    // (i+1)/2が素数かどうかの判定
    for(int j = 2; j*j <= i; j++) {
      if((i+1)/2 % j == 0) {
        flag = false;
        break;
      }
    }
    if(flag) S[i+1] += S[i] + 1;
    else S[i+1] = S[i];
  }
  int Q; cin >> Q;
  for(int i = 0; i < Q; i++) {
    int l, r; cin >> l >> r;
    cout << (S[r+1] - S[l]) << endl;
  }
}