import timeit

class LinearSearch:
    def __init__(self, arr):
        self.arr = arr

    def search(self, target):
        for i in range(len(self.arr)):
            if self.arr[i] == target:
                return i
        return -1

# Test
#arr = [1, 2, 3, 4, 5]
#search = LinearSearch(arr)
#print(search.search(3)) # 2
#print(search.search(6)) # -1


# Test
arr_size = 1000

for i in range(10):  # Adjust the range for the number of iterations you want
    arr = list(range(arr_size))  # range from 0 to arr_size - 1
    search = LinearSearch(arr)
    avg_time = timeit.timeit(lambda: search.search(arr_size - 1), number=1000) / 1000
    print('Avg time linear search with size ' + str(arr_size) + ': ' + str(avg_time))
    arr_size *= 2  # Double the array size for the next iteration