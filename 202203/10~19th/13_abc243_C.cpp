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
  vector<P> inp(N);
  rep(i,N) cin >> inp[i].first >> inp[i].second;
  string s; cin >> s;
  vector<T> vec(N);
  rep(i,N) {
    int x = inp[i].first;
    int y = inp[i].second;
    int c;
    if(s[i] == 'L') c = 0;  // 左は0, 右は1
    else c = 1;
    vec[i] = T(y, x, c);
  }
  sort(ALL(vec));  // y座標, x座標, 左or右でソートする
  int before_y = -1;
  int flag = 0;  // 既に右に行ってる要素があるか
  bool ans = false;
  rep(i,N) {
    int y = get<0>(vec[i]);
    int x = get<1>(vec[i]);
    int c = get<2>(vec[i]);
    if(before_y != y) flag = 0;
    if(flag == 1 && c == 0) ans = true;
    if(flag == 0 && c == 1) flag = 1;  // 既に右に行ってる要素がなくて右に行く要素があった時
    if(ans) break;
    before_y = y;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}