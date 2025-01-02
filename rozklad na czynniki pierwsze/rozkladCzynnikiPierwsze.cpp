#include <iostream>

using std::cout, std::cin;

void RozkladNaCzynnikiPierwsze(int liczbaRozkladana);



int main (){
    
    int liczbaRozkladana;
    
    cout << "liczba do rozlozenia na czynniki pierwsze: ";
        cin >> liczbaRozkladana;

    cout << "podzial "<< liczbaRozkladana << " na czynniki pierwsze: ";
    RozkladNaCzynnikiPierwsze(liczbaRozkladana);

    return 0;
};

void RozkladNaCzynnikiPierwsze(int liczbaRozkladana){
    int dzielnik = 2;
    bool przecinek = false;
    
    while (liczbaRozkladana>1){
        
        while(liczbaRozkladana % dzielnik == 0){
            if (przecinek){cout << ", ";}
                else{przecinek = true;};
            cout << dzielnik;
            liczbaRozkladana /= dzielnik;
        };
        dzielnik++;
    };
};
