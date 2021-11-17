#include <iostream> // input&output
#include <iomanip>  // std:setfill  std:setw 
#include <string>   // string

//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//
//                                                                            //
//  Kristians Danoss - patstavigais darbs 'P1617_MD5' - 20+21sep2021          //
//  Visual studio Code v-1.60.1 / g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0    //
//                  		           			 	                          //
//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//

// OOP - Objektorienteta programesana { DAZAS lietas :
//   1 - INKAPSULACIJA { noslept objektu no cita programmetaja atstajot pieejamu interfeisu
//   2 - MANTOSANA     { Klase manto metodi/es no citas klases
//   3 - POLIMORFIZMS  { Iespeja objektam reaget dazadi, metode viena, darbiba dazada
//
//   KLASE 'mainigais' { datu tips /tapat ka 'int mainigais'/ kurs sastav no vairakiem mainigajiem
//   KLASES 'objekts'  { KLASES mainigais SUBmainigais piem.'int Human'
//   KLASES 'metode'   { --> klases funkcija
//
//   MODIFIKATORI:     { PUBLIC:    { atvertais, pieejams
//                     { PRIVATE:   { slegtais, ieksejais, pieeja no klases
//                     { PROTECTED: { slegtais, noderigs pie /mantosanas/ !!!
//
//  PIEEJA no klases:  { GETTER { ilustre inkapsulaciju { metode/funkcija { 'izsaukt'  mainigo
//                     { SETTER { ilustre inkapsulaciju { metode/funkcija { 'ievietot' mainigo
//
// Konstruktors:       { .. pec noklusejuma { pamatvertibas
//                     { ..  ar parametriem { polimorfiska ipasiba
// Destruktord:        { vajadzigs ja programma iziet no redzamibas zonas -- 'redz.zona { }'
//                  ...{ dest.vajadzigs prieks atminjas atbrivosanas pec 'kada' objekta veidosanas
// THIS -->            { objekts pats norada uz sevi { lai zinatu kur vins atrodas atminja /atm.adrese/

using namespace std;

///////////////////////////////////////
//                                   //
//  Saturs:                          //
//          1 - Krasas               //
//          2 - Funkciju sartaksts   //
//          3 - Klasses              //
//          4 - Main                 //
//          5 - Funkcijas            //
//                                   //
///////////////////////////////////////

// g++ file.cpp -std=c++11 } ! piezime --> kompilesanai
// echo $?                 } ! piezime --> parbaudei terminali, vai (return 0)

// ----[ Krasas ]------------------------------------------------------------------------------------------------[1]
//                                                                                                       <--- Krasas
#ifdef _WIN32 // P.S. ---> ! Ar krasam papildinat izskatu nepietika laika :(
    #include <windows.h> // or #include <stdlib.h>
    
        enum Colors {
        Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
        DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
    };
 
    template<Colors txt = LightGray, Colors bg = Black> ostream& color(ostream &text) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
        return text;
    }
        #define RED    color<Red, Black>
        #define RESET  color<White, Black>
        #define YELLOW color<Yellow, Black>
        
        #define BOLDWHITEBG  color<White, Cyan>         
        #define BOLDWHITEU   color<White, Cyan>         
        #define BOLDCYANBG   color<White, Cyan>         
        #define DARKCYAN     color<Cyan, Black>         
        #define REDI         color<Yellow, Black>        
        #define REDU         color<Yellow, Black>       
        #define BOLDBLUE     color<LightBlue, Black>  

#else // MacOS & Linux

    #define BOLDCYAN    "\033[1m\033[36m"      // Bold Cyan 
    #define BOLDWHITE   "\033[1m\033[37m"      // Bold White 
    #define RESET       "\033[0m"              // :: DEFAULT
    #define BLACK       "\033[30m"             // Black 
    #define RED         "\033[31m"             // Red 

#endif

// ----[ Funkciju saraksts kompilatoram ]------------------------------------------------------------------------[2]
//                                                                                            <--- Funkciju saraksts

void user_input(int*, int*);                                   //     Funkcija { ievadit mainigo { dd/mm/ggg - 0:00
 int check_NUM(int, int, int);                                 // SUB Funkcija { parbaudit vertibas lielumu
void table(int, int, int, int, int, int, int, int, int, int);  //     Funkcija { izvada tabulu
 int check_NULL(int);                                          // SUB Funkcija { parbauda tabulai, vai izdrukat skaitli
void check_NUM_0(int);                                         // SUB Funkcija { iekraso sarkanu nepareizo vertibu
void fill(int);                                                // SUB Funkcija { aizpilda brivu vietu
void space(int);                                               //     Funkcija { <br>
void clear();                                                  //     Funkcija { attirit ekranu
 int check_Char(int, int);                                     //     Funkcija { parbauda vai ievadits 'integer'

