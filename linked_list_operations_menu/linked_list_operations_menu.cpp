#include <iostream>
#include <list>
//#include <string>

//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//
//                                                                                                    //
//  PD3a - Danoss - 30/04/2021 - (on Linux) SublimeText 3.2.2 - compilled on { g++ v9.3.0 Ubuntu }    //
//                  		           			 													  //
//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//

// UZMANIBU !!! Tradicionali kavejot ieskaiti komentarus rakstiju
//              tempaa, censoties pieverst uzmanibu tam, kas manu-
//              prat svarigakais. PLUSS noverojums - Loti gruti 
//              pabeigt programmas laika, jo nemitigi un bezgaligi 
//				gribas kautko likt programmai klaat....

using namespace std;
	
	#define RESET ("\033[0m");
	#define BLUE  ("\x1B[30m\033[46m");
	#define RED ("\033[31m");
	#define GREEN ("\033[32m");
	#define MAGNETA ("\x1B[30\033[45m");
	#define YELLOW ("\033[93m");
	#define CYAN ("\033[36m");

// ----[ GALVENA SADALA: Pamatfunkcijas LISTEI ]--------------------------------------------------------------------

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
 
// Pievienojam ELEMENtu saraksta SAKUMA
void push(struct Node **head_ref, int new_data){
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

		new_node -> data = new_data;  // Ievietojam datus
		new_node -> next = *head_ref; // Parvietojam SARAKSTU -> jauna elementa BEIGAS
		*head_ref = new_node; 	      // Parvietojam 'head' atzimi uz jaunizveidota elementa
}

// Pievienojam ELEMENTU saraksta BEIGAS 
void push_back(struct Node **head_ref, int new_data){
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *temp = *head_ref;
			
		new_node -> data = new_data;
			while (temp -> next != NULL) {	// Parvietojamies lidz saraksta galam
				temp = temp -> next;
			} temp -> next = new_node;		// Kad cikls aizskaitijies lidz galam...
}											// ... pievienojam JAUNU elementu

// Pieveinoijam ELEMENTU Saraksta VIDU
void push_midt(struct Node **head_ref, int new_data, int *el){
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *temp = *head_ref;

		new_node -> data = new_data;
			for(int i = 1; i < *(el) / 2; i++){ // Cikls aizskaitas lidz listes vidum balstoties uz *(el) - elementu skaitu.
				temp = temp -> next;
			} new_node -> next = temp -> next;  // Ievietojam elementu
			  temp -> next = new_node;

			  *(el)+=1; // PIEVIENOJAM vel vienu elementu (saskaitu) pareizam vidus aprekinam
}
// ----------------------------------------------------------------------------------------------------------------


	// Pamatfunkcijas { list FUNKCIJAS
	 int insert_new_number();
	void list_cout_find_el(struct Node *);
	void list_cout_MAX_element(struct Node *, int *);
	void list_cout_MIN_element(struct Node *, int *, int *);
		//void list_cout_MIN_MAX_highlight(struct Node *, int *, int *);
	void list_cout_sum(struct Node *head, int *);
	void list_cout(struct Node *);
	void list_cout_revers(struct Node *, int *);
	void list_cout_count(struct Node *, int *);
	void list_DELETE(struct Node *);
	
	// Funkcijas { meny izvade { VIZUALAS funkcjas
	void cout_izvelne(int);
	void cout_space();
	void target_izvelne(int, int);
	void cout_line();
	void cout_line_new_list();
	 int check_input();
	
	// sistemas komandas
	void clear_scr();

int main(){
	struct Node *head = NULL;// *mid;
	//struct Node *teil = NULL;
	struct Node *temp = NULL;
	struct Node *new_node = NULL;

	int EL = 0;		// Saraksta elementu kopskaitam
	int *el = &EL;

	int ELR = 0;	// Vajadzigs rekursivajam reversam(saraksta izvadei)
	int *el_r =&ELR;	

	int TARGET_MAX = 0;				// Vajadzigs LIELAKA elementa atrasanai
	int *target_max = &TARGET_MAX;

	int TARGET_MIN = 0;				// Vajadzigs MAZAKA elementa atrasanai
	int *target_min = &TARGET_MIN;

// -- Nepietika laika pabeigt FUNKCIJU ievada parbaudei 
// -- NAKAMIE soli butu: apvienot funkcijas { int check_input() & int Insert_new_number() } ... 
// --- ... viena globala funkcija, kura deretu ari elementu skaita un elementu summu ...
// --- ... parbaudei, programmas sakuma	

  /*  int e, vol; 
    	cout << "\nIzvelaties elementu skaitu:";
   		cin >> e;

 		cout << "\nIerakstiet elementu vertibas:";
    	for(int i = 0; i < e; i++){
   
        cin >> vol;
        push(&head, vol);
    }*/
// -------------------------
    push(&head, 10);
    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);
     
      
