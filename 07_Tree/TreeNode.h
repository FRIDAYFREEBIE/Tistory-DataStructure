#include <iostream>

using namespace std;

class TreeNode{
private:
  int data;         // ������
  TreeNode* right;  // ������ �ڽ� ���
  TreeNode* left;   // ���� �ڽ� ���

public:
  TreeNode(int value){
    data = value;
    left = nullptr;
    right = nullptr;
  }

  // ���� �ڽ� ��� ��ȯ
  TreeNode* GetLeftChild(){
    return left;
  }

  // ������ �ڽ� ��� ��ȯ
  TreeNode* GetRightChild(){
    return right;
  }

  // ���� �ڽ� ��� ����
  void SetLeftChild(TreeNode* child){
    left = child;
  }

  // ������ �ڽ� ��� ����
  void SetRightChild(TreeNode* child){
    right = child;
  }

  // ������ ��ȯ
  int getData(){
    return data;
  }

  void setData(int d){
    data = d;
  }
};