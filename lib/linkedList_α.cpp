#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include <iostream>
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
struct Node {
  Node *prev, *next;
  string name;
  Node(string name_ = "") : prev(NULL), next(NULL), name(name_) {}
};

Node* nil;

void init() {
  nil = new Node();
  nil->prev = nil;
  nil->next = nil;
}

void printList() {
  Node* cur = nil->next;
  while(cur != nil) {
    cout << cur->name << " ";
    cur = cur->next;
  }
}

void insert(Node* v, Node* p = nil) {
  v->next = p->next;
  p->next->prev = v;
  p->next = v;
  v->prev = p;
}

void erase(Node *v) {
  if(v == nil) return;
  v->prev->next = v->next;
  v->next->prev = v->prev;
  delete v;
}

int main() {
  init();
  vector<string> names = {"yamamoto", "watanabe", "ito", "takahashi", "suzuki", "sato"};
  Node *watanabe;
  rep(i,(int)names.size()) {
    Node* node = new Node(names[i]);
    insert(node);
    if(names[i] == "watanabe") watanabe = node;
  }
  printList();
  cout << endl;
  erase(watanabe);
  printList();
}

// 配列が苦手とする挿入・削除クエリに強くO(1)でできる. しかし検索クエリはO(N)