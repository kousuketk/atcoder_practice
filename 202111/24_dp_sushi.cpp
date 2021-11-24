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
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int N;
double dp[310][310][310];

double rec(int c1,int c2,int c3){
  if(c1 == 0 && c2 == 0 && c3 == 0) return dp[c1][c2][c3];
	if(dp[c1][c2][c3] > 0)return dp[c1][c2][c3];
	double fans=1/(1-(double)(N-c1-c2-c3)/N);
	if(c1>0)fans+=rec(c1-1,c2,c3)*c1/N/(1-(double)(N-c1-c2-c3)/N);
	if(c2>0)fans+=rec(c1+1,c2-1,c3)*c2/N/(1-(double)(N-c1-c2-c3)/N);
	if(c3>0)fans+=rec(c1,c2+1,c3-1)*c3/N/(1-(double)(N-c1-c2-c3)/N);
	return dp[c1][c2][c3]=fans;
}

int main() {
  cin >> N;
  int c1 = 0, c2 = 0, c3 = 0;
  rep(i,N) {
    int a; cin >> a;
    if(a == 1) c1++;
    else if(a == 2) c2++;
    else c3++;
  }
  double ans = rec(c1, c2, c3);
  cout << fixed << setprecision(10) << ans << endl;
}