#include <iostream>
#include <iomanip>   // std::setfill  std::setw

// Kristians Danoss / patstavigais darbs MD5 / 14sep2021

using namespace std;

// Funkciju saraksts kompilatoram
void clear();
void space(int);
void fill();

class Time {
    private: 
        int MINUTES;
        int STUNDAS;
    
    public:
        Time();
        Time(int, int);
        ~Time(){ cout << "\n  -> Called destructor" << endl; }
          void SetTime(int , int);
          void TimeUpdate(int minutes, int stundas);
          void GetTime() { 
                fill();
                    cout << STUNDAS << ":";
                fill(); 
                    cout << MINUTES; 
               }
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
        TimeUpdate(minutes, stundas);
    }
        // Konstruktors ar argumentiem
    void Time::SetTime(int minutes, int stundas) {
        MINUTES = minutes;
        STUNDAS = stundas;
    }
        // Metode { + viena diena
    void Time::TimeUpdate(int minutes, int stundas){

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
          cout << minutes << endl;
    }
  
int main() {

        clear();
        space(5);

            int min = 59;   
            int stn = 23;   

                Time T1;    
                    T1.SetTime(min, stn);
                        cout << "\n  -----{ Object 1 } ----------------------" << endl;
                        cout << "\n           time INPUT      -> ";
                    T1.GetTime();
                        cout << "\n  time Update + 1 min      -> ";
                    T1.TimeUpdate(min, stn);
                
            min = 8;   
            stn = 23;   
         
                Time T2;
                    T2.SetTime(min, stn);
                        cout << "\n  -----{ Object 2 } ----------------------" << endl;
                        cout << "\n           date INPUT      -> ";
                    T2.GetTime();
                        cout << "\n  time Update + 1 day      -> ";
                    T2.TimeUpdate(min, stn);
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
// Funkcija { vertibam zem 10 pievienot 0 prieksa
void fill(){
    cout << setfill('0') << setw(2);
}