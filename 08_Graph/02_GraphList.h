// FRIDAYFREEBIE 티스토리 - 자료구조 포스팅 자료
// 그래프 (인접 리스트 버전) 헤더

#pragma once


#include "00_GraphNode.h"
#include<vector>
#include<iostream>

class GraphList{
private:
  int v;                         // 정점(노드) 개수
  std::vector<GraphNode*> nodes; // 인접 행렬

public:
  GraphList(int _v);                                    // 생성자
  // 인접 행렬은 vector로 구성되어 있어서 자동으로 메모리 관리가 됨
  // 하지만 인접 리스트는 GraphNode*로 직접 메모리 관리를 하기 때문에 소멸자가 필요함
  ~GraphList();                                         // 소멸자
  
  void addEdge(int _u, int _v, bool _directed = false); // 간선 추가
  void print();                                         // 프린트
};