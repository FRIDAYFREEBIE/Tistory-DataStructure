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

// 너비 우선 탐색
void GraphMatrix::BFS(int start){
  std::vector<bool> visited(v, false); // 방문
  std::queue<int> q;                   // 큐

  // 시작 정점에 방문 표시를 하고 큐에 넣음
  visited[start] = true;
  q.push(start);

  // 큐가 비었다면 모든 정점을 탐색한 것
  while(!q.empty()){
    // 현재 탐색 할 정점
    int current = q.front();
    q.pop();

    std::cout << current << " ";
    
    // 인접한 모든 정점 탐색
    for(int i = 0; i < v; i++){
      // 현재 정점과 연결되어 있고 방문한 적 없을 때
      if(adj[current][i] == 1 && !visited[i]){
        // 방문 표시를 하고 큐에 넣음
        visited[i] = true;
        q.push(i);
      }
    }
  }

  std::cout << "\n";
}