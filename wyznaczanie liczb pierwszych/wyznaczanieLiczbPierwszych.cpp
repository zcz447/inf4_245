#include <iostream>
#include <cctype>
#include <cmath>

using std::cout, std::cin;

bool LiczbaPierwsza(int znacznik);



int main(){

    int poczatekZakresu, koniecZakresu, dlugosc;
    char wyborWypisanych;
    bool poprawnyZakres=0;
    bool tylkoPierwsze, tylkoZlozone;

    while(poprawnyZakres!=true){

        cout << "poczatek zakresu: ";
            cin >> poczatekZakresu;    
        cout << "koniec zakresu: ";
            cin >> koniecZakresu;

            dlugosc = koniecZakresu-poczatekZakresu;
            cout << "dl: " << dlugosc;

    if(koniecZakresu>poczatekZakresu){poprawnyZakres=true;}
    if (dlugosc > 100){

        dlugosc= dlugosc - (dlugosc-100);
        cout << "skrocono zakres do 100 miejsc";}
    }

    int zbiorWartosci [dlugosc];
    bool zbiorPrawd [dlugosc];
    
//wypelnienie zakresu
    for (int i=0; i<=dlugosc; i++){  
        zbiorWartosci[i] = poczatekZakresu + i;         
    }

//wybor co wyswietlic
    while(wyborWypisanych != 'p' && wyborWypisanych != 'z' && wyborWypisanych != 'w'){

        cout << "wypisac liczby pierwsze [p], nie pierwsze [z] czy wszystkie [w]: ";
            cin >> wyborWypisanych;
            wyborWypisanych = tolower(wyborWypisanych);
    }

//sprawdzanie do wyswietlania
if (wyborWypisanych=='p'){
    cout << "\nliczby pierwsze w zakresie ["<< poczatekZakresu << "-" << koniecZakresu << "] : \n";
    tylkoPierwsze=true;
    }
    else if(wyborWypisanych=='z'){

        cout << "\nliczby zlozone w zakresie ["<< poczatekZakresu << "-" << koniecZakresu << "]  \n";
        tylkoZlozone=true;
        }


//wyznaczenie liczby ktora jest sprawdzana i zwrocenie wartosci prawda/falsz
    for (int znacznik = poczatekZakresu; znacznik <= koniecZakresu; znacznik++){
        zbiorPrawd[znacznik-poczatekZakresu]=LiczbaPierwsza(znacznik);
    }

//wyswietlanie w konsoli
    for (int i=0;i<=dlugosc;i++){

        if(tylkoPierwsze==true){
            if (zbiorPrawd[i]){cout<<zbiorWartosci[i]<< ", ";}
        }
            else if(tylkoZlozone==true){
                if (zbiorPrawd[i]==false){cout<<zbiorWartosci[i] << ", ";}
            }
            else if (wyborWypisanych='w'){
                if (zbiorPrawd[i]==true){cout<<zbiorWartosci[i]<<" JEST liczba pierwsza\n";}
                    else{cout<<zbiorWartosci[i]<<" NIE jest liczba pierwsza\n";}
                }
        // nastepnym razem daj sposob na zapisanie w 2 osobnych tablicach, albo w dwuwymiarowej i wyswietlaj w ten sposob
    }
    return 0;
};

bool LiczbaPierwsza(int znacznik){
    if (znacznik<2){return false;}

    for (int dzielnik = 2; dzielnik <= sqrt(znacznik); dzielnik++){
            if(znacznik % dzielnik==0){
                return false;
            }
    }
    return true;
};