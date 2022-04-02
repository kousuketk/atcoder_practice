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

int dist[1510][1510];
vector<string> vec;
int N;

bool check1(int x, int y) {
  if(x+1 > N-1) return false;
  if(y+1 > N-1) return false;
  if(vec[x+1][y+1] == '#') return false;
  return true;
}

bool check2(int x, int y) {
  if(x+1 > N-1) return false;
  if(y-1 < 0) return false;
  if(vec[x+1][y-1] == '#') return false;
  return true;
}

bool check3(int x, int y) {
  if(x-1 < 0) return false;
  if(y+1 > N-1) return false;
  if(vec[x-1][y+1] == '#') return false;
  return true;
}

bool check4(int x, int y) {
  if(x-1 < 0) return false;
  if(y-1 < 0) return false;
  if(vec[x-1][y-1] == '#') return false;
  return true;
}


int main() {
  rep(i,1510) rep(j,1510) dist[i][j] = INF;
  cin >> N;
  vec.resize(N);
  int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
  ax--, ay--, bx--, by--;
  rep(i,N) cin >> vec[i];
  priority_queue<T, vector<T>, greater<T>> que;  // cost, x, y
  que.push(T(0, ax, ay));
  dist[ax][ay] = 0;
  while (!que.empty()) {
    T tmp = que.top(); que.pop();
    int cost = get<0>(tmp);
    int x = get<1>(tmp);
    int y = get<2>(tmp);
    if(dist[x][y] != cost) continue;
    // x, yからいけるところを探す
    // 1
    int tmpx, tmpy;
    tmpx = x, tmpy = y;
    while(check1(tmpx, tmpy)) {
      tmpx++, tmpy++;
      if(dist[tmpx][tmpy] <= cost+1) break;
      dist[tmpx][tmpy] = cost+1;
      que.push(T(dist[tmpx][tmpy], tmpx, tmpy));
    }
    // 2
    tmpx = x, tmpy = y;
    while(check2(tmpx, tmpy)) {
      tmpx++, tmpy--;
      if(dist[tmpx][tmpy] <= cost+1) break;
      dist[tmpx][tmpy] = cost+1;
      que.push(T(dist[tmpx][tmpy], tmpx, tmpy));
    }
    // 3
    tmpx = x, tmpy = y;
    while(check3(tmpx, tmpy)) {
      tmpx--, tmpy++;
      if(dist[tmpx][tmpy] <= cost+1) break;
      dist[tmpx][tmpy] = cost+1;
      que.push(T(dist[tmpx][tmpy], tmpx, tmpy));
    }
    // 4
    tmpx = x, tmpy = y;
    while(check4(tmpx, tmpy)) {
      tmpx--, tmpy--;
      if(dist[tmpx][tmpy] <= cost+1) break;
      dist[tmpx][tmpy] = cost+1;
      que.push(T(dist[tmpx][tmpy], tmpx, tmpy));
    }
  }
  if(dist[bx][by] == INF) cout << -1 << endl;
  else cout << dist[bx][by] << endl;
  return 0;
}