#include <iostream>

// PD_0605 - Danoss - 15/3/21 - GNU nano 4.8

using namespace std;

  #define RED "\033[31m"
  #define RESET "\033[37m"

      void sant(int *, int *, int *);

  int main(){

  int Desmiti = 99, Lati = 0, Santimi = 0;
  int *d = &Desmiti, *l = &Lati, *s = &Santimi;
  int gb = 0, m = 10000;

  cout << "\n" << endl;
  cin >> *(l) >> *(s) >> gb;
  //*(l) += 4; *(s) += 75; gb = 3;

  if(*(l) < 0 || *(s) < 0 || gb < 0){ cout << RED << "\nCERR - negative INT ! \n" << RESET; return 0;}
  if(*(l) > m || *(s) > m || gb > m){ cout << RED << "\nCERR - overload INT ! \n" << RESET; return 0;}

  *(l) *= gb;
  *(s) *= gb;

      sant(l, s, d);

  cout << "\n\n" << *(l) << " " << *(s) << endl << endl;

 return 0;
}

void sant(int *lx, int *sx, int *dx){
  if(*(sx) > *(dx)){
  *(sx) -= 100;
  *(lx) += 1;
   sant(lx, sx, dx);
  }
}
