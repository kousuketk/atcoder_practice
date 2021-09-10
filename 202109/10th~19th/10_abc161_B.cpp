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
  vector<int> vec(N);
  int sum = 0;
  rep(i,N) {
    int tmp; cin >> tmp;
    vec[i] = tmp;
    sum += tmp;
  }
  int line = sum/(4*M);
  if(line*4*M != sum) line++;
  int cnt = 0;
  rep(i,N) {
    if(vec[i] >= line) cnt++;
  }
  if(cnt >= M) cout << "Yes" << endl;
  else cout << "No" << endl;
}