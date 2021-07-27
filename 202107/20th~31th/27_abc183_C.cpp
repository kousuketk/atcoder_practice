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

int N, K;
int dist[10][10];
int ans = 0;

void rec(int bit, int v, int cost) {
  if(bit == (1<<v)) {
    if(cost+dist[0][v] == K) ans++;
    return;
  }
  int prev_bit = bit & ~(1<<v);
  for(int nv = 1; nv < N; nv++) {
    if(!(prev_bit & (1<<nv))) continue;
    rec(prev_bit, nv, cost+dist[nv][v]);
  }
}

int main() {
  cin >> N >> K;
  rep(i,N) rep(j,N) cin >> dist[i][j];
  rec((1<<N)-1, 0, 0);
  cout << ans << endl;
}