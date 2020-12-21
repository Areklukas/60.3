#include <iostream>
#include <fstream>

using namespace std;
const int wielkosc=200;
int nwd(int x, int y)
{
    if (x<y)
        return nwd(y,x);
    if (y==0)
        return x;
    return nwd(y,x%y);
}
int main()
{
    ifstream w("liczby.txt");
    ofstream out("wyniki.txt",fstream::app);
    int liczby[wielkosc];
    for(int i=0; i<wielkosc; i++)
    {
        int a;
        w>>liczby[i];
    }
    int najwieksza=0;
    for(int i=0; i<wielkosc; i++)
    {
        bool prawda=true;
        for(int j=0; j<wielkosc; j++)
            if (i!=j&&nwd(liczby[i],liczby[j])>1)
                prawda=false;
        if (prawda&&liczby[i]>najwieksza)
            najwieksza=liczby[i];
    }
    out<<"Najwieksza pierwsza: "<< najwieksza<<endl;
}
