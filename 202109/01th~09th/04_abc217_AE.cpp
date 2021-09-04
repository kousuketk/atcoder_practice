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
  int Q; cin >> Q;
  vector<int> vec;
  vector<int> vec_sorted;
  rep(i,Q) {
    int a; cin >> a;
    if(a == 1) { // xを追加する
      int x; cin >> x;
      vec.push_back(x);
      auto itr = lower_bound(ALL(vec_sorted), x);
      vec_sorted.insert(itr, x);
    } else if (a == 2) {
      int tmp = vec[0];
      cout << tmp << endl; // 出力
      vec.erase(vec.begin());
      auto itr = lower_bound(ALL(vec_sorted), tmp);
      vec_sorted.erase(itr);
    } else {
      // sortedからvecへコピーする
      copy(vec_sorted.begin(), vec_sorted.end(), vec.begin());
    }
  }
  return 0;
}