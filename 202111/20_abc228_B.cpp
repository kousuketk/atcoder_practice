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
  int N, x; cin >> N >> x;
  x--;
  vector<int> vec(N);
  rep(i,N) {
    int a; cin >> a;
    a--;
    vec[i] = a;
  }
  map<int, int> mp;
  mp[x] = 1;
  int cnt = 1;
  while(true) {
    int nv = vec[x];
    if(mp[nv] > 0) break;
    mp[nv] = 1;
    cnt++;
    x = nv;
  }
  cout << cnt << endl;
}