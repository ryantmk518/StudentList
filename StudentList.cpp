#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Student{
  char name[10];
  int id;
  float gpa;
};

void editStudent(Student* newPtr);

int main() {
  bool start = true;
  while (start == true) {
    char input[10];
    vector<Student*> stu;
    vector<Student*>* stuList = &stu;
    //vector<Student*>::iterator ptr = stu.begin();
    //cout << *ptr << endl;
    cout << "Enter a command" << endl;
    cin >> input;
    cin.get();
    if (strcmp(input, "ADD") == 0) {
      Student* ptrStu = new Student();
      cout << "Enter student info." << endl;
      editStudent(ptrStu);
      stu.push_back(ptrStu);
    }
    if (input == "HELP") {
      
    }
    if (input == "PRINT") {
    
    }
    if (input == "DELETE") {
      char del[10];
      cout<< "Enter name of student to delete" << endl;
      cin >> del;
    }
    if (input == "QUIT") {
      start = false;
      
    }
  }
}

void editStudent(Student* newPtr) {
  Student* ptrStu = new Student();
  cout << "Enter student info." << endl;
  cin >> newPtr->name;
  cin >> newPtr->id;
  cin >> newPtr->gpa;
}
