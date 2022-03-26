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
  int N, M; cin >> N >> M;
  vector<int> A(N+1);
  vector<int> B(M+1);
  vector<int> C(N+M+1);
  rep(i,N+1) cin >> A[N-i];
  rep(i,N+M+1) cin >> C[N+M-i];
  vector<int> A_tmp(N+1);
  rep(i,N+1) A_tmp[i] = C[i];
  rep(i,M+1) {
    // rep(i,N+1) cout << A_tmp[i] << " ";
    // cout << endl;
    int idx = 0;
    int b = A_tmp[0] / A[0];
    B[i] = b;
    rep(i,N+1) A_tmp[i] = A_tmp[i] - A[i]*b;
    rep(i,N) A_tmp[i] = A_tmp[i+1];
    A_tmp[N] = C[N+i+1];  // i+1
  }
  rep(i,M+1) {
    cout << B[M-i];
    if(i != M) cout << " ";
  }
  return 0;
}