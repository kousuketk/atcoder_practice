#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<ll,ll>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
// const int INF = 1001001001;
const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

// エラトステネスの篩の計算量は、O(nloglogn)
int prime[MAX_N];  // i番目の素数
bool is_prime[MAX_N+1];  // 素数かどうか
int sieve(int n) {  // 整数nまで、素数かどうかを調べ、素数の数を返す
  int p = 0;
  for(int i = 0; i <= n; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for(int i = 2; i <= n; i++) {
    if(is_prime[i]) {
      prime[p++] = i;
      for(int j = 2*i; j <= n; j += i) is_prime[j] = false;
    }
  }
  return p;
}