// ------------------------------------------


	int meny = 0;
      clear_scr();
	  cout_izvelne(meny);
	  cout_line();
	  	list_cout(head);
	  	list_cout_count(head, el);
	  	list_cout_sum(head, el);
	  cout_line();
   						

    while(1){
	  meny = check_input();
		switch(meny){
			
			case 0: // elementu IZVADE preteja seciba
				clear_scr();
				cout_izvelne(meny);
				  cout_line();
				    list_cout(head);
				    list_cout_count(head, el);
				    list_cout_sum(head, el);
				      //------------------------------            REVERSAI IZDRUKAI rekursiva FUNKCIJA:
				    	cout << "\n     Saraksts REVERSA    : ";
				    	*(el_r) = *(el);					      // *(el_r) ir TEMP no *(el) = elementu skaita saraksta
				    										      // 
				  		for(int i = 0; i < *(el); i++){		      // Cikls iterejaz tik reizes cik elemetu saraksta
				  			list_cout_revers(head, el_r);	      // FUNKCIJA izdruka tikai pedejo elementu no saraksta
				  			*(el_r) -= 1;					      // (nakamaja iteracija -1 elements no saraksta beigam)
				  											      // 
				  			if(*(el_r) > 0) { 				      // Grafiskais labojums..
				  				cout << " -> ";				      // ..savadak nevareju uztaisit
				  			}								      //
				  		}
				  	  //------------------------------
				  cout_line();  
			  break;

			case 1: // elementa IEVIETOSANA { saraksta SAKUMA
				clear_scr(); 
				cout_izvelne(meny);
				  cout_line();
				    list_cout(head);
				    list_cout_count(head, el);
				    list_cout_sum(head, el);
				      //------------------------------ { Robezparbaude { pielaujams: MAX 10 elementi
				    	if(*(el) >= 10){
				    	  cout << RED;
					  	  cout << "\n\n     OPERACIJA ATCELTA !";
					  	  cout << "\n     Pielaujamais elementu skaits saraksta ir 10";
					  	  cout << RESET; 
					  	  cout << endl;
				    	} else {
				      		  push(&head, insert_new_number());	
				    	}
				      //------------------------------
				  cout_line_new_list();
				    list_cout(head);
				    list_cout_count(head, el);
				    list_cout_sum(head, el);		
				  cout_line();  
			  break;

			case 2: // elementa IEVEITOSANA { saraksta VIDU
				clear_scr();
				cout_izvelne(meny);
				  cout_line();
				    list_cout(head);
				    list_cout_count(head, el);
				    list_cout_sum(head, el);
				      //------------------------------ { Robezparbaude { pielaujams: MAX 10 elementi
				    	  if(*(el) >= 10){
				      		cout << RED;
					  		cout << "\n\n     OPERACIJA ATCELTA !";
					  		cout << "\n     Pielaujamais elementu skaits saraksta ir 10";
					  		cout << RESET; 
					  		cout << endl;
				    	  } else {
				      	  		push_midt(&head, insert_new_number(), el);
				      	  }
				      //------------------------------
				  cout_line_new_list();
		            list_cout(head);
				    list_cout_count(head, el);
				    list_cout_sum(head, el);
				  cout_line();
			  break;

			case 3: // elementa IEVIETOSANA { saraksta BEIGAS
				clear_scr();
				cout_izvelne(meny);
				  cout_line();
				    list_cout(head);
				    list_cout_count(head, el);
				    list_cout_sum(head, el);
				      //------------------------------ { Robezparbaude { pielaujams: MAX 10 elementi
				    	  if(*(el) >= 10){
				    	  	cout << RED;
					  	  	cout << "\n\n     OPERACIJA ATCELTA !";
					  	  	cout << "\n     Pielaujamais elementu skaits saraksta ir 10";
					  	  	cout << RESET; 
					  	  	cout << endl;
				    	  } else {
				    	  		push_back(&head, insert_new_number());
				    	  }
				      //------------------------------
				  cout_line_new_list();
				    list_cout(head);
				    list_cout_count(head, el);
				    list_cout_sum(head, el);
				  cout_line();
			  break;

			  case 4: // elementa DZESANA { saraksta SAKUMA
				clear_scr();
				cout_izvelne(meny);
				  cout_line();
				    list_cout(head);
				    list_cout_count(head, el);
				    list_cout_sum(head, el);
					  //------------------------------ { Robezparbaude { pielaujams: MIN 1 elements
					  	  if(*(el) == 1){
					  	  	cout << RED;
					  	  	cout << "\n\n     OPERACIJA ATCELTA !";
					  	  	cout << "\n     Saraksta jabut vismaz VIENAM elementam";
					  	  	cout << RESET; 
					  	  	cout << endl;
					  	  }	else {		   
				      	    	head = head -> next;
				      	    }		
				      //------------------------------
				  cout_line_new_list();
				    list_cout(head);
				    list_cout_count(head, el);
				    list_cout_sum(head, el);
				  cout_line();
			  break;

			  case 5: // elementa DZESANA { saraksta VIDU
				clear_scr();
				cout_izvelne(meny);
				  cout_line();
				    list_cout(head);
				    list_cout_count(head, el);
				    list_cout_sum(head, el);
				      //------------------------------ { Robezparbaude { pielaujami: MIN 3 elementi
				    	  if(*(el) < 3){
				    	  	cout << RED;
					  	  	cout << "\n\n     OPERACIJA ATCELTA !";
					  	  	cout << "\n     Saraksta jabut vismaz TRIJIEM elementiem";
					  	  	cout << RESET; 
					  	  	cout << endl;
				    	  } else {
					    	  	temp = head; 
						      	    for(int i = 1; i < *(el) / 2; i++){ 
						      	      temp = temp -> next;
						      	    } temp -> next = temp -> next -> next; // Parlecam VIDUS elementam
				    	  }
				      //------------------------------
				  cout_line_new_list();
				    list_cout(head);
				    list_cout_count(head, el);
				    list_cout_sum(head, el);
				  cout_line();
			  break;

			  case 6: // elementa DZESANA { saraksta BEIGAS
				clear_scr();
				cout_izvelne(meny);
				  cout_line();
				    list_cout(head);
				    list_cout_count(head, el);
				    list_cout_sum(head, el);
				      //------------------------------ { Robezparbaude { pielaujami: MIN 2 elementi
				    	  if(*(el) < 2){
				    	  	cout << RED;
					  	  	cout << "\n\n     OPERACIJA ATCELTA !";
					  	  	cout << "\n     Saraksta jabut vismaz DIVIEM elementiem";
					  	  	cout << RESET; 
					  	  	cout << endl;
				    	  } else {
					  	  temp = head;
						        while (temp -> next -> next != NULL){  // Ja aiznakamais elements ir pedejais
							      temp = temp -> next; 				   // tad PIRMSPEDEJAIS elements ir PEDEJAIS
							  	} temp -> next = NULL;				   //
						  }
				      //------------------------------
				  cout_line_new_list();
				    list_cout(head);
				    list_cout_count(head, el);
				    list_cout_sum(head, el);
				  cout_line();
			  break;

			  case 7: // KONKRETA elementa sameklesana saraksta
				clear_scr(); 
				cout_izvelne(meny);
				  cout_line();
				    list_cout(head);
				    list_cout_count(head, el);
				    list_cout_sum(head, el);
				      //------------------------------
				      	  list_cout_find_el(head);
				      //------------------------------
				  cout_line();
			  break;

			  case 8: // LIELAKA elementa sameklesana saraksta
				clear_scr();
				cout_izvelne(meny);
				  cout_line();
				    list_cout(head);
				    list_cout_count(head, el);
				    list_cout_sum(head, el);
				      //------------------------------
				      	  list_cout_MAX_element(head, target_max);
				      	  list_cout_MIN_element(head, target_max, target_min);

				      	  if (*(target_max) == *(target_min)) {

				      	  	 cout << RED; 
				      	  	 cout << "\n     Saraksta ir tikai viens elements, vai ari visi elementi ir vienadi!"; 
				      	  	 cout << RESET;
				      	  	 cout << endl;

				      	  } else {

				      	  //list_cout_MIN_MAX_highlight(head, target_max, target_min);
				      	  list_cout(head); 
				      	  	cout << "\n\n     Lielakais elements  : ";
						    cout << GREEN;
						    cout << *(target_max);
						    cout << RESET;
						    cout << "\n     Mazakais elements   : ";
						    cout << RED;
						    cout << *(target_min);
						    cout << RESET;
						    cout << endl;	
				      	  }
  
				      //------------------------------
				  cout_line();
			  break;

			case 9:
				list_DELETE(head);
				clear_scr();
			  return 0;
		}
	}

 	return 0;
}

