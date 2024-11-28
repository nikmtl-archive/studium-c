import timeit
import random


def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


#test presorted array
def sortOrderdList():
    arr = [i for i in range(10000)]
    avg_time = timeit.timeit(lambda: insertion_sort(arr), number=10) / 10
    print(f'presorted array avg time insertion sort with size {10000}: {avg_time}')
    arr = [i for i in range(20000)]
    avg_time = timeit.timeit(lambda: insertion_sort(arr), number=10) / 10
    print(f'presorted array avg time insertion sort with size {20000}: {avg_time}')


#sortOrderdList()#Output
# presorted array avg time insertion sort with size 10000: 0.001016980002168566
# presorted array avg time insertion sort with size 20000: 0.00203229000326246
#resoning: For sorted array, insertion sort has a time complexity of O(n) which is efficient for large arrays.

#test
def sortUnordertList():
    array_sizes = [100, 200, 1000, 2000, 4000, 10000, 20000, 40000]

    for size in array_sizes:
        arr = [random.randint(0, 100000) for _ in range(size)]
        avg_time = timeit.timeit(lambda: insertion_sort(arr), number=10) / 10
        print(f'Avg time insertion sort with size {size}: {avg_time}')

# Output:
#sortUnordertList()
#Avg time insertion sort with size 100: 2.4179997853934766e-05
#Avg time insertion sort with size 200: 7.744000758975744e-05
#Avg time insertion sort with size 1000: 0.0020478100050240755
#Avg time insertion sort with size 2000: 0.00911674000089988
#Avg time insertion sort with size 4000: 0.0327777500031516
#Avg time insertion sort with size 10000: 0.21230344999348744
#Avg time insertion sort with size 20000: 0.8711946199997328
#Avg time insertion sort with size 40000: 3.6081788999959827
#Resoning: For unsorted array, insertion sort has a time complexity of 1/4 O(n^2) which is not efficient for large arrays.
