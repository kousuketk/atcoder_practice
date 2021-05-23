#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;

int main() {
  string s;
  cin >> s;
  string rev_s;
  for(int i = 0; i < s.size(); i++) {
    char c = s.at(s.size()-i-1);
    rev_s.push_back(c);
  }
  for(int i = 0; i < s.size(); i++) {
    if(rev_s.at(i) == '6') rev_s.at(i) = '9';
    else if(rev_s.at(i) == '9') rev_s.at(i) = '6';
  }
  cout << rev_s << endl;
}