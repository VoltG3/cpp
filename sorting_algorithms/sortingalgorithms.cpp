#include <iostream> 
#include <iomanip>  // setw();
#include <string>
#include <thread>   // sleep(), lib. for #chrono
#include <chrono>   // date and time { C++11
// stdlib ?
//#include <stdio.h>
//#include <stdlib.h>
#include <ctype.h>   // isdigit? tikai ----> cctype???
#include "colors.h"         // --> terminala krasas { WIN32 & macOS
#include "info.h"           // --> teksti { metozu isapraksti
#include "sort_bubble_01.h" // ---------
#include "sort_bubble_02.h" // -----------
#include "sort_bubble_03.h" // -------------
#include "sort_quick.h"     // ---------------  Protams, pareizak butu visus algoritmus ievietot viena datne,
#include "sort_insertion.h" // ---------------  bet sobrid (apgustot) ertibas labad katru algoritmu izvietoju atseviski
#include "sort_merge.h"     // -------------
#include "sort_shell.h"     // -----------
#include "sort_selection.h" // ---------

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//      PD2 Kartosanas Algoritmi - Danoss - 03/02/2021 - Xcode 12.2v & Visual Studio 17.7.3v        //
//                                                                                                  // 
//////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std; 

void clear_screen() {   // Funkcija terminalim { attirit ekranu
#ifdef _WIN32
    system("cls");      // Ja MS-DOS { clear screen
#else
    system("clear");    // ja macOS  { clear
#endif
}

void swap(int *a, int*b){ // Izcelta mainas funkcija galvenokart prieks { sort_selection & sort_quick
    int temp = *a;
    *a = *b;
    *b = temp;  
}

void cout_arr(int[]);           // masiva izvade
void copy_arr(int[], int[]);    // masiva kopesana
void cout_header();             // galvenes izvade
void cout_izvelne(int, int*, int*, int*, int*, int*, int*, int*, int*); // izvelnes izvade
void target_izvelne(int ,int);  // "nospiestas" pogas ietonesana
void check_count(int*);         // parbaude { vai drikst izvadit algoritma veikto 'ciklus kaitu'
 int check_meny();              // parbauda { vai ir ievadits cipars & IZVELNES IEVADE
void pause();                   // Uz ekrana izvades iepauzesana

