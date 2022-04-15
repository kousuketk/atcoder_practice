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
vector<int> vec(1000100, INF);

void insert(int val, int i = 0) {
  if(vec[i] == INF) {
    vec[i] = val;
    return;
  }
  if(vec[i] >= val) insert(val, 2*i+1);
  else insert(val, 2*i+2);
}

bool find(int val, int i = 0) {
  if(vec[i] == val) return true;
  if(vec[i] == INF) return false;
  if(vec[i] >= val) return find(val, 2*i+1);
  else return find(val, 2*i+2);
}

void print1(int i = 0) {
  if(vec[i] == INF) return;
  // 左の子を見る
  print1(2*i+1);
  // 自分を出力
  cout << " " << vec[i];
  // 右の子を見る
  print1(2*i+2);
}

void print2(int i = 0) {
  if(vec[i] == INF) return;
  // 自分を出力
  cout << " " << vec[i];
  // 左の子
  print2(2*i+1);
  // 右の子
  print2(2*i+2);
}

int main() {
  int N; cin >> N;
  rep(i,N) {
    string s; cin >> s;
    if(s == "insert") {
      int x; cin >> x;
      insert(x);
    } else if(s == "find") {
      int x; cin >> x;
      bool ans = find(x);
      if(ans) cout << "yes" << endl;
      else cout << "no" << endl;
    } else {
      print1();
      cout << endl;
      print2();
      cout << endl;
    }
  }
}