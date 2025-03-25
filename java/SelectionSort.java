// Java program for implementation of Selection Sort 
// import java.io.*;
// import java.util.Scanner;
import java.util.Random;

public class SelectionSort 
{ 
	void sort(int arr[]) 
	{ 
		int n = arr.length; 

		// One by one move boundary of unsorted subarray 
		for (int i = 0; i < n-1; i++) 
		{ 
			// Find the minimum element in unsorted array 
			int min_idx = i; 
			for (int j = i+1; j < n; j++) 
				if (arr[j] < arr[min_idx]) 
					min_idx = j; 

			// Swap the found minimum element with the first 
			// element 
			int temp = arr[min_idx]; 
			arr[min_idx] = arr[i]; 
			arr[i] = temp; 
		} 
	} 

	// Prints the array 
	void printArray(int arr[]) 
	{ 
		int n = arr.length; 
		for (int i=0; i<n; ++i) 
			System.out.print(arr[i]+" "); 
		System.out.println(); 
	} 

	// Driver code to test above 
	public static void main(String args[]) 
	{ 
		SelectionSort ob = new SelectionSort();
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

        for (int j = 0; j < 16; j++) {
			for (int i = 0; i < totalData.length; i++) {
				Random rand = new Random();
				totalData[i] = rand.nextInt(2000) + 1;
			}
			start = System.nanoTime();
			ob.sort(totalData);
			stop = System.nanoTime();
			duration = (stop - start)/1000;
			//System.out.println("Sorted array");
			//ob.printArray(totalData);
			totalDuration += duration;
			//System.out.printf("Completion time: %.3f microseconds", duration);
		}
		
		avgDuration = totalDuration / 16;

		System.out.printf("Completion time: %.2f microseconds", avgDuration);
	} 
} 
