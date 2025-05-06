#include <iostream>

using std::cin, std::cout;

double f(double x){ 
	return x*(x*(x-3)+2)-6;
}

double plowieniePrzedzialow(double start, double end, double epsilon){
    if(f(start)==0){return start;}
    if(f(end)==0){return end;}

    double mid;

    while(end-start > epsilon){
        mid=(start+end)/2;
            if(f(mid)==0){return mid;}
        
        if(f(start)*f(mid)<0){end = mid;}
            else{start = mid;}
    }
    return (start+end)/2;
    
}

int main(){

        double start = 1;
        double end = 1;
        double epsilon = 0.00001;

        cout << "zakladajac ze f(a)*f(b) < 0 (czyli jedna wartosc ujemna, jedna dodatnia)";
    while(start*end > 0){
        cout << "\npodaj poczatek przedzialu: ";
            cin >> start;
        cout << "\npodaj koniec przedzialu: ";
            cin >> end;
    }
        
        cout << "miejsce zerowe: " << plowieniePrzedzialow(start,end,epsilon);

    return 0;
}