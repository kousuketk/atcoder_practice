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
  int a;
  cin >> a;
  string N;
  cin >> N;
  int ans = 0;
  for(int i = 0; i < 1000; i++) {
    string s = to_string(i);
    while(s.size() < 3) {
      s = '0' + s;
    }
    // cout << s << endl;
    // 文字列sに対して、Nから生成できるかどうか
    int index = 0;
    for(int j = 0; j < N.size(); j++) {
      if(N.at(j) == s.at(index)) index++;
      if(index == 3) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}