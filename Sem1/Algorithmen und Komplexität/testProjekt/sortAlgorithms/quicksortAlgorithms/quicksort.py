import random
import timeit


def quicksort(arr, low, high):
    if low < high:
        p = partition(arr, low, high)
        quicksort(arr, low, p)
        quicksort(arr, p + 1, high)

def partition(arr, low, high):
    pivot = arr[(low + high) // 2]
    left = low
    right = high
    while True:
        while arr[left] < pivot:
            left += 1
        while arr[right] > pivot:
            right -= 1
        if left >= right:
            return right
        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1


#test
def sortUnordertList():
    array_sizes = [1000, 10000, 100000, 1000000]

    for size in array_sizes:
        arr = [random.randint(0, 100000) for _ in range(size)]
        avg_time = timeit.timeit(lambda: quicksort(arr, 0, len(arr) - 1), number=10) / 10
        print(f'Avg time mergesort with size {size}: {avg_time}')


sortUnordertList()
#Avg time mergesort with size 1000: 0.0013568700000064382
#Avg time mergesort with size 10000: 0.036566800000002786
#Avg time mergesort with size 100000: 0.2874254800000017
#Avg time mergesort with size 1000000: 3.8565465800000083
#Resoning: For unsorted array, quicksort has a time complexity of O(n log n) which is efficient for large arrays.
# Compare to mergesort, quicksort is faster for large arrays.