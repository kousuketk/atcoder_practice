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
  int N; cin >> N;
  map<string, int> mp;
  int max_val = 0;
  rep(i,N) {
    string s; cin >> s;
    mp[s]++;
    max_val = max(max_val, mp[s]);
  }
  auto itr = mp.begin();
  while(itr != mp.end()) {
    if(itr->second == max_val) cout << itr->first << endl;
    itr++;
  }
  return 0;
}