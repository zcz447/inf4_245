#include <iostream>
using std::cin, std::cout;

void DecBin(int liczba) {
    int dlugosc = 0;
    int bin32[32] = {0}; 
    
    while (liczba > 0) {
        bin32[dlugosc] = liczba % 2;
        liczba /= 2;
        dlugosc++;
    }
    
    for (int w = dlugosc - 1; w >= 0; w--) {
        cout << bin32[w];
    }
}

int main() {
    int liczba;

    cout << "Podaj liczbe dziesietna do przemiany w binarna: ";
        cin >> liczba;

    cout << "\n\nPostac binarna liczby " << liczba << " to: ";
        DecBin(liczba); 

    return 0;
}
