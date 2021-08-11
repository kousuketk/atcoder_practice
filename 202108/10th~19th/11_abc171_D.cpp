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
  ll sum = 0;
  rep(i,N) {
    int tmp; cin >> tmp;
    mp[tmp]++;
    sum += tmp;
  }
  int Q; cin >> Q;
  rep(i,Q) {
    int b, c; cin >> b >> c;
    int count_b = mp[b];
    mp[b] = 0; 
    mp[c] += count_b;
    ll diff = count_b*(c-b);
    sum += diff;
    cout << sum << endl;
  }
  return 0;
}