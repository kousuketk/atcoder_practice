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
  queue<P> que; // (val, idx)
  // O(M)で初期ボールを入れる
  rep(i,M) {
    int a = G[i].front();
    G[i].pop();
    que.emplace(a, i);
  }
  map<int, int> mp;  // (val, idx)
  int ans_counter = 0;
  while(!que.empty()) {
    int a = que.front().first;
    int idx = que.front().second; que.pop();
    if(mp[a] > 0) { // 既にあったら取り出して捨てる
      ans_counter++;
      int idx2 = mp[a]-1;
      mp[a] = 0;
      // idx, idx2からballをqueに追加する
      if(!G[idx].empty()) {
        int val = G[idx].front(); G[idx].pop();
        que.emplace(val, idx);
      }
      if(!G[idx2].empty()) {
        int val = G[idx2].front(); G[idx2].pop();
        que.emplace(val, idx2);
      }
    } else {  // なかったらmapに追加する
      mp[a] = idx+1;
    }
  }
  if(ans_counter == N) cout << "Yes" << endl;
  else cout << "No" << endl;
}

// 処理方法がイメージつかない(forループだとうまく処理が回らない等)時は、
// queに突っ込んで見るのも考える