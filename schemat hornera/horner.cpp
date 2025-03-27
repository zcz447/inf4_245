#include <iostream>

using std::cout, std::cin;


int Horner(int stopien, int wspolczynniki[], int argument){
    if(stopien == 0){
        return wspolczynniki[0];
    }
    return argument * Horner(stopien - 1, wspolczynniki, argument) + wspolczynniki[stopien]; 
    
}

int main (){
    
    int *wspolczynniki;
    int argument;
    int stopien;

    cout << "Podaj stopien wielomianu: ";
        cin >> stopien;
    wspolczynniki = new int [stopien + 1];


    for (int i = 0; i <= stopien; i++){
        cout << "podaj wpolczynnik stojacy przy potedze " << stopien-i << ": ";
            cin >> wspolczynniki[i];

//wyswietlanie wielomianu po kazdym wpisie
        cout << "Wielomian: ";
            for (int j = 0; j <= i; j++) {
                if (j > 0) {cout << " + ";}
                cout << wspolczynniki[j];
                if (stopien - j > 0) {
                    cout << "x";
                    if (stopien - j > 1) {cout << "^" << stopien - j;}
                }
            }
            cout << "\n";
    }

        cout << "podaj argument: ";
            cin >> argument;

//wynik
    cout << "\nWartość wielomianu: " << Horner (stopien, wspolczynniki, argument);

    delete [] wspolczynniki;

    return 0;
}
