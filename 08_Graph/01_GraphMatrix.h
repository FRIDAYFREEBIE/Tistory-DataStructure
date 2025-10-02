// FRIDAYFREEBIE 티스토리 - 자료구조 포스팅 자료
// 그래프 (인접 행렬 버전) 헤더

#pragma once

#include<vector>
#include<iostream>
#include<queue>
#include<stack>

class GraphMatrix{
private:
  int v;                              // 정점(노드) 개수
  std::vector<std::vector<int>> adj;  // 인접 행렬

  void DFSUtil(int node, std::vector<bool>& visited); // DFS 재귀 유틸

public:
  GraphMatrix(int _v);                                  // 생성자
  
  void addEdge(int _u, int _v, bool directed = false);  // 간선 추가
  void print();                                         // 프린트

  void BFS(int start);                                  // 너비 우선 탐색
  void DFS(int start);                                  // 깊이 우선 탐색
};