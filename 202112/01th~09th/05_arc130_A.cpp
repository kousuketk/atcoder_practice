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
  ll ans = 0;
  ll cnt = 1;
  for(int i = 1; i < N; i++) {
    if(s[i] == s[i-1]) {
      cnt++;
    } else if(cnt > 1) {
      ans += cnt*(cnt-1)/2;
      cnt = 1;
    }
    if(cnt > 1 && i == N-1) ans += cnt*(cnt-1)/2;
  }
  cout << ans << endl;
}