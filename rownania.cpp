#include <iostream>
#include <fstream>


using namespace std;


	int d, wiersz, kolumna;
	double suma, mnoznik;
	double macierz[10][11];


bool wczytajPlik( string nazwaPliku )
{
    ifstream plik;
    plik.open( nazwaPliku.c_str() );
    if( !plik.good() )
         return false;

    for (int i=0;i<10;i++)
    for (int j=0;j<11;j++){
        plik >> macierz[i][j];
    }

    return true;
}


void wypisz_kolumne(int f)
{

		for ( int i=0; i<10; i++){
		cout << macierz[i][f]<<" ";
		}
}


void ustal_mnoznik(int wiersz, int kolumna)
{
	mnoznik=macierz[wiersz][kolumna]/macierz[d][kolumna];
}

void wr0(int wiersz) //zerwowanie wiersza
{
	for (int c=0+d; c<11; c++){
	macierz[wiersz][c]=macierz[wiersz][c]-(macierz[d][c]*mnoznik);
	}

}

void kl0() //zerowanie kolumny
{

	for (int a=9; (a-d)>0; a--){
		ustal_mnoznik(a, d);
		wr0(a);

	}
}

void sumuj_obliczne()
{
	suma=0;
	for(int b=0; b<d; b++)
	{
	if(d==0)
	{
		break;
	}
	suma=suma+macierz[9-b][10]*macierz[9-d][9-b];
	}
	macierz[9-d][10]=(macierz[9-d][10]-suma)/macierz[9-d][9-d];
}


int main() {

	wczytajPlik("macierz3.txt");

	for (d=0; d<10; d++)
	{
		kl0();
	}

	for (d=0; d<10; d++)
	{
		sumuj_obliczne();
	}
	cout << "Kolejne wspolczynniki to: ";
	wypisz_kolumne(10);


	cout<<endl;

	return 0;
}
