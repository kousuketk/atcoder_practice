#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int n, m;
  cin >> n >> m;
  map<int, vector<int>> mp;
  rep(i,m) {
    int x, y;
    cin >> x >> y;
    mp[x].push_back(y);
  }

  set<int> s;
  s.insert(n);
  for(auto p : mp) {
    vector<int> add;
    for(int y : p.second) {
      if(s.count(y-1) || s.count(y+1)) add.push_back(y);
    }
    for(int y : p.second) s.erase(y);
    for(int y : add) s.insert(y);
  }

  cout << s.size() << endl;
  return 0;
}