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

int N, K;
vector<int> vec;
// 退屈さをx以下にできるか？
bool check(int x) {
  int cnt = 0;
  int cnt_same = 1;
  rep(i,N-1) {
    if(vec[i+1] == vec[i]) {
      if(cnt_same == x) cnt++, cnt_same = 0;
      else cnt_same++;
    } else {
      cnt_same = 1;
    }
  }
  return cnt <= K;
}

int main() {
  cin >> N >> K;
  vec.resize(N);
  rep(i,N) cin >> vec[i];
  int ng = 0;
  int ok = INF;
  while(ng+1 < ok) {
    int mid = (ng+ok)/2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}