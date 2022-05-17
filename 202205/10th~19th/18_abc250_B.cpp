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

int main() {
  int N, A, B; cin >> N >> A >> B;
  vector<string> vec(A*N);
  int cnt_i = 0, cnt_j = 0;
  bool flag = true;
  for(int i = 0; i < A*N; i++) {
    if(cnt_i >= 2*A) cnt_i = 0;
    if(cnt_i < A) flag = true;
    else flag = false;
    string tmp = "";
    cnt_j = 0;
    for(int j = 0; j < B*N; j++) {
      if(cnt_j >= 2*B) cnt_j = 0;
      if(flag) {
        if(cnt_j < B) tmp += '.';
        else tmp += '#';
      } else {
        if(cnt_j < B) tmp += '#';
        else tmp += '.';
      }
      cnt_j++;
    }
    vec[i] = tmp;
    cnt_i++;
  }
  rep(i,A*N) cout << vec[i] << endl;
  return 0;
}