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

int main() {
  map<string, int> mp;
  mp["H"] = 0;
  mp["2B"] = 0;
  mp["3B"] = 0;
  mp["HR"] = 0;
  rep(i,4) {
    string tmp;
    cin >> tmp;
    mp[tmp]++;
  }
  bool flag = false;
  if(
    mp["H"] == 1 &&
    mp["2B"] == 1 &&
    mp["3B"] == 1 &&
    mp["HR"] == 1
  ) flag = true;
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}