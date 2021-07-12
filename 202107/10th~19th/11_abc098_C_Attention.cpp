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
  int N; cin >> N;
  string s; cin >> s;
  vector<int> S(N+1); // S[i+1]:i番目までで東(E)の人の数
  rep(i,N) {
    if(s[i] == 'E') S[i+1] = S[i] + 1;
    else S[i+1] = S[i];
  }
  int ans = INF;
  for(int i = 0; i < N; i++) {
    // i番目の人を選ぶ
    // 0~i-1番目までをE, i+1番目~N-1番目までをWにする
    // cout << "左のコスト:" << (i - S[i]) << "右:" << (S[N] - S[i+1]) << endl;
    int tmp = (i - S[i]) + (S[N] - S[i+1]); // i-S[i]:i-1番目までで、wの人数
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}