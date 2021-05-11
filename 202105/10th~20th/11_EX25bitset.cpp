#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

// 集合Sの内容を昇順で出力する(スペース区切りで各要素の値を出力する)
void print_set(bitset<50> S) {
  vector<int> cont;
  for (int i = 0; i < 50; i++) {
    if (S.test(i)) {
      cont.push_back(i);
    }
  }
  for (int i = 0; i < cont.size(); i++) {
    if (i > 0) cout << " ";
    cout << cont.at(i);
  }
  cout << endl;
}

int main() {
  int N, M;
  bitset<50> A, B;
  cin >> N;
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.set(a, 1);
  }
  cin >> M;
  int count_B = 0;
  for(int i = 0; i < M; i++) {
    int b;
    cin >> b;
    B.set(b, 1);
  }
  string command;
  cin >> command;

  if(command == "intersection") {
    print_set(B&A);
  } else if(command == "union_set") {
    print_set(B|A);
  } else if(command == "symmetric_diff") {
    print_set(B^A);
  } else if(command == "subtract") {
    int x;
    cin >> x;
    A.set(x, 0);
    print_set(A);
  } else if(command == "increment") {
    bitset<50> ret = A << 1;
    if(A.test(49)) ret.set(0, 1);
    print_set(ret);
  } else if(command == "decrement") {
    bitset<50> ret = A >> 1;
    if(A.test(0)) ret.set(49, 1);
    print_set(ret);
  }


  return 0;
}