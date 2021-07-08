#include <iostream>
#include <bitset>
using namespace std;

const int INF = 100000000; // 十分大きな値

int rec(int l,int r){
  //既に計算済み？
  if(dp[l][r] != -1) return dp[l][r];

  //これ以上取り除けない？
  if(abs(l - r) <= 1) return 0;

  int res = 0;
  //パターン1.
  if(abs(w[l] - w[r - 1]) <= 1 && rec(l + 1,r - 1) == r - l - 2)
  {
    //[l , r)がはじき出せるので
    res = r - l;
  }

  //パターン２.区間を分ける
  for(int mid = l + 1;mid <= r - 1;mid++)
  {
    res = max(res , rec(l,mid) + rec(mid,r));
  }
  return dp[l][r] = res;
};

// wに値を入れて、dpを-1に初期化
// 探索して、dp[L][R]を出力

