// PD2 Kartosanas Algoritmi - Danoss - 10/02/2021 - Sublime Text 3.2.2v
// Insertion sort algorithm

// https://purecodecpp.com/archives/2576

void sort_insertion(int *arr, int size, int *pointer_count) {  // der pusizveid.mass
     int j_= 0, buff = 0;
         for(int i = 1; i < size; i++){ // ! i = 1
             buff = arr[i];
             j_ = i - 1;
                 while(j_ >= 0 && arr[j_] > buff){
                     arr[j_ + 1] = arr[j_];
                     j_ = j_ - 1;
                     *(pointer_count) += 1; // [!CIKLU SKAITITAJS!]
                 } arr[j_ + 1] = buff;
             
         } cout << endl;
}