int insert_new_number(){

	int user_input = 0;
    string str;

    while (1) {
    	
    	cout << YELLOW;
		cout << "\n\n     Ievadiet skaitli diapazona 0 - 99";  
        cout << "\n     [?] --> ";
        cout << RESET;

        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            char ch = str.c_str()[i]; // Parveidot STRING par CHAR

            if (!isdigit(ch)) { cout << RED; cout << " CERR: Jaievada cipars!" << RESET; } // ja nav ievadits cipars
            else { user_input = atoi(str.c_str()); } // savadak parverst par INT

            if (user_input > 99) { cout << RED; cout << " CERR: Jaievada skaitli diapazona 0 - 99" << RESET; } // ja ievadits cipars lielaks par 9

            else { // Ja lietotaja ievaditais ir skaitlis, tad ->

                return user_input;
            }
        }
    }
}

void list_cout_find_el(struct Node *head){
if (!head) return;
   
    	int find = 0;
    	cout << YELLOW;
		cout << "\n\n     Ievadi meklejamo vertibu";  
        cout << "\n     [?] --> ";
        cout << RESET;
    	cin >> find;

    	int feil = 0;

    while (head -> next != NULL){
        	if(head -> data == find){
        		find = head -> data;
        		feil += 1;
        	} head = head->next;
    } 

    if (feil != 0){
    	 cout << "\n\n     Mekletais elements  : ";
    	 	cout << GREEN;
      	 	cout << find;
      	 	cout << RESET;
      	 	cout << endl;
    } else {
    	 cout << RED;
    	 cout << "\n\n     Elements neatrasts! : FEIL";
    	 cout << RESET;
    	 cout << endl;
    }
}

