#include <iostream>
#include <vector>
using namespace std;

vector<int> buf;

void dfs(int i, const int size, const int range_start, const int range_end)
{
  if (i == size) {
    // ここで所望の作業を行う
    for(int i = 0; i < buf.size(); ++i){
      cout << buf[i] << " ";
    }
    cout << endl;
  }
  else{
    for(int j = range_start; j <= range_end; ++j){
      buf[i] = j;
      dfs(i + 1, size, range_start, range_end);
    }
  }
}

int main(void)
{
  // 1〜5の数字を使ってできる3桁の数字を全列挙することを考える
  int size = 3;
  int range_start = 1;
  int range_end = 5;

  buf.resize(size);
  dfs(0, size, range_start, range_end);

  return 0;
}

// dfsを使った全探索
// 今回は重複順列で考えて、広義単調増加の制約があるからぎり間に合う
// https://blog.hamayanhamayan.com/entry/2020/05/02/225726