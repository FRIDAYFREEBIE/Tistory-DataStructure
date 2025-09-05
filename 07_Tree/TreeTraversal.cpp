#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Tree{
private:
  TreeNode* root; // 루트 노드

public:
  Tree(TreeNode* r){
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

  TreeNode* GetRoot(){
    return root;
  }

  // 전위 순회: 루트 -> 왼쪽 -> 오른쪽
  void Preorder(TreeNode* node){
    cout << node->getData() << " ";

    // 재귀
    if(node->GetLeftChild() != nullptr){
      Preorder(node->GetLeftChild());
    }
    if(node->GetRightChild() != nullptr){
      Preorder(node->GetRightChild());
    }
  }

  // 중위 순회: 왼쪽 -> 루트 -> 오른쪽
  void Inorder(TreeNode* node){
    // 재귀
    if(node->GetLeftChild() != nullptr){
      Inorder(node->GetLeftChild());
    }

    cout << node->getData() << " ";

    // 재귀
    if(node->GetRightChild() != nullptr){
      Inorder(node->GetRightChild());
    }
  }

  // 후위 순회: 왼쪽 -> 오른쪽 -> 루트
  void Postorder(TreeNode* node){
    // 재귀
    if(node->GetLeftChild() != nullptr){
      Postorder(node->GetLeftChild());
    }
    if(node->GetRightChild() != nullptr){
      Postorder(node->GetRightChild());
    }
    
    cout << node->getData() << " ";
  }
};

int main(){
  TreeNode* root = new TreeNode(1);

  Tree tree(root);

  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(3);

  tree.AddNode(node1);
  tree.AddNode(node2);

  cout << "Preorder: ";
  tree.Preorder(tree.GetRoot());  // 1 2 3
  cout << "\n";

  cout << "Inorder: ";
  tree.Inorder(tree.GetRoot());  // 2 1 3
  cout << "\n";

  cout << "Postorder: ";
  tree.Postorder(tree.GetRoot());  // 2 3 1
  cout << "\n"; 

  TreeNode* node3 = new TreeNode(4);
  TreeNode* node4 = new TreeNode(5);

  tree.AddNode(node3);
  tree.AddNode(node4);
  
  cout << "Preorder: ";
  tree.Preorder(tree.GetRoot());  // 1 2 4
  cout << "\n";

  cout << "Inorder: ";
  tree.Inorder(tree.GetRoot());  // 2 4 5 1 3
  cout << "\n";

  cout << "Postorder: ";
  tree.Postorder(tree.GetRoot());  // 2 2 4 3 1
  cout << "\n"; 

  return 0;
}