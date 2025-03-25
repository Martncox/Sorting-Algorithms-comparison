import time
import random

def print_list(list):
    for i in list:
        print(i)

def merge(num_list, left, mid, right):

    left_sublist = [] 
    right_sublist = [] 

    for i in range(0, mid - left + 1): ## fill left sublist with left side of num_list
        left_sublist.append(num_list[left + i])
    
    for j in range(0, right - mid): ## fill right sublist with right side of num_list
        right_sublist.append(num_list[mid + 1 + j])

    merged_list_index = left ## index variable for sorting the main list
    left_iter = 0  ## int to iterate through the left sublist
    right_iter = 0 ## int to iterate through the right sublist

    while (left_iter < len(left_sublist) and right_iter < len(right_sublist)):
        if (left_sublist[left_iter] <= right_sublist[right_iter]):
            num_list[merged_list_index] = left_sublist[left_iter]
            left_iter += 1
        else:
            num_list[merged_list_index] = right_sublist[right_iter]
            right_iter += 1

        merged_list_index += 1

    while (left_iter < len(left_sublist)):
        num_list[merged_list_index] = left_sublist[left_iter]
        left_iter += 1
        merged_list_index += 1

    while (right_iter < len(right_sublist)):
        num_list[merged_list_index] = right_sublist[right_iter]
        right_iter += 1
        merged_list_index += 1

def merge_sort(num_list, start, end):
    if start >= end:
        return

    partition = start + (end - start) // 2
    merge_sort(num_list, start, partition)
    merge_sort(num_list, partition + 1, end)
    merge(num_list, start, partition, end)

##f = open("list1000.txt", "r")

num_list = []

##for number in f:
    ##num_list.append(int(number))

##f.close()

total_duration = 0.0

for j in range(0, 16):
    
    for i in range(0, 4000):
        num_list.append(random.randint(1, 2000))
        start =  time.time()
        merge_sort(num_list, 0, len(num_list) - 1)
        stop = time.time()

        duration = (stop - start) * 1e6

        total_duration += duration

        num_list.clear()
    
    print("merge sort ", j + 1, " done")
    #print(len(num_list))

    #print_list(num_list)

avg_duration = total_duration / 16

##print_list(num_list)
print("Average Duration: {:.2f} microseconds".format(avg_duration))



