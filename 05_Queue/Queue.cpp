// FRIDAYFREEBIE 티스토리 - 자료구조 포스팅 자료
// 큐 클래스

#include <iostream>

using namespace std;

class Node {
public:
  int data;       // ������ ��
  Node* previous; // ���� ��带 ������ (ť�� ���� ���)

  Node(int d) {
    data = d;
    previous = nullptr;
  }
};

// ���� ����Ʈ ��� ť
class Queue {
public:
  Node* rear;   // ť�� ������ ��� (enqueue)
  Node* front;  // ť�� ù ��° ��� (dequeue)

  Queue(){
    rear = nullptr;
    front = nullptr;
  }

  // ������ ���� (�ڿ���)
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

  // ������ ���� (�տ���)
  void Dequeue(){
    if(front == nullptr) return;

    Node* temp = front;
    front = front->previous;

    if(front == nullptr) rear = nullptr;

    delete temp;
  }

  // front ���� ��ȯ
  Node* Peek(){
    return front;
  }

  // ��� �ִ��� Ȯ��
  bool isEmpty(){
    return front == nullptr && rear == nullptr;
  }

  // ��ü ���
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

  cout << "���� ����" << "\n";
  queue.Enqueue(10);
  queue.Enqueue(20);
  queue.Enqueue(30);
  queue.display();   // 10 20 30

  cout << "���� ����" << "\n";
  queue.Dequeue();
  queue.display();   // 20 30

  return 0;
}
