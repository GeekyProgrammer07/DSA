## Improvements for QuickSort

### 1. Handle Worst-Case (Sorted Array)
Always picking the last element as a pivot can lead to `O(n^2)` complexity when the array is already sorted.  
Instead, choose a **random pivot** (or median-of-three) to improve performance:

```cpp
int randomIndex = startIndex + rand() % (endIndex - startIndex + 1);
swap(arr[randomIndex], arr[endIndex]); // put random pivot at end
int i = startIndex - 1, pivotElement = arr[endIndex];
```

### 2. Tail Recursion Optimization

Reduce stack depth by recursion  on the smaller side first, and then turn the larger side into a loop.