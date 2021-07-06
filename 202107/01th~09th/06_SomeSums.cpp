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
  int n, a, b; cin >> n >> a >> b;
  int ans = 0;
  for(int i = 0; i <= n; i++) {
    string str = to_string(i);
    int tmp_count = 0;
    for(int j = 0; j < str.size(); j++) {
      tmp_count += str[j] - '0';
    }
    if(tmp_count >= a && tmp_count <= b) ans += i;
  }
  cout << ans << endl;
}