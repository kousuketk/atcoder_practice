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
  vector<int> vec(N);
  rep(i,N) vec[i] = i+1;
  vector<P> vec_inp(M);
  rep(i,M) {
    int a, b; cin >> a >> b;
    vec_inp[i] = P(a,b);
  }
  rep(i,M) {
    int a = vec_inp[i].first;
    int b = vec_inp[i].second;
    // find(a), find(b)してaがbより先に現れてなかったら、bの前に入れる
    auto itr_a = find(ALL(vec), a);
    auto itr_b = find(ALL(vec), b);
    if(itr_b < itr_a) {
      vec.erase(itr_a, itr_a+1);
      vec.insert(itr_b, a);
    }
  }
  // もう一回やってcheckする(だめだったら-1, だめじゃなかったらそれを出力する)
  rep(i,M) {
    int a = vec_inp[i].first;
    int b = vec_inp[i].second;
    // もしaがbより先に現れていなかったら矛盾 → -1
    auto itr_a = find(ALL(vec), a);
    auto itr_b = find(ALL(vec), b);
    if(itr_b < itr_a) {
      cout << "-1" << endl;
      return 0;
    }
  }
  rep(i,N) cout << vec[i] << " ";
  cout << endl;
}

// O(N^2)になりTLE
// 平衡二分探索木, AVL木を使おうとしたが、途中結果がsortされてない状態となってしまうため使えない
// →トポロジカルソートで解くらしい