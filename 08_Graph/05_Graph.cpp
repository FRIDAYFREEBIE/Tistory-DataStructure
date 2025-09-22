// FRIDAYFREEBIE 티스토리 - 자료구조 포스팅 자료
// 그래프 메인

#include "01_GraphMatrix.h"
#include "02_GraphList.h"

int main(){
  std::cout<< "\n" << "=== Matrix ===" << "\n";
  GraphMatrix gm(5);
  gm.addEdge(0, 1);
  gm.addEdge(0, 4);
  gm.addEdge(1, 2);
  gm.addEdge(1, 3);
  gm.addEdge(1, 4);
  gm.print();

  std::cout << "\n" << "=== List ===\n";
  GraphList gl(5);
  gl.addEdge(0, 1);
  gl.addEdge(0, 4);
  gl.addEdge(1, 2);
  gl.addEdge(1, 3);
  gl.addEdge(1, 4);
  gl.print();

  return 0;
}