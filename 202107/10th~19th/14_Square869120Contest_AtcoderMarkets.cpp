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
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int N; cin >> N;
  vector<int> A(N);
  vector<int> A_copy(N);
  vector<int> B(N);
  vector<int> B_copy(N);
  rep(i,N) {
    int tmp_a; int tmp_b;
    cin >> tmp_a; cin >> tmp_b;
    A[i] = tmp_a; A_copy[i] = tmp_a;
    B[i] = tmp_b; B_copy[i] = tmp_b;
  }
  sort(ALL(A_copy));
  sort(ALL(B_copy));
  // N/2番目
  int start = A_copy[N/2];
  int goal = B_copy[N/2];
  ll ans = 0;
  for(int i = 0; i < N; i++) {
    ans += abs(start - A[i]);
    ans += B[i] - A[i];
    ans += abs(goal - B[i]);
  }
  cout << ans << endl;
}