#include "Student.h"
#include "Node.h"
#include <iostream>

using namespace std;

Node* Node::getNext(){
  return next;
}

Student* Node:: getStudent(){
  return studentPtr;
}
void Node:: setNext(Node* current){
  next = current;
  cout<<"hasSetNext"<<endl;
}
Node::Node(Student* student){
  int age;
  cout<<"What is the students age?"<<endl;
  cin>>age;
  student->setAge(age);
  studentPtr=student;//sets the studentptr in the Node equal to the new student
  
}
Node::~Node(){
  delete studentPtr;
}
