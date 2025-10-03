#ifndef _NUMEREMARI_H_
#define _NUMEREMARI_H_
#include <string>
using namespace std;
class Numere{
protected:
string numar1;
string numar2;
public:
Numere();
Numere(string, string);
~Numere();
string SubstractFromMe1();
string AddToMe1();
string AddToMe();
string MultiplyWithMe();
string SubstractFromMe();
};
class NumereMari:public Numere
{ private:
  string num1;
  public:
  static double addNo;
  NumereMari(const string &);
  NumereMari(const NumereMari &);
  ~NumereMari();
  string sumareala(string &,string &);
  string diferentareala(string &,string &);
  string operator!();
  string operator*(const NumereMari&); //Inmultirea numerelor
  string operator+(const NumereMari&); //Adunarea numerelor
  string operator-(const NumereMari&); //Diferenta numerelor
  friend ostream& operator<<(ostream&, const NumereMari&); //ne ajuta cand afisam doar un obiectt

};
class NumereNaturale:public NumereMari
{ private:
  string nr1;
  public:
  NumereNaturale(const string &);
};
class NumereIntregi:public NumereMari
{ private:
  string nr2;
  public:
  NumereIntregi(const string &);
};
class NumereReale:public NumereMari
{ private:
  string nr3;
  public:
  NumereReale(const string &);
};
class NumereComplexe:public NumereMari
{ private:
  string nr4;
  public:
  NumereComplexe(const string &);
};
#endif // _NUMEREMARI_H_

