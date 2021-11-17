#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<string,int>;
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
  // 頂点にあるコマをもとに考える。("39245678"は"931456782") → "123456789"になったら完成
  int M; cin >> M;
  Graph G(9);
  rep(i,M) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  string s = "999999999";
  rep(i,8) {
    int p; cin >> p;
    s[p-1] = i+1 + '0';
  }
  // map, queを使ってそれぞれの状態遷移を考える
  map<string, int> mp;
  mp[s] = 1; // +1多くして考える
  queue<P> que;
  rep(i,9) {
    if(s[i] != i+1) {
      que.push(P(s, i));
    }
  }
  while(!que.empty()) {
    P tmp_pair = que.front(); que.pop();
    string now_s = tmp_pair.first;
    int i = tmp_pair.second;

    for(int ni: G[i]) {
      // i, niをchangeして、距離を更新できたらqueに入れる
      string next_s = now_s;
      swap(next_s[i], next_s[ni]);
      if(mp[next_s] == 0 || mp[next_s] > mp[now_s]+1) {
        mp[next_s] = mp[now_s] + 1;
        // cout << next_s << ":" << mp[next_s] << endl;
        rep(j,9) if(next_s[j] != j+1) que.push(P(next_s, j));
      }
    }
  }
  if(mp["123456789"] == 0) cout << "-1" << endl;
  else cout << mp["123456789"]-1 << endl;
}