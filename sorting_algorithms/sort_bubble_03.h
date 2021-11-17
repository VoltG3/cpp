
// PD2 Kartosanas Algoritmi - Danoss - 06/02/2021 -Xcode 12.2v
// Bubble sorting algorithm - uzlabots papildinajums

    void sort_bubble_03 (int arr[], int size, int *pointer_count){
        for(int i = 0; i < size; i++){
            bool flag = true;
                for(int j = 0; j < 100 - (i + 1); j++){ // Modifikacija
                    if(arr[j] > arr[j + 1]){
                        swap(arr[j], arr[j+1]);
                        flag = false;
                    } *(pointer_count) += 1; // [!CIKLU SKAITITAJS!]
                }
            if (flag){ break;}
        } cout << endl;
}