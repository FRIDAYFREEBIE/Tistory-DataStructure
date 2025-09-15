#include <iostream>
#include <queue>
#include "00_TreeNode.h"

using namespace std;

class BinaryTree{
private:
  TreeNode* root; // 루트 노드

public:
  BinaryTree(TreeNode* r){
    root = r;
  }

  // 노드 동적 추가
  void AddNode(TreeNode* node){
    queue<TreeNode*> treeQueue;
    treeQueue.push(root);

    while(!treeQueue.empty()){
      TreeNode* current = treeQueue.front();
      treeQueue.pop();

      if(current->GetLeftChild() == nullptr){
        current->SetLeftChild(node);
        return;
      }
      else if(current->GetRightChild() == nullptr){
        current->SetRightChild(node);
        return;
      }
      else{
        treeQueue.push(current->GetLeftChild());
        treeQueue.push(current->GetRightChild());
      }
    }
  }

  // 트리 출력
  void Display(){
    queue<TreeNode*> treeQueue;
    treeQueue.push(root);

    while(!treeQueue.empty()){
      cout << treeQueue.front()->getData() << "\n";

      if(treeQueue.front()->GetLeftChild() != nullptr){
        treeQueue.push(treeQueue.front()->GetLeftChild());
      }
      if(treeQueue.front()->GetRightChild() != nullptr){
        treeQueue.push(treeQueue.front()->GetRightChild());
      }

      treeQueue.pop();
    }
  }
};

int main(){
  TreeNode* root = new TreeNode(1);

  BinaryTree binaryTree(root);

  TreeNode* newNode1 = new TreeNode(2);
  TreeNode* newNode2 = new TreeNode(3);
  binaryTree.AddNode(newNode1);
  binaryTree.AddNode(newNode2);

  binaryTree.Display();

  return 0;
}