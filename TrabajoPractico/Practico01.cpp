#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Lugar {
private:
    string nombre;

public:
    Lugar(const string& n);
    virtual void mostrarInfo() const;
    virtual ~Lugar();
};

Lugar::Lugar(const string& n) : nombre(n) {}

void Lugar::mostrarInfo() const {
    cout << "Lugar: " << nombre << endl;
}

Lugar::~Lugar() {
}

class Ciudad : public Lugar {
private:
    int poblacion;

public:
    Ciudad(const string& n, int p);
    void mostrarInfo() const override;
    ~Ciudad();
};

Ciudad::Ciudad(const string& n, int p) : Lugar(n), poblacion(p) {}

void Ciudad::mostrarInfo() const {
    Lugar::mostrarInfo();
    cout << "Poblacion: " << poblacion << " habitantes" << endl;
}

Ciudad::~Ciudad() {
}

int main() {
    Lugar lugar1("Pueblo");
    lugar1.mostrarInfo();
    Ciudad ciudad1("Metropolis", 1000000);
    ciudad1.mostrarInfo();
    system("pause");
    return 0;
}