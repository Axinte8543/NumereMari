#include <iostream>
#include "numeremari.h"
#include <string>
#include <fstream>
using namespace std;
ifstream fin("date4.in");
ofstream g("date4.out");
int main()
{cout<<"Buna ziua!"<<endl;
int *m;
int *ct;
ct=new int(0);
m=new int(0);
string *r;
string *tn;
string *tn1;
tn=new string();
tn1=new string();
r=new string();
string a;
string b;
string c;
while(*m==0)
{
cout<<"Introduceti primul numar."<<endl;
getline(cin,a);
cout<<"Introduceti cel de-al doilea numar."<<endl;
getline(cin,b);
cout<<"Ce operatie doriti sa utilizati?"<<endl;
getline(cin,c);
NumereMari *n;
        if (a.find('i') != string::npos) {
            n = new NumereComplexe(a);
            *tn="numar complex";
        } else if (a.find('.') != string::npos) {
            n = new NumereReale(a);
            *tn="numar real";
        } else if (a.find('-') != string::npos) {
            n = new NumereIntregi(a);
            *tn="numar intreg";
        } else {
            n = new NumereNaturale(a);
            *tn="numar natural";
        }

        NumereMari* n1;
        if (b.find('i') != string::npos) {
            n1 = new NumereComplexe(b);
            *tn1="numar complex";
        } else if (b.find('.') != string::npos) {
            n1 = new NumereReale(b);
            *tn1="numar real";
        } else if (b.find('-') != string::npos) {
            n1 = new NumereIntregi(b);
            *tn1="numar intreg";
        } else {
            n1 = new NumereNaturale(b);
            *tn1="numar natural";
        }

try{
for (char d : a) {
            if (!(isdigit(d) || d == 'i' || d == '+' || d == '-' || d == '.'))
                throw d;
            }
for (char d : b) {
            if (!(isdigit(d) || d == 'i' || d == '+' || d == '-' || d == '.'))
               throw d;
            }
if (c == "Suma") {
                cout << "Suma dintre " << *n <<", care este un "<< *tn<< " si " << *n1 <<", care este un "<<*tn1<< " este " << (*n + *n1) << endl;
                *ct=1;
            }
if (c == "Diferenta") {
                cout << "Diferenta dintre " << *n <<", care este un "<< *tn<< " si " << *n1 <<", care este un "<< *tn1<< " este " << (*n - *n1) << endl;
                *ct=1;
            }
if (c == "Inmultire") {
                cout << "Inmultirea dintre " << *n <<", care este un "<< *tn<<  " si " << *n1 <<", care este un "<< *tn1<<  " este " << (*n * *n1) << endl;
                *ct=1;
            }
if(c=="Modulul primului numar")
   {
   cout<<"Modulul numarului "<<*n<<" este "<<!(*n)<<endl;
   *ct=1;}
if(c=="Modulul celui de-al doilea numar")
   {
   cout<<"Modulul numarului "<<*n1<<" este "<<!(*n1)<<endl;
   *ct=1;}
if(*ct==0)
    {cout<<"Operatia pe care ai scris-o nu este valida."<<endl;
    NumereMari::addNo--;}
}
catch (char d)
{
    cout<<"Caracterul invalid:"<<d<<".Nu se poate face operatia."<<endl;
    NumereMari::addNo--;
}
cout<<"Ai efectuat "<<NumereMari::addNo<<" operatii"<<endl;
delete n;
delete n1;
cout<<"Vrei sa incerci din nou?"<<endl;
*m=2;
while(*m==2)
{getline(cin,*r);
if(*r=="Da")
   *m=0;
if(*r=="Nu")
   *m=1;
if(*m==2)
   cout<<"Nu ai scris un raspuns valid"<<endl;}
*ct=0;
}
cout<<"Aici s-a terminat conversatia noastra.Sa aveti o zi placuta!";
delete ct;
delete m;
delete r;
/*
g<<"Buna ziua!"<<endl;
int *m1;
int *ct1;
ct1=new int(0);
m1=new int(0);
string *r1;
r1=new string();
string a1;
string b1;
string c1;
while(*m1==0)
{
g<<"Introduceti primul numar."<<endl;
getline(fin,a1);
g<<"Introduceti cel de-al doilea numar."<<endl;
getline(fin,b1);
g<<"Ce operatie doriti sa utilizati?"<<endl;
getline(fin,c1);
NumereMari *n3;
        if (a.find('i') != string::npos) {
            n3 = new NumereComplexe(a);
            *tn="numar complex";
        } else if (a.find('.') != string::npos) {
            n3 = new NumereReale(a);
            *tn="numar real";
        } else if (a.find('-') != string::npos) {
            n3 = new NumereIntregi(a);
            *tn="numar intreg";
        } else {
            n3 = new NumereNaturale(a);
            *tn="numar natural";
        }

        NumereMari* n4;
        if (b.find('i') != string::npos) {
            n4 = new NumereComplexe(b);
            *tn1="numar complex";
        } else if (b.find('.') != string::npos) {
            n4 = new NumereReale(b);
            *tn1="numar real";
        } else if (b.find('-') != string::npos) {
            n4 = new NumereIntregi(b);
            *tn1="numar intreg";
        } else {
            n4 = new NumereNaturale(b);
            *tn1="numar natural";
        }

try{
for (char d1 : *a1) {
            if (!(isdigit(d1) || d1 == 'i' || d1 == '+' || d1 == '-' || d1 == '.'))
                throw d1;
            }
for (char d1 : *b1) {
            if (!(isdigit(d1) || d1 == 'i' || d1 == '+' || d1 == '-' || d1 == '.'))
               throw d1;
            }
if(*c1=="Suma")
   {g<<"Suma dintre "<<n3<<" si "<<n4<<" este "<<n3+n4<<endl;
   *ct1=1;}
if(*c1=="Diferenta")
   {g<<"Diferenta dintre "<<n3<<" si "<<n4<<" este "<<n3-n4<<endl;
   *ct1=1;}
 if(*c1=="Inmultire")
   {g<<"Inmultirea dintre "<<n3<<" si "<<n4<<" este "<<n3*n4<<endl;
   *ct1=1;}
if(*c1=="Modulul primului numar")
   {
   g<<"Modulul numarului "<<n3<<" este "<<!n4<<endl;
   *ct1=1;}
if(*c1=="Modulul celui de-al doilea numar")
   {
   g<<"Modulul numarului "<<n4<<" este "<<!n4<<endl;
   *ct1=1;}
if(*ct1==0)
    g<<"Operatia pe care ai scris-o nu este valida."<<endl;
}
catch (char d1)
{
    g<<"Caracterul invalid:"<<d1<<".Nu se poate face operatia."<<endl;
}
g<<"Vrei sa incerci din nou?"<<endl;
*m1=2;
while(*m1==2)
{getline(fin,*r1);
if(*r1=="Da")
   *m1=0;
if(*r1=="Nu")
   *m1=1;
if(*m1==2)
   g<<"Nu ai scris un raspuns valid"<<endl;}
*ct1=0;
}
g<<"Aici s-a terminat conversatia noastra.Sa aveti o zi placuta!";
delete ct1;
delete m1;
delete r1;
delete a1;
delete b1;
delete c1;*/
}


//folosim constructorii si destructorii
//am separat clasa de cpp
//avem o valaore de tip static,avem lista de initializare

