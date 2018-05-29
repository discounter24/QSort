#include <iostream>
#include "Element.h"

void stablesort(Element E[], long long size);

void quicksort(Element E[], long long left, long long right, long long size);
long long partition(Element E[], long long left, long long right);
void swap(Element E[], long long pos1, long long pos2);
void printArray(Element E[], long long size);

int main(void){

	Element E[8]{ Element(4,"erste 4"), Element(4,"zweite vier"), Element(1,"nix"), Element(3,"3"), Element(5,"5"),Element(8,"8.1"),Element(8,"8.2"), Element(90,"90") };

	std::cout << "Input: ";
	printArray(E,8);

	stablesort(E,8);

	printArray(E, 8);

	std::cin.get();

	return 0;
}

void stablesort(Element E[], long long size)
{
	
	long long grIndex = size - 1;
	long long x = 1;
	long long stellen = 0;
	while (grIndex >= x)
	{
		x *= 10;
		stellen++;
	}

	long long multiplikator = pow(10, stellen);

	for (long long i = 0; i < size; i++)
	{
		E[i].key = E[i].key * multiplikator;
		E[i].key = E[i].key + i;
	}

	quicksort(E, 0, size - 1, size);

	for (long long i = 0; i < size; i++)
	{
		E[i].key = E[i].key / multiplikator;
	}

}


void quicksort(Element E[], long long left, long long right, long long size){
	if (left < right) {
		long long i = partition(E, left, right);
		//printArray(E, size);

		quicksort(E, left, i - 1, size);
		quicksort(E, i + 1, right, size);
	}
}

long long partition(Element E[], long long left, long long right) {
	long long ppos = right, pivot = E[right].key;
	//std::cout << std::endl << "Pivot: " << pivot << std::endl;
	while (true)
	{
		while (left < right && E[left].key < pivot) left++;
		while (left < right && E[right].key >= pivot) right--;
		if (left >= right) break;

		swap(E, left, right);
	}
	swap(E, left, ppos);
	return left;
}

void swap(Element E[], long long pos1, long long pos2)
{
	Element tmp = E[pos1];
	E[pos1] = E[pos2];
	E[pos2] = tmp;
}

void printArray(Element E[], long long size)
{
	for (long long i=0;i<size;i++)
	{
		std::cout << "(" << E[i].key << "," <<  E[i].name << ")" << " ";
	}
	std::cout << std::endl << std::endl;
}