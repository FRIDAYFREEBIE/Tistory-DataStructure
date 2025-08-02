#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 100; // 해시테이블 크기

// 해시테이블 구조체
struct HashItem{
  string key;
  int value;
};

int hashFunction(const string& key);
void insert(const string& key, int value);
int get(const string& key);

HashItem* hashTable[TABLE_SIZE]; // 해시테이블

int main(){
  insert("A", 1);
  insert("B", 2);
  
  cout << "A: " << get("A") << "\n";
  cout << "B: " << get("B") << "\n";
}

// 해시 함수
int hashFunction(const string& key){
  int hash = 0;

  for(char c : key){
    hash = (hash * 31 + c) % TABLE_SIZE;
    // 단순히 각 문자의 아스키 값을 더하면 충돌이 발생할 수 있다 EX) "ABC", "CBA"
    // 곱하기를 통해 문자 순서에 따라 다른 값이 나오게 한다.
    // 31을 사용한 이유는 작은 소수이기 때문
  }

  return hash;
}

// 삽입 함수
void insert(const string& key, int value){
  int index = hashFunction(key);
  hashTable[index] = new HashItem{key, value};
}

// 탐색 함수
int get(const string& key){
  int index = hashFunction(key);
  
  if(hashTable[index] != nullptr && hashTable[index]->key == key){
    return hashTable[index]->value;
  }

  return -1; // 값이 존재하지 않을 때
}