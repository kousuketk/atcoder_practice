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
  int N; cin >> N;
  int ans = INF;
  for(int i = 1; i < N; i++) {
    int a = i;
    int b = N - i;
    string str_a = to_string(a);
    string str_b = to_string(b);
    int tmp_count = 0;
    for(char c : str_a) {
      int tmp = c - '0';
      tmp_count += tmp;
    }
    for(char c : str_b) {
      int tmp = c - '0';
      tmp_count += tmp;
    }
    ans = min(ans, tmp_count);
  }
  cout << ans << endl;
}