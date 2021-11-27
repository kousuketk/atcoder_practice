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
  vector<ll> time(N);
  vector<vector<int>> vec;
  rep(i,N) {
    ll T; cin >> T;
    int K; cin >> K;
    time[i] = T;
    vector<int> tmp_vec(K);
    rep(j,K) {
      int a; cin >> a;
      a--; tmp_vec[j] = a;
    }
    vec.push_back(tmp_vec);
  }
  ll ans = 0;
  vector<int> done(N);
  priority_queue<int, vector<int>> que;
  que.push(N-1);
  while(!que.empty()) {
    int tmp = que.top(); que.pop();
    if(done[tmp]) continue;
    done[tmp] = 1;
    ans += time[tmp];
    int k = vec[tmp].size();
    rep(i,k) {
      int nv = vec[tmp][i];
      if(!done[nv]) que.push(nv);
    }
  }
  cout << ans << endl;
}