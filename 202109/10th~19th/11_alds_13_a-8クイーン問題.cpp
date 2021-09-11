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

int main() {
  int K; cin >> K;
  vector<P> vec(K);
  rep(i,K) cin >> vec[i].first >> vec[i].second;
  vector<int> perm{0,1,2,3,4,5,6,7};
  do {
    vector<string> mass(8, "........");
    bool flag = true;
    rep(i,8) {
      int num = perm[i];
      mass[i][num] = 'Q';
      // 斜めにQがないかチェックrep(j,i)
      int cnter = 1;
      for(int j = i-1; j >= 0; j--) {
        int l = num+cnter;
        int r = num-cnter;
        if(l >= 0 && mass[j][l] == 'Q') flag = false;
        if(r < 8 && mass[j][r] == 'Q') flag = false;
        cnter++;
        if(!flag) break;
      }
      if(!flag) break;
    }
    if(!flag) continue;
    // vecでチェック
    rep(i,K) {
      int a = vec[i].first;
      int b = vec[i].second;
      if(mass[a][b] != 'Q') flag = false;
    }
    if(flag) {
      rep(i,8) cout << mass[i] << endl;
      return 0;
    }
  }while(next_permutation(perm.begin(), perm.end()));
}

