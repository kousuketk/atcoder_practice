#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<queue<int>>;
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
  int N, M; cin >> N >> M;
  Graph G(M);
  rep(i,M) {
    int k; cin >> k;
    rep(j,k) {
      int a; cin >> a;
      G[i].push(a);
    }
  }
  map<int, int> mp;
  queue<int> que;
  for(int i = 0; i < M; i++) {
    que.push(i);
  }
  int count = 0;
  bool flag = true;
  for(int i = 0; i < N; i++) {
    int idx = que.front();
    int a = G[idx].front();
    if(mp[a] > 0) {
      G[idx].pop();
      int idx2 = mp[a]-1;
      G[idx2].pop();
      // i, idxのqueを入れていく
      que.push(idx);
      que.push(idx2);
      count--;
    }
    count++;
    if(count >= M) flag = false;
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}