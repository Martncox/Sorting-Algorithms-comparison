
import time
import random

def selectionSort(array, size):

    for ind in range(size):
        min_index = ind
 
        for j in range(ind + 1, size):
            # select the minimum element in every iteration
            if array[j] < array[min_index]:
                min_index = j
         # swapping the elements to sort the array
        (array[ind], array[min_index]) = (array[min_index], array[ind])
 
# def ReadDataFromFile(filename):
#     with open(filename, 'r') as file:
#         data = [int(line.strip()) for line in file]
#     return data

# filename = "list1000.txt"
# data = ReadDataFromFile(filename)

totalValue = 0
sizeArray = 100000

for j in range (0, 16):
    num_list = []
    for i in range(0, sizeArray):
        num_list.append(random.randint(0, 2000)+1)
        
    start = time.time()
    selectionSort(num_list, sizeArray)
    stop = time.time()
    
    execution_time_microseconds = (stop - start) * 1e6
    totalValue += execution_time_microseconds
    print("Currently completed ", j+1, "sorts")
    
avgValue = totalValue / 16
print("On average", avgValue, " microseconds to complete")
