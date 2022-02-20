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
  stack<P> st;  // (a, b) a：値, b：何回目の値であるか
  vector<int> ans(N);
  rep(i,N) {
    int a; cin >> a;
    if(st.empty()) {
      st.push({a, 1});
      ans[i] = st.size();
      continue;
    }
    // a, b
    int before_a = st.top().first;
    if(before_a == a) {
      if((st.top().second + 1) == a) {  // a-1個取り除く
        rep(j,a-1) st.pop();
      } else {
        st.push({a, st.top().second+1});
      }
    } else {
      st.push({a, 1});
    }
    ans[i] = st.size();
  }
  rep(i,N) cout << ans[i] << endl;
}