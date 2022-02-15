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
struct Node {
  Node *prev, *next;
  int key;
  Node(int key) : prev(NULL), next(NULL), key(key) {}
};

int main() {
  int N, Q; cin >> N >> Q;
  Node* nil;
  nil = new Node(-1);
  vector<Node*> vec(N);
  rep(i,N) {
    Node* node = new Node(i);
    node->prev = nil;
    node->next = nil;
    vec[i] = node;
  }
  vector<int> a(N);
  rep(i,N) cin >> a[i], a[i]--;
  rep(i,N) {
    if(i > 0) vec[a[i]]->prev = vec[a[i-1]];
    if(i < N-1) vec[a[i]]->next = vec[a[i+1]];
  }
  Node* head = new Node(-2);
  Node* tail = new Node(-2);
  head->next = vec[a[0]];
  tail->next = vec[a[N-1]];
  rep(i,Q) {
    int q; cin >> q; q--;
    if(vec[q]->prev == nil) {  // 先頭だったとき
      Node* next_node = vec[q]->next;
      next_node->prev = nil;
      Node* tail_node = tail->next;
      tail_node->next = vec[q];
      vec[q]->prev = tail_node;
      vec[q]->next = nil;
      head->next = next_node;
      tail->next = vec[q];
    } else if(vec[q]->next == nil) {  // 末尾だったとき
      Node* prev_node = vec[q]->prev;
      prev_node->next = nil;
      Node* head_node = head->next;
      head_node->prev = vec[q];
      vec[q]->prev = nil;
      vec[q]->next = head_node;
      head->next = vec[q];
      tail->next = prev_node;
    } else {  // それ以外
      Node* prev_node = vec[q]->prev;
      Node* next_node = vec[q]->next;
      prev_node->next = nil;
      next_node->prev = nil;
      Node* head_node = head->next;
      Node* tail_node = tail->next;
      head_node->prev = vec[q];
      tail_node->next = vec[q];
      vec[q]->prev = tail_node;
      vec[q]->next = head_node;
      head->next = next_node;
      tail->next = prev_node;
    }
  }
  head = head->next;
  while(head != nil) {
    cout << head->key + 1;
    head = head->next;
    if(head != nil) cout << " ";
  }
  cout << endl;
  return 0;
}

// head, tailを使ったから、nilの番兵はいらなかった
// https://drken1215.hatenablog.com/entry/2018/09/21/202000