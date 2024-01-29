#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "employee.h"
#include "heap.h"

#define MAX_VAL 5

int main(int argc, char *argv[])
{
	char name[MAX_NAME_LEN];

	Employee A[MAX_VAL];
	int sal;
	int i = 0;
	while(i < MAX_VAL){
		printf("Name: ");
		scanf("%s", &name);

		printf("\nSalary: ");
		scanf("%d", &sal);

		printf("\n");

		strcpy(A[i].name, name);
		A[i].salary = sal;
		
		i++;
	}

	printList(A, MAX_VAL);
	heapSort(A, MAX_VAL);
	printList(A, MAX_VAL);

	
	/*Employee e1, e2, e3, e4, e5, e6, e7, e8, e9;
	srand(time(NULL));
	e1.salary = rand() % 100;
	e2.salary = rand() % 100;
	e3.salary = rand() % 100;
	e4.salary = rand() % 100;
	e5.salary = rand() % 100;
	e6.salary = rand() % 100;
	e7.salary = rand() % 100;
	e8.salary = rand() % 100;
	e9.salary = rand() % 100;
	//e10.salary = rand() % 100;

	strcpy(e1.name, "A");
	strcpy(e2.name, "B");
	strcpy(e3.name, "C");
	strcpy(e4.name, "D");
	strcpy(e5.name, "E");
	strcpy(e6.name, "F");
	strcpy(e7.name, "G");
	strcpy(e8.name, "H");
	strcpy(e9.name, "I");
	//strcpy(e10.name, "J");

	int length = 9;
	Employee A[] = {e1, e2, e3, e4, e5, e6, e7, e8, e9}; 

	printList(A, length);

	heapSort(A, length);

	printList(A, length);

	return 0;*/
}
