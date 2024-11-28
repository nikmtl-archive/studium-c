import timeit
import random
from math import log

def shell_sort(arr):
    n = len(arr)
    T = int(log(n, 3)) -1
    if T < 1: T = 1
    h = int((3**T - 1) / 2)
    while h > 0:
        for i in range(h, n):
            temp = arr[i]
            j = i
            while (j >= h) and (arr[j - h] > temp):
                arr[j] = arr[j - h]
                j -= h
            arr[j] = temp
        h //= 3

#test presorted array
def sortOrderdList():
    arr = [i for i in range(10000)]
    avg_time = timeit.timeit(lambda: shell_sort(arr), number=10) / 10
    print(f'presorted array avg time shell sort with size {10000}: {avg_time}')
    arr = [i for i in range(20000)]
    avg_time = timeit.timeit(lambda: shell_sort(arr), number=10) / 10
    print(f'presorted array avg time shell sort with size {20000}: {avg_time}')


sortOrderdList()#Output
# presorted array avg time insertion sort with size 10000: 0.005368420004379005
# presorted array avg time insertion sort with size 20000: 0.01224220999283716
#Resoning: For unsorted array, insertion sort has a time complexity of n log n which is efficient for large arrays.

#test
def sortUnordertList():
    array_sizes = [100, 200, 1000, 2000, 4000, 10000, 20000, 40000]

    for size in array_sizes:
        arr = [random.randint(0, 100000) for _ in range(size)]
        avg_time = timeit.timeit(lambda: shell_sort(arr), number=10) / 10
        print(f'Avg time shell sort with size {size}: {avg_time}')

# Output:
sortUnordertList()
#Avg time shell sort with size 100: 2.2950000129640102e-05
#Avg time shell sort with size 200: 5.019999807700515e-05
#Avg time shell sort with size 1000: 0.00045951999491080644
#Avg time shell sort with size 2000: 0.001025109994225204
#Avg time shell sort with size 4000: 0.0024266700027510526
#Avg time shell sort with size 10000: 0.007123649993445724
#Avg time shell sort with size 20000: 0.016780349996406586
#Avg time shell sort with size 40000: 0.04014201998943463
#Resoning: For unsorted array, insertion sort has a time complexity of n log n which is efficient for large arrays.