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

// スコアは、大きいものからN/2個選んだもの
int main() {
  int N; cin >> N;
  vector<ll> vec(N);
  vector<ll> vec_copy(N);
  rep(i,N) {
    ll a; cin >> a;
    vec[i] = a;
    vec_copy[i] = a;
  }
  sort(ALL(vec_copy), greater());
  multiset<ll> ms;
  ll score = 0;
  rep(i,N/2) {
    ms.insert(vec_copy[i]);
    score += vec_copy[i];
  }
  vector<bool> flag(N);  // すぬけ君が取る場所
  for(int i = 0; i < N; i++) {
    auto itr = ms.find(vec[i]);
    if(itr == ms.end()) continue;
    ms.erase(itr);
    flag[i] = true;
  }
  // 前から見ていく
  int sum = 0;
  int start = 0;
  bool out = false;
  rep(i,N) {
    if(out && flag[i]) continue;
    if(out && !flag[i]) {
      out = false;
      start = i;
      sum = 0;
    }
    if(flag[i]) sum++;
    if((i-start)%2==1 && (i-start+1)/2 < sum) {
      out = true;
      continue;
    }
  }
  int k = start;
  cout << k << " " << score << endl;
  return 0;
}