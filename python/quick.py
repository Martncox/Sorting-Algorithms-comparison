# Quick sort in Python

# def partition(array, low, high):
#     piviot = array[high]
#     y = low -1

#     for x in range(low, high):
#         if array[x] <= piviot:
#             x =+ 1
#             array[y], array[x] = array[x], array[y]


#     array[y + 1], array[high] = array[high], array[y +1]
#     return y + 1

# def quick(array, low, high):
#     if low < high:
#         ps = partition(array, low, high)
#         quick(array, low, ps -1)
#         quick(array, ps + 1, high)

# def readDataFromFile(filename):
#     with open(filename, 'r') as file:
#         data = [int(line.strip()) for line in file]
#     return data

# # Input file name
# filename = "list1000.txt"

# # Read unsorted data from file
# unsorted_data = readDataFromFile(filename)


# # Perform quicksort
# quick(unsorted_data, 0, len(unsorted_data) - 1)

# # Display sorted array
# print('Sorted Array in Ascending Order:')
# print(unsorted_data)



##f = open("list1000.txt", "r")
##print(f.read())

import time
import random

def partition(array, low, high):
    pivot = array[high]
    x = low - 1

    for y in range(low, high):
        if array[y] <= pivot:
            x += 1
            array[x], array[y] = array[y], array[x]

    array[x + 1], array[high] = array[high], array[x + 1]
    return x + 1

def quick(array, low, high):
    if low < high:
        pi = partition(array, low, high)
        quick(array, low, pi - 1)
        quick(array, pi + 1, high)

# def readDataFromFile(filename):
#     with open(filename, 'r') as file:
#         data = [int(line.strip()) for line in file]
#     return data

# # Input file name
# file_name = "list1000.txt"

# # Read unsorted data from file
# unsorted_data = readDataFromFile(file_name)
totalValue = 0

for j in range (0, 16):
    num_list = []
    for i in range(0, 10000):
        num_list.append(random.randint(0, 2000)+1)

    start = time.time()

    # Perform quicksort
    quick(num_list, 0, len(num_list) - 1)

    end = time.time()

    # Display sorted array
    # print('Sorted Array in Ascending Order:')
    # print(num_list)
    execution_time_microseconds = (end - start) * 1e6
    totalValue += execution_time_microseconds
    

avgValue = totalValue / 16
print("Average execution time:", avgValue, "microseconds")