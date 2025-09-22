// FRIDAYFREEBIE 티스토리 - 자료구조 포스팅 자료
// 동적 배열 클래슨

#include <iostream>

using namespace std;

class DynamicArray{
  private:
    int* data;  // �迭 ������
    int size;   // �뷮
    int length; // ��� ����

    // �뷮�� 2��� �ø��� �Լ�
    void resize(){
      cout << "resize() ȣ��" << "\n";

      // ���ο� �迭 ����
      int newSize = size * 2;
      int* newData = new int[newSize];
      
      // ���� ��� ����
      for(int i = 0; i < length; i++){
        newData[i] = data[i];
      }
      
      // ���� �迭 ����
      delete[] data;
      
      // �� �迭 �Ҵ�
      data = newData;
      size = newSize;
    }

  public:
    // ������
    DynamicArray(){
      size = 2;
      length = 0;
      data = new int[size];
    }

    // �Ҹ���
    ~DynamicArray(){
      delete[] data;
    }
    
    // �� �ڿ� �����͸� �߰��ϴ� �Լ�
    void push_back(int value){
      // �뷮 �˻�
      if(length == size)  resize();
      // �� �ڿ� ������ �߰�
      data[length++] = value;
    }
    
    // �ش� �ε����� ���� ��ȯ�ϴ� �Լ�
    int get(int index) const{
      // ���� �˻�
      if(index < 0 || index >= length) throw out_of_range("�ε����� ���� ����");

      return data[index];
    }

    // �迭 ũ�� ��ȯ �Լ�
    int getSize() const{
      return length;
    }
};

int main(){
  DynamicArray arr;

  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3); // �뷮 �ʰ��� resize() ȣ�� (�⺻ �뷮�� 2)
  // arr[] = {1, 2, 3}

  for(int i = 0; i < arr.getSize(); i++){
    cout << arr.get(i) << " ";
  }
  
  cout << "\n";

  return 0;
}