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
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  string s; cin >> s;
  int a, b, c, d;
  a = s[0] - '0'; b = s[1] - '0';
  c = s[2] - '0'; d = s[3] - '0';
  if(a+b+c+d==7) {cout << a << "+" << b << "+" << c << "+" << d << "=7" << endl; return 0;}
  if(a-b+c+d==7) {cout << a << "-" << b << "+" << c << "+" << d << "=7" << endl; return 0;}
  if(a-b-c+d==7) {cout << a << "-" << b << "-" << c << "+" << d << "=7" << endl; return 0;}
  if(a-b-c-d==7) {cout << a << "-" << b << "-" << c << "-" << d << "=7" << endl; return 0;}
  if(a-b+c-d==7) {cout << a << "-" << b << "+" << c << "-" << d << "=7" << endl; return 0;}
  if(a+b-c-d==7) {cout << a << "+" << b << "-" << c << "-" << d << "=7" << endl; return 0;}
  if(a+b+c-d==7) {cout << a << "+" << b << "+" << c << "-" << d << "=7" << endl; return 0;}
  if(a+b-c+d==7) {cout << a << "+" << b << "-" << c << "+" << d << "=7" << endl; return 0;}
}