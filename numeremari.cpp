#include <iostream>
#include <string>
#include "numeremari.h"
double NumereMari::addNo=0;
Numere::Numere(){}
Numere::Numere (string numar1,string numar2)
{this->numar1=numar1;
 this->numar2=numar2;}
Numere::~Numere (){}
string Numere::SubstractFromMe1(){
   int c=0; //numarul din minte
   int ok=0;
   if((numar2>numar1 && numar1.length()==numar2.length()) || numar1.length()<numar2.length())
      ok=1;
   string rezultat;
   if (ok == 1)
        swap(numar1, numar2); //daca ok este 1 inseamna ca numarul2 este mai mare ca numarul 2
   int i=numar1.length()-1;
   int j=numar2.length()-1;
   while (i >= 0 || j >= 0 || c != 0) {
        int cifra1= i>=0?numar1[i]-'0':0; //daca am terminat cifrele cifra1 o sa fie 0,daca nu o sa primim cifra
        int cifra2= j>=0?numar2[j]-'0':0; //daca am terminat cifrele cifra2 o sa fie 0,daca nu o sa primim cifra
        int diferenta=cifra1-cifra2-c;
        if(diferenta<0) //daca diferenta cifrelor este mai mica ca 0 numarul din minte o sa fie 1 si adaugam 10 la diferenta
           {c=1;
           diferenta=diferenta+10;}
        else
           c=0;
        rezultat=to_string(diferenta)+rezultat;
        i--;
        j--;}
    if(ok==1)
      swap(numar1,numar2);
int pozitieNonZero = 0;
    while (pozitieNonZero<rezultat.length()&&rezultat[pozitieNonZero]=='0') {
        pozitieNonZero++;}
    if (pozitieNonZero==rezultat.length()){
        return "0";}
    return rezultat.substr(pozitieNonZero);
}//acest cod parcurge sirul de caractere rezultat pentru a gasi prima pozitie care contine un caracter diferit de 0
string Numere::AddToMe1(){
   int c=0; //numarul din minte
   string rezultat;
   int i=numar1.length()-1; //cate cifre are numarul 1
   int j=numar2.length()-1; //cate cifre are numarul 2
   while (i >= 0 || j >= 0 || c > 0) {
        int cifra1= i>=0?numar1[i]-'0':0; //daca am terminat cifrele cifra1 o sa fie 0,daca nu o sa primim cifra
        int cifra2= j>=0?numar2[j]-'0':0; //daca am terminat cifrele cifra2 o sa fie 0,daca nu o sa primim cifra
        int suma=cifra1+cifra2+c;
        c=suma/10;
        rezultat=to_string(suma%10)+rezultat; //aici punem numarul
        i--;
        j--;}
     return rezultat;
}
string Numere::AddToMe(){
   if(numar1[0]=='-' && numar2[0]=='-')
       {numar1=numar1.substr(1);
        numar2=numar2.substr(1);
        Numere m(numar1,numar2);
        string r=m.AddToMe1();
        return '-'+r;}
//Daca ambele numere sunt negative le facem pozitive,le facem suma si dupa aceea il facem negativ
   if(numar1[0]!='-' && numar2[0]!='-')
        {Numere m(numar1,numar2);
        string r=m.AddToMe1();
        return r;}
//Facem suma dintre numere
   if(numar1[0]=='-' && numar2[0]!='-')
        {if(numar1.length()-1>numar2.length())
           {string altceva=numar1.substr(1);
            Numere m(altceva,numar2);
            string ceva=m.SubstractFromMe1();
           return '-'+ceva;}
        if(numar1.length()-1<numar2.length())
           {string altceva=numar1.substr(1);
            Numere m(altceva,numar2);
            string ceva=m.SubstractFromMe1();
           return ceva;}
        if(numar1.length()-1==numar2.length())
           {int ok;
            string altceva=numar1.substr(1);
           if(altceva<=numar2)
              ok=1;
           else
              ok=0;
           Numere m(altceva,numar2);
           string ceva=m.SubstractFromMe1();
           if(ok==1)
              return ceva;
           else
              return '-'+ceva;}
           }
   if(numar1[0]!='-' && numar2[0]=='-')
        {if(numar1.length()<numar2.length()-1)
           {string altceva=numar2.substr(1);
            Numere m(altceva,numar1);
            string ceva=m.SubstractFromMe1();
           return ceva;}
        if(numar1.length()>numar2.length()-1)
           {string altceva=numar2.substr(1);
            Numere m(altceva,numar1);
            string ceva=m.SubstractFromMe1();
           return ceva;}
        if(numar1.length()==numar2.length()-1)
           {int ok;
            string altceva=numar2.substr(1);
           if(altceva<=numar1)
              ok=1;
           else
              ok=0;
           Numere m(altceva,numar1);
           string ceva=m.SubstractFromMe1();
           if(ok==1)
              return ceva;
           else
              return '-'+ceva;}}
}
string Numere::MultiplyWithMe() {
    int len1=numar1.length();
    int len2=numar2.length();
    int ok=1;
    if (numar1[0] == '-') {
        ok=-ok;
        numar1=numar1.substr(1);
        len1--;
    }
    if (numar2[0] == '-') {
        ok=-ok;
        numar2=numar2.substr(1);
        len2--;
    }
    //daca numar1 sau numar2 sunt negative le scadem lungimea pe care am salvat-o in len1 si len2,iar daca doar un numar este negativ
    //il transofmam pe ok in -1, iar daca ambele sunt negative ok redevine 1
    string rezultat(len1+len2,'0');
    //rezultat o sa aiba lungimea len1+len2 si o sa fie full cu 0

    for (int i=len1-1;i>=0;i--) {
        int c=0; //numarul din minte
        int cifra1=numar1[i]-'0'; //transformam din caracter in cifra ultima cifra a primului numar
        for (int j=len2-1;j>=0;j--) {
            int cifra2=numar2[j]-'0'; //transformam din caracter in cifra ultima cifra a celui de al doilea numar
            int produs=cifra1*cifra2+(rezultat[i+j+1]-'0')+c;
            rezultat[i+j+1]=produs%10+'0';
            c=produs/10;
        }
        rezultat[i]=rezultat[i]+c;
    }

    size_t pozitieNonZero=rezultat.find_first_not_of('0');
    if (pozitieNonZero==string::npos) {
        return "0";
    } else {
        rezultat=rezultat.substr(pozitieNonZero);
    }
    //codul cauta prima aparitie a unui caracter diferit de '0' intr-un sir. daca gaseste, elimina toate zerourile initiale din sir.
    //daca sirul este alcatuit doar din zerouri initiale, returneaza "0".
    //altfel, returneaza șirul modificat fara zerouri initiale.
    if(ok == -1){
        rezultat='-'+rezultat; //daca ok e -1 ii adaugam - inainte de dumar
    }

    return rezultat;
}
string Numere::SubstractFromMe(){
       int ok=0;
       int ok2=0;
       if(numar1.length()>numar2.length())
          ok2=1;
       if(numar1.length()<numar2.length())
          ok2=2;
       if(numar1>numar2)
          ok=1;
       if(numar1[0]=='-' && numar2[0]=='-')
        {numar1=numar1.substr(1);
         numar2=numar2.substr(1);
         Numere r(numar1,numar2);
         string t=r.SubstractFromMe1();
         if(ok2==1)
          return '-'+t;
         if(ok2==2)
          return t;
         if(ok==1)
           return '-'+t;
         else
           return t;
        }
       if(numar1[0]!='-' && numar2[0]!='-')
        {Numere r(numar1,numar2);
         string t=r.SubstractFromMe1();
         if(t=="0")
          return t;
         if(ok2==2)
          return '-'+t;
         if(ok2==1)
          return t;
         if(ok==0)
           return '-'+t;
         else
           return t;
        }

      if((numar1[0]=='-' && numar2[0]!='-') || (numar1[0]!='-' && numar2[0]=='-'))
       {if(numar1[0]=='-')
            {numar1=numar1.substr(1);
            Numere r(numar1,numar2);
            string t=r.AddToMe();
            return '-'+t;}
         else
            {numar2=numar2.substr(1);
             Numere r(numar1,numar2);
             string t=r.AddToMe();
             return t;}
}
}
string NumereMari::sumareala(string &num1,string &num2){
    string numar10;
    string numar20;
    string numar3;
    string numar4;
    int i=0;
    int v1=0;
    int v2=0;
    int ok=0;
    int ok1=0;
    while(num1[i]!='.' && i!=num1.length() && num1[i]!='+' && (num1[i]!='-' || i==0))
        {numar10=numar10+num1[i];
         i++;}
    if(numar10[0]=='-')
       {numar20=numar20+'-';
       v1=-1;
       ok1=ok1+1;}
    if(i!=num1.length() && num1[i]!='+' &&  num1[i]!='-')
         {i++;
          while(i!=num1.length() && num1[i]!='+' &&  num1[i]!='-')
        {numar20=numar20+num1[i];
         i++;}
         }
    else
        numar20='0';
    v1=v1+numar20.length(); //v1 ne spune daca numarul este negativ de exemplu daca avem -245.954 o sa transformam in numar10=-245 si numar20=-954
    i=0;
    while(num2[i]!='.' && i!=num2.length() && num2[i]!='+' && (num2[i]!='-' || i==0))
        {numar3=numar3+num2[i];
         i++;}
    if(numar3[0]=='-')
       {numar4=numar4+'-';
       v2=-1;
       ok1=ok1+1;}
    if(i!=num2.length() && num2[i]!='+' &&  num2[i]!='-')
         {i++;
          while(i!=num2.length() && num2[i]!='+' &&  num2[i]!='-')
        {numar4=numar4+num2[i];
         i++;}
         }
    else
        numar4='0';
       v2=v2+numar4.length(); //v2 ne spune daca numarul este negativ de exemplu daca avem -245.954 o sa transformam in numar3=-245 si numar4=-954
    string numar5=numar20;
    string numar6=numar4; //stocam undeva numerele de dupa virgula
    numar1=numar10;
    numar2=numar3;
    string rezultat=AddToMe();
    string rezultat1="0";
    while(v1!=v2)
         if(v1<v2) //ca numerele de dupa virgula sa fie de aceeasi lungime
           {numar20=numar20+'0';
           v1=v1+1;}
         else
           {numar4=numar4+'0';
           v2=v2+1;}
    if((numar20[0]=='-' || numar4[0]=='-') && (numar20[0]=='-' && numar4[0]=='-')) //daca unul din numere este negativ ok devine 1
        ok=1;
    numar1=numar20;
    numar2=numar4;
    rezultat1=AddToMe();
    string ceva="1";
    if(numar5=="0" && numar6=="0") //daca numerele sunt intregi
        return rezultat;
    numar10=numar5.substr(1);
    if(numar5[0]=='-' && numar10<numar6)
        {string p="100";
         numar1=p;
         numar2=rezultat1;
         rezultat1=SubstractFromMe();
         numar1=ceva;
         numar2=rezultat;
         rezultat=AddToMe();
        }
    numar10=numar6.substr(1);
    if(numar6[0]=='-' && numar5<numar10)
        {string p="100";
         string ceva1="-1";
         numar1=p;
         numar2=rezultat1;
         rezultat1=SubstractFromMe();
         numar1=rezultat;
         numar2=ceva1;
         rezultat=AddToMe();
         return rezultat+'.'+rezultat1;
        }
    if(rezultat1[0]=='-')
       {rezultat1=rezultat1.substr(1);
       ceva="-1";
       if(rezultat[0]!='-')
          rezultat='-'+rezultat;}
    if(rezultat1.length()>v1)
    {numar1=rezultat;
     numar2=ceva;
     rezultat=AddToMe();
     rezultat1=rezultat1.substr(1);}
    if(rezultat1[0]=='-')
        rezultat1=rezultat1.substr(1);
    if(numar5!="0" || numar6!="0")
         return rezultat+'.'+rezultat1;
    else
         return rezultat;}
