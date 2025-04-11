#ifndef INTERVALHEAP_H
#define INTERVALHEAP_H

#include <iostream>
#include <fstream>
#define inf INT_MAX
using namespace std;

typedef struct Node    // each node has two parts: interval start and end
{
	int start, end;
} Node;

typedef struct IntervalHeap
{
	Node* intervals;   // intervals stored in an array
	int size;          // current size
	int max_size;      // maximum capacity
	bool full;         // if true: every node contains a full interval, 
	                   // if false: the last node has only one element (always the start is filled if there's only one value)
} IntervalHeap;

IntervalHeap* CreateIntervalHeap(int);  // creates the interval heap represented as an array with the given max size

void Destroy(IntervalHeap*);           // frees used memory: first the interval array, then the heap itself

int GetMin(IntervalHeap*);             // returns the minimum value (start of the first node)

int GetMax(IntervalHeap*);             // returns the maximum value (end of the first node if present,
                                       // otherwise returns the start of the first node) – this can happen
                                       // if the heap contains only a single value

void UpMin(IntervalHeap*);             // used during insertion: places the inserted minimum to the correct position

void UpMax(IntervalHeap*);             // used during insertion: places the inserted maximum to the correct position

void DownMin(IntervalHeap*);           // used when deleting minimum: repositions the value along the minimum path

void DownMax(IntervalHeap*);           // used when deleting maximum: repositions the value along the maximum path

void Insert(IntervalHeap*, int);       // inserts a new value at the bottom of the heap, then applies UpMin or UpMax

void DeleteMin(IntervalHeap*);         // copies the end of the last node (if exists) or the start to the min position, then applies DownMin

void DeleteMax(IntervalHeap*);         // copies the end of the last node (if exists) or the start to the max position, then applies DownMax

void Print(IntervalHeap*);             // prints the array of intervals to the screen in [a,b] [c,d]... format

void FilePrint(IntervalHeap*, const char*);  // prints the array of intervals to a file in [a,b] [c,d]... format

int GetSize(IntervalHeap*);            // returns the current size of the interval heap

#endif
