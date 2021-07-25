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

int main() {
  int N; cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  vector<int> C(N);
  rep(i,N) cin >> A[i]; rep(i,N) cin >> B[i]; rep(i,N) cin >> C[i];
  sort(ALL(A)); sort(ALL(B)); sort(ALL(C));
  int ans = 0;
  rep(i,N) {
    int a = A[i];
    auto itr_b = upper_bound(ALL(B), a);
    if(itr_b == B.end()) break;
    int b = *itr_b;
    B.erase(itr_b);
    auto itr_c = upper_bound(ALL(C), b);
    if(itr_c == C.end()) break;
    C.erase(itr_c);
    ans++;
  }
  cout << ans << endl;
}