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
  string s, t; cin >> s >> t;
  int N = s.size();
  bool ans = false;
  if(s == t) ans = true;
  for(int i = 0; i < N-1; i++) {
    string tmp = s;
    tmp[i] = s[i+1];
    tmp[i+1] = s[i];
    if(tmp == t) ans = true;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}