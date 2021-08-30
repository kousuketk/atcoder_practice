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

// 提出コードはc++になってる？
int main() {
  string s; cin >> s;
  int i = 0;
  string a, b;
  while(true) {
    if(s[i] == '.') break;
    a += s[i];
    i++;
  }
  b = s[i+1];
  int x = stoi(a);
  int y = stoi(b);
  cout << x;
  if(y <= 2) cout << "-" << endl;
  else if(y <= 6) cout << endl;
  else cout << "+" << endl;
}