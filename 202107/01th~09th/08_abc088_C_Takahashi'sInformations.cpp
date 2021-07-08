#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const ll INF = 1100100100100100100;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  vector<vector<int>> vec(3, vector<int>(3));
  rep(i,3) rep(j,3) cin >> vec[i][j];
  for(int a1 = 0; a1 <= 100; a1++) {
    int b1 = vec[0][0] - a1;
    int b2 = vec[0][1] - a1;
    int b3 = vec[0][2] - a1;
    for(int a2 = 0; a2 <= 100; a2++) {
      for(int a3 = 0; a3 <= 100; a3++) {
        if((vec[1][0] == a2 + b1) &&
          (vec[1][1] == a2 + b2) &&
          (vec[1][2] == a2 + b3) &&
          (vec[2][0] == a3 + b1) &&
          (vec[2][1] == a3 + b2) &&
          (vec[2][2] == a3 + b3)) {
            cout << "Yes" << endl;
            return 0;
          }
      }
    } 
  }
  cout << "No" << endl;
  return 0;
}