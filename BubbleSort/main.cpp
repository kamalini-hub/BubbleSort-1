#include <iostream>
#include "tVector.h"

int main()
{
	tVector<int> original;
	original.push_back(2);
	original.push_back(5);
	original.push_back(25);
	original.push_back(1);

	original.bubbleSort();

	original.printArray();

}