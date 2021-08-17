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
  ll K; cin >> K;
  vector<int> vec(N);
  map<int, int> mp;
  rep(i,N) {
    int tmp; cin >> tmp;
    tmp--;
    vec[i] = tmp;
    mp[i] = 0;
  }
  vector<int> road;
  queue<int> que;
  road.push_back(0);
  mp[0] += 1;
  que.push(0);
  int circle_v;
  while(!que.empty()) {
    int v = que.front(); que.pop();
    int nv = vec[v];
    if(mp[nv] != 0) {  // サイクル検出
      circle_v = nv;
      break;
    }
    road.push_back(nv);
    que.push(nv);
    mp[nv]++;
  }
  int circle_idx;
  rep(i,N) {
    if(road[i] == circle_v) {
      circle_idx = i;
      break;
    }
  }
  // printVec(road);
  // cout << circle_v << endl;
  // cout << circle_idx << endl;
  ll circle_size = road.size() - circle_idx;
  ll road_size = road.size();
  int ans;
  if(K < road_size) {
    ans = road[K];
  } else {
    int k_idx = (K-circle_idx) % circle_size;
    ans = road[circle_idx+k_idx];
  }
  cout << ans+1 << endl;
}