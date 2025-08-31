#include <iostream>

using namespace std;

class Node{
public:
  int data;   // 데이터
  Node* prev; // 이전 노드 포인터 (여기서는 앞쪽 노드 포인터)
  Node* next; // 다음 노드 포인터 (여기서는 뒤쪽 노드 포인터)

  Node(int d){
    data = d;
    prev = nullptr;
    next = nullptr;
  }
};

class Deque{
public:
  Node* front;  // 맨 앞 노드
  Node* back;   // 맨 뒤 노드

  Deque(){
    front = nullptr;
    back = nullptr;
  }

  // 앞에서 삽입
  void Push_Front(int val){
    Node* newNode = new Node(val);

    // 덱이 비어있을 때
    if(isEmpty()){
      front = newNode;
      back = newNode;
    }
    else{
      newNode->next = front;
      front->prev = newNode;
      front = newNode;
    }
  }

  // 뒤에서 삽입
  void Push_Back(int val){
    Node* newNode = new Node(val);

    // 덱이 비어있을 때
    if(isEmpty()){
      front = newNode;
      back = newNode;
    }
    else{
      newNode->prev = back;
      back->next = newNode;
      back = newNode;
    }
  }

  // 앞에서 삭제
  void Pop_Front(){
    if(isEmpty()) return;

    Node* temp = front;
    
    front = front->next;

    if(front == nullptr) back = nullptr;
    else front->prev = nullptr;

    delete temp;
  }

  // 뒤에서 삭제
  void Pop_Back(){
    if(isEmpty()) return;
    
    Node* temp = back;

    back = back->prev;

    if(back == nullptr) front = nullptr;
    else back->next = nullptr;
    
    delete temp;
  }

  // front 반환
  int Front(){
    if(isEmpty()) return -1;

    return front->data;
  }

  // back 반환
  int Back(){
    if(isEmpty()) return -1;

    return back->data;
  }
  
  // 비어있느지 확인
  bool isEmpty(){
    return front == nullptr;
  }

  // 전체 출력 (앞에서부터)
  void display(){
    Node* temp = front;
    while(temp != nullptr){
      cout << temp->data << " ";
      temp = temp ->next;
    }

    cout << "\n";
  }
};

int main(){
  Deque deque;

  cout << "삽입 연산 (앞)" << "\n";
  deque.Push_Front(2);
  deque.Push_Front(1);
  deque.display(); // 1 2

  cout << "삽입 연산 (뒤)" << "\n";
  deque.Push_Back(3);
  deque.display(); // 1 2 3

  cout << "삭제 연산 (앞)" << "\n";
  deque.Pop_Front();
  deque.display(); // 2 3

  cout << "삭제 연산 (뒤)" << "\n";
  deque.Pop_Back();
  deque.display(); // 2

  return 0;
}