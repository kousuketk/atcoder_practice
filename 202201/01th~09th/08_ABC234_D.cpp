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
  int N, K; cin >> N >> K;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  map<int, int> mp;
  int min_val = INF;
  rep(i,K) {
    int p = vec[i];
    min_val = min(p, min_val);
    mp[p] = 1;
  }
  cout << min_val << endl;
  for(int i = K; i < N; i++) {
    int p = vec[i];
    mp[p] = 1;
    if(p > min_val) {
      while(true) {
        min_val++;
        if(mp.count(min_val)) break;
      }
    }
    cout << min_val << endl;
  }
  return 0;
}