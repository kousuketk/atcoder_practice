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
  int count = 0;
  while(count < 10) {
    // 5の時
    count++;
    if(idx > (N-5)) {
      cout << "NO" << endl;
      return 0;
    }
    string tmp_s = S.substr(idx, 5);
    cout << tmp_s << endl;
    if(tmp_s == "esare" || tmp_s == "resare") {
      idx += 5;
      if(idx == N) {
        cout << "YES" << endl;
        return 0;
      }
      continue;
    }
  }
}