#include <iostream>

// PD2 Kartosanas Algoritmi - Danoss - 10/02/2021 Sublime Text 3.2.2v

using namespace std;

#define colors_h

#ifdef _WIN32
    #include <windows.h> // or #include <stdlib.h>
    
    enum Colors {
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
    DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
 
template<Colors txt = LightGray, Colors bg = Black>
ostream& color(ostream &text) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
    return text;
}
        #define RED    color<Red, Black>
        #define RESET  color<White, Black>
        #define YELLOW color<Yellow, Black>
        
        //Pielietotas krasas ---------------------------------> Win32
        #define BOLDWHITEBG  color<White, Cyan>         //
        #define BOLDWHITEU   color<White, Cyan>         //
        #define BOLDCYANBG   color<White, Cyan>         // ! Seit var nesakrist definetie krasas nosaukumi ar
        #define DARKCYAN     color<Cyan, Black>         // realu izvadamo krasu, jo programma tika veidota
        #define REDI         color<Yellow, Black>       // macOS videe, lidz ar to preiks Win32 krasas tiek 
        #define REDU         color<Yellow, Black>       // pieskanjotas.
        #define BOLDBLUE     color<LightBlue, Black>    //
#else
                            //  2m - dark
                            //  3m - italica
                            //  4m - underline
                            //  5m - blinking
                            //  6m - lightdark
                            //  7m - highlight background

    #define GREEN       "\033[32m"             /* Green */
    #define YELLOW      "\033[33m"             /* Yellow */
    #define BLUE        "\033[34m"             /* Blue */
    #define MAGENTA     "\033[35m"             /* Magenta */
    #define CYAN        "\033[36m"             /* Cyan */
    #define WHITE       "\033[37m"             /* White */
    #define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
    #define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
    #define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
    #define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
    //#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
    #define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
    #define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
    #define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
    #define RESET       "\033[0m"
    #define BLACK       "\033[30m"             /* Black */
    #define RED         "\033[31m"             /* Red */
    
    // Pielietotas krasas, teksta formatejums ---------> macOS
    #define BOLDWHITEBG  "\033[7m\033[37m"    /* Text Black - Background White - Button*/
    #define BOLDWHITEU   "\033[4m\033[37m"    /* Text Black - Background White - Underline*/
    #define BOLDCYANBG   "\033[7m\033[36m"    /* Text Black - Background Cyan */
    #define DARKCYAN     "\033[2m\033[36m"    /* Text Dark Cyan */
    #define REDI         "\033[3m\033[31m"    /* Text RED -Italica */
    #define REDU         "\033[4m\033[31m"    /* Text RED -Underline */
    #define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */

#endif


