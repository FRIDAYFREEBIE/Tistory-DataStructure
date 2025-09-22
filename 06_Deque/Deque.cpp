// FRIDAYFREEBIE 티스토리 - 자료구조 포스팅 자료
// 덱 클래스

#include <iostream>

using namespace std;

class Node{
public:
  int data;   // ������
  Node* prev; // ���� ��� ������ (���⼭�� ���� ��� ������)
  Node* next; // ���� ��� ������ (���⼭�� ���� ��� ������)

  Node(int d){
    data = d;
    prev = nullptr;
    next = nullptr;
  }
};

class Deque{
public:
  Node* front;  // �� �� ���
  Node* back;   // �� �� ���

  Deque(){
    front = nullptr;
    back = nullptr;
  }

  // �տ��� ����
  void Push_Front(int val){
    Node* newNode = new Node(val);

    // ���� ������� ��
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

  // �ڿ��� ����
  void Push_Back(int val){
    Node* newNode = new Node(val);

    // ���� ������� ��
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

  // �տ��� ����
  void Pop_Front(){
    if(isEmpty()) return;

    Node* temp = front;
    
    front = front->next;

    if(front == nullptr) back = nullptr;
    else front->prev = nullptr;

    delete temp;
  }

  // �ڿ��� ����
  void Pop_Back(){
    if(isEmpty()) return;
    
    Node* temp = back;

    back = back->prev;

    if(back == nullptr) front = nullptr;
    else back->next = nullptr;
    
    delete temp;
  }

  // front ��ȯ
  int Front(){
    if(isEmpty()) return -1;

    return front->data;
  }

  // back ��ȯ
  int Back(){
    if(isEmpty()) return -1;

    return back->data;
  }
  
  // ����ִ��� Ȯ��
  bool isEmpty(){
    return front == nullptr;
  }

  // ��ü ��� (�տ�������)
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

  cout << "���� ���� (��)" << "\n";
  deque.Push_Front(2);
  deque.Push_Front(1);
  deque.display(); // 1 2

  cout << "���� ���� (��)" << "\n";
  deque.Push_Back(3);
  deque.display(); // 1 2 3

  cout << "���� ���� (��)" << "\n";
  deque.Pop_Front();
  deque.display(); // 2 3

  cout << "���� ���� (��)" << "\n";
  deque.Pop_Back();
  deque.display(); // 2

  return 0;
}