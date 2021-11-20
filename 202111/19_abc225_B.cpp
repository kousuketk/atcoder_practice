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
  int N; cin >> N;
  map<int, int> mp;
  rep(i,N-1) {
    int a, b; cin >> a >> b;
    a--; b--;
    mp[a]++; mp[b]++;
  }
  bool ans = false;
  rep(i,N) if(mp[i] == N-1) ans = true;
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}