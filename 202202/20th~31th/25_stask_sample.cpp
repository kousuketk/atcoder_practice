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
  string s; cin >> s;
  stack<int> st;  // i番目の"("がスタックにあることを示す
  bool flag = true;
  vector<P> ans;
  rep(i,(int)s.size()) {
    if(s[i] == '(') {
      st.push(i);
    } else if(st.empty()) {
      flag = false;
      break;
    } else {
      int idx = st.top();
      st.pop();
      ans.push_back({idx, i});
    }
  }
  if(!st.empty()) flag = false;
  if(flag) {
    rep(i,(int)ans.size()) cout << ans[i].first << " " << ans[i].second << endl;
  } else {
    cout << "No" << endl;
  }
}

// input_sample
// (()(())())(()())
// (()(())(()())
// )(()(())(()())