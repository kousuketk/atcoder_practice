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

int main() {
  int N; cin >> N;
  vector<int> x(N);
  vector<int> y(N);
  rep(i,N) cin >> x[i] >> y[i];
  int count = 0;
  for(int i = 0; i < N; i++) {
    double xi = x[i], yi = y[i];
    for(int j = i+1; j < N; j++) {
      double xj = x[j], yj = y[j];
      double t = (yj-yi)/(xj-xi);
      if(t >= -1 && t <= 1) count++;
    }
  }
  cout << count << endl;
}