int main(int argc, const char* argv[]) {

    int arr[] = { 54, 70, 75, 63, 17, 59, 87, 16, 93, 81, 60, 67, 90, 53, 88, 9, 61, 8, 96, 98, 12, 34, 66, 76, 38, 55, 58, 27, 92, 45, 41, 4, 20, 22, 69, 77, 86, 35, 19, 32, 49, 15, 29, 23, 83, 95, 25, 91, 33, 47, 24, 62, 13, 42, 73, 44, 78, 72, 7, 5, 10, 48, 71, 18, 39, 97, 64, 79, 51, 74, 31, 37, 57, 30, 94, 80, 28, 1, 56, 85, 46, 100, 82, 40, 26, 21, 68, 43, 14, 3, 65, 99, 89, 52, 84, 36, 2, 6, 11, 50 };
    const int size = sizeof(arr) / sizeof(arr[0]); // Tiek aprekinata masiva lielums(garums)
    //  POINTER ir vajadzigs prieks 'veikto ciklu' skaita atainosanas
    int A1[size], count_A1 = 0; int* pointer_A1 = &count_A1; copy_arr(A1, arr);  // A1 - Burbulkartosana   
    int A2[size], count_A2 = 0; int* pointer_A2 = &count_A2; copy_arr(A2, arr);  // A2 - Burbulkartosana, papildinata
    int A3[size], count_A3 = 0; int* pointer_A3 = &count_A3; copy_arr(A3, arr);  // A3 - Burbulkartosana, uzlabots papildinajums
    int A4[size], count_A4 = 0; int* pointer_A4 = &count_A4; copy_arr(A4, arr);  // A4 - Ievietosanas kartosana
    int A5[size], count_A5 = 0; int* pointer_A5 = &count_A5; copy_arr(A5, arr);  // A5 - Atra kartosana
    int A6[size], count_A6 = 0; int* pointer_A6 = &count_A6; copy_arr(A6, arr);  // A6 - Sapludinasanas kartosana
    int A7[size], count_A7 = 0; int* pointer_A7 = &count_A7; copy_arr(A7, arr);  // A7 - Caulas kartosana
    int A8[size], count_A8 = 0; int* pointer_A8 = &count_A8; copy_arr(A8, arr);  // A8 - Atlases kartosana

    // - Programmas kermenis (Body) -------------------------------------------
    clear_screen();
    cout_header();
    cout_arr(arr);
    int MENY = 0;
    cout_izvelne(MENY, pointer_A1, pointer_A2, pointer_A3, pointer_A4, pointer_A5, pointer_A6, pointer_A7, pointer_A8);

    while (1) {
       
        MENY = check_meny();

        switch (MENY) {
        case 1:
            clear_screen(); // 1. attirit ekranu
            if(*(pointer_A1) == 0){ // 2. ja 'cilu skaits' == 0 ...
                 sort_bubble_01(A1, size, pointer_A1); //       ... tad sakartot masivu un piefikset veikto 'ciklu skaitu'
            }
                cout_header(); // 3. izdrukat galveni
                cout_arr(arr); // 4. izdrukat 'sakartojamo' masivu
                cout_izvelne(MENY, pointer_A1, pointer_A2, pointer_A3, pointer_A4, pointer_A5, pointer_A6, pointer_A7, pointer_A8); // 5. izdrukat izvelni
                pause(); // 6. iepauzet turpmakas darbibas 'citadi rezultats paradas 'nepiefiksejami' atri.
            cout << "\n\n KLASISKA BURBULKARTOSANAS ALGORITMS"; // 7. Izdrukat izveleta algoritma virsrakstu
            cout_arr(A1); // 8. izdrukat masivu, sakartoto ar izveletu algoritmu
            info(MENY); // 9. izdrukat isu info par izveleto algoritmu
            continue;
        case 2:
            clear_screen();
            if(*(pointer_A2) == 0){
                sort_bubble_02(A2, size, pointer_A2);
            }
                cout_header();
                cout_arr(arr);
                cout_izvelne(MENY, pointer_A1, pointer_A2, pointer_A3, pointer_A4, pointer_A5, pointer_A6, pointer_A7, pointer_A8);
                pause();
            cout << "\n\n PAPLDINATS BURBULKARTOSANA ALGORITMS";
            cout_arr(A2);
            info(MENY);
            continue;
        case 3:
            clear_screen();
            if(*(pointer_A3) == 0){
                sort_bubble_03(A3, size, pointer_A3);
            }
                cout_header();
                cout_arr(arr);
                cout_izvelne(MENY, pointer_A1, pointer_A2, pointer_A3, pointer_A4, pointer_A5, pointer_A6, pointer_A7, pointer_A8);
                pause();
            cout << "\n\n UZLABOTS BURBULKARTOSANA ALGORITMS";
            cout_arr(A3);
            info(MENY);
            continue;
        case 4:
            clear_screen();
            if(*(pointer_A4) == 0){
                sort_insertion(A4, size, pointer_A4);
            }
                cout_header();
                cout_arr(arr);
                cout_izvelne(MENY, pointer_A1, pointer_A2, pointer_A3, pointer_A4, pointer_A5, pointer_A6, pointer_A7, pointer_A8);
                pause();
            cout << "\n\n IEVIETOSANAS KARTOSANAS ALGORITMS";
            cout_arr(A4);
            info(MENY);
            continue;
        case 5:
            clear_screen();
            if(*(pointer_A5) == 0){
                sort_quick(A5, 0, size -1, pointer_A5); // no size!!
            }
                cout_header();
                cout_arr(arr);
                cout_izvelne(MENY, pointer_A1, pointer_A2, pointer_A3, pointer_A4, pointer_A5, pointer_A6, pointer_A7, pointer_A8);
                pause();
            cout << "\n\n ATRAS KARTOSANAS ALGORITMS";
            cout_arr(A5);
            info(MENY);
            continue;
        case 6:
            clear_screen();
            if(*(pointer_A6) == 0){
                sort_merge(A6, 0, size-1, size, pointer_A6); // no size!! !!!!!!!! num_!
            }
                cout_header();
                cout_arr(arr);
                cout_izvelne(MENY, pointer_A1, pointer_A2, pointer_A3, pointer_A4, pointer_A5, pointer_A6, pointer_A7, pointer_A8);
                pause();
            cout << "\n\n SAPLUDINASANAS (KARTOSANAS) ALGORITMS";
            cout_arr(A6);
            info(MENY);
            continue;
        case 7:
            clear_screen();
            if(*(pointer_A7) == 0){
                sort_shell(A7, size, pointer_A7); // no size!! !!!!!!!! num_!
            }
                cout_header();
                cout_arr(arr);
                cout_izvelne(MENY, pointer_A1, pointer_A2, pointer_A3, pointer_A4, pointer_A5, pointer_A6, pointer_A7, pointer_A8);
                pause();
            cout << "\n\n CAULAS KARTOSANAS ALGORITMS";
            cout_arr(A7);
            info(MENY);
            continue;
        case 8:
            clear_screen();
            if(*(pointer_A8) == 0){
                sort_selection(A8, size, pointer_A8); // no size!! !!!!!!!! num_!
            }
                cout_header();
                cout_arr(arr);
                cout_izvelne(MENY, pointer_A1, pointer_A2, pointer_A3, pointer_A4, pointer_A5, pointer_A6, pointer_A7, pointer_A8);
                pause();
            cout << "\n\n ATLASES KARTOSANAS ALGORITMS";
            cout_arr(A8);
            info(MENY);
            continue;
        case 9:
            return 1;
            break;
        }
    }

    return 0;
}

