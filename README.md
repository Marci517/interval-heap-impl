# Interval Heap in C++

This project implements an **Interval Heap** in C++, a specialized data structure that supports efficient access to both minimum and maximum values. An interval heap is a type of double-ended priority queue where elements are stored in pairs representing intervals. Each node maintains two values: a minimum and a maximum, allowing constant-time retrieval of both ends.

The data structure is particularly useful when applications require frequent access to both the smallest and largest elements, while also maintaining efficient insertion and deletion operations.

## Features

- Insert elements into the interval heap
- Retrieve the minimum or maximum value
- Remove the minimum or maximum value
- Display the heap contents to the screen or to a file