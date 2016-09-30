Project 02: lsort
===================

This is a simple implementation of the Unix [sort] utility that works on
[singly-linked lists].

[sort]: http://man7.org/linux/man-pages/man1/sort.1.html
[singly-linked lists]: https://en.wikipedia.org/wiki/Linked_list#Singly_linked_lists

1. 
STL Sort:
-Worst Case complexity: O(n log n)
-Average Case complexity: O(n log n)
-Best Case complexity: O(n log n)

STL sort has no specific algorithm it is required to be based on, but the 
mandated worst case complexity of the algorithm must be n log n.

Q Sort:
-Worst Case complexity: O(n^2)
-Average Case complexity: O(n log n)
-Best Case complexity: O(log n)

qsort is based off of the quicksort algorithm and is slightly modified to 
allowa best case complexity of log n instead of n log n

Merge Sort:
-Worst Case complexity: O(n log n)
-Average Case complexity: O(n log n)
-Best Case complexity: O(n log n)

The complaexity is usually O(n log n) because it recursively divides the 
list in half with every recursive step and always recurses to the base case 
regardless of the order of the list. 

Quick Sort:
-Worst Case complexity: O(n^2)
-Average Case complexity: O(n log n)
-Best Case complexity: O(n log n)
