#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main() {
  string x;
  string y;
  cin >> x;
  for(int i = 0; i < x.size(); i++) {
    if(x.at(i) == '.') break;
    y += x.at(i);
  }
  cout << y << endl;
}