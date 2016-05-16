#include <iostream>

#include "Generation.h"
int main(){

	int NUMBERS_ITEMS=5; //Number of object of each sample 
	int SIZE_BIN=10; //size of the container
	int NUM_GENERACIONES=3; //Number of the  generations 
	int NUM_CROMOSOMASXGENERACION =5; //Number of the cromosomes of each generation
	printf("\n\nNumber of Items =%i", NUMBERS_ITEMS);
	printf("\nSize Bin =%i", SIZE_BIN );
	printf("\nNumber generations =%i",NUM_GENERACIONES );
	printf("\nNumber  de cromosomas por generacion =%i \n", NUM_CROMOSOMASXGENERACION);
	
	for (int i=1; i<=NUM_GENERACIONES; i++){

		printf("\n\n---------------Generation number---------------- %i \n",i);
		Generation g(NUMBERS_ITEMS, SIZE_BIN);
		g.createGeneration(NUM_CROMOSOMASXGENERACION);
		printf("\nFinal Results of the generation number %i \n", i);

		g.show();

	}
}
