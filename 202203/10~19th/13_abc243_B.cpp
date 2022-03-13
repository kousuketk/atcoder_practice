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
  vector<int> A(N);
  vector<int> B(N);
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];
  rep(i,N) {
    int a = A[i];
    mp[a] = 1;
  }
  int ans1 = 0;
  int ans2 = 0;
  rep(i,N) {
    int b = B[i];
    if(b == A[i]) {
      ans1++;
    } else if(mp.count(b)) {
      ans2++;
    }
  }
  cout << ans1 << endl;
  cout << ans2 << endl;
  return 0;
}