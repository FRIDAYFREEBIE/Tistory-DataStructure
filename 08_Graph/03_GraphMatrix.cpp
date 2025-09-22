// FRIDAYFREEBIE 티스토리 - 자료구조 포스팅 자료
// 그래프 (인접 행렬 버전) 클래스

#include "01_GraphMatrix.h"

// 생성자
GraphMatrix::GraphMatrix(int _v) {
  v = _v;
  adj = std::vector<std::vector<int>>(v, std::vector<int>(v, 0));
}

// 간선 추가
void GraphMatrix::addEdge(int _u, int _v, bool _directed) {
  adj[_u][_v] = 1;
  if (!_directed) adj[_v][_u] = 1;
}

// 프린트
void GraphMatrix::print() {
  for(int i = 0; i < v; i++) {
    for(int j = 0; j < v; j++) {
      std::cout << adj[i][j] << " ";
    }
    std::cout << "\n";
  }
}