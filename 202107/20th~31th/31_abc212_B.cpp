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
  string s; cin >> s;
  bool flag = false;
  if(s[0] == s[1] && s[0] == s[2] && s[0] == s[3]) flag = true;
  bool mini_flag = true;
  rep(i,3) {
    if(!(s[i] == '9' && s[i+1] == '0') && !(s[i]+1 == s[i+1])) mini_flag = false;
  }
  if(mini_flag) flag = true;
  if(flag) cout << "Weak" << endl;
  else cout << "Strong" << endl;
}