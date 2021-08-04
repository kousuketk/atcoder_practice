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

vector<int> ans_vec; // 素数を格納していく

// Nまでの素数をans_vecに入れていく
void eratosthenes(int N) {
  vector<bool> is_prime(N+1);
  for(int i = 0; i <= N; i++) is_prime[i] = true;  // とりあえず全部trueにしておく
  
  for(int i = 2; i <= N; i++) {
    if(is_prime[i]) {
      for(int j = 2*i; j <= N; j += i) is_prime[j] = false;  // 倍数をfalseにしていく
      ans_vec.push_back(i); // 素数を入れていく
    }
  }
}