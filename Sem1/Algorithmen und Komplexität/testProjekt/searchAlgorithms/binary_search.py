import timeit

class BinarySearch:

    def search_iterative(self, arr, target):
        low, high = 0, len(arr) - 1
        while low <= high:
            mid = (high + low) // 2
            if arr[mid] == target:
                return mid
            elif arr[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        return -1

    def search_recursive(self, arr, target, low, high):
        if low > high:
            return -1
        mid = (high + low) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            return self.search_recursive(arr, target, mid + 1, high)
        else:
            return self.search_recursive(arr, target, low, mid - 1)

# Test
search = BinarySearch()
arr_size = 1000

for i in range(10):  # Adjust the range for the number of iterations you want
    arr = range(arr_size)  # range from 0 to arr_size - 1
    avg_time = timeit.timeit(lambda: search.search_iterative(arr, arr_size - 1), number=1000) / 1000
    print('Avg time binary search with size ' + str(arr_size) + ': ' + str(avg_time))
    arr_size *= 2  # Double the array size for the next iteration