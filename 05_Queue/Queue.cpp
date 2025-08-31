#include <iostream>
using namespace std;

class Node {
public:
  int data;       // 데이터 값
  Node* previous; // 이전 노드를 포인터 (큐의 다음 노드)

  Node(int d) {
    data = d;
    previous = nullptr;
  }
};

// 연결 리스트 기반 큐
class Queue {
public:
  Node* rear;   // 큐의 마지막 노드 (enqueue)
  Node* front;  // 큐의 첫 번째 노드 (dequeue)

  Queue(){
    rear = nullptr;
    front = nullptr;
  }

  // 데이터 삽입 (뒤에서)
  void Enqueue(int item){
    Node* newNode = new Node(item);

    if(rear == nullptr && front == nullptr){
      rear = newNode;
      front = newNode;
    }
    else{
      Node* temp = rear;
      rear = newNode;
      temp->previous = newNode;
    }
  }

  // 데이터 삭제 (앞에서)
  void Dequeue(){
    if(front == nullptr) return;

    Node* temp = front;
    front = front->previous;

    if(front == nullptr) rear = nullptr;

    delete temp;
  }

  // front 값을 반환
  Node* Peek(){
    return front;
  }

  // 비어 있는지 확인
  bool isEmpty(){
    return front == nullptr && rear == nullptr;
  }

  // 전체 출력
  void display(){
    Node* temp = front;
    while(temp != nullptr){
      cout << temp->data << " ";
      temp = temp->previous;
    }
    cout << "\n";
  }
};

int main() {
  Queue queue;

  cout << "삽입 연산" << "\n";
  queue.Enqueue(10);
  queue.Enqueue(20);
  queue.Enqueue(30);
  queue.display();   // 10 20 30

  cout << "삭제 연산" << "\n";
  queue.Dequeue();
  queue.display();   // 20 30

  return 0;
}
