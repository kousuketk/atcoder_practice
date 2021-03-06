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
  string s; cin >> s;
  int ans = 0;
  int tmp_count = 0;
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
      tmp_count++;
    } else {
      ans = max(ans, tmp_count);
      tmp_count = 0;
    }
  }
  ans = max(ans, tmp_count);
  cout << ans << endl;
}