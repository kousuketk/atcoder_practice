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
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  ll manh = 0;
  ll yu = 0;
  int tye = 0;
  rep(i,N) {
    manh += abs(vec[i]);
    yu += pow(abs(vec[i]), 2);
    tye = max(tye, abs(vec[i]));
  }
  long double yu_ans = sqrt(yu);
  cout << manh << endl;
  cout << fixed << setprecision(13) << yu_ans << endl;
  cout << tye << endl;
}