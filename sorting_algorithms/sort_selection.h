// PD2 Kartosanas Algoritmi - Danoss - 11/02/2021 - Sublime Text 3.2.2v
// Selection sorting algorithm - rekursivs

// https://www.programiz.com/dsa/selection-sort

void swap(int *, int *);

void sort_selection(int array[], int size, int *pointer_count) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        
        for (int i = step + 1; i < size; i++) {
            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx]){
                min_idx = i;
            } *(pointer_count) += 1; // [!CIKLU SKAITITAJS!]
        }
    swap(&array[min_idx], &array[step]);  // put min at the correct position
    }
}

// function to swap the the position of two elements
/*void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}*/
