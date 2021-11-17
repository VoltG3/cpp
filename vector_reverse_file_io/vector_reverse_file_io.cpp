#include <iostream> // std:: input/output stream
#include <fstream>  // ios::in & ios::out
#include <string>   // string
#include <vector>   // vector
#include <iomanip>  // std::setw();

//  PD4_Danoss - 24/02/2021/ - Xcode 12.2v

void clear_screen() {   // Funkcija terminalim { attirit ekranu
    #ifdef _WIN32
        system("cls");      // Ja MS-DOS { clear screen
    #else
        system("clear");    // ja macOS  { clear
    #endif
}

using namespace std;

void Text_format_out(vector<int>, int, int*); // Funkcija { teksta formatesanai

int main(int argc, const char * argv[]) {
    
    // DATNES (nolasisana) -----------------------------------------------
    fstream datne;
    //string FileName_Nolasisanai = "/Users/voltg3/Documents/PD4/PD4/data_in.txt";
    string FileName_Nolasisanai = "data_in.txt";
    datne.open(FileName_Nolasisanai, ios::in);
    
        if (datne.is_open()){
            string dati; // Mainigais virtenei
            while(getline(datne, dati)){ // Datu ielase virtene no datnes
            } dati = dati + ", end of string"; // pievienot pedejo elementu...
                                               // ... savadak dzesisies ped.cipars
            char elements[dati.size()];  // Char masivs ASCII simboliem
            dati.copy(elements, dati.size()); // Konverte virteni char masiva
            elements[dati.size()] = '\0';
           
            // Char masiva konvertesana veselajos INT skaitlos --------------
            vector<int> A_in; // masivs konvertetiem INT elm.
            int iter = 0; // Iteraciju skaita kontrole
            int c = 0;  // Elements = ' char(elements) --> int(c) --> A[] '

            for(int i = 0; i < dati.size(); i++){

                i = i + iter;
                iter = 0;
                // Ja elm. ir ASCII skaitlu simbolu diapazonaa '47 <- -> 58'
                if(elements[i] > char(47) && elements[i] < char(58)){
                    c = elements[i] - '0';
                    // Ja nakamais elm. ir ASCII 'space' vai ari 'komats'...
                    if(elements[i+1] == char(32) || elements[i+1] == char(44)){
                        A_in.push_back(c); //... tad pievienojam 'c' pie INT masiva
                // BET, ja tomer nakamais elements ari ir 'CIPARS' tad ...
                }else if(elements[i+1] > char(47) && elements[i+1] < char(58)){
                    c = c * 10 + elements[i+1] - '0'; // pirmo reizina un piev. otro
                // UN, ja tresais elements ir 'SPACE' vai 'komats' ...
                    if(elements[i+2] == char(32) || elements[i+2] == char(44)){
                        A_in.push_back(c); //... tad pievienojam 'c' pie INT masiva
                        iter = iter+1; // JA skaitls sastav no diviem cip. tad -1 iteracija
                // BET, ja ari tresais elemenrs ir cipars, tad ... reizinat ar desmit...
                }else if(elements[i+2] > char(47) && elements[i+2] < char(58)){
                    c = c * 10 + elements[i+2] - '0'; //... un pieskaitit treso ciparu.
                // UN tada gadijuma ja pectam seko 'space' vai komats, tad...
                    if(elements[i+3] == char(32) || elements[i+3] == char(44)){
                        iter = iter + 1; //... vel vienreiz -1 no nakamas iteracijas
                        A_in.push_back(c);
                        if(c > 99){iter = iter + 1;} // ja skaitl. ir lielaks par 2 cip. ...
                        // tad, -1 iteracija
                }}}}
            } clear_screen(); // attirit ekranu pirms izvades
           
            
            int rinda = 0;   // ...
            int *j = &rinda; // Vajadzigs izvadamo elem. skaita viena rinda (kontrolei)

            // IZVADIT ieguto masivu -----------------------------------------
            cout << "\n\nCOUT VECTOR" << endl << endl;
                for(int i = 0; i < A_in.size(); i++){
                    Text_format_out(A_in, i, j);
                } cout << endl;
            
            // Masiva kopesana (reversaa) ------------
            vector<int> A_out; // massivs -> A_in masiva reversam
            int size_ = 0;
            size_ += A_in.size();
            
            for(int i = size_ - 1; i >= 0; i--){
                A_out.push_back(A_in[i]);
            }
            
            // IZVADIT masivu reversa (+ visu elem. summa) -------------------
            int summ = 0; // Mainigais visu elementu summai
            cout << "\n\nCOUT VECTOR - REVERS" << endl;
                for(int i = 0; i < A_out.size(); i++){
                    Text_format_out(A_out, i, j);
                    summ += A_out[i]; // Saskata vissu elementu summu
                } cout << endl;
            cout << "\n\t Masiva elementu summa: " << summ << endl << endl;
            
    // DATNES (ierakstisana) ---------------------------------------------
    fstream datne_out;
    
    //string FileName_Ierakstisanai = "/Users/voltg3/Documents/PD4/PD4/data_out.txt";
    string FileName_Ierakstisanai = "data_out.txt";
            datne_out.open(FileName_Ierakstisanai, ios::out);
            
            if(datne_out.is_open()){
                datne_out << "MASIVS PRETEJA SECIBA" << endl;
                datne_out << "No datnes --> " << FileName_Nolasisanai << endl;
                datne_out << "\n";
                
                *(j) = 1;
                for(int i = 0; i < A_out.size(); i++){

                    if (*(j) == 26) {           // Parnes izvadi jauna rinda
                        datne_out << endl;
                        *(j) = 1;               // Skaitit no jauna
                    } *(j) += 1;
                    
                    datne_out << setw(3) << A_out[i];
                    
                    if(i + 1 == A_out.size()){ // pec pedeja cipara komata NEizvadisanai
                        datne_out << " ";
                    } else { datne_out << ", ";}
                    
                } datne_out << "\n " << endl;;
                datne_out << "Masiva elementu summa: " << summ;
            } datne_out.close();

            
        //Notekums attiecas uz datnes (ielasisanu)
        } else {
            cout << "Datne nolasisanai netiek atrasta" << endl;
        } datne.close();
     
    return 0;
}

// Funkcija { teksta formatesanai
void Text_format_out(vector<int> M, int i, int *j){
    if(*(j) == 0){              // Ivadit atkapi pirms pirma elementa
        cout << "\t";
    }
    
    *(j) += 1;
    if (*(j) == 26) {           // Parnes izvadi jauna rinda
        cout << endl << "\t";
        *(j) = 1;               // Skaitit no jauna
    }
    
    if (i > 99) {                       // Vizuali pareizi izvadit..
        cout << setw(2) << M[i] << " "; // .. ja 2ciparu ves.skaitlis
    } else {
        cout << setw(3) << M[i] << " "; // .. ja 3ciparu ves.skaitlis
    }
}
