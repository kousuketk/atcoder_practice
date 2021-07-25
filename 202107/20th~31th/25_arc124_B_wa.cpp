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
// int binary(int bina){
//   int ans = 0;
//   for (int i = 0; bina>0 ; i++)
//   {
//     ans = ans+(bina%2)*pow(10,i);
//     bina = bina/2;
//   }
//   return ans;
// }
string toBinary(int n) {
  string r;
  while (n != 0){
    r += ( n % 2 == 0 ? "0" : "1" );
    n /= 2;
  }
  return r;
}
int rev_binary(int binary) {
  int decimal = 0;
  int base = 1;
  while(binary>0){
    decimal = decimal + ( binary % 10 ) * base;
    binary = binary / 10;
    base = base * 2;
  }
  return decimal;
}
int xora(string a, string b) {
  int a_size = a.size();
  int b_size = b.size();
  if(a_size < b_size) {
    a.swap(b);
    swap(a_size, b_size);
  }
  // aのほうがサイズが大きい
  int res = 0;
  int i = 0;
  while(i < b_size) {
    if((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) res += pow(2, i);
    i++;
  }
  while(i < a_size) {
    if(a[i] == '1') res += pow(2, i);
    i++;
  }
  return res;
}

int main() {
  int N; cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];
  vector<vector<int>> dp(N, vector<int>(N));
  rep(i,N) {
    string a = toBinary(A[i]);
    rep(j,N) {
      string b = toBinary(B[j]);
      // dp[i][j] = A[i]とB[j]のXOR
      dp[i][j] = xora(a, b);
    }
  }
  // sortする
  rep(i,N) sort(dp[i].begin(), dp[i].end());
  // a1~aNを前から見ていく(小さい順で)
  vector<ll> ans;
  rep(i,N) {
    int a = dp[0][i]; // 0番目に対してdp[1~N-1]を見ていく
    rep(j,N-1) {
      auto itr = lower_bound(ALL(dp[j+1]), a);
      if(*itr != a) break;
      if(j == N-2) ans.push_back(a);
    }
  }
  int ans_size = ans.size();
  cout << ans_size << endl;
  rep(i,ans_size) cout << ans[i] << endl;
}