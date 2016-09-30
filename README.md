Project 02: lsort
===================

This is a simple implementation of the Unix [sort] utility that works on
[singly-linked lists].

[sort]: http://man7.org/linux/man-pages/man1/sort.1.html
[singly-linked lists]: https://en.wikipedia.org/wiki/Linked_list#Singly_linked_lists

Questions
-
1) **Complexities:**

STL Sort:

- Worst Case complexity: O(n log n)
- Average Case complexity: O(n log n)
- Best Case complexity: O(n log n)

STL sort has no specific algorithm it is required to be based on, but the 
mandated worst case complexity of the algorithm must be n log n.

Q Sort:

- Worst Case complexity: O(n^2)
- Average Case complexity: O(n log n)
- Best Case complexity: O(log n)

qsort is based off of the quicksort algorithm and is slightly modified to 
allowa best case complexity of log n instead of n log n

Merge Sort:

- Worst Case complexity: O(n log n)
- Average Case complexity: O(n log n)
- Best Case complexity: O(n log n)

The complexity is usually O(n log n) because it recursively divides the 
list in half with every recursive step and always recurses to the base case 
regardless of the order of the list. 

Quick Sort:

- Worst Case complexity: O(n^2)
- Average Case complexity: O(n log n)
- Best Case complexity: O(n log n)

Depending on the selection of the pivot, the quick sort complexity can degrade to O(n^2) if the elements being sorted are already in order. On average and best case, the complexity is O(n log n) because a pivot divides the list into two after each iteration.

2) **Sorting Algorithm Benchmarks**

| Mode 	| Size 	  | Elapsed Time  | Memory   |
|---------|-----------|---------------|----------|
| STL		| 10		  | 0.001998s     | 1.109Mb  |
| STL		| 100		  | 0.001999s     | 1.117Mb  |
| STL		| 1000		  | 0.003998s     | 1.199Mb  |
| STL		| 10000	  | 0.031994s     | 2.039Mb  |
| STL		| 100000	  | 0.415935s     | 9.832Mb  |
| STL		| 1000000	  | 6.046079s     | 86.656Mb |
| STL		| 10000000  | 78.753029s    | 894.074Mb|
| QSORT	| 10		  | 0.001999s     | 1.105Mb  |
| QSORT	| 100		  | 0.001998s     | 1.113Mb  |
| QSORT	| 1000		  | 0.003998s     | 1.250Mb  |
| QSORT	| 10000	  | 0.025995s     | 2.098Mb  |
| QSORT	| 100000	  | 0.332949s     | 10.410Mb |
| QSORT	| 1000000	  | 4.559305s     | 92.813Mb |
| QSORT	| 10000000  | 60.207848s    | 917.578Mb|
| MERGE	| 10		  | 0.001998s     | 1.102Mb  |
| MERGE	| 100		  | 0.001999s     | 1.109Mb  |
| MERGE	| 1000		  | 0.010997s     | 1.219Mb  |
| MERGE	| 10000	  | 1.043840s     | 2.320Mb  |
| MERGE	| 100000	  | 205.595407s   | 13.309Mb |
| MERGE	| 1000000	  | SEG FAULT     | SEG FAULT|
| MERGE	| 10000000  | SEG FAULT     | SEG FAULT|
| QUICK	| 10		  | 0.001999s     | 1.102Mb  |
| QUICK	| 100		  | 0.001998s     | 1.105Mb  |
| QUICK	| 1000		  | 0.003998s     | 1.176Mb  |
| QUICK	| 10000	  | 0.025995s     | 1.863Mb  |
| QUICK	| 100000	  | 0.346974s     | 8.730Mb  |
| QUICK	| 1000000	  | 5.705132s     | 77.394Mb |
| QUICK	| 10000000  | 75.864464s    | 764.039Mb|

3) **Discussion:**

- Based on the benchmarks, it appears that all of the sorting algorithms have relatively similar performance levels for lists of 1000 and under. When the number of elements to be sorted exceeds that, the qsort ending up taking up the most memory out of all of them, and the merge sort took the longest time to sort.

- This reveals how theoretical complexity is just that - theoretical. Merge sort and STL sort should have the most optimal worst case complexities, but they were some of the slower ones. Actual performance has number of contributing factors, including OS and architecture that allow varying performance.

- In my opinion, quick sort seemed to be the best. It had the fasted time for the greatest amount of elements to be sorted and it took up less space than the other sorts to sort that long list. It was also the hardest to implement, so its more satisfying to see that it works. The only trade of would be the worst case complexity is really bad depending on the pivot choice.

**Individual Contributions:**
Thomas started the stl and qsort sorts, and then he did the merge sort and question number one of the README. Kyle finished the stl and qsort sorts, wrote the quick sort, and did numbers 1-3 of the README.