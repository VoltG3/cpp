
// PD2 Kartosanas Algoritmi - Danoss - 10/02/2021 - Sublime Text 3.2.2v
// Merge sorting algorithm - classic

// https://www.softwaretestinghelp.com/merge-sort/

void merge(int *, int, int, int, int);

void sort_merge(int *arr, int low, int high, int size, int *pointer_count) {
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low + high)/2;
        sort_merge(arr, low, mid, size, pointer_count);
        sort_merge(arr, mid+1, high, size, pointer_count);
        //merge or conquer sorted arrays
        merge(arr, low, high, mid, size);
    }  *(pointer_count) += 1;  // [!CIKLU SKAITITAJS!]
}
// Merge sort 
void merge(int *arr, int low, int high, int mid, int size) { // ! Visual Studio 16.7.3v - kompilators nepienem massivu ar 'c[size]'
    int i, j, k, c[100];                                     // ! -Xcode 12.2v                pielauj c[size]
    i = low;                                                 // ! -Dev C++ 5.11v              pielauj c[size]
    k = low;                                                 // ! -macOS Clang v.1200(gnu+11) pielauj c[size]
    j = mid + 1;                                             // ! nezinu ar kadu programmu tiks testets darbs, tamdel ieliku manuali 'garumu' c[100]   
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}