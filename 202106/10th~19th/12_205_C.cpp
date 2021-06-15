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
  ll a, b, c;
  cin >> a >> b >> c;
  if(c % 2 == 0) {
    if(abs(a) == abs(b)) {
      cout << "=" << endl; return 0;
    } else if(abs(a) > abs(b)) {
      cout << ">" << endl; return 0;
    } else {
      cout << "<" << endl; return 0;
    }
  } else {
    if(a == b) {
      cout << "=" << endl; return 0;
    } else if(a > b){
      cout << ">" << endl; return 0;
    } else {
      cout << "<" << endl; return 0;
    }
  }
}