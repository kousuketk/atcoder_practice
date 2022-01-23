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
  int N; cin >> N;
  vector<int> array(2*N);
  vector<vector<ll>> vec(2*N, vector<ll>(2*N));
  rep(i,2*N) {
    rep(j,2*N) {
      if(j <= i) vec[i][j] = 0;
      else cin >> vec[i][j];
    }
  }
  rep(i,2*N) array[i] = i+1;
  ll ans = 0;
  do {
    if(array[0] != 1) break;
    bool flag = true;
    rep(i,N-1) if(array[2*i] > array[2*(i+1)]) flag = false;
    rep(i,N) if(array[2*i] > array[2*i+1]) flag = false;
    if(!flag) continue;
    // 答えを求めていく
    vector<ll> tmp_vec;
    rep(i,N) {
      int idx_i = array[2*i];
      int idx_j = array[2*i+1];
      idx_i--, idx_j--;
      ll a = vec[idx_i][idx_j];
      tmp_vec.push_back(a);
    }
    ll tmp_val = tmp_vec[0];
    rep(i,N-1) tmp_val = tmp_val ^ tmp_vec[i+1];
    ans = max(ans, tmp_val);
  } while(next_permutation(ALL(array)));
  cout << ans << endl;
}