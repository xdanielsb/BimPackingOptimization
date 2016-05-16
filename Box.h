#include <stdio.h>


using namespace std;

class Box{
    boxes * objetos;
    public:
        Box();
        void add(int val);
		void show();
		boxes* getElement();
		boxes* getHead();
		void setHead();
		bool cabe(int, int);
};

Box::Box(){
    objetos = NULL;
}

void Box::add(int val){
    boxes *elem= new boxes();
    elem->v =val;
    elem -> siguiente = objetos;
    objetos = elem;
}	

void Box::show(){
	boxes *head= objetos;
	while(head!=NULL){
		int val = head->v;
		printf("%i ",val);
		head= head->siguiente;
	}
	printf("\n");
}
//if the element fits in the box or bin. 
bool Box::cabe(int peso, int SIZE_BIN){
	boxes *head= objetos;
//	printf("peso =%i, size_bin=%i\n",peso,SIZE_BIN);
	while(head!=NULL){
		int val = head->v;
		if((SIZE_BIN-val)>=peso){ //Si cabe?
			head->v =val+peso; 
			//printf("true");
			return true;
		}
		head= head->siguiente;
	}
	return false;
}

boxes* Box::getHead(){
	return objetos;
}

void Box::setHead(){
	objetos=NULL;
}




