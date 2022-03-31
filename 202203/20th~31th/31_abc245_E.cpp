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
  vector<int> A(N), B(N), C(M), D(M);
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];
  rep(i,M) cin >> C[i];
  rep(i,M) cin >> D[i];
  vector<T> vec(N+M);
  rep(i,N) {
    int a = A[i];
    int b = B[i];
    vec[i] = T(a, 0, b);
  }
  rep(i,M) {
    int c = C[i];
    int d = D[i];
    vec[N+i] = T(c, 1, d);
  }
  sort(ALL(vec), greater());
  multiset<int> ms;
  rep(i,N+M) {
    int e = get<0>(vec[i]);
    int f = get<1>(vec[i]);
    int g = get<2>(vec[i]);
    if(f == 1) {
      ms.insert(g);
    } else {
      auto itr = ms.lower_bound(g);
      if(itr == ms.end()) {
        cout << "No" << endl;
        return 0;
      }
      ms.erase(itr);
    }
  }
  cout << "Yes" << endl;
  return 0;
}