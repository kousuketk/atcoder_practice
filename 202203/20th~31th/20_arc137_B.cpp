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

int N;
vector<int> vec;
// aを最大いくつ反転できるか？
int cnt_rev(int a) {
  int res = 0;
  int now_cnt = 0;
  rep(i,N) {
    if(now_cnt == 0 && vec[i] != a) continue;
    if(vec[i] == a) {
      now_cnt++;
      res = max(res, now_cnt);
    } else {
      now_cnt--;
    }
  }
  return res;
}

int main() {
  cin >> N;
  vec.resize(N);
  rep(i,N) cin >> vec[i];
  int cnt_one = 0;
  rep(i,N) if(vec[i] == 1) cnt_one++;
  int cnt_rev_one = cnt_rev(1);
  int cnt_rev_zero = cnt_rev(0);
  int min_val = cnt_one - cnt_rev_one;
  int max_val = cnt_one + cnt_rev_zero;
  int ans = max_val - min_val + 1;
  cout << ans << endl;
  return 0;
}