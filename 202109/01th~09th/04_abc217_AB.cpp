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
  map<string, int> mp;
  mp["ABC"] = 1;
  mp["ARC"] = 1;
  mp["AGC"] = 1;
  mp["AHC"] = 1;
  rep(i,3) {
    string s; cin >> s;
    mp[s] = 0;
  }
  string ans;
  if(mp["ABC"] == 1) ans = "ABC";
  if(mp["ARC"] == 1) ans = "ARC";
  if(mp["AGC"] == 1) ans = "AGC";
  if(mp["AHC"] == 1) ans = "AHC";
  cout << ans << endl;
}