#include<stdio.h>

/*
Structures that storage the cromosome, gens, and, boxes

*/

/*
	This is a cromosome with out  the factor
*/
struct element{
    int value;
    element *siguiente;
};

/*
This structure reprents  a cromosome
*/

struct Cromosomac{
	int fact;
	element *cromosoma;
	Cromosomac *siguiente;
};

struct boxes{
	int v;
	boxes *siguiente;
};