void list_cout_MAX_element(struct Node *head, int *target_max){
if (!head) return;

	*(target_max) = 0;

    while (head -> next != NULL){
        	
        	if(head -> data > *(target_max)){
        		*(target_max) = head -> data;
        	} 

        	head = head->next;
    } 	
}

void list_cout_MIN_element(struct Node *head, int *target_max, int *target_min){
if (!head) return;

	*(target_min) = *(target_max);

	while (head -> next != NULL){

		if (*(target_min) > head -> data){
			*(target_min) = head -> data;
		}
		head = head -> next;
	}
}

// Funkcija (iekrasot LIELAKO un MAZAKO elementu nav PABEIGTA! = japartaisa delj pedeja el. pareizas izvades)
/*void list_cout_MIN_MAX_highlight(struct Node *head, int *target_max, int *target_min){
if (!head) return;

	cout << "\n     Saistitais saraksts : ";
	
		while (head -> next != NULL){
			if(head -> data == *(target_max)){
				cout << GREEN;
				cout << head -> data;
				cout << RESET;
				cout << " -> ";
			} else if (head -> data == *(target_min)){
				cout << RED;
				cout << head -> data;
				cout << RESET;
				cout << " -> "; 
			} else {
				cout << head -> data << " -> ";
			}
        					  
        	head = head -> next;
    	}	cout << head -> data;
}*/

void list_DELETE(struct Node *head){
if (!head) return;
    
    while (head -> next != NULL){			
     free(head);
      head = head -> next;
    } 
}

void list_cout(struct Node *head){
if (!head) return;
    
    cout << "\n     Saistitais saraksts : ";

    while (head -> next != NULL){			
      cout << head -> data << " -> ";
      head = head -> next;
    } cout << head->data;
}

void list_cout_revers(struct Node *head, int *el_r){
if (!head) return;
    
	for(int j = 0; j < *(el_r); j++){
			
		if(j == *(el_r) - 1) {
			cout << head -> data;	
		} head = head -> next;
	} 
}

void list_cout_count(struct Node *head, int *el){
if (!head) return;

    *(el) = 1;	
    cout << "\n     Elementu skaits     : ";

    while (head->next != NULL){
        *(el) += 1; 
        head = head -> next;
    }
    cout << *(el);
}

void list_cout_sum(struct Node *head, int *el){
if (!head) return;

    int summ = 0;
    cout << "\n     Visu elementu summa : ";

    for(int i = 0; i < *(el); i++){
        summ += head -> data; 
        head = head->next;

    } cout << summ;
    cout << endl;
}

