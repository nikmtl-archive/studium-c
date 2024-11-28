import timeit
import random


def merg_sort(arr):
    temp_arr = [0] * len(arr)
    return _merg_sort(arr, temp_arr, 0, len(arr) - 1)

def _merg_sort(arr, temp_arr, left, right):
    if left < right:
        mid = (left + right) // 2
        _merg_sort(arr, temp_arr, left, mid)
        _merg_sort(arr, temp_arr, mid + 1, right)
        merge(arr, temp_arr, left, mid, right)
    return arr

def merge(arr, temp_arr, left, mid, right):
    i = left
    j = mid + 1
    k = left

    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            temp_arr[k] = arr[i]
            i += 1
        else:
            temp_arr[k] = arr[j]
            j += 1
        k += 1

    while i <= mid:
        temp_arr[k] = arr[i]
        i += 1
        k += 1

    while j <= right:
        temp_arr[k] = arr[j]
        j += 1
        k += 1

    for i in range(left, right + 1):
        arr[i] = temp_arr[i]

    return arr

#test presorted array
def sortOrderdList():
    array_sizes = [1000, 10000, 100000, 1000000]

    for size in array_sizes:
        arr = [i for i in range(size)]
        avg_time = timeit.timeit(lambda: merg_sort(arr), number=10) / 10
        print(f'presorted array avg time mergesort with size {size}: {avg_time}')

sortOrderdList()
#Output
# presorted array avg time mergesort with size 1000: 0.004559120000340045
# presorted array avg time mergesort with size 10000: 0.05466653999901609
# presorted array avg time mergesort with size 100000: 0.5372727800000575
# presorted array avg time mergesort with size 1000000: 6.235809180000797
#resoning: For presorted array, mergesort has a time complexity of O(n log n) which is efficient for large arrays.

#test
def sortUnordertList():
    array_sizes = [1000, 10000, 100000, 1000000]

    for size in array_sizes:
        arr = [random.randint(0, 100000) for _ in range(size)]
        avg_time = timeit.timeit(lambda: merg_sort(arr), number=10) / 10
        print(f'Avg time mergesort with size {size}: {avg_time}')


sortUnordertList()
# Output:
# Avg time mergesort with size 1000: 0.0034989399995538407
# Avg time mergesort with size 10000: 0.0456556900011492
# Avg time mergesort with size 100000: 0.5958844599997974
# Avg time mergesort with size 1000000: 8.373484270001063
#Resoning: For unsorted array, mergesort has a time complexity of O(n log n) which is efficient for large arrays.