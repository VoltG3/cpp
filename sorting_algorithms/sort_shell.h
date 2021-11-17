
// PD2 Kartosanas Algoritmi - Danoss - 10/02/2021 - Sublime Text 3.2.2v
// Shell sorting algorithm - classic

// https://www.softwaretestinghelp.com/shell-sort/

void sort_shell(int arr[], int N, int *pointer_count) { 
    for (int gap = N/2; gap > 0; gap /= 2) { 
        for (int i = gap; i < N; i += 1) { 
                //sort sub lists created by applying gap 
            int temp = arr[i]; 
         
            int j; 

        for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
                               
                arr[j] = temp; 
                *(pointer_count) += 1; // [!CIKLU SKAITITAJS!]
        }   
    } 
}  