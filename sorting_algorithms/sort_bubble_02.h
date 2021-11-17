
// PD2 Kartosanas Algoritmi - Danoss - 06/02/2021 -Xcode 12.2v
// Bubble sorting algorithm - papildinats

    void sort_bubble_02 (int arr[], int size, int *pointer_count){
        for(int i = 0; i < size - 1; i++){
            for(int j = 0; j < size - (i + 1); j++){ // Modifikacija
                if(arr[j] > arr[j + 1]){
                    swap(arr[j], arr[j+1]);
                }
            *(pointer_count) += 1; // [!CIKLU SKAITITAJS!]
            }
        } cout << endl;
    }