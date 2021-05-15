#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main() {
  string x;
  string y;
  cin >> x;
  for(char c : x) {
    if(c ==  '.') break;
    y += c;
  }
  cout << y << endl;
}