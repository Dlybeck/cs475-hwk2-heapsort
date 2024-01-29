/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author:
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	// TODO - BuildHeap on the heap
	buildHeap(A, n);
	// TODO - while n > 0:
	while(n > 0){
		// TODO - swap A[n-1] with A[0], since A[0] is the smallest number.
		swap(&A[n-1], &A[0]);
		// TODO - A[n-1] now sorted in place, so decrement n
		n--;
		for(int i = 0; i <= n; i++){
			heapify(A, i, n);
		}
	}
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	// just calls heapify in a loop to set up array
	// TODO - heapify() every element from A[n/2] down-to A[0]
	for(int i = n/2; i >= 0; i--){
		heapify(A, i, n);
	}
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n){	
	int li = i*2;
	int ri = i*2 + 1;

	// TODO - get index of left child of element i
	Employee l = A[li];
	// TODO - get index of right child of element i
	Employee r = A[ri];

	// TODO - determine which child has a smaller salary. We'll call the index of this
	//		element: "smaller"
	int new_i;
	Employee smaller;
	if(l.salary <= r.salary){
		smaller = l; //left has smaller salary
		new_i = li;
	} 
	else{
		smaller = r; //right has smaller salary
		new_i = ri;
	} 

	// TODO - recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
	//			Then recursively heapify A[smaller].
	if((A[i].salary > smaller.salary) && (new_i <  n)){
		if(li < n && ri < n) {
			//update array value with smaller
			if(l.salary <= r.salary)
				swap(&A[i], &A[li]);
			else
				swap(&A[i], &A[ri]);

			heapify(A, new_i, n);
		}
	}
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	Employee temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	printf("\n");
	for(int i = 0; i < n; i++){
		if(i == n-1) //last one
			printf("[id=%s sal=%d]\n", A[i].name, A[i].salary);
		else
			printf("[id=%s sal=%d], ", A[i].name, A[i].salary);
	}
}
