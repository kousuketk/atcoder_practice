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

// 三角形になるときtrue, ならないときfalse
bool check(int x1, int y1, int x2, int y2, int x3, int y3) {
  if(x1 == x2 && x1 == x3) return false;
  if(x1 == x2 || x1 == x3) return true;
  if((y1-y3)*(x1-x2) == (y1-y2)*(x1-x3)) return false; // 傾きが同じ→三角形にならない
  return true;
}

// 直線にならなければ良い→傾きだけ見ればいい
int main() {
  int N; cin >> N;
  vector<P> vec(N);
  rep(i,N) cin >> vec[i].first >> vec[i].second;
  int cnt = 0;
  for(int i = 0; i < N; i++) {
    for(int j = i+1; j < N; j++) {
      for(int k = j+1; k < N; k++) {
        int x1 = vec[i].first;
        int y1 = vec[i].second;
        int x2 = vec[j].first;
        int y2 = vec[j].second;
        int x3 = vec[k].first;
        int y3 = vec[k].second;
        if(check(x1, y1, x2, y2, x3, y3)) cnt++;
      }
    }
  }
  cout << cnt << endl;
}