string NumereMari::diferentareala(string &num1,string &num2){
    string numar10;
    string numar20;
    string numar3;
    string numar4;
    int ok2=0;
    int i=0;
    int v1=0;
    int v2=0;
    int ok=0;
    int ok1=0;
    while(num1[i]!='.' && i!=num1.length())
        {numar10=numar10+num1[i];
         i++;}
    if(numar10[0]=='-')
       {numar20=numar20+'-';
       v1=-1;
       ok1=ok1+1;}
    if(i!=num1.length())
         {i++;
          while(i!=num1.length())
        {numar20=numar20+num1[i];
         i++;}
         }
    else
        numar20='0';
    v1=v1+numar20.length();
    i=0;
    while(num2[i]!='.' && i!=num2.length())
        {numar3=numar3+num2[i];
         i++;}
    if(numar3[0]=='-')
       {numar4=numar4+'-';
       v2=-1;
       ok1=ok1+1;}
    if(i!=num2.length())
         {i++;
          while(i!=num2.length())
        {numar4=numar4+num2[i];
         i++;}
         }
    else
        numar4='0';
       v2=v2+numar4.length();
    if(numar10==numar3)
       ok2=1;
    if(numar10>numar3)
       ok2=2;
    string numar5=numar20;
    string numar6=numar4;
    if(numar5[0]=='-')
        numar5=numar5.substr(1);
    if(numar6[0]=='-')
        numar6=numar6.substr(1);
    numar1=numar10;
    numar2=numar3;
    string rezultat=SubstractFromMe();
    string rezultat1="0";
    while(v1!=v2)
         if(v1<v2)
           {numar20=numar20+'0';
           v1=v1+1;}
         else
           {numar4=numar4+'0';
           v2=v2+1;}
    if((numar20[0]=='-' || numar4[0]=='-') && (numar20[0]=='-' && numar4[0]=='-'))
        ok=1;
    numar1=numar20;
    numar2=numar4;
    rezultat1=SubstractFromMe();
    string ceva;
    if(numar5<numar6)
    {string p;
     string m;
     if(numar5.length()<numar6.length())
        {string p(numar5.length(),'0');
        p='1'+p;
        m=p;}
     else
        {string p(numar6.length(),'0');
        p='1'+p;
        m=p;}
     string p1="1";
     if(rezultat1[0]=='-')
        rezultat1=rezultat1.substr(1);
     int t=m.length()-1;
     if(rezultat[0]!='-' && rezultat[0]!='0' && ok1!=2)
        {numar1=m;
         numar2=rezultat1;
        rezultat1=SubstractFromMe();}
     if(rezultat[0]!='-' && rezultat[0]!='0')
        {numar1=rezultat;
         numar2=p1;
         rezultat=SubstractFromMe();}
     while(rezultat1.length()<t)
        rezultat1='0'+rezultat1;
     if(ok2==1 && ok1!=2)
        return '-'+rezultat+'.'+rezultat1;
     if((ok2==0 && ok1!=2) || (ok1==2 && ok2==1))
        return rezultat+'.'+rezultat1;
     if(ok2==0 && ok1==2)
        {numar1=rezultat;
         numar2=p1;
         rezultat=AddToMe();
         return rezultat+'.'+rezultat1;}
     if(ok2==2 && ok1==2)
     {  numar1=m;
        numar2=rezultat1;
        rezultat1=SubstractFromMe();
        numar1=rezultat;
        numar2=p1;
        rezultat=AddToMe();
        if(rezultat=="0")
            rezultat='-'+rezultat;
         return rezultat+'.'+rezultat1;}

    }
    if(rezultat1[0]=='-')
       {rezultat1=rezultat1.substr(1);
       ceva="-1";}
    if(rezultat1.length()>v1)
    {numar1=rezultat;
     numar2=ceva;
     rezultat=AddToMe();
     rezultat1=rezultat1.substr(1);}
    if(numar5!="0" || numar6!="0")
         return rezultat+'.'+rezultat1;
    else
         return rezultat;
    }
