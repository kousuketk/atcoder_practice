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

int MAX_TIME = 86400;

int changeStr(string str) {
  int h = stoi(str.substr(0, 2));
  int m = stoi(str.substr(3, 2));
  int s = stoi(str.substr(6, 2));
  return h*3600 + m*60 + s;
}

int main() {
  int N; cin >> N;
  vector<int> ansvec;
  int cnt = 0;
  while(N != 0) {
    vector<int> vec(MAX_TIME+10);
    rep(i,N) {
      string strl, strr; cin >> strl >> strr;
      int l = changeStr(strl);
      int r = changeStr(strr);
      vec[l]++;
      vec[r]--;
    }
    int ans = 0;
    rep(i,MAX_TIME) vec[i+1] += vec[i];
    rep(i,MAX_TIME) ans = max(ans, vec[i]);
    ansvec.push_back(ans);
    cin >> N;
    cnt++;
  }
  rep(i,cnt) cout << ansvec[i] << endl;
  return 0;
}