// Izvadit { izvelni
void cout_izvelne(int meny_num){
  int x = 0;
   cout << "PD3 patstavigais darbs - K.Danoss              ";
     cout << YELLOW;
       cout << "Darbibas ar vienkarso saistito sarakstu";
         cout << RESET;
   cout << endl;
  
    cout << BLUE;
	cout << "┌────────────────────────────────────────────────────────────────────────────────────┐";
	cout << endl;
	  		   
	cout << "│   Saraksts preteja seciba   : ";
		x = 0; target_izvelne(x, meny_num); cout << "[ 0. reversa ]"; cout << RESET;
			cout << BLUE; 
			cout << "                                       │"; 
	cout << endl;
	
	cout << "│   Ievietot mezglu saraksta  : ";
		x = 1; target_izvelne(x, meny_num); cout << "[ 1. sakuma  ]"; cout_space(); cout << RESET;
	    x = 2; target_izvelne(x, meny_num); cout << "[ 2. vidu    ]"; cout_space(); cout << RESET;
	    x = 3; target_izvelne(x, meny_num); cout << "[ 3. beigas  ]"; cout << RESET;
	    	cout << BLUE;
	  		cout << "       │"; 
	cout << endl;    	

	cout << "│   Nodzest mezglu saraksta   : ";
	  	x = 4; target_izvelne(x, meny_num); cout << "[ 4. sakuma  ]"; cout_space(); cout << RESET;
	  	x = 5; target_izvelne(x, meny_num); cout << "[ 5. vidu    ]"; cout_space(); cout << RESET;
	  	x = 6; target_izvelne(x, meny_num); cout << "[ 6. beigas  ]"; cout << RESET;
	  		cout << BLUE;
	  		cout << "       │"; 
	cout << endl;

	cout << "│   Sameklet saraksta vertibu : ";
	  	x = 7; target_izvelne(x, meny_num); cout << "[ 7. prasito ]"; cout_space(); cout << RESET;
	  	x = 8; target_izvelne(x, meny_num); cout << "[ 8. MIN-MAX ]"; cout << RESET;
	  		cout << BLUE;
	  		cout << "                       │"; 
	cout << endl;

	cout << "│         Iziet no programmas : ";    
	    x = 9; target_izvelne(x, meny_num); cout << "[ 9. exit    ]"; cout << RESET;
	    	cout << BLUE; 
			cout << "                                       │"; 
	cout << endl;         

	cout << BLUE; 
	cout << "└────────────────────────────────────────────────────────────────────────────────────┘";
	cout << RESET; cout << endl;
	system("date"); // ??

}
void cout_space(){ // Izvadiit iekrasoto atstarpi starp 'memy' pogaam
    cout << BLUE;
       cout << "  ";
    cout << RESET;
}

void target_izvelne(int X, int MENY_NUM) { // Lietotaja izveleta sadala no izvelnes tiek ietoneta
	if(X == MENY_NUM) { cout << MAGNETA;}
	else {cout << BLUE;}
}

void cout_line(){
	cout << "\n──────────────────────────────────────────────────────────────────────────────────────"; cout << endl;
}       

void cout_line_new_list(){
	cout << "\n\n───";
	cout << MAGNETA;
	cout << "[ Atjauninats saraksts ]";
	cout << RESET;
	cout << "─────────────────────────────────────────────────────────"; cout << endl;
}   

int check_input() { // Parbaude { vai ievadits 'int'!
    int meny = 0;
    string str;

    while (1) {
    	
    	cout << YELLOW;
		cout << "\n     Ievadi opciju no 0 lidz 9";  
        cout << "\n     [?] --> ";
        cout << RESET;

        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            char ch = str.c_str()[i]; // Parveidot STRING par CHAR

            if (!isdigit(ch)) { cout << RED; cout << "     CERR: Jaievada cipars!" << RESET; } // ja nav ievadits cipars
            else { meny = atoi(str.c_str()); } // savadak parverst par INT

            if (meny > 9) { cout << RED; cout << "     CERR: Jaievada vienu ciparu no 0 lidz 9!" << RESET; } // ja ievadits cipars lielaks par 9

            if (meny > char(48) || meny < char(58)) { // Ja ievadits ASCII cipar 0-9 { tad atgriest INT

                return meny;
            }
        }
    }
}

void clear_scr() {   // Funkcija terminalim { attirit ekranu
    #ifdef _WIN32
        system("cls");      // if MS-DOS { clear screen
    #else
        system("clear");    // if not!   { clear
    #endif
}