// ----[ Klasses ]-----------------------------------------------------------------------------------------------[3]
//                                                                                                  <--- Klasse DATE
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

        /* // Destruktors
        Date::~Date(){
            //delete [] *... ; --> NAV ' *pinter ' !
        }*/

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
            fill(2);
            cout << diena << "/";
            fill(2);
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
                
                    cout << "\n        TimeStamp 1    ---> " << first_date;
                    cout << "\n        TimeStamp 2    ---> " << secon_date;
                    cout << "\n        Dienu starpiba ---> " << rez;
        }

//                                                                                                  <--- Klasse TIME
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
                fill(2);
                    cout << STUNDAS << ":";
                fill(2); 
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

        /* // Destruktors
        Time::~Time(){
            //delete [] *... ; --> NAV ' *pinter ' !
        } */

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

            fill(2);
            cout << stundas  << ":";
            fill(2); 
            cout << minutes; // ------- ENDL;
        }

        // Metode { apvienotas metodes { DateUpdate(); --UN-- TimeUpdate()
        void Time::DateAndTime(){ 
           
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

// ----[ MAIN ]--------------------------------------------------------------------------------------------------[4]
//                                                                                                          <-- MAIN
int main() {
    clear();

                                                            
    int DIENA_1   = 0; int *diena_1   = &DIENA_1;     
    int MENES_1   = 0; int *menes_1   = &MENES_1;     
    int GADS_1    = 0; int *gads_1    = &GADS_1;      
    int MINUTES_1 = 0; int *minutes_1 = &MINUTES_1;   
    int STUNDAS_1 = 0; int *stundas_1 = &STUNDAS_1;  
   
    int DIENA_2   = 0; int *diena_2   = &DIENA_2;     
    int MENES_2   = 0; int *menes_2   = &MENES_2;     
    int GADS_2    = 0; int *gads_2    = &GADS_2;      
    int MINUTES_2 = 0; int *minutes_2 = &MINUTES_2;   
    int STUNDAS_2 = 0; int *stundas_2 = &STUNDAS_2;  

    int variable = 0;   
    int VARIANTS = 0; int *variants = &VARIANTS;    

    table(*diena_1, *diena_2, *menes_1, *menes_2, *gads_1, *gads_2, *minutes_1, *minutes_2, *stundas_1, *stundas_2);
    
        /**(diena_1) = 30;   *(diena_2) = 29;
        *(menes_1) = 12;   *(menes_2) = 11;
        *(gads_1)  = 2021; *(gads_2) = 1933; 
        *(minutes_1) = 59; *(minutes_2) = 36;
        *(stundas_1) = 23; *(stundas_2) = 22;*/
      

    
    // TimeStamp 1 --------------------------------------------------------------------------------------------------
    cout << "\n  Ievadiet Dienu -> ";
        *(variants) = 1;
        user_input(diena_1, variants);
        clear();
        table(*diena_1, *diena_2, *menes_1, *menes_2, *gads_1, *gads_2, *minutes_1, *minutes_2, *stundas_1, *stundas_2);
     cout << "\n  Ievadiet Menesi -> ";
        *(variants) = 2;
        user_input(menes_1, variants);
        clear();
         table(*diena_1, *diena_2, *menes_1, *menes_2, *gads_1, *gads_2, *minutes_1, *minutes_2, *stundas_1, *stundas_2);
    cout << "\n  Ievadiet Gadu-> ";
        *(variants) = 3;
        user_input(gads_1, variants);
        clear();
         table(*diena_1, *diena_2, *menes_1, *menes_2, *gads_1, *gads_2, *minutes_1, *minutes_2, *stundas_1, *stundas_2);
    cout << "\n  Ievadiet Minuti-> ";
        *(variants) = 4;
        user_input(minutes_1, variants);
        clear();
         table(*diena_1, *diena_2, *menes_1, *menes_2, *gads_1, *gads_2, *minutes_1, *minutes_2, *stundas_1, *stundas_2);
    cout << "\n  Ievadiet Stundu-> ";
        *(variants) = 5;
        user_input(stundas_1, variants);
        clear();
         table(*diena_1, *diena_2, *menes_1, *menes_2, *gads_1, *gads_2, *minutes_1, *minutes_2, *stundas_1, *stundas_2);

    // TimeStamp 2 ----------------------------------------------------------------------------------------------------
    cout << "\n  Ievadiet Dienu -> ";
        *(variants) = 1;
        user_input(diena_2, variants);
        clear();
        table(*diena_1, *diena_2, *menes_1, *menes_2, *gads_1, *gads_2, *minutes_1, *minutes_2, *stundas_1, *stundas_2);
    cout << "\n  Ievadiet Menesi -> ";
        *(variants) = 2;
        user_input(menes_2, variants);
        clear();
         table(*diena_1, *diena_2, *menes_1, *menes_2, *gads_1, *gads_2, *minutes_1, *minutes_2, *stundas_1, *stundas_2);
    cout << "\n  Ievadiet Gadu-> ";
        *(variants) = 3;
        user_input(gads_2, variants);
        clear();
         table(*diena_1, *diena_2, *menes_1, *menes_2, *gads_1, *gads_2, *minutes_1, *minutes_2, *stundas_1, *stundas_2);
    cout << "\n  Ievadiet Minuti-> ";
        *(variants) = 4;
        user_input(minutes_2, variants);
        clear();
         table(*diena_1, *diena_2, *menes_1, *menes_2, *gads_1, *gads_2, *minutes_1, *minutes_2, *stundas_1, *stundas_2);
    cout << "\n  Ievadiet Stundu-> ";
        *(variants) = 5;
        user_input(stundas_2, variants);
        clear();
         table(*diena_1, *diena_2, *menes_1, *menes_2, *gads_1, *gads_2, *minutes_1, *minutes_2, *stundas_1, *stundas_2);

    Time T1;    
         T1.SetDate(*(diena_1), *(menes_1), *(gads_1));
         T1.SetTime(*(minutes_1), *(stundas_1)); 
    Time T2;
         T2.SetDate(*(diena_2), *(menes_2), *(gads_2));
         T2.SetTime(*(minutes_2), *(stundas_2));

    space(2);
        cout << "\n                        TimeStamp 1   TimeStamp 2";
        cout << "\n                        -----------   -----------";
        cout << "\n    Ievadits datums  -> ";
                    T1.GetDate();
                    cout << "    ";
                    T2.GetDate();
        cout << "\n    + viena diena    -> ";
                    T1.DateUpdate();
                    cout << "    ";
                    T2.DateUpdate();
                    space(1);
        cout << "\n    Ievadits laiks   -> ";
                    cout << "     ";    
                    T1.GetTime();
                    cout << "         "; 
                    T2.GetTime();
        cout << "\n    + viena minute   -> ";  
                    cout << "     "; 
                    T1.TimeUpdate();
                    cout << "         "; 
                    T2.TimeUpdate();   
                    space(2);              
        cout << "\n    Date & Time:  +1 minute pie Time";
        cout << "\n    ---------------------------------------------";
        cout << "\n        TimeStamp 1: -> ";
                    T1.DateAndTime();
                    cout << "  +1m";
        cout << "\n        TimeStamp 2: -> ";
                    T2.DateAndTime(); 
                    cout << "  +1m"; 
                    space(2);
       
        cout << "\n    Dienu saits, un dienu sakits starp datumiem ";
        cout << "\n    ---------------------------------------------";
                    T2.DateDiff(T1, T2);

        space(5);
    return 0;
}

// ----[ Funkcijas ]---------------------------------------------------------------------------------------------[5]
//                                                                                                     <-- Funkcijas
// Funkcija { ievadit mainigo { dd/mm/ggg - 0:00
void user_input(int* mainigais, int* variants){
    while(1){
        int target_NUM = 0; // Noteikumam { no While() cikla iziesanai
        int user_input = 0; // Lietotaja ievaditas vertibas saglabasanai
   
        user_input = check_Char(user_input, *(variants)); //             :: mainiga vertiba ir = funkcija { kura lietotais ievada mainigo, un funkcija parbauda { vai ievadits skaitlis
        if(check_NUM(user_input, *(variants), target_NUM) == 1) { //     :: parbaude { vai ievadita vertiba neparsniedz lielumu
            *(mainigais) = user_input; // ... ja neparsniedz, tad pieskirt parbauditu vertibu mainigajam DIENA
            break; //              ... un pabeigt 'while' ciklu (jo no funcijas check_NUM tiek atgriezts 'target_NUM = 1') 
        } else { 
            target_NUM = 0; //     ... ja vertiba neder        { Skat. funkciju { Check_NUM(int, int, int)  
            continue; //           ... turpinat 'while' ciklu
        }
    } 
}

// Funkcija { parbaudit vertibas lielumu
//           (int user_input, int skat.zemak int while ciklam)
int check_NUM(int variable,   int variants,   int target_NUM){
     
    int checksum = 0;
        if(variants == 1) { checksum = 30;   } // - DIENA
        if(variants == 2) { checksum = 12;   } // - MENES
        if(variants == 3) { checksum = 9999; } // - GADS
        if(variants == 4) { checksum = 59;   } // - MINUTES
        if(variants == 5) { checksum = 23;     // - STUNDAS
        } // else { cerr... }

    if(variable > checksum) { // ja 'user_input' lielaks par 'variantu'         
        cout << RED << "  Skaitlis par lielu !" << RESET << endl; 
        target_NUM = 0; //   ... tad while cikls turpinasies
    } else { //              ... citadi ja 'user_input' sakrit ar pielaujamiem lielumiem
        target_NUM = 1; //   ... tad while ciklam tiek atgriezta vertiba cikla beigsanai 
    } return target_NUM; //  ... funkcija atgriez vertibu
}
    /*// SUB Funkcija { iekraso sarkanu nepareizo vertibu !!!! Laiks :( 
    void check_NUM_0(int target){                         // !
        if (target == 0) {                                // !
            cout << RED;                                  // !
        }
    }*/
    
// Funkcija { izvada tabulu
void table(int diena_1, int diena_2, int menes_1, int menes_2, int gads_1, int gads_2, int minutes_1, int minutes_2, int stundas_1, int stundas_2){

    cout << "\n  +------------------+-------------------+--------------+";
    cout << "\n  |  TimeStamp 1     |   TimeStamp 2     |   INFO       |";
    cout << "\n  +------------------+-------------------+--------------+";
    cout << "\n  |  Diena  -> "; check_NULL(diena_1);   cout << "  | "; cout << "  Diena  -> "; check_NULL(diena_2);   cout << "  |"; cout << "   MAX = 30   |";
    cout << "\n  |  Menes  -> "; check_NULL(menes_1);   cout << "  | "; cout << "  Menes  -> "; check_NULL(menes_2);   cout << "  |"; cout << "   MAX = 12   |";
    cout << "\n  |  Gads   -> "; check_NULL(gads_1);    cout << "  | "; cout << "  Gads   -> "; check_NULL(gads_2);    cout << "  |"; cout << "   MAX = 9999 |";
    cout << "\n  |  Minute -> "; check_NULL(minutes_1); cout << "  | "; cout << "  Minute -> "; check_NULL(minutes_2); cout << "  |"; cout << "   MAX = 59   |";
    cout << "\n  |  Stunda -> "; check_NULL(stundas_1); cout << "  | "; cout << "  Stunda -> "; check_NULL(stundas_2); cout << "  |"; cout << "   MAX = 23   |";
    cout << "\n  +-----------------------------------------------------+";
}
    // Funkcija { (SUB funkcija) :: tabulai, parbauda vai izdrukat skaitli
    int check_NULL(int null) {

        if(null == 0) { //      ja 0, tad izdrukat linijas
            cout << "----"; 
        } else { //             ja !NE nulle { ir ievadits un akceptets skaitlis, pec parbaudes ...
            fill(4); //          ... tad izsaut funkciju { parbaudit vai vertiba mazaka par 10       
            cout << null;
        }
        return 0;// ... ja 'user_input' sakrit ar pielaujamiem lielumiem
    }

    // Funkcija { (SUB Funkcija) :: aizpilda brivu vietu ja cipars ir zem desmita
    void fill(int count) {
            if (count == 2) {                       // pireks divciparu mainigiem { arpus tabulas
                cout << setfill('0') << setw(2);
            } else {                                // prieks tabulas mainigajiem { tabulaa
                cout << setfill(' ') << setw(4);
            }
    }

// Funkcija { <br>
void space(int x)  {
    for(int i = 0; i < x;  i++){
        cout << endl;
    }
}

// Funkcija { attirit ekranu
void clear() { 
     #ifdef _WIN32
        system("cls");      // if MS-DOS { clear screen
    #else
        system("clear");    // if not!   { clear
    #endif 
}

// Funkcija { parbauda vai ievadits 'integer'
int check_Char(int user_input, int variant) {
    string VARIANT;
        if(variant == 1) { VARIANT = "dienu";  }
        if(variant == 2) { VARIANT = "menesi"; }
        if(variant == 3) { VARIANT = "gadu";   }
        if(variant == 4) { VARIANT = "minuti"; }
        if(variant == 5) { VARIANT = "stundu"; }

    string str;
    while (1) {// ... ja 'user_input' sakrit ar pielaujamiem lielumiem
        cout << "  [?] --> ";
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            char ch = str.c_str()[i];   // Parveidot STRING par CHAR

            if (!isdigit(ch)) {         // ja nav ievadits cipars
                cout << RED << "  Jaievada cipars!" << RESET << endl << endl;
                cout << "  Ievadiet " << VARIANT << " -> ";
                break;                  // ! ja ne BREAK { SAVADAK drukas tik cik burtu ierakstits
            } else {                    // savada parverst par INT
                user_input = atoi(str.c_str());   
                return user_input;
            } 

        }
    }
}