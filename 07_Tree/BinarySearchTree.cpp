#include <iostream>
#include "TreeNode.h"

using namespace std;

class BinarySearchTree{
private:
  TreeNode* root; // 루트 노드

public:
  BinarySearchTree(TreeNode* r){
    root = r;
  }
  
  TreeNode* GetRoot(){
    return root;
  }
  
  // 탐색 (루트 노드, 값)
  TreeNode* Search(TreeNode* node, int value){
    if(node == nullptr){
      return nullptr;
    }

    if(value == node->getData()){
      return node;
    }
    // 재귀 탐색
    else if(value < node->getData()){
      return Search(root->GetLeftChild(), value);
    }
    else if(value > node->getData()){
      return Search(root->GetRightChild(), value);
    }

    return nullptr;
  }

  // 삽입 (루트 노드, 값)
  TreeNode* Insert(TreeNode* node, int value){
    if(node == nullptr){
      return new TreeNode(value);
    }
    
    // 재귀 탐색
    if(value < node->getData()){
      node->SetLeftChild(Insert(node->GetLeftChild(), value));
    }
    else if(value > node->getData()){
      node->SetRightChild(Insert(node->GetRightChild(), value));
    }

    return node;
  }

  // 삭제 (루트 노드, 값)
  TreeNode* Delete(TreeNode* node, int value){
    if(node == nullptr){
      return nullptr;
    }

    // 재귀 탐색
    if(value < node->getData()){
      node->SetLeftChild(Delete(node->GetLeftChild(), value));
    }
    else if(value > node->getData()){
      node->SetRightChild(Delete(node->GetRightChild(), value));
    }
    // 삭제
    else{
      // 자식이 없는 경우
      if(node->GetLeftChild() == nullptr && node->GetRightChild() == nullptr){
        delete node;
        return nullptr;
      }
      // 왼쪽 자식만 있는 경우
      else if(node->GetLeftChild() == nullptr){
        TreeNode* temp = node->GetRightChild();
        delete node;
        return temp;
      }
      // 오른쪽 자식만 있는 경우
      else if(node->GetRightChild() == nullptr){
        TreeNode* temp = node->GetLeftChild();
        delete node;
        return temp;
      }
      // 양쪽 다 자식이 있는 경우
      else{
        TreeNode* successorParent = node;

        // 오른쪽 서브트리의 가장 작은 노드
        TreeNode* successor = node->GetRightChild();

        while(successor->GetLeftChild() != nullptr){
          successorParent = successor;
          successor = successor->GetLeftChild();
        }
        
        // 기존 노드 교체
        node->setData(successor->getData());

        // 노드 삭제
        if(successorParent == node){
          successorParent->SetRightChild(Delete(successor, successor->getData()));
        }
        else{
          successorParent->SetLeftChild(Delete(successor, successor->getData()));
        }

        return node;
      }
    }

    return node;
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
};

int main(){
  TreeNode* root = new TreeNode(10);

  BinarySearchTree BST(root);

  BST.Insert(BST.GetRoot(), 5);
  BST.Insert(BST.GetRoot(), 10);
  BST.Insert(BST.GetRoot(), 15);
  BST.Insert(BST.GetRoot(), 3);
  BST.Insert(BST.GetRoot(), 7);
  BST.Insert(BST.GetRoot(), 13);
  BST.Insert(BST.GetRoot(), 17);

  BST.Inorder(BST.GetRoot()); // 3 5 7 10 13 15 17
  cout << "\n";

  BST.Delete(BST.GetRoot(), 3);
  BST.Delete(BST.GetRoot(), 15);

  BST.Inorder(BST.GetRoot()); // 5 7 10 13 17
  cout << "\n";

  return 0;
}