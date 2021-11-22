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
  int N, M; cin >> N >> M;
  Graph G(N);
  rep(i,M) {
    int x, y; cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  int ans = 1;
  for(int tmp = 0; tmp < (1<<N); tmp++) {
    bitset<12> bit(tmp);

    bool flag = true;
    // bit(tmp)全体の相互関係があれば、bit(tmp)ごとカウントする
    for(int i = 0; i < N; i++) {
      if(bit.test(i)) {
        for(int j = 0; j < N; j++) {
          if(i == j) continue;
          if(bit.test(j)) {
            auto result = find(ALL(G[i]), j);
            if(result == G[i].end()) flag = false;
          }
        }
      }
    }
    if(flag) ans = max(ans, (int)bit.count());
  }
  cout << ans << endl;
}