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
  string s1, s2; cin >> s1 >> s2;
  bool flag = true;
  if(s1[1] == '#' && s2[0] == '#' && s1[0] == '.' && s2[1] == '.') flag = false;
  if(s1[0] == '#' && s2[1] == '#' && s1[1] == '.' && s2[0] == '.') flag = false;
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}