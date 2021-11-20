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
  int N, Q; cin >> N >> Q;
  vector<int> par(N);
  vector<int> child(N);
  rep(i,N) par[i] = i;  // 初期化(自分の親は自分)
  rep(i,N) child[i] = i;  // 初期化(自分の子は自分)
  rep(i,Q) {
    int num; cin >> num;
    if(num == 1) {
      int x, y; cin >> x >> y;
      x--; y--;
      par[y] = x;
      child[x] = y;
    } else if(num == 2) {
      int x, y; cin >> x >> y;
      x--; y--;
      child[x] = x;
      par[y] = y;
    } else {
      int x; cin >> x;
      x--;
      vector<int> vec_par;
      vec_par.push_back(x);
      int v = x;
      while(true) {
        int nv = par[v];
        if(v == nv) break;
        vec_par.push_back(nv);
        v = nv;
      }
      vector<int> vec_child;
      v = x;
      while(true) {
        int nv = child[v];
        if(v == nv) break;
        vec_child.push_back(nv);
        v = nv;
      }
      // 合体させる
      reverse(ALL(vec_par));
      vec_par.insert(vec_par.end(), ALL(vec_child));
      cout << vec_par.size() << " ";
      rep(i,vec_par.size()) cout << vec_par[i]+1 << " ";
      cout << endl;
    }
  }
}