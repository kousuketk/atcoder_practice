#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<double,double>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int main() {
  int N; cin >> N;
  vector<P> vec(N);
  rep(i,N) {
    double a, b; cin >> a >> b;
    vec[i] = P(a, b);
  }
  double total_minutes = 0.0;
  rep(i,N) {
    double a = vec[i].first;
    double b = vec[i].second;
    total_minutes += a/b;
  }
  double minutes = total_minutes/2.0;
  double distance = 0;
  rep(i,N) {
    double a = vec[i].first;
    double b = vec[i].second;
    if(a/b < minutes) {
      minutes -= a/b;
      distance += a;
    } else {
      distance += minutes*b;
      break;
    }
  }
  cout << fixed << setprecision(10) << distance << endl;
}