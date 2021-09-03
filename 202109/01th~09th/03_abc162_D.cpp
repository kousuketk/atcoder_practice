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
  string s; cin >> s;
  int cnt_r = 0;
  int cnt_g = 0;
  int cnt_b = 0;
  ll cnt = 0;
  rep(i,N) {
    if(s[i] == 'R') {
      cnt_r++;
      cnt += cnt_g*cnt_b;
    } else if(s[i] == 'G') {
      cnt_g++;
      cnt += cnt_r*cnt_b;
    } else if(s[i] == 'B') {
      cnt_b++;
      cnt += cnt_r*cnt_g;
    }
  }
  // j-i≠k-jを探す
  rep(i,N) {
    for(int j = 1; j <= N/2; j++) {
      // s[i], s[i+j], s[i+2*j]を見る
      if(i+j >= N || i+2*j >= N) break;
      if(s[i] != s[i+j] && s[i] != s[i+2*j] && s[i+j] != s[i+2*j]) cnt--;
    }
  }
  cout << cnt << endl;
}