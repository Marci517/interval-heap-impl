# Specification – Interval Heap

## General Description

The interval heap is a binary heap where each element stores two values representing an interval. The last element may store only one value. This structure allows efficient access to both minimum and maximum values.

As with any binary heap, the interval heap must satisfy a heap property. Specifically:

- The left value of each interval represents a minimum, so the structure satisfies the **min-heap property** for left values.
- The right value represents a maximum, so it satisfies the **max-heap property** for right values.
- Additionally, the first value in an interval is always less than or equal to the second.

In other words, the interval at the root encompasses all intervals below it.

## Data Structure

The structure that stores the interval heap includes:

- Its size (can be represented using 2 bytes)
- The current number of elements
- The values
- A boolean flag indicating whether the heap is full

## Operations

### `CreateIntervalHeap`

Creates an interval heap of size `n`.

- Preconditions: None  
- Postconditions: The interval heap is created.

---

### `Destroy`

Releases the memory allocated for the interval heap.

- Preconditions: None  
- Postconditions: The memory for the interval heap is released.

---

### `GetMin`

Returns the minimum value in the interval heap.

- Preconditions: The heap must not be empty  
- Postconditions: Returns the minimum value.

---

### `GetMax`

Returns the maximum value in the interval heap.

- Preconditions: The heap must not be empty  
- Postconditions: Returns the maximum value.

---

### `UpMin`

Moves a minimum value from the end of the heap up along the min-branch until it's in the correct position.

- Preconditions: The heap must not be empty  
- Postconditions: The minimum value is placed correctly.

---

### `UpMax`

Moves a maximum value from the end of the heap up along the max-branch until it's in the correct position.

- Preconditions: The heap must not be empty  
- Postconditions: The maximum value is placed correctly.

---

### `DownMin`

Moves the minimum value down from the root along the min-branch until it is in the correct position.

- Preconditions: The heap must not be empty  
- Postconditions: The minimum value is placed correctly.

---

### `DownMax`

Moves the maximum value down from the root along the max-branch until it is in the correct position.

- Preconditions: The heap must not be empty  
- Postconditions: The maximum value is placed correctly.

---

### `Insert`

Inserts a new value at the end of the interval heap. It checks whether the heap is full and uses the `UpMin` and `UpMax` functions accordingly.

- Preconditions: The heap must not be full  
- Postconditions: The value is inserted.

---

### `DeleteMin`

Deletes the minimum value from the interval heap using the `DownMin` function.

- Preconditions: The heap must not be empty  
- Postconditions: The minimum value is deleted.

---

### `DeleteMax`

Deletes the maximum value from the interval heap using the `DownMax` function.

- Preconditions: The heap must not be empty  
- Postconditions: The maximum value is deleted.

---

### `Print`

Prints the interval heap as an array to standard output.

- Preconditions: The heap must not be empty  
- Postconditions: The heap is printed in array format.

---

### `FilePrint`

Prints the interval heap as an array to a file.

- Preconditions: The heap must not be empty  
- Postconditions: The heap is written to the file in array format.

---

### `GetSize`

Returns the current size of the interval heap.

- Preconditions: None  
- Postconditions: The current size is returned.
