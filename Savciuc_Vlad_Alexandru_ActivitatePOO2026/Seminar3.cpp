#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Prajitura {
public:
	char* denumire;
	float pret;
	int cantitate;
	bool dePost;
	int nrIngrediente;
	string* ingrediente;
	/*const int id;*/
	Prajitura() {
		this->denumire = new char[strlen("Tiramisu") + 1];
		strcpy(denumire, "Tiramisu");
		this->pret = 15;
		this->cantitate = 250;
		this->dePost = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "piscoturi";
		this->ingrediente[1] = "vanilie";
		this->ingrediente[2] = "cafea";
		
	}
	Prajitura(const char* denumire, float pret) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->pret = 15;
		this->cantitate = 250;
		this->dePost = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "piscoturi";
		this->ingrediente[1] = "vanilie";
		this->ingrediente[2] = "cafea";

	}
	void afisare()
	{
		cout << "Denumire: " << this->denumire << endl;
		cout << "Pret: " << this->pret << endl;
		cout << "Cantitate: " << this->cantitate << endl;
		cout << "De post:" << (this->dePost ? "DA": "NU") << endl;
		cout << "Nr ingrediente: " << this->nrIngrediente << endl;
		cout << "Ingredientele sunt: ";
		for (int i = 0;i < nrIngrediente;i++)
		{
			cout << this->ingrediente[i] << "; ";

		}
		cout << endl;

	}
	float costMediuGram()
	{
		if (pret / cantitate == 0)
		{
			return 0;
		}
		else {
			return this->pret / this->cantitate;
		}

	}
	void modificaDenumire(const char* denumire)
	{
		delete this->denumire;
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);

	}

	
};
float CalculeazaCantitateTotala(Prajitura* prajituri, int nr_prajituri)
{
	float greutate = 0;
	for (int p = 0;p < nr_prajituri;p++)
	{
		greutate += prajituri[p].cantitate;

	}
	return greutate;
}

void main()
{
	Prajitura p;
	p.afisare();
	Prajitura p2("Amandina",40);
	p2.afisare();
	cout << p.costMediuGram();
	Prajitura* prajituri;
	prajituri = new Prajitura[3];
	prajituri[2].afisare();
	prajituri[1].pret = 50;
	prajituri[2].cantitate = 70;
	for (int i= 0;i < 3;i++)
	{
		cout << prajituri[i].denumire << ' ' << prajituri[i].costMediuGram() << endl;
		

	}
	float greutate_totala = CalculeazaCantitateTotala(prajituri, 3);
	cout << "Total: " << greutate_totala << endl;


}