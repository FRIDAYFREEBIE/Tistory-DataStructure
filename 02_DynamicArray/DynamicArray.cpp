#include <iostream>

using namespace std;

class DynamicArray{
  private:
    int* data;  // 배열 포인터
    int size;   // 용량
    int length; // 요소 갯수

    // 용량을 2배로 늘리는 함수
    void resize(){
      cout << "resize() 호출" << "\n";

      // 새로운 배열 생성
      int newSize = size * 2;
      int* newData = new int[newSize];
      
      // 기존 요소 복사
      for(int i = 0; i < length; i++){
        newData[i] = data[i];
      }
      
      // 기존 배열 삭제
      delete[] data;
      
      // 새 배열 할당
      data = newData;
      size = newSize;
    }

  public:
    // 생성자
    DynamicArray(){
      size = 2;
      length = 0;
      data = new int[size];
    }

    // 소멸자
    ~DynamicArray(){
      delete[] data;
    }
    
    // 맨 뒤에 데이터를 추가하는 함수
    void push_back(int value){
      // 용량 검사
      if(length == size)  resize();
      // 맨 뒤에 데이터 추가
      data[length++] = value;
    }
    
    // 해당 인덱스의 값을 반환하는 함수
    int get(int index) const{
      // 범위 검사
      if(index < 0 || index >= length) throw out_of_range("인덱스가 범위 밖임");

      return data[index];
    }

    // 배열 크기 반환 함수
    int getSize() const{
      return length;
    }
};

int main(){
  DynamicArray arr;

  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3); // 용량 초과로 resize() 호출 (기본 용량이 2)
  // arr[] = {1, 2, 3}

  for(int i = 0; i < arr.getSize(); i++){
    cout << arr.get(i) << " ";
  }
  
  cout << "\n";

  return 0;
}