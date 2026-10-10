#include <iostream>
using namespace std;

struct Ghiozdan
{
    float lungime;
    int nrbuzunare;
    bool laptop;
    char* producator;
};

Ghiozdan citireGhiozdan()
{
    char numeprod[100];
    Ghiozdan g;
    cout << "lungime="; cin >> g.lungime;
    cout << "nrbuzunare="; cin >> g.nrbuzunare;
    cout << "pt laptop? (0 sau 1)"; cin >> g.laptop;
    cout << "producator=";
    cin >> numeprod;
    g.producator = new char[strlen(numeprod) + 1];
    strcpy_s(g.producator, strlen(numeprod) + 1, numeprod);
    return g;
}

void modificarelungime(Ghiozdan* g, float lungime)
{
    (*g).lungime = lungime;
}

void afisareGhiozdan(Ghiozdan g)
{
    cout << "lungime=" << g.lungime << endl;
    cout << "nrbuzunare=" << g.nrbuzunare << endl;
    cout << "pt laptop?" << g.laptop << endl;
    cout << "producator=" << g.producator << endl;
}

void main()
{
    //Ghiozdan g;
    //g=citireGhiozdan();
    //modificarelungime(&g, 56);
    //afisareGhiozdan(g);
    int nrghiozdane = 3;
    Ghiozdan* ghiozdane;
    ghiozdane = new Ghiozdan[3];
    for (int i = 0; i < nrghiozdane; i++)
    {
        ghiozdane[i] = citireGhiozdan();
    }
    for (int i = 0; i < nrghiozdane; i++)
    {
        afisareGhiozdan(ghiozdane[i]);
    }
}