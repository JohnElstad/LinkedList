#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;
//John Elstad- This is a linked List program- 1/6/17
int main(){

  cout<<"Linked List"<<endl;
  bool running = true;
  Node* head = NULL;
  Node* current = NULL;
  while(running==true){
    cout<<"ADD, PRINTALL, QUIT and DELETE are valid commands"<<endl;
    char input[100];
    cin>>input;
    if(strcmp(input,"ADD")==0){
      Student* student = new Student;//creates a student and stdntPtr
      
      if(head == NULL){//if there are no students
	Node* N = new Node(student);
	head = N;

      }
      else{
	Node* N = new Node(student);
	Node* temp = head;
	head=N;
	head->setNext(temp);
      }
    }
    else if(strcmp(input,"PRINTALL")==0){
      current = head;
      cout<<"PRINTING"<<endl;
      
      while(current!=NULL){
	cout<<"TEST(inWhile)"<<endl;
	cout<<(current->getStudent())->getAge()<<endl;
	current = current->getNext();
      }
    }
    else if(strcmp(input,"DELETE")==0){
      Node* previous=NULL;
      cout<<"What age of student do you want to delete?"<<endl;
      int ageinput;
      cin>>ageinput;
      current = head;
      while(current!=NULL){
	if(ageinput==current->getStudent()->getAge()){
	  if(previous==NULL){
	    current=head;
	    Node* temp;
	    temp = current;
	    current=current->getNext();
	    delete temp;
	  }
	  else{
	    previous->setNext(current->getNext());
	    delete current;
	    
	  }
	}
	else{
	  previous = current;
	  current = current->getNext();
	  
	}
      }
    }
    else if(strcmp(input,"QUIT")==0){
      cout<<"QUITTING"<<endl;
      running=false;
    }
    else{
      cout<<"PRINTALL DELETE ADD QUIT"<<endl;
    }
  }
}
