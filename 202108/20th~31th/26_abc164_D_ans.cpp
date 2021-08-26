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
const int MOD = 2019;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int main() {
  string s; cin >> s;
  int N = s.size();
  ll ans = 0;
  map<int, int> mp;
  mp[0] = 1;
  int total = 0;
  int ten = 1;
  rep(i,N) {
    total = (total + ten*(s[N-1-i]-'0')) % MOD;
    ans += mp[total];
    mp[total]++;
    ten = (ten*10) % MOD;
  }
  cout << ans << endl;
}