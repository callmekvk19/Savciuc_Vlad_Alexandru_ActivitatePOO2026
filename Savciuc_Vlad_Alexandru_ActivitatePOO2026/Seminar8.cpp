#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Prajitura {
private:
	char* denumire;
	float pret;
	int cantitate;
	bool dePost;
	int nrIngrediente;
	string* ingrediente;
	const int id;
	static int contor;
public:
#pragma region Constructori
	friend class Student;
	Prajitura() :id(contor++) {
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
	Prajitura(const char* denumire, float pret) :id(contor++) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->pret = pret;
		this->cantitate = 250;
		this->dePost = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "piscoturi";
		this->ingrediente[1] = "vanilie";
		this->ingrediente[2] = "cafea";
	}

	Prajitura(const Prajitura& p) :id(contor++) {
		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy(this->denumire, p.denumire);

		this->pret = p.pret;
		this->cantitate = p.cantitate;
		this->dePost = p.dePost;
		this->nrIngrediente = p.nrIngrediente;

		this->ingrediente = new string[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->ingrediente[i] = p.ingrediente[i];
		}
	}
	Prajitura(const char* denumire, float pret, int cantitate, bool dePost, int nrIngrediente,const string* Ingrediente) :id(contor++) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->pret = pret;
		this->cantitate = 250;
		this->dePost = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[this->nrIngrediente];
		for (int i = 0;i < nrIngrediente;i++)
		{
			this->ingrediente[i] = ingrediente[i];
		}
	}
	~Prajitura();//declarare destructor
	Prajitura& operator=(const Prajitura& P1) {
		if (this != &P1) {

			this->cantitate = P1.cantitate;
			if (this->denumire != NULL)
				delete[] this->denumire;
			this->denumire = new char[strlen(P1.denumire) + 1];
			strcpy(this->denumire, P1.denumire);
			this->dePost = P1.dePost;
			this->pret = P1.pret;
			this->nrIngrediente = P1.nrIngrediente;
			if (this->ingrediente != NULL)
				delete[] this->ingrediente;
			this->ingrediente = new string[this->nrIngrediente];
			for (int i = 0;i < P1.nrIngrediente; i++)
				this->ingrediente[i] = P1.ingrediente[i];
		}
		return *this;
	}

#pragma endregion

#pragma region geteri si seteri
	int getCantitate() {
		return this->cantitate;
	}
	int getNrIngrediente() {
		return this->nrIngrediente;
	}
	float getPret() {
		return this->pret;
	}
	static int getContor() {
		return contor;
	}

#pragma endregion
#pragma region Operatori
	Prajitura operator+(const Prajitura& p) {
		Prajitura result = *this;
		result.pret = this->pret + p.pret;
		result.cantitate = this->cantitate + p.cantitate;
		return result;
	}
	string& operator[](int pozitie) //sa caut pt ca n am inteles de ce se pune &
	{
		if (pozitie >= 0 && pozitie < nrIngrediente)
		{
			return this->ingrediente[pozitie];
		}
		return ingrediente[0];
	}

	operator float()//e unar si returneaza deja this
	{
		return this->pret;

	}
	explicit operator int()
	{
		return this->cantitate;
	}
	float operator()()
	{
		return this->costMediuGram();
	}
	float operator()(float TVA)
	{
		return (this->pret + (TVA * pret)) / this->cantitate;
	}
	float operator()(int discount)
	{
		return (this->pret - (discount / 100.0) * this->pret) / this->cantitate;
	}
	bool operator==(Prajitura prajitura)
	{
		if (strcmp(this->denumire, prajitura.denumire) != 0)
		{
			return false;
		}
		if (this->cantitate != prajitura.cantitate)
		{
			return false;
		}
		if (this->dePost != prajitura.dePost)
		{
			return false;
		}
		if (this->nrIngrediente != prajitura.nrIngrediente)
		{
			return false;
		}
		return true;
	}
	Prajitura operator-=(Prajitura p)
	{
		if (this->pret > p.pret)
		{
			this->pret = this->pret - p.pret;

		}
		else this->pret = 0;
		return *this;
	}

	Prajitura operator+=(string ingredient)
	{
		string* aux = new string[this->nrIngrediente + 1];
		for (int i = 0;i < this->nrIngrediente;i++)
		{
			aux[i] = this->ingrediente[i];
		}
		aux[this->nrIngrediente] = ingredient;
		delete[] this->ingrediente;
		this->ingrediente = aux;
		this->nrIngrediente++;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Prajitura& p)
	{
		out << p.denumire << ' ' << p.pret << ' ' << p.cantitate << ' ' << "DE POST " << (p.dePost ? "DA" : "NU") << ' ' << p.nrIngrediente << endl;
		for (int i = 0;i < p.nrIngrediente;i++)
		{
			out << p.ingrediente[i] << ' ';
		}
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Prajitura& p)
	{
		cout << "Introdu denumirea: ";
		char ddenumire[256];
		in >> ddenumire;
		p.denumire = new char[strlen(ddenumire) + 1];
		strcpy_s(p.denumire, strlen(ddenumire) + 1, ddenumire);
		cout << "pret, cantitate, de post: ";
		in >> p.pret >> p.cantitate >> p.dePost;
		cout << "Nr ingrediente: ";
		in >> p.nrIngrediente;
		p.ingrediente = new string[p.nrIngrediente];
		cout << "Lista ingredientelor: ";
		for (int i = 0;i < p.nrIngrediente;i++)
		{
			in >> p.ingrediente[i];
			cout << ' ';
		}
		return in;
	}

