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
  int siz = s.size();
  bool flag1 = false;
  bool flag2 = false;
  bool flag3 = true;
  map<char, int> mp;
  for(int i = 0; i < siz; i++) {
    char c = s[i];
    if(c >= 'A' && c <= 'Z') flag1 = true;
    if(c >= 'a' && c <= 'z') flag2 = true;
    if(mp.count(c)) flag3 = false;
    mp[c]++;
  }
  if(flag1 && flag2 && flag3) cout << "Yes" << endl;
  else cout << "No" << endl;
}