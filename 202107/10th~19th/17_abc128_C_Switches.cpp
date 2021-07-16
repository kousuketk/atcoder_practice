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
  int N, M; cin >> N >> M;
  vector<vector<int>> vec(M);
  rep(i,M) {
    int k; cin >> k;
    rep(j,k) {
      int tmp; cin >> tmp;
      tmp--;
      vec[i].push_back(tmp);
    }
  }
  vector<int> p(M);
  rep(i,M) cin >> p[i];
  // bit全探索
  int ans = 0;
  for(int tmp = 0; tmp < (1<<N); tmp++) {
    bitset<10> s(tmp);

    for(int i = 0; i < M; i++) {
      int flag_on = 0;
      for(int j = 0; j < vec[i].size(); j++) {
        // vec[i][j]について、bitが立ってたらsum++;
        if(s.test(vec[i][j])) flag_on++;
      }
      if(flag_on % 2 != p[i]) break;
      if(i == M-1) ans++;
    }
  }
  cout << ans << endl;
}