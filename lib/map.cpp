#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int K;
  string s, t;
  cin >> K >> s >> t;
  ll score_s = 0, score_t = 0;
  map<int, int> dic_s {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}, {9,0}};
  map<int, int> dic_t {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}, {9,0}};
  for(int i = 0; i < 4; i++) {
    dic_s[(s[i] - '0')]++;
    dic_t[(t[i] - '0')]++;
  }
  auto itr = dic_s.begin();
  while(itr != dic_s.end()) {
    cout << itr->first << " " << itr->second << endl;
    itr++;
  }
  // cout << dic_s[1] << endl;
  // cout << dic_t[2] << endl;
}