#include <iostream>

using namespace std;

class TreeNode{
private:
  int data;         // 데이터
  int height;       // 높이
  TreeNode* right;  // 오른쪽 노드
  TreeNode* left;   // 왼쪽 노드

public:
  TreeNode(int value){
    data = value;
    height = 1;
    left = nullptr;
    right = nullptr;
  }

  int getData() { return data; }
  void setData(int d) { data = d; }

  TreeNode* GetLeftChild() { return left; }
  TreeNode* GetRightChild() { return right; }
  void SetLeftChild(TreeNode* child) { left = child; }
  void SetRightChild(TreeNode* child) { right = child; }

  int getHeight() { return height; }
  void setHeight(int h) { height = h; }
};