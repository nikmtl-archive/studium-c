import random
import timeit


def quicksort(arr, low, high):
    if low >= high:
        return

    lt, gt = partition(arr, low, high)
    quicksort(arr, low, lt -1)
    quicksort(arr, gt + 1, high)

def partition(arr, low, high):
    pivot = arr[low]
    lt = low
    gt = high
    i = low
    while i <= gt:
        if arr[i] < pivot:
            arr[i], arr[lt] = arr[lt], arr[i]
            lt += 1
            i += 1
        elif arr[i] > pivot:
            arr[i], arr[gt] = arr[gt], arr[i]
            gt -= 1
        else:
            i += 1
    return lt, gt


# test
def sortUnordertList():
    array_sizes = [1000, 10000, 100000, 1000000]

    for size in array_sizes:
        arr = [random.choice([1, 2, 3]) for _ in range(size)]
        avg_time = timeit.timeit(lambda: quicksort(arr, 0, len(arr) - 1), number=10) / 10
        print(f'Avg time quicksort with size {size}: {avg_time}')


sortUnordertList()
#Avg time quicksort with size 1000: 0.002988269999991644
#Avg time quicksort with size 10000: 0.004187849999993887
#Avg time quicksort with size 100000: 0.04439827999999579
#Avg time quicksort with size 1000000: 0.34743969999999536
#Resoning: For unsorted array, quicksort has a time complexity of O(n log n) which is efficient for large arrays.
# Compare to normal quicksort, quicksort 3 way is faster for large arrays.