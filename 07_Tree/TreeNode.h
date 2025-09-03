#include <iostream>

using namespace std;

class TreeNode{
private:
  int data;         // 데이터
  TreeNode* right;  // 오른쪽 자식 노드
  TreeNode* left;   // 왼쪽 자식 노드

public:
  TreeNode(int value){
    data = value;
    left = nullptr;
    right = nullptr;
  }

  // 왼쪽 자식 노드 반환
  TreeNode* GetLeftChild(){
    return left;
  }

  // 오른쪽 자식 노드 반환
  TreeNode* GetRightChild(){
    return right;
  }

  // 왼쪽 자식 노드 설정
  void SetLeftChild(TreeNode* child){
    left = child;
  }

  // 오른쪽 자식 노드 설정
  void SetRightChild(TreeNode* child){
    right = child;
  }

  // 데이터 반환
  int getData(){
    return data;
  }
};