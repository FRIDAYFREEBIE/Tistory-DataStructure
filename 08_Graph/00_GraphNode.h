// FRIDAYFREEBIE 티스토리 - 자료구조 포스팅 자료
// 그래프 노드 헤더

#pragma once

#include <vector>

class GraphNode{
public:
  int id;
  std::vector<int> neighbors;  // 인접 리스트 버전에서 사용

  GraphNode(int _id){
    id = _id;
  }

  // 인접 노드(id) 추가
  void addNeighbors(int v){
    neighbors.push_back(v);
  }
};