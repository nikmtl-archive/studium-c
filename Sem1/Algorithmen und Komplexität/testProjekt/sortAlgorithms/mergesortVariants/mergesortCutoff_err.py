import random
import timeit
from sortAlgorithms.shellSort import shell_sort

def merge(left, right):
    result = []
    left_idx = right_idx = 0
    while left_idx < len(left) and right_idx < len(right):
        if left[left_idx] < right[right_idx]:
            result.append(left[left_idx])
            left_idx += 1
        else:
            result.append(right[right_idx])
            right_idx += 1
    while left_idx < len(left):
        result.append(left[left_idx])
        left_idx += 1
    while right_idx < len(right):
        result.append(right[right_idx])
        right_idx += 1
    return result

def merge_sort(arr):
    if len(arr) <= 12:
        return shell_sort(arr)  # Ensure shell_sort returns the sorted array

    mid = len(arr) // 2

    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])

    return merge(left, right)

# test presorted array
def sort_ordered_list():
    array_sizes = [1000, 10000, 100000, 1000000]

    for size in array_sizes:
        arr = [i for i in range(size)]
        avg_time = timeit.timeit(lambda: merge_sort(arr), number=10) / 10
        print(f'presorted array avg time mergesort cutoff with size {size}: {avg_time}')

# test
def sort_unordered_list():
    array_sizes = [1000, 10000, 100000, 1000000]

    for size in array_sizes:
        arr = [random.randint(0, 100000) for _ in range(size)]
        avg_time = timeit.timeit(lambda: merge_sort(arr), number=10) / 10
        print(f'Avg time mergesort cutoff with size {size}: {avg_time}')

# Output:
sort_ordered_list()
