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
  stack<int> st;
  int before_val = -1;
  int cnt = 0;
  int total = 0;
  vector<int> ans(N);
  rep(i,N) {
    int a; cin >> a;
    total++;
    if(a != before_val) {
      st.push(a);
      before_val = a;
      cnt = 1;
      ans[i] = total;
      continue;
    }
    if(a == before_val) {
      cnt++;
      if(cnt == a) { // k個連続してk個のボールがすべて消える
        total -= cnt;
        ans[i] = total;
        // cnt-1だけpop
        for(int k = 0; k < (int)(cnt-1); k++) {
          st.top();
          st.pop();
        }
        // pop()したあとは、以前をたどって更新処理をする
        stack<int> tmp_st;
        before_val = st.top();
        cnt = 0;
        while (st.top() == before_val) {
          cnt++;
          int b = st.top();
          st.pop();
          tmp_st.push(b);
        }
        // 終わったらもとに戻す
        rep(j,(int)tmp_st.size()) {
          int b = tmp_st.top();
          tmp_st.pop();
          st.push(b);
        }
      } else {
        ans[i] = total;
        st.push(a);
      }
    }
  }
  rep(i,N) cout << ans[i] << endl;
}

// stackのpopができない問題...
// まじでなんでなのかわからない...
// →別のところでsegmentation errorを起こしていた....