//min(x,y)が0以下の場合はmax(x,y)が返される
//ユークリッドの互除法を元に実装→計算量O(logN)
long long gcd(long long x,long long y){
  if(x<y) swap(x,y);
  //xの方が常に大きい
  long long r;
  while(y>0){
    r=x%y;
    x=y;
    y=r;
  }
  return x;
}

//オーバフローしないようにかける順番を気を付ける
long long lcm(long long x,long long y){
  return long long(x/gcd(x,y))*y;
}

// こんな感じの再帰関数でも書ける
long long GCD(long long x, long long y) {
  if(y == 0) return x;
  return GCD(y, x % y);
}