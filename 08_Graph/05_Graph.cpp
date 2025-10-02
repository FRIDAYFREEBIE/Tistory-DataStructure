// FRIDAYFREEBIE 티스토리 - 자료구조 포스팅 자료
// 그래프 메인

#include "01_GraphMatrix.h"
#include "02_GraphList.h"

int main(){
  GraphMatrix gm(6);

  gm.addEdge(0, 1);
  gm.addEdge(0, 4);
  gm.addEdge(1, 2);
  gm.addEdge(1, 3);
  gm.addEdge(4, 5);

  std::cout<< "\n" << "=== Matrix ===" << "\n";
  gm.print();

  std::cout<< "\n" << "==== DFS ====" << "\n";
  gm.DFS(0);

  return 0;
}