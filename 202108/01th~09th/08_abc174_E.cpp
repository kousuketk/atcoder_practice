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

int N;
ll K;
vector<int> vec;

// 最も長い丸太の長さをd以下にすることができるか？
bool check(int d) {
  auto itr = lower_bound(ALL(vec), d);
  ll count = 0;
  while(itr != vec.end()) {
    count += ceil((double)*itr/d) - 1;
    itr++;
  }
  if(count <= K) return true;
  else return false;
}

int main() {
  cin >> N >> K;
  vec.resize(N);
  rep(i,N) cin >> vec[i];
  sort(ALL(vec));
  // 実際に探索する
  int left = 0, right = INF;
  while(right - left > 1) {
    int mid = (left + right)/2;
    if(check(mid)) right = mid;
    else left = mid;
  }
  cout << right << endl;
}