#pragma endregion
	void afisare()
	{
		cout << "Denumire: " << this->denumire << endl;
		cout << "Pret: " << this->pret << endl;
		cout << "Cantitate: " << this->cantitate << endl;
		cout << "De Post: " << (this->dePost ? "DA" : "NU") << endl;
		cout << "Nr ingrediente: " << this->nrIngrediente << endl;
		cout << "Ingredientele sunt: ";
		for (int i = 0;i < this->nrIngrediente;i++)
		{
			cout << this->ingrediente[i] << "; ";
		}
		cout << endl;

	}
	float costMediuGram() {
		if (this->cantitate == 0) {
			return 0;
		}
		else {
			return this->pret / this->cantitate;
		}
	}

	void modificaDenumire(const char* denumire) {
		delete this->denumire;

		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
	}


};

int Prajitura::contor = 100;

Prajitura::~Prajitura() {//implementare destructor (pt string si char)
	delete[] this->denumire;
	delete[] this->ingrediente;
}
float calculeazaCantitateTotala(Prajitura* prajituri, int nr_prajituri) {
	float greutate = 0;

	for (int p = 0; p < nr_prajituri; p++)
		greutate += prajituri[p].getCantitate();

	return greutate;
}

float calculeazaPretPerIngredient(Prajitura p) {
	if (p.getNrIngrediente() != 0)
		return p.getPret() / p.getNrIngrediente();

	return 0;
}


class Student {
private:
	string nume;
	Prajitura prajitura;

public:
	Student() {
		this->nume = "Andrei";
	}
	Student(string nume, Prajitura p) {
		this->nume = nume;
		this->prajitura = p;
	}
	string getNume() {
		return this->nume;
	}
	Prajitura getPrajitura() {
		return this->prajitura;
	}
	void setNume(string nume) {
		this->nume = nume;
	}
	void setPrajitura(Prajitura p) {
		this->prajitura = p;
	}
	float calculeazaNrTotalCalorii(float caloriiPerGram) {
		float nrTotal = caloriiPerGram * this->prajitura.getCantitate();
		return nrTotal;
	}
	void afiseazaMasa() {
		cout << this->nume << " mananca prajitura " << this->prajitura.denumire << endl;
	}
	friend ostream& operator<<(ostream& out, const Student& stud)
	{
		out << stud.nume << endl << stud.prajitura << endl;
		return out;
	}
};

class PrajituraFaraZahar : public Prajitura
{
private:
	bool rawVegan;
	float kcal;
public:
	PrajituraFaraZahar(): Prajitura("Prajitura fara zahar", 10)
	{
		this->rawVegan = true;
		this->kcal = 150;
	}
	PrajituraFaraZahar(bool rawVegan, float kiloCalorii) : Prajitura()
	{
		this->rawVegan = rawVegan;
		this->kcal = kiloCalorii;
	}
	PrajituraFaraZahar(bool rawVegan, float kiloCalorii, const char* denumire, float pret, int cantitate, bool dePost, int nrIngrediente, const string* ingrediente) : Prajitura(denumire, pret, cantitate, dePost,nrIngrediente,ingrediente)
	{
		this->rawVegan = rawVegan;
		this->kcal = kiloCalorii;
	}
	PrajituraFaraZahar(const PrajituraFaraZahar& pfz): Prajitura(pfz)
	{
		this->rawVegan = pfz.rawVegan;
		this->kcal = pfz.kcal;
	}
	PrajituraFaraZahar operator=(const PrajituraFaraZahar& pfz)
	{
		if (this != &pfz)
		{
			(Prajitura)*this = (Prajitura)pfz;
			this->rawVegan = pfz.rawVegan;
			this->kcal = pfz.kcal;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const PrajituraFaraZahar& pfz)
	{
		out << (Prajitura)pfz;
		out << "Raw Vegan: " << (pfz.rawVegan ? "DA " : "NU ") << pfz.kcal;
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, PrajituraFaraZahar& pfz)
	{
		//operator>>(in, (Prajitura)pfz);
		//in  (Prajitura)pfz;
		in >> pfz.rawVegan >> pfz.kcal;
	}

	

	~PrajituraFaraZahar()
	{

	}

};


void main() {
	Prajitura p;
	//p.afisare();
	Prajitura::getContor();
	Prajitura P1("amandina", 20.6);
	/*Student s1("Cristian", P1);
	//s1.afiseazaMasa();
	//cout << s1.calculeazaNrTotalCalorii(0.5);
	//
	//cout << endl;
	//cout << calculeazaPretPerIngredient(p);
	cout << p[1] << endl;
	p[1] = "Frisca";
	cout << p[1] << endl;
	float pret;
	pret = (float)P1;
	cout << "Pret: " << pret << endl;
	int cantitate;
	cantitate = (int)P1;
	cout << "Cantitate: " << cantitate << endl;
	cout << "Pret per gram: " << P1() << endl;
	cout << "Pret cu TVA per gram: " << P1(0.21f) << endl;
	cout << "Pret cu discount per gram: " << P1(10) << endl;
	if (p == P1)
	{
		cout << "Prajitura egale" << endl;
	}
	else cout << "Prajiturile sunt diferite" << endl;
	p -= P1;
	cout << p.getPret();
	PrajituraFaraZahar pfz1;
	PrajituraFaraZahar pfz2(200, true);
	PrajituraFaraZahar pfz3(pfz2);
	pfz1 = pfz3;
	cout << pfz1;

	Student s("Pop", pfz1);
	cout << s;

	Prajitura praj;
	cin >> praj;
	cout << praj;

}