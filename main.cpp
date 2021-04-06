#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class plik{
	public:
		ifstream wejscie;
		ofstream wyjscie;
	plik();
	~plik();
	bool sprawdzPlik();
};
plik::plik(){
	wejscie.open("ciagi.txt");
	wyjscie.open("wynik.txt");
}
plik::~plik(){
	wejscie.close();
	wyjscie.close();
}
bool plik::sprawdzPlik(){
	if(wejscie.good()&&wyjscie.good()) return true;
	else return false;
}
/////////
class ciagi:public plik{
	public:
		vector <int> ciag;
		string liczba;
		int SprawdzanaLiczba;
	void wczytaj();
	void sprawdz(int liczba);
	void zapisCiagu(int liczba);
	void zapisDoPliku();
};
void ciagi::wczytaj(){
	while(!wejscie.eof()){
		wejscie>>liczba;
		bitset<32> bin(liczba);
		SprawdzanaLiczba = bin.to_ulong();
		sprawdz(SprawdzanaLiczba);
	}
}
void ciagi::sprawdz(int liczba){
	vector <int> t;
	for(int i=2; i<=liczba/2; i++){
    	int x=liczba;
    	while(x%i==0){
    		x=x/i;
    		t.push_back(x);
    	}
	}
	if(t.size()==2) zapisCiagu(SprawdzanaLiczba);
	else return; 
}
void ciagi::zapisCiagu(int liczba){
	ciag.push_back(liczba);
}
void ciagi::zapisDoPliku(){
	wyjscie<<ciag.size()<<endl;
	wyjscie<<"Minimalnie: "<<*min_element(ciag.begin(),ciag.end())<<endl;
	wyjscie<<"Maksymalnie: "<<*max_element(ciag.begin(),ciag.end());
}
int main(){
	plik p1;
	ciagi c1;
	p1.sprawdzPlik();
	if(p1.sprawdzPlik() == false) exit(0);
	else{
		c1.wczytaj();
		c1.zapisDoPliku();
	}
	return 0;
}
