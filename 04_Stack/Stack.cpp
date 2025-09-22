// FRIDAYFREEBIE 티스토리 - 자료구조 포스팅 자료
// 스택 클래스

#include <iostream>

using namespace std;

class Node {
public:
  int data;   // 데이터
  Node* next; // 다음 노드 포인터

  Node(int d) {
    data = d;
    next = nullptr;
  }
};

// 연결 리스트 기반 스택
class Stack {
public:
  Node* top; // 스택의 맨 위

  Stack(){
    top = nullptr;
  }

  // 데이터 삽입 (위에서)
  void Push(int item){
    Node* newNode = new Node(item);
    newNode->next = top;
    top = newNode;
  }

  // 데이터 삭제
  void Pop(){
    if(top == nullptr) return;

    Node* temp = top;
    top = top->next;

    delete temp;
  }

  // top 값을 반환
  int Peek(){
    if (top == nullptr) return -1; // 스택이 비어 있으면 -1 반환

    return top->data;
  }

  // 비어 있는지 확인
  bool isEmpty(){
    return top == nullptr;
  }

  // 전체 출력
  void display(){
    if(top == nullptr) return;

    Node* temp = top;
    while(temp != nullptr){
      cout << temp->data << " ";
      temp = temp->next;
    }

    cout << endl;
  }
};

int main() {
  Stack stack;

  cout << "삽입 연산" << endl;
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  stack.Push(4);
  stack.Push(5);

  stack.display(); // 5 4 3 2 1

  cout << "삭제 연산" << endl;
  stack.Pop();
  stack.display(); // 4 3 2 1

  return 0;
}
