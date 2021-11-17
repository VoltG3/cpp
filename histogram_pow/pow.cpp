#include <iostream> // std::cout
#include <iomanip>	// std::setw(int)
#include <array>	// array
#include <math.h>	// pow() { 'JA Win32' 
//#include <stdlib>  

// MD3_2_Danoss
// macOS Clang v.1200.0.32.27

using namespace std;

	void clear_screen(); // Norade kompilatoram par funkcijas esamibu
	void cout_header();	 // 


int main() {

	const int rows = 11;	// const { nemainigs index'u skaits un tips ..
	const int columns = 5;  // 
		array<array<double, columns>, rows> X = {};	//  div.d. masivs - tukss
	
		clear_screen();		// funkcijas izsauksana { cls/clear

// MASIVA IZVEIDOSANA ---------------------------------------------------------------------
	
	double q = 0; // sis mainigais bus vajadzigs pirmajam masiva elementam ( X[0][0]=2 )
	
	for (int row = 0; row < X.size(); row++) { // Rinda no 55 elementiem
		for (int column = 0; column < X[row].size(); column++) { // Kolona ir rind.fragments no 11 elementiem

// ar IF --------------------------------
			if(column == 0){ 
				if(q == 0) { q = 2; } else { q += 0.1; } 	
											X[row][column] = q + X[row][column]; 
			} 
			
			if(column == 1){ 				X[row][column] = 1 / X[row][0]; 	}
			if(column == 2){ 				X[row][column] = pow(X[row][0], 2);	}
			if(column == 3){				X[row][column] = pow(X[row][0], 3);	}
			if(column == 4){				X[row][column] = pow(X[row][0], 4);	}
		}					
	}
				
// ar CASE ------------------------------					
/*			switch(column) {
				case 0 : 
					if(q == 0) { q = 2; } else { q += 0.1; } 	
						 X[row][column] = q + X[row][column]; break;
				case 1 : X[row][column] = 1 / X[row][0]; break;
				case 2 : X[row][column] = pow(X[row][0], 2); break;
				case 3 : X[row][column] = pow(X[row][0], 3); break;
				case 4 : X[row][column] = pow(X[row][0], 4); break;
			}
		}
	}*/

	
		cout_header(); // funkcijas izsauksana { izvadit 'galveni'
		
		// Izveidota masiva izvadisana
		for (int row = 0; row < X.size(); row++) {
			for (int column = 0; column < X[row].size(); column++) {
				cout << setw(8) << X[row][column];
			}
			cout << endl;
		}
		cout << endl;

	return 0;
}

// Funkcijas { attirit ekranu
void clear_screen() { // Funkcija terminalim { attirit ekranu
	#ifdef _WIN32	
	    system("cls");		// Ja MS-DOS { clear screen
	#else
	    system ("clear");	// ja macOS  { clear
	#endif
}

// Funkcijas { izvadit tabulu
void cout_header(){
	cout << setprecision(2);	// izvadit { divi cipari ...
	cout.setf(ios::fixed);		// iestata karogu {      ... aiz komata
	
	cout << "\n" << setw(6) << "x";		
	cout << setw(10) << "1/x";
	cout << setw(8) << "x^2";
	cout << setw(8) << "x^3";
	cout << setw(8) << "x^4" << endl;
	
	cout << "\n" << setw(8) << "----";
	cout << setw(8) << "----";
	cout << setw(8) << "----";
	cout << setw(8) << "-----";
	cout << setw(8) << "-----" << endl;
}