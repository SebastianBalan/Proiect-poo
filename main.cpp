#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class numarMare
{

    list <int> l;
public:
///operatii
    numarMare operator+( numarMare );
    numarMare operator-( numarMare );

    ///constructor
    numarMare(char* );
    numarMare()
    {}

    friend ostream &operator<<(ostream &output, numarMare &a);
    friend istream &operator>>(istream  &input, numarMare &a);


    friend class Vector;

};

class Vector
{
    int a;
    friend class numarMare;
public:

};

numarMare::numarMare(char *s)
{
    int n=strlen(s);
    int i=0;
    while(i<n)
    {
        l.push_back((int)(s[i] - '0'));///convertesc valoare din cod ascii la valoarea numerica
        i++;
    }

}

numarMare numarMare :: operator+(numarMare a)
{
    numarMare c;
    int x=0;
    while(!a.l.empty() && !l.empty())
    {

        c.l.push_front((a.l.back()+l.back()+x)%10);
        if(x==1)
        {
            x=0;

        }
        if(a.l.back()+l.back()>9)
            x=1;
        a.l.pop_back();
        l.pop_back();

    }

    while(!a.l.empty())
    {
        if (a.l.back() + 1 > 9)
        {
            x = 1;
        }

        c.l.push_front((a.l.back() + x)%10);
        x=0;

        a.l.pop_back();
    }
///la finalul uneia dintre liste nu adauga 1 daca este peste 9
    while(!l.empty())
    {
        if (l.back() + 1 > 9)
        {
            x = 1;
        }

        c.l.push_front((l.back() + x)%10);
        x=0;
        l.pop_back();
    }

    while(!c.l.empty())
    {
        cout<<c.l.front()<<" ";
        c.l.pop_front();
    }

    cout<<endl;
    return c;
}

numarMare numarMare :: operator-(numarMare a)
{
    numarMare c;
    int x=0;///daca m-am imprumutat 0 fals, 1 adevarat
    while(!a.l.empty() && !l.empty())
    {
        if(x==1)
        {
            int aux=a.l.back();
            a.l.pop_back();
            aux--;
            a.l.push_back(aux);
            x=0;
        }

        if(a.l.back() < l.back())
        {
            int aux=a.l.back();
            a.l.pop_back();
            x=1;///ma imprumut de la urmatorul
            aux+=10;
            a.l.push_back(aux);
            c.l.push_front(a.l.back()-l.back());
        }
        else
            c.l.push_front(a.l.back()-l.back());

        a.l.pop_back();
        l.pop_back();

    }

    while(!a.l.empty())
    {
        if(x==1)
        {
            int aux=a.l.back();
            a.l.pop_back();
            aux--;
            a.l.push_back(aux);
            x=0;
        }
        c.l.push_front(a.l.back());
        a.l.pop_back();
    }

    while(!c.l.empty())
    {
        cout<<c.l.front()<<" ";
        c.l.pop_front();
    }

    cout<<endl;
    return c;
}

ostream &operator<<(ostream &output, numarMare &a)
{
    ///output << "\nLista este: ";
    /// list <int> :: iterator it;
    ///for(it = a.l.begin(); it != a.l.end(); ++it)
    ///  output  << " " << *it;

    return output;
}

istream &operator>>(istream &input,numarMare &a)
{
    cout<<"Introduceti datele din lista, daca vreti sa opriti inserarea tastati -1 \n";
    int k=0;
    while(k>=0)
    {
        input >> k;
    }

    return input;
}

int main()
{
    numarMare a;  ///=numarMare("784587689876545");
    numarMare b;   ///=numarMare("460538702670");
    numarMare e ;  ///=numarMare("784587689876545");
    numarMare f ; ///=numarMare("460538702670");
    numarMare c,d;
    cin >> a >> b ;
    c=a+b;
    d=f-e;
    return 0;
}
