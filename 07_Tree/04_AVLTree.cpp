#include <iostream>
#include "00_TreeNode.h"

using namespace std;

class AVLTree{
private:
  TreeNode* root; // 루트 노드

  // 높이 반환
  int getHeight(TreeNode* node) { return node ? node->getHeight() : 0; }

  // BF 반환
  int getBalance(TreeNode* node){
    if(node == nullptr) return 0;
    return getHeight(node->GetLeftChild()) - getHeight(node->GetRightChild());
  }

  // 높이 갱신
  void updateHeight(TreeNode* node){
    if(node == nullptr) return;

    int lh = getHeight(node->GetLeftChild());
    int rh = getHeight(node->GetRightChild());
    node->setHeight(1 + max(lh, rh));
  }

  // ===== 회전 함수 =====

  // LL
  TreeNode* rotateRight(TreeNode* node){
    TreeNode* l = node->GetLeftChild();
    TreeNode* r = l->GetRightChild();

    l->SetRightChild(node);
    node->SetLeftChild(r);

    updateHeight(node);
    updateHeight(l);

    return l;
  }

  // RR
  TreeNode* rotateLeft(TreeNode* node){
    TreeNode* r = node->GetRightChild();
    TreeNode* l = r->GetLeftChild();

    r->SetLeftChild(node);
    node->SetRightChild(l);

    updateHeight(node);
    updateHeight(r);

    return r;
  }

  // LR
  TreeNode* rotateLeftRight(TreeNode* node){
    node->SetLeftChild(rotateLeft(node->GetLeftChild()));
    return rotateRight(node);
  }
  
  // RL
  TreeNode* rotateRightLeft(TreeNode* node){
    node->SetRightChild(rotateRight(node->GetRightChild()));
    return rotateLeft(node);
  }

  // ===== 삽입 =====
  TreeNode* insertNode(TreeNode* node, int value){
    if(node == nullptr) return new TreeNode(value);
    
    // 삽입 위치 탐색
    if(value < node->getData()) node->SetLeftChild(insertNode(node->GetLeftChild(), value));
    else if (value > node->getData()) node->SetRightChild(insertNode(node->GetRightChild(), value));
    else return node;

    updateHeight(node);
    
    // 균형 맞추기
    int balance = getBalance(node);
    if (balance > 1 && value < node->GetLeftChild()->getData()) return rotateRight(node);
    if (balance < -1 && value > node->GetRightChild()->getData()) return rotateLeft(node);
    if (balance > 1 && value > node->GetLeftChild()->getData()) return rotateLeftRight(node);
    if (balance < -1 && value < node->GetRightChild()->getData()) return rotateRightLeft(node);
    return node;
  }

public:
  AVLTree() { root = nullptr; }
  TreeNode* GetRoot() { return root; }

  void Insert(int value) { root = insertNode(root, value); }

  // 순회
  void Inorder(TreeNode* node){
    if(node == nullptr) return;

    Inorder(node->GetLeftChild());
    cout << node->getData() << " ";
    Inorder(node->GetRightChild());
  }
};

int main(){
  AVLTree avl;

  avl.Insert(30);
  avl.Insert(20);
  avl.Insert(25); // LR

  avl.Inorder(avl.GetRoot()); // 20 25 30
  cout << "\n";

  return 0;
}