NumereMari::NumereMari(const string& num2) : num1(num2)
     {addNo=addNo+0.5;}
NumereMari::NumereMari(const NumereMari &obj)
    {num1=obj.num1;
    }
NumereMari::~NumereMari()
{}
string NumereMari::operator*(const NumereMari& p){
      string rezultat4="";
      int ct=0;
      string num3=num1;
      string num4=p.num1;
      if(num3[num3.length()-1]=='i')
         {string rezultat1="";
         int j;
         rezultat1=rezultat1+num3[0];
         for(int i=1;i<num3.length()-1;i++)
            {if(num3[i]!='+' && num3[i]!='-')
             rezultat1=rezultat1+num3[i];
            else
            {j=i;
             break;}}
         if(num3[j]=='+')
            j=j+1;
         for(int i=j;i<num3.length()-1;i++)
             rezultat4=rezultat4+num3[i];
         num3=rezultat1;
         ct=1;
         }
    string rezultat5="";
      if(num4[num4.length()-1]=='i')
         {string rezultat1="";
         int j;
         rezultat1=rezultat1+num4[0];
         for(int i=1;i<num4.length()-1;i++)
            {if(num4[i]!='+' && num4[i]!='-')
             rezultat1=rezultat1+num4[i];
            else
            {j=i;
             break;}}
         if(num4[j]=='+')
            j=j+1;
         for(int i=j;i<num4.length()-1;i++)
             rezultat5=rezultat5+num4[i];
         num4=rezultat1;
         ct=ct+2;
         }
    /* in rezultat4 retinem partea imaginara a num1 si in rezultat5 a lui num2*/
    string rezultat1="";
    int j=0;
    int k=0;
    int l=0;
    int m=0;
    for(int i=0;i<num3.length();i++)
        if(num3[i]!='.')
          rezultat1=rezultat1+num3[i];
        else
          j=i; //in j retinem pozitia in care se afla punct
    if(j!=0)
        j=num3.length()-j-1; //cate cifre sunt dupa punct
    string rezultat2="";
    for(int i=0;i<num4.length();i++)
        if(num4[i]!='.')
          rezultat2=rezultat2+num4[i];
          else
          k=i; //in k retinem pozitia in care se afla punct
    if(k!=0)
        k=num4.length()-k-1; //cate cifre sunt dupa punct
    int t=0;
    t=j+k;
    string rezultat6="";
    for(int i=0;i<rezultat4.length();i++)
        if(rezultat4[i]!='.')
          rezultat6=rezultat6+rezultat4[i];
          else
           l=i; //in l retinem pozitia in care se afla punct
    if(l!=0)
         l=rezultat4.length()-l-1; //cate cifre sunt dupa punct
    string rezultat7="";
    for(int i=0;i<rezultat5.length();i++)
        if(rezultat5[i]!='.')
          rezultat7=rezultat7+rezultat5[i];
          else
          m=i; //in m retinem pozitia in care se afla punct
    if(m!=0)
        m=rezultat5.length()-m-1; //cate cifre sunt dupa punct
    int z;
    z=m+l;
    num3=rezultat1;
    num4=rezultat2;
    numar1=rezultat1;
    numar2=rezultat2;
    string rezultat=MultiplyWithMe();
    string rezultat3;
    for(int i=0;i<rezultat.length();i++)
    {if(i==rezultat.length()-t)
           rezultat3=rezultat3+'.';
        rezultat3=rezultat3+rezultat[i];}
    if(t==0 && z==0)
        {if(ct==0)
         return rezultat;
        if(ct==1)
         {rezultat5="";
          numar1=num4;
          numar2=rezultat6;
          rezultat4=MultiplyWithMe();
         if(rezultat4[0]!='-')
         return rezultat+'+'+rezultat4+'i';
         else
         return rezultat+rezultat4+'i';
         }
         if(ct==2)
         {rezultat5="";
          numar1=num3;
          numar2=rezultat7;
          rezultat4=MultiplyWithMe();
         if(rezultat4[0]!='-')
         return rezultat+'+'+rezultat4+'i';
         else
         return rezultat+rezultat4+'i';
         }
         if(ct==3)
         {numar1=num4;
          numar2=rezultat6;
          rezultat5=MultiplyWithMe();
          numar1=num3;
          numar2=rezultat7;
          rezultat4=MultiplyWithMe();
          numar1=rezultat6;
          numar2=rezultat7;
          num3=MultiplyWithMe();
          num4="-1";
          numar1=num4;
          numar2=num3;
          num3=MultiplyWithMe();
          rezultat6=sumareala(num3,rezultat);
          rezultat7=sumareala(rezultat5,rezultat4);
          if(rezultat7[0]!='-')
          return rezultat6+'+'+rezultat7+'i';
          else
          return rezultat6+rezultat7+'i';
         }
         }
    else
    {if(ct==0)
      return rezultat3;
     if(ct==1)
        { numar1=num4;
          numar2=rezultat6;
          rezultat=MultiplyWithMe();
        rezultat4="";
         for(int i=0;i<rezultat.length();i++)
         {if(i==rezultat.length()-k-l)
           rezultat4=rezultat4+'.';
          rezultat4=rezultat4+rezultat[i];}
        if(rezultat4[0]!='-')
          return rezultat3+'+'+rezultat4+'i';
          else
          return rezultat3+rezultat4+'i';
    }
    if(ct==2)
        {numar1=num3;
         numar2=rezultat7;
        rezultat=MultiplyWithMe();
        rezultat4="";
         for(int i=0;i<rezultat.length();i++)
         {if(i==rezultat.length()-m-j)
           rezultat4=rezultat4+'.';
          rezultat4=rezultat4+rezultat[i];}
        if(rezultat4[0]!='-')
          return rezultat3+'+'+rezultat4+'i';
          else
          return rezultat3+rezultat4+'i';
    }
     }
    if(ct==3)
        {numar1=num4;
         numar2=rezultat6;
         rezultat=MultiplyWithMe();
         numar1=rezultat7;
         numar2=rezultat6;
         num4=MultiplyWithMe();
         numar1=num3;
         numar2=rezultat7;
         rezultat6=MultiplyWithMe();
        rezultat4="";
         for(int i=0;i<rezultat.length();i++)
         {if(i==rezultat.length()-k-l)
           rezultat4=rezultat4+'.';
          rezultat4=rezultat4+rezultat[i];}
         rezultat5="";
         for(int i=0;i<rezultat6.length();i++)
         {if(i==rezultat6.length()-m-j)
           rezultat5=rezultat5+'.';
          rezultat5=rezultat5+rezultat6[i];}
         rezultat6="";
         for(int i=0;i<num4.length();i++)
         {if(i==num4.length()-z)
           rezultat6=rezultat6+'.';
          rezultat6=rezultat6+num4[i];}
        rezultat="-1";
        numar1=rezultat;
        numar2=rezultat6;
        rezultat2=MultiplyWithMe();
        numar1=rezultat;
        numar2=rezultat6;
        rezultat2=MultiplyWithMe();
        rezultat=rezultat3+rezultat2;
        rezultat3=rezultat4+rezultat5;
        if(rezultat3[0]!='-')
          return rezultat+'+'+rezultat3+'i';
          else
          return rezultat+rezultat3+'i';
    }
     }
