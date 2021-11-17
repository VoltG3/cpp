#include<iostream>  // input & output
#include<iomanip>   // std::setfill  std::setw

// Kristians Danoss / patstavigais darbs MD5 / 20sep2021

using namespace std;

// Funkciju saraksts kompilatoram
void clear();
void space(int);
void fill();

// --------------------------------------------------------------------------------------

class Date {
    private: 
        int DIENA;
        int MENES;
        int GADS;
    
    public:
        Date();
        Date(int, int, int, Date, Date);
        ~Date(){ /*cout << "\n  -> Called destructor" << endl;*/ }
          void SetDate(int diena, int menes, int gads);
          void DateUpdate();
          void DateDiff(Date Obj01, Date Obj02);
        
          void GetDate(){ cout <<  DIENA << "/"<< MENES << "/" << GADS; }
          int GetD() { return DIENA; } // atgriez Objekta { dienu
          int GetM() { return MENES; } // atgriez Objekta { menesi
          int GetG() { return GADS;  } // atgriez Objekta { gadu
};
        // Default vertibas izsaucot klassi
        Date::Date() {      
            DIENA = 0;
            MENES = 0;
            GADS = 0;
        } 
        // Default konstruktors { metozu saraksts
        Date::Date(int diena, int menes, int gads, Date Obj01, Date Obj02) {   
            SetDate(diena, menes, gads);
            DateUpdate();
            DateDiff(Obj01, Obj02);
        }
        // Konstruktors ar argumentiem
        void Date::SetDate(int diena, int menes, int gads) {
            DIENA = diena;
            MENES = menes;
            GADS = gads;
        }
        // Metode { + viena diena
        void Date::DateUpdate(){
            int diena = GetD();
            int menes = GetM();
            int gads  = GetG();
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
            fill();
            cout << diena << "/";
            fill();
            cout << menes << "/" << gads; // ------- ENDL;
        }
        // Metode { starpibas summa starp diviem objektiem
        void Date::DateDiff(Date Obj01, Date Obj02) {
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

// --------------------------------------------------------------------------------------

class Time : public Date {  // Mantosana
    private: 
        int MINUTES;
        int STUNDAS;
    
    public:
        Time();       
        Time(int, int);
        ~Time(){ /*cout << "\n  -> Called destructor" << endl; */ }
          void SetTime(int , int);
          void TimeUpdate();
          void GetTime() { 
                fill();
                    cout << STUNDAS << ":";
                fill(); 
                    cout << MINUTES; 
               }
          void DateAndTime();
           int GetMin() { return MINUTES; } // atgriez Objekta { stundu
           int GetStn() { return STUNDAS; } // atgriez Objekta { minuti 
};
        // Default vertibas izsaucot klassi
        Time::Time() {      
            MINUTES = 0;
            STUNDAS = 0;
        } 
        // Default konstruktors { metozu saraksts
        Time::Time(int minutes, int stundas) {   
            SetTime(minutes, stundas);
            TimeUpdate();
            DateAndTime();
        }
        // Konstruktors ar argumentiem
        void Time::SetTime(int minutes, int stundas) {
            MINUTES = minutes;
            STUNDAS = stundas;
        }
        // Metode { + viena diena
        void Time::TimeUpdate(){
            int minutes = GetMin();
            int stundas = GetStn();
            if(minutes + 1 <= 59) {          // ja       { 59 mazaks par STUNDAS + 1
                minutes += 1;                // tad      { STUNDAS + 1
            } else {                         // citadi   { 
                minutes = 0;                 //            MINUTES = 0 ...
                    if(stundas + 1 <= 23) {  // ... ja   { 23 mazaks par STUNDAS + 1
                        stundas += 1;        // .. tad   { STUNDAS + 1
                    } else {                 // . citadi { :: 
                        stundas = 0;         //            :: STUNDAS = 0 
                    }
            }

            fill();
            cout << stundas  << ":";
            fill(); 
            cout << minutes; // ------- ENDL;
        }
        // Metode { apvienotas metodes { DateUpdate(); --UN-- TimeUpdate()
        void Time::DateAndTime(){ 
            cout << "\n  ";

        /*  
            TimeUpdate();                          // Metode --> pluss 1 minute                                                       
                if(GetMin()==59 && GetStn()==23) { //     ja --> laiks ir 23:59
                    DateUpdate();                  //    tad --> Metode no DATE, kura pieskaita +1 dienu
                } else {                           // citadi -->
                    GetDate();                     //        --> Metode no DATE, izdrukat datumu (!NE +1 diena)
                }
        */
       
        // ! CITA verisja { Lai drukatos sakuma datums ubn pectam laiks
            if(GetMin()==59 && GetStn()==23) {    //          ja --> laiks ir 23:59
                DateUpdate();                     // DATE metode --> +1 diena   
                cout << " - ";                    //
                TimeUpdate();                     // TIME metode --> +1 minute
            } else {                              //      citadi ...
                GetDate();                        // DATE metode --> +0 dienas (izdrukat datumu { !NE +1 diena) 
                cout << " - ";                    //
                TimeUpdate();                     // TIME metode --> +1 minute
            }
        }

// --------------------------------------------------------------------------------------

int main(){

    // DATE
    clear();
        space(5);

            int day = 30;   
            int mon = 12;   
            int yer = 2021; 
            int min = 59;   
            int stn = 23; 

                Time T1;    
                //date *d1 = &D1;
                    T1.SetDate(day, mon, yer);
                        cout << "\n  -----{ Object 1 } ----------------------" << endl;
                        cout << "\n           date INPUT      -> ";
                    T1.GetDate();
                        cout << "\n  date Update + 1 day      -> ";
                    T1.DateUpdate();
                    space(1);
                // -------------------------------------------------
                    T1.SetTime(min, stn); 
                        cout << "\n           time INPUT      -> ";
                    T1.GetTime();
                        cout << "\n  time Update + 1 min      -> ";
                    T1.TimeUpdate();  
                    space(1);  
                // -------------    
                        cout << "\n  -----{ DateAndTime(); [ +1 min] } ------" << endl;
                    T1.DateAndTime(); 
                    space(1);

                space(2);


            day = 30;   
            mon = 11;   
            yer = 2021; 
            min = 8;   
            stn = 23; 

                Time T2;
                //date *d2 = &D2;
                    T2.SetDate(day, mon, yer);
                        cout << "\n  -----{ Object 2 } ----------------------" << endl;
                        cout << "\n           date INPUT      -> ";
                    T2.GetDate();
                        cout << "\n  date Update + 1 day      -> ";
                    T2.DateUpdate();
                    space(1);
                // -------------------------------------------------
                    T2.SetTime(min, stn);
                        cout << "\n           time INPUT      -> ";
                    T2.GetTime();
                        cout << "\n  time Update + 1 day      -> ";
                    T2.TimeUpdate();
                    space(1);
                // -------------    
                        cout << "\n  -----{ DateAndTime(); [ +1 min] } ------" << endl;
                    T2.DateAndTime();
                    space(1);

                // -------------------------------------------------
                // -------------------------------------------------
                    cout << "\n  -----{ Days Between } ------------------" << endl;
                    T2.DateDiff(T1, T2);
                        cout << endl;
                        cout << "\n  -> END "; 
   
        space(2);
    return 0;
}

// --------------------------------------------------------------------------------------

// Funkcija { attirit ekranu
void clear(){ system("clear"); }
// Funkcija { <br>
void space(int x)  {
    for(int i = 0; i < x;  i++){
        cout << endl;
    }
}
// Funkcija { vertibam zem 10 pievienot 0 prieksa
void fill(){
    cout << setfill('0') << setw(2);
}