#include <iostream>
#include <cmath> //floor
using std::cout, std::cin, std::cerr;


//code ineffective, split at the decimal point to leverage, how to connect it though
int CalculatePowerRecursive(int podstawa, int wykladnik){

    if (wykladnik==0){return 1;}
        else if (wykladnik % 2 == 0){return CalculatePowerRecursive(podstawa*podstawa, wykladnik/2);}
        else if (wykladnik % 2 == 1) {return podstawa * CalculatePowerRecursive(podstawa, wykladnik-1);};
    return 0;
}
//musi byc po ze wzgledu na to ze wywoluje CalculatePowerRecursive, moglabym deklaracje na gorze ale to troche bez sensu 
void DisplayResult(float podstawa, float wykladnik){

    double wynik = 1;
    double dizesietnaWykladnika = wykladnik - floor(wykladnik);

    //zmiana zmiennych na czesc calkowita, aby modulo dzialalo zmiana na int
    int calkowitaWykladnika = floor(wykladnik);

        if (calkowitaWykladnika == 0) {wynik = 1;}
            else if (calkowitaWykladnika == 1) {wynik = podstawa;}
            else if (podstawa == 1) {wynik = 1;}
            else if (podstawa == 0){wynik = 0;}  
                else{wynik *= CalculatePowerRecursive(podstawa,abs(calkowitaWykladnika));}

    //zaistnial problem przez ktory trzeba bylo zmienic na float, wczesniej byl int, teraz i tak musi byc float bo mamy czesc dziesietna
    if (dizesietnaWykladnika > 0) {
        if (podstawa > 0) {
            //nie ma wysokiej precyzji, ale nie mam lepszego sposobu
            wynik *= exp(dizesietnaWykladnika * log(podstawa));
        } else {
            cerr << "Error: Podstawa ujemna z wykladnikiem dziesietnym jest nieobslugiwana\n";
            return;
        }
    }
        if (calkowitaWykladnika < 0) {wynik = 1 / wynik;}

        cout << "wynik " << podstawa << " ^ " << wykladnik << ": " << wynik;
}

int main(){
    float podstawa, wykladnik;

    cout << "| Potegowanie |\n\n";
        cout << "podaj podstawe: ";
            cin >> podstawa;
        cout << "podaj wykladnik: ";
            cin >> wykladnik;

    DisplayResult(podstawa,wykladnik);
    return 0;        
}