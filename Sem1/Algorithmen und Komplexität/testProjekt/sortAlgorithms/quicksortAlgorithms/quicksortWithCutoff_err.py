import random
import timeit
from sortAlgorithms.insertionSort import insertion_sort  # Adjust the import path as necessary

CUTOFF = 10  # Define a cutoff threshold

def quicksort(arr, low, high):
    if high - low <= CUTOFF:
        insertion_sort(arr)
    else:
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

# Test
def sortUnordertList():
    array_sizes = [100000]

    for size in array_sizes:
        arr = [random.randint(0, 100000) for _ in range(size)]
        avg_time = timeit.timeit(lambda: quicksort(arr, 0, len(arr) - 1), number=10) / 10
        print(f'Avg time quicksort with size {size}: {avg_time}')

sortUnordertList()