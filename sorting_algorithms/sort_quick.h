// PD2 Kartosanas Algoritmi - Danoss - 10/02/2021 - Visual Studio 17.7.3v
// Quick sorting algorithm - rekursivs

// https://www.programiz.com/dsa/quick-sort

//void swap(int *, int *);

void swap(int *, int *);
int partition(int [], int, int, int *);

void sort_quick(int array[], int low, int high, int *pointer_count) {
  if (low < high) {
    // Select pivot position and put all the elements smaller 
    // than pivot on left and greater than pivot on right
    int pi = partition(array, low, high, pointer_count);

    // Sort the elements on the left of pivot
    sort_quick(array, low, pi - 1, pointer_count);

    // Sort the elements on the right of pivot
    sort_quick(array, pi + 1, high, pointer_count);
  }
}

// Function to swap position of elements
//void swap(int *a, int *b) {
//  int t = *a;
//  *a = *b;
//  *b = t;
//}

// Function to partition the array on the basis of pivot element
int partition(int array[], int low, int high, int *pointer_count) {
  // Select the pivot element
  int pivot = array[high];
  int i = (low - 1);

  // Put the elements smaller than pivot on the left 
  // and greater than pivot on the right of pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    } *(pointer_count) += 1; // [!CIKLU SKAITITAJS!]
  }
  //printArray(array, 7);
  //cout << "........\n";
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}