string NumereMari::operator+(const NumereMari& p){
      string numar10="";
      string numar20="";
      string numar3="";
      string numar4="";
      int i=0;
      while(i!=num1.length() && num1[i]!='+' && (num1[i]!='-' || i==0))
           {numar10=numar10+num1[i];
           i++;}
      while(i!=num1.length())
           {numar20=numar20+num1[i];
           i++;}
      i=0;
      while(i!=p.num1.length() && p.num1[i]!='+' && (p.num1[i]!='-' || i==0))
           {numar3=numar3+p.num1[i];
           i++;}
      while(i!=p.num1.length())
           {numar4=numar4+p.num1[i];
           i++;}
      if(numar20!="")
        numar20.pop_back();
      if(numar4!="")
        numar4.pop_back();
      if(numar20[0]=='+')
         numar20=numar20.substr(1);
      if(numar4[0]=='+')
         numar4=numar4.substr(1);
      string num3;
      num3=sumareala(numar10,numar3);
      string num4;
      num4=sumareala(numar20,numar4);
      if(num4!="")
        {if(num4[0]!='-')
            return num3+'+'+num4+'i';
            else
            return num3+num4+'i';}
      else
          return num3;
  }
string NumereMari::operator-(const NumereMari& p){
      string numar10="";
      string numar20="";
      string numar3="";
      string numar4="";
      int i=0;
      while(i!=num1.length() && num1[i]!='+' && (num1[i]!='-' || i==0))
           {numar10=numar10+num1[i];
           i++;}
      while(i!=num1.length())
           {numar20=numar20+num1[i];
           i++;}
      i=0;
      while(i!=p.num1.length() && p.num1[i]!='+' && (p.num1[i]!='-' || i==0))
           {numar3=numar3+p.num1[i];
           i++;}
      while(i!=p.num1.length())
           {numar4=numar4+p.num1[i];
           i++;}
      if(numar20!="")
        numar20.pop_back();
      if(numar4!="")
        numar4.pop_back();
      if(numar20[0]=='+')
         numar20=numar20.substr(1);
      if(numar4[0]=='+')
         numar4=numar4.substr(1);
      string num3;
      num3=diferentareala(numar10,numar3);
      string num4;
      num4=diferentareala(numar20,numar4);
      if(num4!="" && num4!="0")
        {if(num4[0]!='-')
            return num3+'+'+num4+'i';
            else
            return num3+num4+'i';}
         else
            return num3;
  }
