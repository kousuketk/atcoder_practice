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
  int N, Q; cin >> N >> Q;
  map<int, vector<int>> mp;
  rep(i,N) {
    int a; cin >> a;
    mp[a].push_back(i+1);
  }
  rep(i,Q) {
    int x, k; cin >> x >> k;
    if((mp.count(x) == 0) || ((int)mp[x].size() < k)) {
      cout << -1 << endl;
    } else {
      cout << mp[x][k-1] << endl;
    }
  }
  return 0;
}