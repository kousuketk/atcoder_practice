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
  vector<int> vec_sorted(N);
  rep(i,N) {
    int sum = 0;
    rep(j,3) {
      int p; cin >> p;
      sum += p;
    }
    vec[i] = sum;
    vec_sorted[i] = sum;
  }
  sort(ALL(vec_sorted));
  rep(i,N) {
    int now = vec[i];
    auto itr = upper_bound(ALL(vec_sorted), now+300);
    int rank = vec_sorted.end() - itr + 1;
    if(rank <= K) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}