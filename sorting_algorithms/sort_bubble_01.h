
// PD2 Kartosanas Algoritmi - Danoss - 06/02/2021 -Xcode 12.2v
// Bubble sorting algorithm - classic

// https://qnaplus.com/implement-bubble-sort-c/
// https://codelessons.ru/cplusplus/algoritmy/puzyrkovaya-sortirovka-v-c-glavnye-momenty.html

    void sort_bubble_01 (int arr[], int size, int *pointer_count){
        for(int i = 0; i < size - 1 ; i++){ // jo 0 bet ciklu ir 100 tatad 101
            for(int j = 0; j < size - 1; j++){ // ! 100 insetefor 'size'
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                }
                *(pointer_count) += 1; // [!CIKLU SKAITITAJS!]
            }
        } cout << endl;
    }