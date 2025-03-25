import java.util.Arrays;
// import java.util.Scanner;
// import java.io.*;
import java.util.Random;

class Quicksort {

  // method to find the partition position
  static int partition(int array[], int low, int high) {
    
    // choose the rightmost element as pivot
    int pivot = array[high];
    
    // pointer for greater element
    int i = (low - 1);

    // traverse through all elements
    // compare each element with pivot
    for (int j = low; j < high; j++) {
      if (array[j] <= pivot) {

        // if element smaller than pivot is found
        // swap it with the greater element pointed by i
        i++;

        // swapping element at i with element at j
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }

    }

    // swapt the pivot element with the greater element specified by i
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    // return the position from where partition is done
    return (i + 1);
  }

  static void quickSort(int array[], int low, int high) {
    if (low < high) {

      // find pivot element such that
      // elements smaller than pivot are on the left
      // elements greater than pivot are on the right
      int pi = partition(array, low, high);
      
      // recursive call on the left of pivot
      quickSort(array, low, pi - 1);

      // recursive call on the right of pivot
      quickSort(array, pi + 1, high);
    }
  }
}

// Main class
class Main {
    public static void main(String args[]) {

    Quicksort ob = new Quicksort();
    int[] totalData = new int[1000];
    //int lineNum = 0;
    double start, stop, duration;
    double totalDuration = 0.0;
    double avgDuration;

    // try {
    //     File myObj = new File("list1000.txt");
    //     Scanner myReader = new Scanner(myObj);
    //     while (myReader.hasNextLine()) {
    //         String data = myReader.nextLine();
    //         totalData[lineNum] = Integer.parseInt(data);
    //         lineNum++;
    //     }
    //     myReader.close();
    // } catch (FileNotFoundException e) {
    //     System.out.println("An error occurred.");
    //     e.printStackTrace();
    // }
    int size = totalData.length;

    for (int j = 0; j < 16; j++) {
            for (int i = 0; i < size; i++) {
                Random rand = new Random();
                totalData[i] = rand.nextInt(2000) + 1;
            }
            
            start = System.nanoTime();
            // call quicksort() on array data
            Quicksort.quickSort(totalData, 0, size - 1);
            stop = System.nanoTime();
            duration = (stop - start)/1000;
            //System.out.println("Sorted array");
            //System.out.println("Sorted Array in Ascending Order ");
            //System.out.println(Arrays.toString(totalData));
            //System.out.printf("Completion time: %.2f microseconds", duration);
            totalDuration += duration;
        }
        avgDuration = totalDuration / 16;
        System.out.printf("Completion time: %.2f microseconds", avgDuration);
    }
    
}