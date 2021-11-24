#include <iostream> // std::cout
#include <iomanip>	// std::setw
#include <array>	  // array
#include <thread>	  // sleep(), lib. for #chrono
#include <chrono> 	// date and time { C++11	
//#include <stdlib> 

using namespace std;

	#ifdef _WIN32 
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

		#else	
			#define yellow "\033[33m"
			#define reset  "\033[0m"      
		#endif

	void clear_screen() {   
		#ifdef _WIN32	
		    system("cls");		// if MS-DOS { clear screen
		#else
		    system ("clear");	// else macOS/Linux  { clear
		#endif
	}

// [1] - count of iterations is count of index in the array
// [2] - cout row and column number
// [3] - cout histogram, value of index element 
// [*] - 1 sec { 10000

int main() { 

	const int rows = 4;			
	const int collons = 3;		
		    int histogram = 0; 	

		array<array<int, collons>, rows> E = {4, 3, 19, 3, 15, 7, 11, 9, 13, 5, 17, 1};

		clear_screen(); 
		
    // cout { table header
		cout << endl;								  
		cout << "\tElement" << setw(10) << "Value";  
		cout << setw(20) << "Histogram";			  
		cout << endl;								  

		for(int row = 0; row < E.size(); row++) { // ---------------------- [1]				    
			for(int column = 0; column < E[row].size(); column++) { // ------ [2]
				cout << "\t[" << row << "]";							
				cout << "[" << column << "]";
				cout << setw(10) << E[row][column]; 
				histogram = E[row][column];	
				cout << setw(19) << " ";
				
					for (int h = 0; h < histogram; h++) {	// -------------------- [3]
				    cout.flush();
				    this_thread::sleep_for(chrono::milliseconds(100) ); // ---- [*]	
							cout << yellow << "*"; 	
						} cout << reset << endl;
			}
		} cout << endl; 

	return 0;
}