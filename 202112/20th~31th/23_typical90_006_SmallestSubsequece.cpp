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
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

// next[i][c]：Sのi文字目以降で最初に文字cが登場するindex
vector<vector<int>> calcNext(const string &S) {
  int n = (int)S.size();
  vector<vector<int>> res(n+1, vector<int>(26, n));
  for(int i = n-1; i >= 0; i--) {
    for(int j = 0; j < 26; j++) res[i][j] = res[i+1][j];
    res[i][S[i] - 'a'] = i;
  }
  return res;
}

int main() {
  int N, K; cin >> N >> K;
  string S; cin >> S;
  vector<vector<int>> next = calcNext(S);
  int idx = 0;
  string ans = "";
  while(K > 0) {
    for(int j = 0; j < 26; j++) {
      int next_idx = next[idx][j];
      if((N - next_idx) >= K) {  // 次の文字の後ろにK個あれば貪欲法で決定していく
        ans += S[next_idx];
        idx = next_idx + 1;
        break;
      }
    }
    K--;
  }
  cout << ans << endl;
}