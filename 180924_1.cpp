#include <iostream>
#include <string>

using namespace std;
// strings are actually arrays of chars this is so funny

int main(){
	cout << "No I am not writing a 'hello world' here that would be stupid" << endl;
	
	string slowo;
	
	cout << "Slowo do analizy: ";
		cin >> slowo;
	cout << endl <<slowo << ", dlugosc: " << slowo.length() << endl;
	
	short dlugoscSlowa = slowo.length();	
	
	//for (i=0;i<dlugoscSlowa;i++){
	//	swap 
	//}
	
	return 0;
}