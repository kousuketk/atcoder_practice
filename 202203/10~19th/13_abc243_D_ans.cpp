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
  ll X; cin >> X;
  string S; cin >> S;
  stack<char> st;
  rep(i,N) {
    // もしUで、その前にL, Rだったら、取り除く
    if(st.size() > 0 && S[i] == 'U') {
      if(st.top() == 'L' || st.top() == 'R') st.pop();
      else st.push(S[i]);
    } else {
      st.push(S[i]);
    }
  }
  int siz = st.size();
  stack<char> new_st;
  rep(i,siz) {
    char c = st.top();
    st.pop();
    new_st.push(c);
  }
  // new_stに対して実際に動かす
  rep(i,siz) {
    char c = new_st.top();
    new_st.pop();
    if(c == 'U') X = X / 2;
    if(c == 'L') X = 2*X;
    if(c == 'R') X = 2*X + 1;
  }
  cout << X << endl;
  return 0;
}