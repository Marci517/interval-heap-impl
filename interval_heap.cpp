#include <iostream>
#include <fstream>
#include "interval_heaps.h"
using namespace std;


IntervalHeap* CreateIntervalHeap(int n)
{
	IntervalHeap* heap = new IntervalHeap;

	heap->size = 0;
	heap->max_size = n;
	heap->intervals = new Node[n];
	heap->full = true;

	return heap;
}

void Destroy(IntervalHeap* heap)
{
	delete[] heap->intervals;
	delete[] heap;
}

int GetMin(IntervalHeap* heap)
{
	if (heap->size < 1)
	{
		cout << "Empty!" << endl;
		return inf;
	}
	else
	{
		return heap->intervals[0].start;
	}
}

int GetMax(IntervalHeap* heap)
{
	if (heap->size < 1)
	{
		cout << "Empty!" << endl;
		return inf;
	}
	else
	{
		if (heap->size == 1)
		{
			if (heap->full)
			{
				return heap->intervals[0].end;
			}
			else return heap->intervals[0].start;
		}
		else
		{
			return heap->intervals[0].end;
		}
	}
}


void UpMin(IntervalHeap* heap)
{
	int minimum;
	int minind;

	minind = heap->size - 1;
	minimum = heap->intervals[minind].start;

	while (minind > 0 && heap->intervals[(minind + 1) / 2 - 1].start > minimum)
	{
		heap->intervals[minind].start = heap->intervals[(minind + 1) / 2 - 1].start;
		minind = (minind + 1) / 2 - 1;
	}

	heap->intervals[minind].start = minimum;
}

void UpMax(IntervalHeap* heap)
{
	int maximum;
	int maxind;

	maxind = heap->size - 1;
	maximum = heap->intervals[maxind].end;

	while (maxind > 0 && heap->intervals[(maxind + 1) / 2 - 1].end < maximum)
	{
		heap->intervals[maxind].end = heap->intervals[(maxind + 1) / 2 - 1].end;
		maxind = (maxind + 1) / 2 - 1;
	}

	heap->intervals[maxind].end = maximum;
}

void DownMin(IntervalHeap* heap)
{
	int left, right, minimum, index = 0;

	do
	{
		minimum = index;
		left = (index + 1) * 2 - 1;
		right = (index + 1) * 2;

		if (left < heap->size && heap->intervals[left].start < heap->intervals[index].start)
		{
			index = left;
		}

		if (right < heap->size && heap->intervals[right].start < heap->intervals[index].start)
		{
			index = right;
		}

		swap(heap->intervals[minimum].start, heap->intervals[index].start);

		if (heap->intervals[index].start > heap->intervals[index].end)
		{
			swap(heap->intervals[index].start, heap->intervals[index].end);
		}

		if (heap->intervals[minimum].start > heap->intervals[minimum].end)
		{
			swap(heap->intervals[minimum].start, heap->intervals[minimum].end);
		}

	} while (minimum != index);

}

void DownMax(IntervalHeap* heap)
{
	int left, right, maximum, index = 0;

	if (heap->full == false)
	{
		heap->intervals[heap->size - 1].end = heap->intervals[heap->size - 1].start;
	}

	do
	{
		maximum = index;
		left = (index + 1) * 2 - 1;
		right = (index + 1) * 2;

		if (left < heap->size && heap->intervals[left].end > heap->intervals[index].end)
		{
			index = left;
		}

		if (right < heap->size && heap->intervals[right].end > heap->intervals[index].end)
		{
			index = right;
		}

		swap(heap->intervals[maximum].end, heap->intervals[index].end);

		if (heap->intervals[index].start > heap->intervals[index].end)
		{
			swap(heap->intervals[index].start, heap->intervals[index].end);
		}

		if (heap->intervals[maximum].start > heap->intervals[maximum].end)
		{
			swap(heap->intervals[maximum].start, heap->intervals[maximum].end);
		}

	} while (maximum != index);
}

void Insert(IntervalHeap* heap, int x)
{

	if (heap->full)
	{
		if (heap->size + 1 <= heap->max_size)
		{
			heap->size++;
			heap->intervals[heap->size - 1].start = x;
			heap->full = false;
			UpMin(heap);

			if (heap->intervals[heap->size - 1].start == x)
			{
				heap->intervals[heap->size - 1].end = heap->intervals[heap->size - 1].start;
				UpMax(heap);
				heap->intervals[heap->size - 1].start = heap->intervals[heap->size - 1].end;
			}
		}
		else
		{
			cout << "Full!";
			return;
		}
	}
	else
	{
		heap->full = true;
		heap->intervals[heap->size - 1].end = x;
		if (heap->intervals[heap->size - 1].start <= heap->intervals[heap->size - 1].end)
		{
			UpMax(heap);
		}
		else
		{
			swap(heap->intervals[heap->size - 1].start, heap->intervals[heap->size - 1].end);
			UpMin(heap);
		}
	}


}

void DeleteMin(IntervalHeap* heap)
{
	if (heap->size < 1)
	{
		cout << "Empty!" << endl;
		return;
	}

	if (heap->full)
	{
		heap->full = false;
		heap->intervals[0].start = heap->intervals[heap->size - 1].end;
	}
	else
	{
		heap->full = true;
		heap->intervals[0].start = heap->intervals[heap->size - 1].start;
		heap->size--;
	}

	DownMin(heap);

	
}

void DeleteMax(IntervalHeap* heap)
{
	if (heap->size < 1)
	{
		cout << "Empty!" << endl;
		return;
	}

	if (heap->full)
	{
		heap->full = false;
		heap->intervals[0].end = heap->intervals[heap->size - 1].end;
	}
	else
	{
		heap->full = true;
		heap->intervals[0].end = heap->intervals[heap->size - 1].start;
		heap->size--;
	}

	DownMax(heap);
}

void Print(IntervalHeap* heap)
{
	int i;

	if (heap->size < 1)
	{
		cout << "Empty!" << endl;
		return;
	}

	for (i = 0; i <= heap->size - 1; i++)
	{
		if (i == heap->size - 1)
		{
			if (heap->full)
			{
				cout << "[" << heap->intervals[i].start << "," << heap->intervals[i].end << "] ";
			}
			else
			{
				cout << "[" << heap->intervals[i].start << "] ";
			}
		}
		else
		{
			cout << "[" << heap->intervals[i].start << "," << heap->intervals[i].end << "] ";
		}
	}

	cout << endl;
}

void FilePrint(IntervalHeap* heap, const char* fle)
{
	ofstream out(fle);
	int i;

	if (heap->size < 1)
	{
		out << "Empty!" << endl;
		return;
	}

	for (i = 0; i <= heap->size - 1; i++)
	{
		if (i == heap->size - 1)
		{
			if (heap->full)
			{
				out << "[" << heap->intervals[i].start << "," << heap->intervals[i].end << "] ";
			}
			else
			{
				out << "[" << heap->intervals[i].start << "] ";
			}
		}
		else
		{
			out << "[" << heap->intervals[i].start << "," << heap->intervals[i].end << "] ";
		}
	}

	out << endl;

	out.close();
}

int GetSize(IntervalHeap* heap)
{
	return heap->size;
}
