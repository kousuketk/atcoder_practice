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

bool is_batch(string s) {
  string sc = s;
  reverse(ALL(sc));
  return s == sc;
}

int main() {
  string s; cin >> s;
  int siz = s.size();
  bool flag1 = is_batch(s);
  bool flag2 = is_batch(s.substr(0, (siz-1)/2));
  bool flag3 = is_batch(s.substr((siz+3)/2 - 1, siz - (siz+3)/2 + 1));
  if(flag1 && flag2 && flag3) cout << "Yes" << endl;
  else cout << "No" << endl;
}