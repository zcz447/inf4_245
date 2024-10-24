#include <iostream>
#include <cctype>
using namespace std;


int PotegowanieRekurencyjne(int podstawa, int wykladnik);
int PotegowanieIteracyjne(int podstawa, int wykladnik);

int main(){
    
    int podstawa, wykladnik;
    char wybor;

    cout << "| Potegowanie |\n\npodaj podstawe: ";
        cin >> podstawa;
    cout << "podaj wykladnik: ";
        cin >> wykladnik;

    while(wybor != 'i' && wybor != 'r'){
        cout << "\niteracyjne [i]\nrekurencyjne [r]\n";
            cin >> wybor;
        wybor = tolower(wybor);
    }

    if (wybor == 'i'){
        cout << "wynik: " << PotegowanieIteracyjne(podstawa,wykladnik);
    }    
        else{
            cout << "wynik: " << PotegowanieRekurencyjne(podstawa,wykladnik);
        }

    return 0;
};


int PotegowanieIteracyjne(int podstawa, int wykladnik){
    int wynik = podstawa;
    if(wykladnik ==1){
        return podstawa;
    }
    else{
        for (int i=1;i < wykladnik; i++){
            wynik = wynik * podstawa;
        }
        return wynik;
    }
};
int PotegowanieRekurencyjne(int podstawa, int wykladnik){

    if (wykladnik==0){
        return 1;
    }
        else if (wykladnik % 2 == 0){
            return PotegowanieRekurencyjne(podstawa*podstawa, wykladnik/2);
        }
            else if (wykladnik % 2 == 1) {
                return podstawa * PotegowanieRekurencyjne(podstawa, wykladnik-1);
            };
};