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

int main() {
  string S; cin >> S;
  reverse(S.begin(), S.end());
  int N = S.size();
  // 逆転させたSの先頭から見ていく
  // esare, resare, maerd, remaerd
  // idx == S.size()-1 になったらok
  int idx = 0;
  while(true) {
    // 5の時
    if(idx > (N-5)) {
      cout << "NO" << endl;
      return 0;
    }
    string tmp_s = S.substr(idx, 5);
    if(tmp_s == "esare" || tmp_s == "maerd") {
      idx += 5;
      if(idx == N) {
        cout << "YES" << endl;
        return 0;
      }
      continue;
    }
    // 6の時
    if(idx > N-6) {
      cout << "NO" << endl;
      return 0;
    }
    string tmp_s2 = S.substr(idx, 6);
    if(tmp_s2 == "resare") {
      idx += 6;
      if(idx == N) {
        cout << "YES" << endl;
        return 0;
      }
      continue;
    }
    // 7の時
    if(idx > N-7) {
      cout << "NO" << endl;
      return 0;
    }
    string tmp_s3 = S.substr(idx, 7);
    if(tmp_s3 == "remaerd") {
      idx += 7;
      if(idx == N) {
        cout << "YES" << endl;
        return 0;
      }
      continue;
    }
    cout << "NO" << endl;
    return 0;
  }
}