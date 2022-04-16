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
  string s; cin >> s;
  map<int,int> mp;
  int n = s.size();
  rep(i,n) {
    int val = s[i] - '0';
    mp[val]++;
  }
  rep(i,10) {
    if(mp[i] == 0) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}