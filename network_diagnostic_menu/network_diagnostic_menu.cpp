#include <iostream>
//#include <string>

// PD_0605 - Danoss - 26/3/21 - GNU nano 4.8


//https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
//http://www.linuxandubuntu.com/home/10-linux-commands-for-network-diagnostics#1_ping

using namespace std;
	
	#define RESET ("\033[0m");
	#define BLUE  ("\x1B[30m\033[46m");
	#define RED ("\033[31m");
	#define MAGNETA ("\x1B[30\033[45m");
	#define YELLOW ("\033[93m");
	#define CYAN ("\033[36m");

	void cout_izvelne(int);
	void cout_space();
	void target_izvelne(int, int);
	int check_input();
	  void command_ping();
	  void command_dig();
	  void command_ethtool();
	  void command_ipaddrls();
	void cout_line();

int main(){

	int meny = 0;
      system("clear");
	  cout_izvelne(meny);
   
    while(1){
	  meny = check_input();
		switch(meny){
			
			case 1:
				system("clear");
				cout_izvelne(meny);
				cout << endl;
				   cout_line();
				      system("ping -c 4 www.linuxandubuntu.com");
				   cout_line();
				command_ping();   
			  break;

			case 2:
				system("clear");
				cout_izvelne(meny);
				cout << endl;
				   cout_line();
				      system("dig www.linuxandubuntu.com");
		           cout_line();
				command_dig();
			  break;

			case 3:
				system("clear");
				cout_izvelne(meny);
				cout << endl;
				   cout_line();
				      system("ethtool eth0");
				   cout_line();
				command_ethtool();
			  break;

			  case 4:
				system("clear");
				cout_izvelne(meny);
				cout << endl;
				   cout_line();
				      system("ip addr ls");
				   cout_line();
				command_ipaddrls();
			  break;

			case 9:
				system("clear");
			  return 0;
		}
	}

 return 0;

}
// Izvadit { izvelni
void cout_izvelne(int meny_num){
  int x = 0;
   cout << "Cetras Utiliites v1.0                                        ";
     cout << YELLOW;
       cout << "Diagnose Network In Linux";
         cout << RESET;
   cout << endl;
  
    cout << BLUE;
	cout << "┌────────────────────────────────────────────────────────────────────────────────────┐";
	cout << endl;
	
	  cout << "│"; 
	  		 cout_space();
	  x = 0; target_izvelne(x, meny_num); cout << "    MENY    "; cout << RESET; 
	         cout_space();
	  x = 1; target_izvelne(x, meny_num); cout << "[ 1 ping ]"; cout << RESET;
	         cout_space();
	  x = 2; target_izvelne(x, meny_num); cout << "[ 2 dig ]"; cout << RESET;
	         cout_space();
	  x = 3; target_izvelne(x, meny_num); cout << "[ 3 ethtool ]"; cout << RESET;
	         cout_space();
	  x = 4; target_izvelne(x, meny_num); cout << "[ 4 ip addr ls ]"; cout << RESET;
	         cout_space();
	  x = 9; target_izvelne(x, meny_num); cout << "[ exit 9 ]"; cout << RESET;
	         cout_space();

	  cout << BLUE; cout << "│"; cout << endl;

	cout << BLUE; 
	cout << "└────────────────────────────────────────────────────────────────────────────────────┘";
	cout << RESET; cout << endl;
	system("date");

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

int check_input() { // Parbaude { vai ievadits 'int'!
    int meny = 0;
    string str;

    while (1) {
    	
    	cout << endl;
		  cout << YELLOW;
		    cout << "      Ievadi opciju no 1 lidz 4, vai ari 9";  
		      cout << endl;
          cout << "      [?] --> ";
             cout << RESET;

        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            char ch = str.c_str()[i]; // Parveidot STRING par CHAR

            if (!isdigit(ch)) { cout << RED; cout << " CERR: Jaievada cipars!" << RESET; } // ja nav ievadits cipars
            else { meny = atoi(str.c_str()); } // savadak parverst par INT

            if (meny > 9) { cout << RED; cout << " CERR: Jaievada vienu ciparu no 1 lidz 4!, vai 9!" << RESET; } // ja ievadits cipars lielaks par 9

            if (meny > char(47) || meny < char(58)) { // Ja ievadits ASCII cipar 1-9 { tad atgriest INT

                return meny;
            }
        }
    }
}

void command_ping(){
cout << CYAN;
	cout << endl << endl;
	cout << "\e[3m      PING"; cout << endl;
	cout << endl;
	cout << "      \"One of the first commands, if not the first one, when diagnosing a "; cout << endl;
	cout << "      network failure or intermittence. The ping tool will help us determine"; cout << endl;
	cout << "      if there is a connection in the network, be it local or the Internet.\" \e[0m"; cout << endl;
	cout << endl; 
 cout << RESET;	
}

void command_dig(){
cout << CYAN;
	cout << endl << endl;
	cout << "\e[3m      DIG"; cout << endl;
	cout << endl;
	cout << "      \"This command allows us to verify if the DNS is working correctly, before that, "; cout << endl;
	cout << "      we must verify which DNS we have in the network configuration. In this example,"; cout << endl;
	cout << "      we want to see the IP address of our website, www.linuxandubuntu.com which returns"; cout << endl;
	cout << "      us 173.274.34.38.\"\e[0m"; cout << endl;
	cout << endl; 
 cout << RESET;
}

void command_ethtool(){
cout << CYAN;
	cout << endl << endl;
	cout << "\e[3m      ETHTOOL"; cout << endl;
	cout << endl;
	cout << "      \"This tool is a replacement for mii-tool. It comes from CentOS6 onwards "; cout << endl;
	cout << "      and allows to see if the network card is physically connected to the network,"; cout << endl;
	cout << "      that is. We can diagnose if the network cable is actually connected to the switch.\" \e[0m"; cout << endl;
	cout << endl; 
 cout << RESET;
}

void command_ipaddrls(){
cout << CYAN;
	cout << endl << endl;
	cout << "\e[3m      IP ADDR LS"; cout << endl;
	cout << endl;
	cout << "      \"Another of the specific tools of Linux that allows us to list the network cards  "; cout << endl;
	cout << "      and their respective IP addresses. This tool is very useful when you have several"; cout << endl;
	cout << "      IP addresses configured.\" \e[0m"; cout << endl;
	cout << endl; 
 cout << RESET;
}
//                 Another of the specific tools of Linux that allows us to list the network cards 
//                 and their respective IP addresses. This tool is very useful when you have several 
//                 IP addresses configured. 

//                 and allows to see if the network card is physically connected to the network, 
//                that is. We can diagnose if the network cable is actually connected to the switch. 

void cout_line(){
	cout << "──────────────────────────────────────────────────────────────────────────────────────"; cout << endl;
}                  