import timeit
import random

def selection_sort(arr):
    for i in range(len(arr)):
        min_index = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index]=arr[min_index], arr[i]




#test presorted array
def sortOrderdList():
    arr = [i for i in range(10000)]
    avg_time = timeit.timeit(lambda: selection_sort(arr), number=10) / 10
    print(f'presorted array avg time selection sort with size {10000}: {avg_time}')
    arr = [i for i in range(20000)]
    avg_time = timeit.timeit(lambda: selection_sort(arr), number=10) / 10
    print(f'presorted array avg time selection sort with size {20000}: {avg_time}')


sortOrderdList()#Output
#presorted array avg time selection sort with size 10000: 1.720304620009847
#presorted array avg time selection sort with size 20000: 7.064035170001444
#Resoning: For sorted array, selection sort has a time complexity of O(n^2) which is not efficient for large arrays.

#test
def sortUnordertList():
    array_sizes = [100, 200, 1000, 2000, 4000, 10000, 20000, 40000]

    for size in array_sizes:
        arr = [random.randint(0, 100000) for _ in range(size)]
        avg_time = timeit.timeit(lambda: selection_sort(arr), number=10) / 10
        print(f'Avg time selection sort with size {size}: {avg_time}')

# Output:
sortUnordertList()
#Avg time selection sort with size 100: 0.00015687999548390507
#Avg time selection sort with size 200: 0.0005930399987846613
#Avg time selection sort with size 1000: 0.017921910004224627
#Avg time selection sort with size 2000: 0.06942165000364184
#Avg time selection sort with size 4000: 0.28134633000008763
#Avg time selection sort with size 10000: 1.7603827200015076
#Avg time selection sort with size 20000: 7.686397349997423
#Avg time selection sort with size 40000: 32.46082277999958
#Resoning: For unsorted array, selection sort has a time complexity of O(n^2) which is not efficient for large arrays.