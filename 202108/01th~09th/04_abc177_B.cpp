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
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  string S, T; cin >> S >> T;
  int size_s = S.size();
  int size_t = T.size();
  int ans = size_t;
  for(int i = 0; i <= size_s - size_t; i++) {
    // i~size_tを見て、diffを取る
    int diff = 0;
    for(int j = 0; j < size_t; j++) {
      if(S[i+j] != T[j]) diff++;
    }
    ans = min(ans, diff);
  }
  cout << ans << endl;
}