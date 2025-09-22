// FRIDAYFREEBIE 티스토리 - 자료구조 포스팅 자료
// 연결리스트 클래스

#include <iostream>

using namespace std;

struct Node
{
  int data;   // 데이터
  Node* next; // 다음 노드 주소

  Node(int value){
    data = value;
    next = nullptr;
  }
};

class LinkedList{
  private:
    Node* head; // 시작 노드

  public:
    LinkedList(){
      head = nullptr;
    }
    
    // 데이터 삽입 (앞에서)
    void push(int value){
      Node* newNode = new Node(value);

      // 현재 헤드 노드를 다음 노드로 설정
      newNode->next = head;
      
      // 헤드 노드 갱신
      head = newNode;
    }
    
    // 데이터 삭제 (앞에서)
    void pop(){
      if(head == nullptr) return;
      
      Node* current = head;
      
      // 헤드 노드를 다음 노드로 갱신
      head = current->next;

      // 기존 헤드 노드 삭제
      delete current;
    }
    
    // 전체 출력
    void print(){
      Node* current = head;

      while(current != nullptr){
        cout << current->data << "->";
        current = current->next;
      }

      cout << "null \n";
    }
};

int main(){
  LinkedList list;

  list.push(30);
  list.push(20);
  list.push(10);

  // 10 -> 20 -> 30 -> null
  list.print();

  list.pop();

  // 20 -> 30 -> null
  list.print();

  return 0;
}