// Funkcija { masiva kopesana -------------------------------------
void copy_arr(int A[], int arr[]) {
    for (int i = 0; i < 100; i++) {
        A[i] = arr[i];
    }
}
// Funkcija { masiva izvade ---------------------------------------
void cout_arr(int arr[]) {
    cout << endl << endl;
    int number_size = 0;
    for (int i = 0; i < 100; i++) {
        number_size = arr[i];

        if (number_size > 99) {                   // Vizuali pareizi izvadit veselo skaitli...
            cout << setw(2) << arr[i] << " ";     // ... tabulaa, ja skaitlis ir lielaks par 99
        }
        else {
            cout << setw(3) << arr[i] << " ";
        }
       
        if (i == 24 || i == 49 || i == 74) { cout << endl; } // Tabulas rindas parnese jaunaa rindaa

    } cout << endl;
}
// Funkcija { galvenes izvade -------------------------------------
void cout_header() {
    for(int i = 0; i < 100; i++){ cout << BOLDCYANBG << " "; } cout << endl;
    cout << " MASIVU SAKARTOSANAS ALGORITMI";
    for(int i = 0; i < 70; i++){ cout << " ";} cout << endl;
    for(int i = 0; i < 100; i++){ cout << BOLDWHITEU << BOLDCYANBG << " ";} cout << RESET << endl; 
}
// Funkcija { izvelnes izvade -------------------------------------
void cout_izvelne(int meny_numm, int* pointer_a1, int* pointer_a2, int* pointer_a3, int* pointer_a4, int* pointer_a5, int* pointer_a6, int* pointer_a7, int* pointer_a8) {
    int x = 0;
    cout << "\n\t [!] IZVELIES METODI AR KURU SAKARTOT SO MASIVU!";
    cout << "\n\t"; x = 1; target_izvelne(x, meny_numm); cout << " [1]" << " Burbulkartosanas algoritms - klasiskais  " << RESET << "\t\t" << "Cilu skaits - "; check_count(pointer_a1);
    cout << "\n\t"; x = 2; target_izvelne(x, meny_numm); cout << " [2]" << " Burbulkartosanas algoritms - uzlabots    " << RESET << "\t\t" << "Cilu skaits - "; check_count(pointer_a2);
    cout << "\n\t"; x = 3; target_izvelne(x, meny_numm); cout << " [3]" << " Burbulkartosanas algoritms - papildinats " << RESET << "\t\t" << "Cilu skaits - "; check_count(pointer_a3);
    cout << "\n\t"; x = 4; target_izvelne(x, meny_numm); cout << " [4]" << " Ievietosanas (kartosanas algoritms)      " << RESET << "\t\t" << "Cilu skaits - "; check_count(pointer_a4);
    cout << "\n\t"; x = 5; target_izvelne(x, meny_numm); cout << " [5]" << " Atras kartosanas algoritms               " << RESET << "\t\t" << "Cilu skaits - "; check_count(pointer_a5);
    cout << "\n\t"; x = 6; target_izvelne(x, meny_numm); cout << " [6]" << " Sapludinasanas (kartosanas) algoritms    " << RESET << "\t\t" << "Cilu skaits - "; check_count(pointer_a6);
    cout << "\n\t"; x = 7; target_izvelne(x, meny_numm); cout << " [7]" << " Caulas kartosanas algoritms              " << RESET << "\t\t" << "Cilu skaits - "; check_count(pointer_a7);
    cout << "\n\t"; x = 8; target_izvelne(x, meny_numm); cout << " [8]" << " Atlases kartosanas algoritms             " << RESET << "\t\t" << "Cilu skaits - "; check_count(pointer_a8);
    cout << "\n\t [9]" << " EXIT" << endl;
}
// Funkcija { "nospiestas" pogas ietonesana -----------------------
void target_izvelne(int X, int MENY_NUMM){
    if(X == MENY_NUMM){         // x = { lietotaja izveleta sadala no izvelnes...  
        cout << BOLDCYANBG;     // ... { ta tiek ietoneta
    }
}
// Funkcija { parbauda vai drikst izvadit algoritma veikto 'ciklus kaitu'
void check_count(int* COUNT) {
    if (*(COUNT) == 0) {
        cout << RED << setw(4) << "n/a" << RESET;
    }
    else {
        cout << BOLDBLUE << setw(4) << *(COUNT) << RESET;
    }
}
// Funkcijas { Parbaude { vai ir ievadits cipars & IZVELNES IEVADE
int check_meny() {
    int meny = 0;
    string str;

    while (1) {
        cout << "\n\t [?] --> ";
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            char ch = str.c_str()[i]; // Parveidot STRING par CHAR

            if (!isdigit(ch)) { cout << RED << " Jaievada cipars!" << RESET; } // ja nav ievadits cipars
            else { meny = atoi(str.c_str()); } // savada parverst par INT

            if (meny > 9) { cout << RED << " Jaievada vienu ciparu no 1 lidz 9!" << RESET; } // ja ievadits cipars lielaks par 9

            if (meny > char(47) || meny < char(58)) { // Ja ievadits ASCII cipar 1-9 { tad atgriest INT

                return meny;
            }
        }
    }
}
// Funkcija { Iepauze 'Body' izvadi -------------------------------
void pause(){
    cout.flush();
    this_thread::sleep_for(chrono::milliseconds(250) );  // 1s = 10000  
}