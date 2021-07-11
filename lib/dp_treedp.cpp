const int MAX_V = 2100;  // ツリーのサイズのありうる最大値

int N;  // ツリーのサイズ
vector<int> tree[MAX_V];  // ツリーを隣接リスト形式のグラフ構造で表したもの

int sizeSubtree[MAX_V];  // sizeSubtree[v] := v を根とする部分ツリーのサイズ
vector<int> centroids;  // 重心列挙の答えがここに入る

/* ツリーDP */
void SubFindCentroids(int v, int parent_of_v = -1) {
  sizeSubtree[v] = 1;
  bool isCentroid = true;
  for (auto ch : tree[v]) {
    if (ch == parent_of_v) continue;
    SubFindCentroids(ch, v);
    if (sizeSubtree[ch] > N / 2) isCentroid = false;
    sizeSubtree[v] += sizeSubtree[ch];
  }
  if (N - sizeSubtree[v] > N / 2) isCentroid = false;
  if (isCentroid) centroids.push_back(v);
}

void FindCentroids() {
  centroids.clear();
  SubFindCentroids(0, N); // これを呼び出すと centoroids に重心を列挙したものが入る
}

// https://qiita.com/drken/items/4b4c3f1824339b090202