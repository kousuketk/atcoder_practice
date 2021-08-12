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
  vector<P> member(N);  // i番目の幼児がどこの幼稚園で何点か
  vector<multiset<int>> vec_set(200005);
  multiset<int> set;
  rep(i,N) {
    int a, b; cin >> a >> b;
    b--;
    member[i].first = b;
    member[i].second = a;
    vec_set[b].insert(a);
  }
  rep(i,200005) {
    auto itr = vec_set[i].rbegin();
    if(*itr == 0) set.insert(INF);
    else set.insert(*itr);
  }
  rep(i,Q) {
    // 変更がある2箇所の幼稚園で変更を行う
    int c, d; cin >> c >> d;
    c--; d--;
    int before = member[c].first; // 移動前の幼稚園
    member[c].first = d;
    // before幼稚園では、vec_set, setの変更(erase)と, 新しいvec_setのsetへの追加
    int value = member[c].second;
    vec_set[before].erase(vec_set[before].find(value));
    set.erase(set.find(value));
    auto itr2 = vec_set[i].rbegin();
    if(*itr2 == 0) set.insert(INF);
    else set.insert(*itr2);
    // 新しい幼稚園(d)では、vec_set(insert), set(erase)、と新しいvec_setのsetへの追加
    auto itr3 = vec_set[d].rbegin();  // set(erase)
    if(*itr3 == 0) set.erase(set.find(INF));
    else set.erase(set.find(*itr3));
    vec_set[d].insert(value);  // vec_set(insert)
    set.insert(*vec_set[d].rbegin());
    // ansの出力
    auto itr_ans = set.begin();
    cout << *itr_ans << endl;
  }
  return 0;
}

// 終了コード139で、メモリが足りない....