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
  int N, K; cin >> N >> K;
  map<int, int> mp;
  rep(i,N) {
    int a; cin >> a;
    mp[a]++;
  }
  vector<int> vec;
  auto itr = mp.begin();
  while(itr != mp.end()) {
    vec.push_back(itr->second);
    itr++;
  }
  sort(vec.begin(), vec.end());
  int delete_count = vec.size() - K;
  int ans = 0;
  for(int i = 0; i < delete_count; i++) {
    ans += vec[i];
  }
  cout << ans << endl;
  // size - K要素を削除しないといけない, 
}