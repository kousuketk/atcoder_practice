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

int N, L, K;
vector<int> vec;
// N個からK個選んだときに、各長さをx以上にできるか？
bool check(int x) {
  int len = 0;
  int cnt = 0;
  rep(i,N+1) {
    len += vec[i];
    if(len >= x) {
      cnt++;
      len = 0;
    }
  }
  return cnt >= K+1;
}

int main() {
  // 最小値の最大化
  cin >> N >> L >> K;
  vec.resize(N+1);
  int tmp_a;
  rep(i,N) {
    int a; cin >> a;
    if(i == 0) {
      vec[i] = a;
    } else if(i == N-1) {
      vec[i] = a - tmp_a;
      vec[i+1] = L - a;
    } else {
      vec[i] = a - tmp_a;
    }
    tmp_a = a;
  }
  int left = 0, right = INF;
  while(left+1 < right) {
    int mid = (left + right) / 2;
    if(check(mid)) left = mid;
    else right = mid;
  }
  cout << left << endl;
}