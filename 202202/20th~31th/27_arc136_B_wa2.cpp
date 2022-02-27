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
  map<int, int> mpA;
  map<int, int> mpB;
  rep(i,N) {
    int a; cin >> a;
    mpA[a]++;
  }
  rep(i,N) {
    int b; cin >> b;
    mpB[b]++;
  }
  bool ans = true;
  rep(i,5000) {
    int cnt_a = mpA[i];
    int cnt_b = mpB[i];
    if(cnt_a != cnt_b) ans = false;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}