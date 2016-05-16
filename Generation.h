#include <iostream>
#include "cromosoma.h"
#include <unistd.h>
#include <stdlib.h>
//#include <Windows.h>



using namespace std;

class Generation {
    Cromosomac *generation;
	int NUMBERS_ITEMS;
	int SIZE_BIN;

    public:
	Generation(int,int);
    void setFactor();	
	Cromosomac * createGeneration(int);
	Cromosomac*  createCromosoma(); 
	void addCromosoma(element*, int);
	void show();
	void setCromosoma(Cromosomac*);
	Cromosomac* getCromosoma();
};

//COnstructor
Generation::Generation(int n,int s){
    generation= NULL;
	NUMBERS_ITEMS=n;
	SIZE_BIN=s;
}

//THis method add a cromosome to the generation
void Generation::addCromosoma(element* val,  int fa){
    Cromosomac *elem= new Cromosomac();
    elem->cromosoma =val;
    elem -> siguiente = generation;
	elem -> fact = fa;
    generation = elem;
}

//This method show the generation
void Generation::show(){
	Cromosomac *head= generation;
	while(head!=NULL){
		element *val = head->cromosoma;
		Cromosoma aux;
	//	aux->setElements(val);
		aux.show(val);
		printf(" Number of bins= %i",head->fact);
		if(head->fact<=(NUMBERS_ITEMS/2)){
			printf(" This cromossome survives");
		}
		printf( "\n");
		head= head->siguiente;
	}
}

// This method create the generation
Cromosomac * Generation::createGeneration(int val){

//val- >Number of cromosomes of each generation

	for (int i=1; i<=val; i++){
    	Cromosoma c;
		Cromosoma d;
		c.createCromosoma(NUMBERS_ITEMS, SIZE_BIN);
		d.createCromosoma(NUMBERS_ITEMS, SIZE_BIN);
	
	//	printf("\n");
	//	d.show(d.getElement());
	//	printf("\n");
	//	d.show(c.getElement());	
	//	printf("\n");
	int fact = c.getfactor(SIZE_BIN,NUMBERS_ITEMS, c.getElement()); //number of bins that the sample use
	addCromosoma(d.getElement(), fact);
	usleep(1000000);
//	Sleep(1000);
	}
	return generation;
}

//This method set the generation
void Generation::setCromosoma(Cromosomac* gen){
	generation = gen;
}

//This method gets the cromosome
Cromosomac* Generation::getCromosoma(){
	return generation;
}
