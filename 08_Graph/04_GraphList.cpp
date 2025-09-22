// FRIDAYFREEBIE 티스토리 - 자료구조 포스팅 자료
// 그래프 (인접 리스트 버전) 클래스

#include "02_GraphList.h"

// 생성자
GraphList::GraphList(int _v) {
  v = _v;
  for(int i = 0; i < v; i++) {
    nodes.push_back(new GraphNode(i));
  }
}

// 소멸자
GraphList::~GraphList() {
  for(auto n : nodes) delete n;
}

// 간선 추가
void GraphList::addEdge(int _u, int _v, bool _directed) {
  nodes[_u]->addNeighbors(_v);
  if (!_directed) nodes[_v]->addNeighbors(_u);
}

void GraphList::print() {
  for(int i = 0; i < v; i++) {
    std::cout << i << " -> ";
    for (int nb : nodes[i]->neighbors) {
      std::cout << nb << " ";
    }
    std::cout << "\n";
  }
}