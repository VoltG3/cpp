#include <iostream> // std::cout
#include <iomanip>	// std::setw(int)
#include <array>	// array
#include <thread>	// sleep(), lib. for #chrono
#include <chrono> 	// date and time { C++11	
//#include <stdlib> 

// MD3_1_Danoss
// macOS Clang v.1200.0.32.27

using namespace std;

	// Teksta krasas
	#ifdef _WIN32 // Ja Windows platforma
		#include <windows.h>
			enum Colors {
    				Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
    				DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, DarkYellow, White
			};
 
			template<Colors txt = LightGray, Colors bg = Black>
					ostream& color(ostream &text) {
    					HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    					SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
    				return text;
    				
    					#define yellow color<DarkYellow, Black> 
    					#define reset  color<White,  Black>
    			return text;
			}
		#else	// Ja macOS platforma
			#define yellow "\033[33m"
			#define reset  "\033[0m"      
		#endif

	void clear_screen() { // Funkcija terminalim { attirit ekranu
		#ifdef _WIN32	
		    system("cls");		// Ja MS-DOS { clear screen
		#else
		    system ("clear");	// ja macOS  { clear
		#endif
	}


int main() { // galvena funkcija

	const int rows = 4;			// const - nemainigs 'integer' { rindu skaitam			
	const int collons = 3;		// const - nemainigs 'integer' { kolonnu skaitam
		  int histogramma = 0; 	// mainigais bus nepieciesams histogrammas izvadisanai
		
		// Divdimensiju masivs 'E' -- arejais masivs ir indexu virkne
		//						   -- ieksejais masivs ir indexu(noraazzu) virkne
		//							  kuras norada ar kuru areja masiva indexu saksies
		//							  jauna 'kolonna'  
		array<array<int, collons>, rows> E = {4, 3, 19, 3, 15, 7, 11, 9, 13, 5, 17, 1};
		// ! manipulejot ar div.d. masivu janem vera, ka { 'Kollona' uztverama ka RINDA -
		//   JO 'terminalii' nevar izdrukat sakuma vienu kolonu un tad blakam otru
		//	 tamdelj piem.masiivs no(4 rindam, 3 kolonam) { pirma izvadita uz ekrana viena rinda
		// 	 ir katras kolonnas(rindas) pirmais index... un tt i++
		//   pie sis ipasibas sakuma nav tik viegli pierst
		//	 Kolona ir Rinda jo par Kollonu vinja klust tikai pateicoties pielietotam << endl;

		clear_screen(); // Izsaucam funkciju { clear/cls
		
		cout << endl;								  // Galvenes izvadisana
		cout << "Elements" << setw(10) << "Vertiba";  // 
		cout << setw(20) << "Histogramma";			  //
		cout << endl;								  //

		// Sazarotais cikls { div.d. masiva izvade
		for(int row = 0; row < E.size(); row++) { 					    // CIKLS 1 -   E.size() 	   == int rows 4
			for(int column = 0; column < E[row].size(); column++) {     // CIKLS 2 -   E.[row].size()  == int collons 3
		// 1. cikls { raw + 1 {{ masiva(indexu) skaits				       -- Var protams uzreiz ierakstit .size vieta massiva indexu skaitu
		// 2. cikls { nolasa ar tiesu piekluvi '[]' collonu skaitu.      Parocigak tomer bus 'izsaukt' masiva lielumu .size, ipassi darba
		// .. veic darbibu { ar vienu kollonu(masiva posmu)...			 ar vektoriem, kur .size var mainites
		// Cikls gala. 1 & 2 cikls no jauna, { otraa kolonna(posms) 
				cout << "[" << row << "]";							
				cout << "[" << column << "]";
				cout << setw(10) << E[row][column]; // izvada aktualo masiva elementu
				histogramma = E[row][column];	// 'histogrammas' vertiba ir= nulle apstradats masiva elementa lielums
				cout << setw(19) << " ";
				
					for (int h = 0; h < histogramma; h++) {	// CIKLS 3 - izvada simbolu tik reizes, cik ir 'histogramma' vertiba
		/* taimeris */		cout.flush();
		/* 			*/			this_thread::sleep_for(chrono::milliseconds(100) );  // 1s = 10000	
							cout << yellow << "*"; // teksts tiek iekrasots, mainigais yellow der gan Win32 gan macOS
								
						}
						cout << reset;	// atgriez pie baltas teksta krasas

			cout << endl; // Pirms atgriesties pirmaja ciklaa { pariet jauna rinda
			}
		}

		cout << endl; // atkape lidz terminala pazinojumiem, pec programmas aizversanas

	return 0;
}
