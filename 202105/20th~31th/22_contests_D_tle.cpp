#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;

long long nCr(long long n, long long k) {
  if (n == k || k == 0)
    return 1;
  else {
    return nCr(n - 1, k - 1) + nCr(n - 1, k);
  }
}

int main() {
  int a, b;
  ll k;
  cin >> a >> b >> k;
  vector<char> vec;
  ll max_count = nCr(a+b, b);
  cout << "end" << endl;
  if(k >= max_count/2) {
    ll count = max_count;
    rep(i,b) vec.push_back('b');
    rep(i,a) vec.push_back('a');
    do {
      if(count == k) {
        for(int i = 0; i < vec.size(); i++) {
          cout << vec.at(i);
        }
        cout << endl;
        return 0;
      }
      count--;
    } while(prev_permutation(vec.begin(), vec.end()));
  } else {
    cout << "else" << endl;
    ll count = 1;
    rep(i,a) vec.push_back('a');
    rep(i,b) vec.push_back('b');
    do {
      if(count == k) {
        for(int i = 0; i < vec.size(); i++) {
          cout << vec.at(i);
        }
        cout << endl;
        return 0;
      }
      count++;
    } while(next_permutation(vec.begin(), vec.end()));
  }
}