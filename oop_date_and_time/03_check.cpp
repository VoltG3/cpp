#include <iostream> // input&output
#include <iomanip>  // std:setfill  std:setw 
#include <string>   // string

// Kristians Danoss / patstavigais darbs MD5 / 13-19sep2021
//
//                  ! Bloks { Parbaudei -> ievaditam vertibam
//

using namespace std;

#define BOLDCYAN    "\033[1m\033[36m"      // Bold Cyan 
#define BOLDWHITE   "\033[1m\033[37m"      // Bold White 
#define RESET       "\033[0m"              // :: DEFAULT
#define BLACK       "\033[30m"             // Black 
#define RED         "\033[31m"             // Red 

// Funkciju saraksts kompilatoram
 int check_NUM(int, int, int);          // SUB Funkcija { parbaudit vertibas lielumu
void table(int, int, int, int, int);    //     Funkcija { izvada tabulu
 int check_NULL(int);                   // SUB Funkcija { parbauda tabulai, vai izdrukat skaitli
void check_NUM_0(int);                  // SUB Funkcija { iekraso sarkanu nepareizo vertibu
void fill();                            // SUB Funkcija { aizpilda brivu vietu
void clear();                           //     Funkcija { attirit ekranu
 int check_Char(int, int);              //     Funkcija { parbauda vai ievadits 'integer'
int main() {
    clear();

                      // check_NUM | :: norade, kura mainiga vertiba ir parbaudama                
    int diena = 0;    // variant = 1
    int menes = 0;    // variant = 2
    int gads = 0;     // variant = 3
    int minutes = 0;  // variant = 4
    int stundas = 0;  // variant = 5
    // mainigie { noteikumam { parbaudei vai lietotaja ievaditais skaitlis NAV par lielu !
    int variable = 0;   // lietotaja ievaditais mainigais 'user_input'
    int variant = 0;    // Skat. tabulu 'line 30-34'

    table(diena, menes, gads, minutes, stundas);

    while(1){
        int target_NUM = 0; // Noteikumam { no While() cikla iziesanai
        int user_input = 0; // Lietotaja ievaditas vertibas saglabasanai
   
        cout << "\n  Ievadiet Dienu -> ";
    // if ... [ SALIKT PAREJAS VERTIBAS ]
        user_input = check_Char(user_input, 1); //             :: mainiga vertiba ir = funkcija { kura lietotais ievada mainigo, un funkcija parbauda { vai ievadits skaitlis
        if(check_NUM(user_input, 1, target_NUM) == 1) { //     :: parbaude { vai ievadita vertiba neparsniedz lielumu
            diena = user_input; // ... ja neparsniedz, tad pieskirt parbauditu vertibu mainigajam DIENA
            break; //              ... un pabeigt 'while' ciklu (jo no funcijas check_NUM tiek atgriezts 'target_NUM = 1') 
        } else { 
            target_NUM = 0; //     ... ja vertiba neder        { Skat. funkciju { Check_NUM(int, int, int)  
            continue; //           ... turpinat 'while' ciklu
        }
    } 
  
    // clear();
    cout << endl;

        //diena = 30;
        menes = 12;
        gads = 9999;
        minutes = 59;
        stundas = 23;

    table(diena, menes, gads, minutes, stundas);

    //cout << "\n   Diena  -> "; check_NUM(diena,   1);
    //cout << "\n   Menes  -> "; check_NUM(menes,   2);
    //cout << "\n   Gads   -> "; check_NUM(gads,    3);
    //cout << "\n   Minute -> "; check_NUM(minutes, 4);
    //cout << "\n   Stunda -> "; check_NUM(stundas, 5);

    return 0;
}

// Funkcija { parbaudit vertibas lielumu
//           (int user_input, int skat.zemak int while ciklam)
int check_NUM(int variable,   int variant,   int target_NUM){
     
    int checksum = 0;
        if(variant == 1) { checksum = 30;   } // - DIENA
        if(variant == 2) { checksum = 12;   } // - MENES
        if(variant == 3) { checksum = 9999; } // - GADS
        if(variant == 4) { checksum = 59;   } // - MINUTES
        if(variant == 5) { checksum = 23;     // - STUNDAS
        } // else { cerr... }

    if(variable > checksum) { // ja 'user_input' lielaks par 'variantu'         
        cout << RED << "  Skaitlis par lielu !" << RESET << endl; 
        target_NUM = 0; //   ... tad while cikls turpinasies
    } else { //              ... citadi ja 'user_input' sakrit ar pielaujamiem lielumiem
        target_NUM = 1; //   ... tad while ciklam tiek atgriezta vertiba cikla beigsanai 
    } return target_NUM; //  ... funkcija atgriez vertibu
}
// SUB Funkcija { iekraso sarkanu nepareizo vertibu
void check_NUM_0(int target){                         // !
    if (target == 0) {                                // !
        cout << RED;                                  // !
    }
}
// Funkcija { izvada tabulu
void table(int diena, int menes, int gads, int minutes, int stundas){

    cout << "\n  +------------------+-------------------+--------------+";
    cout << "\n  |  TimeStamp 1     |   TimeStamp 2     |   INFO       |";
    cout << "\n  +------------------+-------------------+--------------+";
    cout << "\n  |  Diena  -> "; check_NULL(diena);   cout << "  | "; cout << "  Diena  -> "; check_NULL(diena);   cout << "  |"; cout << "   MAX = 30   |";
    cout << "\n  |  Menes  -> "; check_NULL(menes);   cout << "  | "; cout << "  Menes  -> "; check_NULL(menes);   cout << "  |"; cout << "   MAX = 12   |";
    cout << "\n  |  Gads   -> "; check_NULL(gads);    cout << "  | "; cout << "  Gads   -> "; check_NULL(gads);    cout << "  |"; cout << "   MAX = 9999 |";
    cout << "\n  |  Minute -> "; check_NULL(minutes); cout << "  | "; cout << "  Minute -> "; check_NULL(minutes); cout << "  |"; cout << "   MAX = 59   |";
    cout << "\n  |  Stunda -> "; check_NULL(stundas); cout << "  | "; cout << "  Stunda -> "; check_NULL(stundas); cout << "  |"; cout << "   MAX = 23   |";
    cout << "\n  +-----------------------------------------------------+";
}
    // Funkcija { (SUB funkcija) :: tabulai, parbauda vai izdrukat skaitli
    int check_NULL(int null) {

        if(null == 0) { //      ja 0, tad izdrukat linijas
            cout << "----"; 
        } else { //             ja !NE nulle { ir ievadits un akceptets skaitlis, pec parbaudes ...
            fill(); //          ... tad izsaut funkciju { parbaudit vai vertiba mazaka par 10       
            cout << null;
        }
        return 0;// ... ja 'user_input' sakrit ar pielaujamiem lielumiem
    }

    // Funkcija { (SUB Funkcija) :: aizpilda brivu vietu ja cipars ir zem desmita
    void fill() {
        cout << setfill(' ') << setw(4);
    }

// Funkcija { attirit ekranu
void clear() { 
    system("clear"); 
}

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