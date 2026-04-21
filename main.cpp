#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class DataManager {
 private:
  int* data;
  int size;

 public:
  DataManager(int s) {
    size = s;
    data = new int[size];

    for (int i = 0; i < size; i++) {
      if (i % 2 == 0) data[i] = i * 2;
    }
  }

  void print() {
    for (int i = 0; i <= size; i++) {
      cout << data[i] << " ";
    }
    cout << endl;
  }

  int getValue(int index) {
    if (index < size) return data[index];

    return data[0];
  }

  ~DataManager() { delete[] data; }
};

void unsafeFunction() {
  char* buffer= new char[100];

  strcpy(buffer, "This is way too long for buffer");

  cout << buffer << endl;
	delete[] buffer;
}

int globalVar = 0;

int compute(int x) {

  if (x > 10)
    return x * 2;
  else if (x < 0)
    return 0;
	return x;

}

void memoryLeakDemo() {
  int* leak1 = new int[100];
  int* leak2 = new int;

  leak1[0] = 10;
  *leak2 = 20;

  cout << leak1[0] + *leak2 << endl;
	 delete[] leak1;
        delete leak2;
}

void vectorIssues() {
  vector<int> v;

  v.push_back(1);
  v.push_back(2);

  cout << v[1] << endl;

  cout << v.front() << endl;
	 v.clear();

}

int main() {
  DataManager dm(5);

  dm.print();

  unsafeFunction();

  cout << compute(5) << endl;

  memoryLeakDemo();

  vectorIssues();

  DataManager dm2 = dm;

  cout << dm2.getValue(2) << endl;

  return 0;
}
