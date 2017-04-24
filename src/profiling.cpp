#include <iostream>
#include <string>
#include "mathlib.h"

using namespace std;


int main(void) {

double strtodouble;//ukladaju sa cisla po jednom zo vstupu
double spolu=0;//sucet cisel zo vstupu
int counter=0; //N=pocet cisel
double prumer;//aritmeticky priemer cisel
double pole[1000];//pole s cislami zo vstupu
int i=0;
int j;
double s;//smerodajna odchylka
double suma=0;//suma v smerodajnej odchylke




while (cin >> strtodouble){ //nacitavanie cisel zo vstupu
      spolu=sum(spolu,strtodouble);
      pole[i]=strtodouble;
      counter++;
      i++;
      if(counter==1000){
          break;
          cout << "Maximalny pocet cisel je 1000. Zapocitali sme iba prvych 1000 cisel.";
    }

}
if (counter != 10 && counter != 100 && counter != 1000){
//funguje aj pri inom pocte cisel ako je
//v zadani, ale vypise upozornenie na iny pocet(ok napr. ked nezarata chybne napisane cisla)
        cout << "!!!POZOR!!!Zadali ste " << counter <<  "cisel. Ocakavany pocet je 10,100 alebo 1000\nAk ste zadali iny pocet, skontrolujte desatinne cisla(bodka)\n";
} else {
    prumer=div(spolu,counter);

    for(j=0;j<counter;j++){ //pocitanie sumy v smerodajnej odchylke
        double par=sub(pole[j],prumer);//pocita xi-prumer
        double moc=pwr(par,2);//pocita 2. mocninu z predchadzajuceho
        suma+=moc;//pocita sumu v smer.odch.
    }
    double pododmoc=div(suma,--counter);//vypocita suma/N-1 - co je pod odmocninou
    s=sqroot(pododmoc);// vypocita odmocninu z prechadzajuceho == smerodajna odchylka

    cout << "priemer zadanych cisel je " << prumer << endl;
    cout << "smerodajna odchylka zadanych cisel je " << s << endl;
}
return 0;
}
