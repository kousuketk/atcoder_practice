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
  vector<vector<int>> vec;
  rep(i,N) {
    int l; cin >> l;
    vector<int> tmp_vec(l);
    rep(j,l) cin >> tmp_vec[j];
    vec.push_back(tmp_vec);
  }
  sort(ALL(vec));
  int ans = 1;
  for(int i = 1; i < N; i++) {
    bool equal = vec[i].size() == vec[i-1].size() && 
                 std::equal(vec[i].begin(), vec[i].end(), vec[i-1].begin(), vec[i-1].end());
    if(!equal) ans++;
  }
  cout << ans << endl;
}