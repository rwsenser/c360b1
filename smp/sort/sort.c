// Bubble sort in C
// URL: https://www.programiz.com/dsa/bubble-sort

// perform the bubble sort

// #include <stdio.h>

#include "nanoprintf.h"
#include "rwsstdio.h"

void bubbleSort(int array[], int size) {
   int step, i;
  // loop to access each array element
  for (step = 0; step < size - 1; ++step) {
      
    // loop to compare array elements
    for (i = 0; i < size - step - 1; ++i) {
      
      // compare two adjacent elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {
        
        // swapping occurs if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

#if 1
// print array
void printArray(int array[], int size) {
  int i;
  char buffer[120];
  for (i = 0; i < size; ++i) {
    printf("%d: %d", i, array[i]);
  }
  printf("");
}
#endif

int main() {
  int data[] = {-2, 45, 0, 11, -9};
  
  // find the array's length
  int size = sizeof(data) / sizeof(data[0]);

  bubbleSort(data, size);
#if 1  
  printf("Sorted Array in Ascending Order:!");
  printArray(data, size);
#endif

  return(size);
}
