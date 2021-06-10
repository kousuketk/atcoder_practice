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
  int N, K;
  cin >> N >> K;
  int a = N;
  for(int i = 0; i < K; i++) {
    string s = to_string(a);
    sort(s.rbegin(), s.rend());
    int g1 = stoi(s);
    sort(s.begin(), s.end());
    int g2 = stoi(s);
    a = g1 - g2;
  }
  cout << a << endl;
}