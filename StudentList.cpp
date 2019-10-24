#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

//StudentList. Ryan Thammakhoune. 

struct Student{
  char fname[10];
  char lname[10];
  int id;
  float gpa;
};

void editStudent(vector<Student*>* stuList);

int main() {
  bool start = true;
  vector<Student*> stu;
  vector<Student*>* stuList = &stu;
  while (start == true) {
    char input[10];
    cout << "Enter a command" << endl;
    cin >> input;
    cin.get();
    if (strcmp(input, "ADD") == 0) {
      editStudent(stuList);
    }
    if (strcmp(input, "HELP") == 0) {
      cout << "Type ADD to add a student\nType PRINT to print list\nType DELETE to delete student\nType QUIT to quit" << endl; 
    }
    if (strcmp(input, "PRINT") == 0) {
      vector<Student*> :: iterator ptr = stuList->begin();
      for (;ptr != stuList->end(); ++ptr) {
	cout << (*ptr) -> fname << " " << (*ptr) -> lname << ", "<< (*ptr) -> id << ", "<< (*ptr) -> gpa << endl;
      }
    }
    if (strcmp(input, "DELETE") == 0) {
      int del;
      cout<< "Enter id of student to delete" << endl;
      cin >> del;
      vector<Student*> :: iterator ptr = stuList->begin();
      for (;ptr != stuList->end(); ++ptr) {
	if (del == (*ptr) -> id) {
	  //delete (*ptr);
	  stuList -> erase(ptr);
	}
      }
    }
    if (strcmp(input, "QUIT") == 0) {
      start = false;
      
    }
  }
}

void editStudent(vector<Student*>* stuList) {
  Student* ptrStu = new Student();
  cout << "Enter student first name" << endl;
  cin >> ptrStu->fname;
  cout << "Enter student last name" << endl;
  cin >> ptrStu->lname;
  cout << "Enter student id" << endl;
  cin >> ptrStu->id;
  cout << "Enter student gpa" << endl;
  cin >> ptrStu->gpa;
  stuList->push_back(ptrStu);
}
