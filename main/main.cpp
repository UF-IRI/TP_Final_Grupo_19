#include "iri.cpp"
#include "funciones.h"
#include <iostream>
#include <fstream>

int main()
{
    Patient* aux_lista = nullptr;
    int n;
    Patient* irrecuperables;
    int taman, tamanio;
    int* tamactual;
    int* taman_aumentar;
    string a_irre;
    Patient* recuperables;
    string a_recu;

    abrir_archivo();

    leer_archivos();// nuevas variables

    secretaria(aux_lista, n);

    creararchivo_irre(irrecuperables, taman, a_irre);

    creararchivo_re(recuperables, tamanio, a_recu);

    void resize_iree(Patient * &lista_irre, int* tamactual, int* tam_aumentar);




    return EXIT_SUCCESS;
}

void abrir_archivo()
{
    string dummy;
    char coma;
    fstream  archip, archic, archia;
    archip.open("pacientes.csv", ios::out);
    archic.open("contactos.csv", ios::out);
    archia.open("consultas.csv", ios::out);
    if (!(archip.is_open()))
    {
        return;//preguntar
    }
    if (!(archic.is_open()))
    {
        return;
    }
    if (!(archia.is_open()))
    {
        return;
    }

    archip >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
    archic >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
    archia >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;

    archip.close();
    archic.close();
    archia.close();

}