#include <iostream>
#include <cctype> //dla tolower()
#include <cmath> //dla abs(), floor()

float PotegowanieRekurencyjne(float podstawa, int wykladnikCalkowita);
float PotegowanieIteracyjne(float podstawa, int wykladnikCalkowita);

using std::cout, std::cin;



int main(){
    
    float podstawa, wykladnik;
    float wynik = 1;
    char wybor;

    cout << "| Potegowanie |\n\npodaj podstawe: ";
        cin >> podstawa;
    cout << "podaj wykladnik: ";
        cin >> wykladnik;

// informacja o liczbie ujemnej, zmiana wykladnika na liczbe rzeczywista dodatnia jezeli tak, podzielenie na czesc calkowita i po przecinku (reszta)
        bool wykladnikUjemny = (wykladnik < 0);
            if (wykladnikUjemny == true){wykladnik = abs(wykladnik);}

        int wykladnikCalkowita = floor(wykladnik);
        float wykladnikReszta = wykladnik - wykladnikCalkowita;

// zakonczenie bez wykonywania zbednych operacji poprzez wylapanie wykladnikow [-1,0,1] oraz podstawy [0,1]
       if(wykladnik==0){

            cout << "wynik: " << 1;
            return 0;
        }

            else if(wykladnik==1){

                if(wykladnikUjemny==false) {cout << "wynik: " << podstawa;}
                    else{cout << "wynik: " << 1 / podstawa;}
                return 0;
            }

            else if (podstawa == 0) {

                cout << "wynik: " << 0;
                return 0;
                }

            else if (podstawa == 1){

                cout << "wynik: " << 1;
                return 0;
            }

//policzenie PRZYBLIZONEJ reszty poza funkcja
            if (wykladnikReszta > 0){wynik = wynik + wykladnikReszta * (podstawa -1);}

//sprawdzenie czy ta liczba moze istniec
    if (podstawa < 0 && wykladnikReszta > 0){

        wynik*=PotegowanieRekurencyjne(podstawa,wykladnikCalkowita);

        if (wykladnikUjemny==false){cout << "brak rozwiązania, wynikiem jest: " << wynik << "i - liczba urojona"; }
                else{cout << "brak rozwiązania, wynikiem jest: " << 1 / wynik << "i - liczba urojona"; }
        return 0;
    }

// zapytanie o wybor rodzaju funkcji
    while(wybor != 'i' && wybor != 'r'){

        cout << "\niteracyjne [i]\nrekurencyjne [r]\n";
            cin >> wybor;
        wybor = tolower(wybor);
    }

// wykonanie funkcji w zaleznosci od wyboru
    if (wybor == 'i'){

        wynik*=PotegowanieIteracyjne(podstawa,wykladnikCalkowita);

        if (wykladnikUjemny==false) {cout << "wynik: " << wynik;}
            else {cout << "wynik: " << 1 / wynik;}        
    }    
        else{
            wynik*=PotegowanieRekurencyjne(podstawa,wykladnikCalkowita);
            
            if (wykladnikUjemny==false) {cout << "wynik: " << wynik;}
                else {cout << "wynik: " << 1 / wynik;}
        }

    return 0;
};

float PotegowanieIteracyjne(float podstawa, int wykladnikCalkowita){

    float wynik = 1;

    // TO DZIAŁA WRESZCZIE, NAPISALAM WYKLADNIKRESZTA W IF I SZUKALAM BLEDU POL GODZINY, KOCHAM UMIEJETNOSC CZYTANIA ZE ZROZUMIENIEM
        while (wykladnikCalkowita > 0) {

            if (wykladnikCalkowita % 2 == 1) {
                wynik *= podstawa;
                wykladnikCalkowita--;
            }
                else{
                    podstawa *= podstawa;
                    wykladnikCalkowita = floor(wykladnikCalkowita/ 2);
                } 
        }
            return wynik;
};



float PotegowanieRekurencyjne(float podstawa, int wykladnikCalkowita){

//milo wiedziec ze wybucha bez pierwszej czesci, naprawde milusio
    if (wykladnikCalkowita==0){return 1;}
        else if (wykladnikCalkowita % 2 == 0){return PotegowanieRekurencyjne(podstawa*podstawa, wykladnikCalkowita/2);}
        else if (wykladnikCalkowita % 2 == 1) {return podstawa * PotegowanieRekurencyjne(podstawa, wykladnikCalkowita-1);};
};
