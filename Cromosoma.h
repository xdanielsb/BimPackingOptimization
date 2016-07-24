#include <stdio.h>
#include "element.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Box.h"

using namespace std;

class Cromosoma{
    element * elements;
    
    public:
        Cromosoma();
        void add(int val);
		void show(element*);
		element* createCromosoma(int, int);
		void setElements(element*);
		int getfactor(int,int,element*);		
		element* getElement();

};
//Constructor
Cromosoma::Cromosoma(){
    elements = NULL;
}


//Add gen to the cromosome
void Cromosoma::add(int val){
    element *elem= new element();
    elem->value =val;
    elem -> siguiente = elements;
    elements = elem;

}	


//Show the cromosome
void Cromosoma::show(element* aux){
	element *head= aux;
	while(head!=NULL){
		int val = head->value;
		printf("%i ",val);
		head= head->siguiente;
	}
	printf(" ");
}


//Create the cromosome 
element* Cromosoma::createCromosoma(int NUMBERS_ITEMS, int SIZE_BIN){
  	srand (time(NULL));
	for(int i=1; i<=NUMBERS_ITEMS; i++){
		int val= rand() % SIZE_BIN + 1;
		add(val);
	}
	return elements;
}

//get the cromosome "set of gens"
element * Cromosoma::getElement(){
    return elements;
} 


//change the currently cromosome by other
void Cromosoma::setElements(element* val){
	elements=val;	
}

//Get the factor
/*
The factor is the paramater which said who cromosomes survives
by default the evolution gives as  NUMBER OF ITEMS/3
*/

int Cromosoma::getfactor(int SIZE_BIN, int NUMGENES, element *aux){
	element *head= aux;
	int numbins=0;
	Box b ; //Box Class	
	//b->setHead();
	printf("------------Behaviour Box--------------\n");
	for (int i=1;i<=NUMGENES; i++){  //Buscamos en los genes
		int valor= head->value;

//		printf("%i ",valor);
		bool cabe= b.cabe(valor,SIZE_BIN); 
		if(cabe==false){
			numbins++;	
			b.add(valor);
		}
		head= head->siguiente;
	b.show();
	}
	
//	printf("Numero de maletas necesarias =%i \n",numbins);
	return numbins;
}
