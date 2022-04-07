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

int vec[1000010];
int main() {
  int N; cin >> N;
  rep(i,N) {
    int a, b; cin >> a >> b;
    b++;
    vec[a]++;
    vec[b]--;
  }
  rep(i,1000000) vec[i+1] += vec[i];
  int ans = 0;
  rep(i,1000001) ans = max(ans, vec[i]);
  cout << ans << endl;
  return 0;
}