string NumereMari::operator!(){
     if(num1[num1.length()-1]!='i')
       {if(num1[0]=='-')
    {string numar4(num1.length()-1,'0');
    for(int i=1;i<=num1.length();i++)
        {numar4[i-1]=num1[i];}
    return numar4;}
 else
    return num1;
}
   else
   {string rezultat1="";
    string rezultat2="";
    int j=0;
    rezultat1=rezultat1+num1[0];
    for(int i=1;i<num1.length();i++)
        {if(num1[i]!='+' && num1[i]!='-')
          rezultat1=rezultat1+num1[i];
         else
          {j=i;
          i=num1.length();}}
    for(int i=j+1;i<num1.length()-1;i++)
        rezultat2=rezultat2+num1[i];
    NumereMari p1(rezultat1);
    NumereMari p2(rezultat2);
    string t=p1*p1;
    string r=p2*p2;
    NumereMari p3(t);
    NumereMari p4(r);
    string p=p3+p4;
    p="Radical din "+p;
    return p;
   }
}

ostream& operator<<(ostream& out, const NumereMari& p)
{
 out<<"("<<p.num1<<")";
 return out;
}
NumereNaturale::NumereNaturale(const string& num2) : NumereMari(num2),nr1(num2)
{}
NumereIntregi::NumereIntregi(const string& num2) : NumereMari(num2),nr2(num2)
{}
NumereReale::NumereReale(const string& num2) : NumereMari(num2),nr3(num2)
{}
NumereComplexe::NumereComplexe(const string& num2) : NumereMari(num2),nr4(num2)
{}
