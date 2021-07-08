#include <iostream>
#include <vector>
using namespace std;

long long fibo(int n, vector<long long> &memo) {
  // ベースケース
  if (n == 0) return 0;
  else if (n == 1) return 1;

  // メモをチェック (既に計算済みなら答えをリターンする)
  if (memo[n] != -1) return memo[n];

  // 答えをメモしながら、再帰呼び出し
  return memo[n] = fibo(n-1, memo) + fibo(n-2, memo);
}

int main() {
  // メモ用配列 (-1 は未計算であることを表す)
  int N;
  cin >> N;
  vector<long long> memo(N, -1);
  cout << fibo(N, memo) << endl;
}