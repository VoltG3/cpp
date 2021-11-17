#include <iostream>

// Kristians Danoss / patstavigais darbs MD5 / 13sep2021
//
// g++ file.cpp -std=c++11 } ! piezime, kompilesanai
// echo $?                 } ! piezime, parbaude uz (return 0)

using namespace std;

// Funkciju saraksts kompilatoram
void clear();
void space(int);

class date {
    private: 
        int DIENA;
        int MENES;
        int GADS;
    
    public:
        date();
        date(int, int, int, date, date);
        ~date(){ /*cout << "\n  -> Called destructor" << endl;*/ }
          void SetDate(int diena, int menes, int gads);
          void dateUpdate(int diena, int menes, int gads);
          void dateDiff(date Obj01, date Obj02);
        
          void GetDate(){ cout <<  DIENA << "/"<< MENES << "/" << GADS; }
          int GetD() { return DIENA; } // atgriez Objekta { dienu
          int GetM() { return MENES; } // atgriez Objekta { menesi
          int GetG() { return GADS;  } // atgriez Objekta { gadu
};
        // Default vertibas izsaucot klassi
    date::date() {      
        DIENA = 0;
        MENES = 0;
        GADS = 0;
    } 
        // Default konstruktors { metozu saraksts
    date::date(int diena, int menes, int gads, date Obj01, date Obj02) {   
        SetDate(diena, menes, gads);
        dateUpdate(diena, menes, gads);
        dateDiff(Obj01, Obj02);
    }
        // Konstruktors ar argumentiem
    void date::SetDate(int diena, int menes, int gads) {
        DIENA = diena;
        MENES = menes;
        GADS = gads;
    }
        // Metode { + viena diena
    void date::dateUpdate(int diena, int menes, int gads){

        if(diena + 1 <= 30) {           // ja       { 30 mazaks par DIENA + 1
            diena += 1;                 // tad      { DIENA + 1
        } else {                        // citadi   { 
            diena = 1;                  //            DIENA = 1 ...
                if(menes + 1 <= 12) {   // ... ja   { 12 mazaks par MENES + 1
                    menes += 1;         // .. tad   { MENES + 1
                } else {                // . citadi { :: 
                    menes = 1;          //            :: MENES ir Janvaris 
                    gads += 1;          //            :: GADS + 1
                }
         }

        cout <<  diena  << "/" << menes << "/" << gads  << endl;
    }
        // Metode { starpibas summa starp diviem objektiem
    void date::dateDiff(date Obj01, date Obj02) {
        int first_date = (((Obj01.GetG() * 12) + Obj01.GetM()) * 30) + Obj01.GetD();
        int secon_date = (((Obj02.GetG() * 12) + Obj02.GetM()) * 30) + Obj02.GetD();
       
        int rez = 0; // Minusot mazako Objektu no lielaka Objekta { pozitivam rezultatam
            if (first_date < secon_date) { 
                rez = secon_date - first_date;
            } else {
                rez = first_date - secon_date;
            }
            
                cout << "\n     Obj(1) -> " << first_date;
                cout << "\n     Obj(2) -> " << secon_date;
                cout << "\n     REZULT -> " << rez;
    }

int main() {

        clear();
        space(5);

            int day = 30;   // 12;
            int mon = 12;   // 02;
            int yer = 2021; // 1892;

                date D1;    
                //date *d1 = &D1;
                    D1.SetDate(day, mon, yer);
                        cout << "\n  -----{ Object 1 } ----------------------" << endl;
                        cout << "\n           date INPUT      -> ";
                    D1.GetDate();
                        cout << "\n  date Update + 1 day      -> ";
                    D1.dateUpdate(day, mon, yer);
                
            day = 30;   // 7;
            mon = 11;   // 02;
            yer = 2021; // 1982;

                date D2;
                //date *d2 = &D2;
                    D2.SetDate(day, mon, yer);
                        cout << "\n  -----{ Object 2 } ----------------------" << endl;
                        cout << "\n           date INPUT      -> ";
                    D2.GetDate();
                        cout << "\n  date Update + 1 day      -> ";
                    D2.dateUpdate(day, mon, yer);
                        cout << "\n  -----{ Days Between } ------------------" << endl;
                    D2.dateDiff(D1, D2);
                        cout << endl;
                        cout << "\n  -> END " << endl << endl;
        
        space(2);
    return 0;
}

// Funkcija { attirit ekranu
void clear(){ system("clear"); }
// Funkcija { <br>
void space(int x)  {
    for(int i = 0; i < x;  i++){
        cout << endl;
    }
}