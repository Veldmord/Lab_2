#include "print_hello_world.h"

void function_(int a)
{
	int sum = 0;
	for(int i = 0; i < a; i++)
	{
		sum += i;
	}
	std::cout << "Sum = " << sum << std::endl;
}
