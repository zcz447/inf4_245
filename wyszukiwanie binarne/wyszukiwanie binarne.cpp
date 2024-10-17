#include <iostream>
using namespace std;

    int PozycjaSzukanej(int tab[], int szukana);

int main(){
    

    int tab[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    //ciekawiej jak mozna samemu definiowac
    int szukana;
        cout << "jakiej liczby szukasz? ";
            cin >> szukana;

    int miejsce = PozycjaSzukanej(tab, szukana);
        // arrays are sent as pointers, cool

        //sprawdzajka
        if (miejsce != -1){
                cout << "szukana liczba znajduje się na polu: " << miejsce; 
            }
            else{
                    cout << "szukana liczba nie znajduje się w tabeli, szkoda :( ";
                }
    return 0;
}

int PozycjaSzukanej(int tab[], int szukana){
    int l = 0;
    int p = 15;
        int sr = (l+p)/2;
    
        while (l <= p) {
            if (tab[sr] == szukana){
                return sr;
            }
                else if (tab[sr] > szukana){
                    p = sr - 1;
                }
                    else{
                        l = sr + 1;
                    }
            sr = (l+p)/2;
        };
        return -1;
}
