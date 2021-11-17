// PD2 Kartosanas Algoritmi - Danoss - 11/02/2021 - Sublime Text 3.2.2v
// Info teksti par algoritmiem
void n1();  // - Klasiskais Burbulkartosanas algoritms
void n2();  // - Uzlabots burbulkartosanas algoritms
void n3();  // - Papildinajums uzlabotam burbulkartosanas algoritmam
void n4();  // - Ieveitosanas kartosanas algortms
void n5();  // - Atra kartosana
void n6();  // - Sapludinsanas kartosanas algoritms
void n7();  // - Caulas kartosanas algoritms
void n8();  // - Atlases kartosana

void info (int nr){
    switch(nr) {    // nr { lietotaja ievadits izvelnes skaitlis
        case 1: n1(); break;
        case 2: n2(); break;
        case 3: n3(); break;
        case 4: n4(); break;
        case 5: n5(); break;
        case 6: n6(); break;
        case 7: n7(); break;
        case 8: n8(); break;
    }
}

void n1(){
    cout << REDI << "\n\tSis kartosanas algoritms, parasti neiziet arpus macibu materiala ramjiem." << endl;
    cout << "\n\t" << REDU << "Nav piemerots lieliem datu apjomiem." << RESET << endl;
}

void n2(){
    cout << REDI << "\n\tSis kartosanas algoritms, parasti neiziet arpus macibu materiala ramjiem." << endl;
    cout << "\tPapildinajums - ar katru areja cikla izpilditu iteraciju - iekseja cikla iteraciju" << endl;
    cout << "\tskaits tiek samazinats" << endl;
    cout << "\n\t" << REDU << "Nav piemerots lieliem datu apjomiem." << RESET << endl;
}

void n3(){
    cout << REDI << "\n\tSis kartosanas algoritms, parasti neiziet arpus macibu materiala ramjiem." << endl;
    cout << "\tPapildinajums - ar katru areja cikla izpilditu iteraciju - iekseja cikla iteraciju" << endl; 
    cout << "\tskaits tiek samazinats" << endl;
    cout << "\tUzlabojums papildinajumam - Ja masivs ir sakartots, tad areja cikla iteracijas" << endl;
    cout << "\ttiek apstadinatas." << endl;
    cout << "\n\t" << REDU << "Nav piemerots lieliem datu apjomiem." << RESET << endl;
}

void n4(){
    cout << REDI << "\n\tSis kartosanas algoritms, ir balstits uz salidzinasanu atrasanas vieta." << endl;
    cout << "\ttiek uzturets apakssaraksts, kas viemer ir sakartots." << endl;
    cout << "\n\t" << REDU << "Nav piemerots lieliem datu apjomiem." << RESET << endl;
}

void n5(){
    cout << REDI << "\n\t Sis rekursivais kartosanas algoritms, sadala masivu divos segmentos:" << endl;
    cout << "\t     Pirmaja sgmenta - visi elementi mazaki vai vienadi ar kontrolvertibu." << endl;
    cout << "\t     Otraja segmenta - visi elementi ir lielaki par kontrolvertibu." << endl;
    cout << "\t                     - rekursivi sakarto abus segmentus." << endl;
    cout << "\n\t " << REDU << "Pietiekami efektivs prieks lieliem datu apjomiem." << RESET << endl;
}

void n6(){
    cout << REDI << "\n\tSis kartosanas algoritms ir lidzigs ATRAS KARTOSANAS algoritmam." << endl;
    cout << "\t" << "Masivs tiek sadalits divas dalas, katra dala tiek sakartota" << endl;
    cout << "\tatseviski, un pectam abas sakartotas dalas tieks sapludinatas kopa." << endl;
    cout << "\n\t" << REDU << "Pietiekami efektivs prieks lieliem datu apjomiem." << RESET << endl;
}

void n7(){
    cout << REDI << "\n\tSis kartosanas algoritms ir uzlabots IEVIETOSANAS algoritms." << endl;
    cout << "\tMasivs tieks sadalits vairakos apakssarakstos, katra saraksta elementi" << endl;
    cout << "\ttiek ievietoti pareizaja pozicija pec pieaugum secibas," << endl;
    cout << "\tsaraksti tiek salikti viena masiva." << endl;
    cout << "\n\t" << REDU << "Loti efektivs prieks lieliem datu apjomiem." << RESET << endl;
}

void n8(){
    cout << REDI << "\n\tSis kartosanas algoritms atrod masiva mazako elementu un" << endl;
    cout << "\tievieto to pareizaja vieta, samainot to ar pirmo elementu." << endl;
    cout << "\n\t" << REDU << "Nav piemerots lieliem datu apjomiem." << RESET << endl;
}