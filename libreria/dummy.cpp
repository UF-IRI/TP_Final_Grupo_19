#include "funciones.h"

void creararchivo_irre(Patient*& p_irrecuperables, int tam, string a_irrecuperables)
{
    fstream archi_irrecuperables;               // archip= archivo de pacientes; archic= archivo de contacto; archia= archivo de ultima consulta.
    int i;
    archi_irrecuperables.open(a_irrecuperables, ios::app);


    if (archi_irrecuperables.is_open()) {
        {
            archi_irrecuperables << "ID, PatientName,Patientsurname,sex,DateOfBirth,Hs,Data" << endl;
            for (i = 0; i < tam; i++)
                archi_irrecuperables << p_irrecuperables->ID << "," << p_irrecuperables->PatientName << "," << p_irrecuperables->PatientSurname << "," <<
                p_irrecuperables->Sex << "," << p_irrecuperables->DateOfBirth.Month << "/" << p_irrecuperables->DateOfBirth.Day << "/" <<
                p_irrecuperables->DateOfBirth.Year << "," << p_irrecuperables->Hs << "," << p_irrecuperables->Data.Name << endl;
        }

    }

    archi_irrecuperables.close();


    return;
}

void creararchivo_re(Patient*& p_recuperables, int tam, string a_recuperables)
{
    fstream archi_recuperables;
    int i;
    archi_recuperables.open(a_recuperables, ios::app);


    if (archi_recuperables.is_open()) {
        {
            archi_recuperables << "ID, PatientName,Patientsurname,sex,DateOfBirth,Hs,Data" << endl;
            for (i = 0; i < tam; i++)
                archi_recuperables << p_recuperables->ID << "," << p_recuperables->PatientName << "," << p_recuperables->PatientSurname << "," <<
                p_recuperables->Sex << "," << p_recuperables->DateOfBirth.Month << "/" << p_recuperables->DateOfBirth.Day << "/" <<
                p_recuperables->DateOfBirth.Year << "," << p_recuperables->Hs << "," << p_recuperables->Data.Name << endl;
        }

    }

    archi_recuperables.close();


    return;
}

void leer_archivos()
{
    Patient* patients_irre = new Patient[0]; // lista para guardar los pacientes irrecuperables
    int conti = 0; // contador para saber la cantidad de pacientes irrecuperables
    Patient* patients_re = new Patient[0]; // lista para guardar los pacientes recuperables
    int contr = 0; // contador para saber la cantidad de pacientes recuperables
    Patient aux; // auxiliar para guardar los datos del archivos
    Contact caux;// auxiliar de contacto
    Appointment aaux;   // auxiliar de visita
    string dummy; //string para leer el header
    char coma; // char para leer el header
    int IDaux, IDaux; // para q esto
    time_t timer; // fecha de presente
    struct tm y2k = { 0 };
    double seconds; // variabke oara guardar la diferencia
    time(&timer); //completar renata

    //abrimos los archivos
    fstream  archip, archic, archia;
    archip.open((BASE_PATH + "../data_files/input/Pacientes.csv"), ios::in);
    archic.open((BASE_PATH + "../data_files/input/Contacto.csv"), ios::in);
    archia.open((BASE_PATH + "../data_files/input/Consultas.csv"), ios::in);

    //preguntamos si estan abiertos
    if (!(archip.is_open() && archic.is_open() && archia.is_open()))//
        return;

    //salteamos los headers
    archip >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
    archic >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
    archia >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;

    do
    {
        while (archip)
        {
            archip >> aux.ID >> coma >> aux.PatientName >> coma >> aux.PatientSurname >> coma >> aux.Sex >> coma >> aux.DateOfBirth.Month >> coma >>
                aux.DateOfBirth.Day >> coma >> aux.DateOfBirth.Year >> coma >> aux.Hs >> coma >> aux.Data.Name >> coma >> aux.LastVisit.CheckOut.Day >> coma >> aux.LastVisit.CheckOut.Month >> coma >> aux.LastVisit.CheckOut.Year >> coma >> aux.PatientContact.EmergencyName;
            while (archia)
            {
                archia >> aaux.CheckIn.Day >> coma >> aaux.CheckIn.Month >> coma >> aaux.CheckIn.Year >> coma >> aaux.CheckOut.Day >> coma >>
                    aaux.CheckOut.Month >> coma >> aaux.CheckOut.Year >> coma >> aaux.Present >> coma >> aaux.InfoDoctor.Plate;
                while (archic)
                {
                    archic >> caux.EmergencyName >> coma >> caux.Email >> coma >> caux.EmergencyEmail >> coma >> caux.EmergencyPhoneNumber >> coma >> caux.EmergencySurname >> coma >> caux.PhoneNumber >> coma >> caux.Relationship >> coma >> caux.Residency;

                    if (aux.PatientContact.EmergencyName == caux.EmergencyName && aux.LastVisit.CheckOut.Day == aaux.CheckOut.Day && aux.LastVisit.CheckOut.Month == aaux.CheckOut.Month && aux.LastVisit.CheckOut.Year == aaux.CheckOut.Year)
                    {
                        y2k.tm_hour = 0; // dejamos las horas en 0
                        y2k.tm_min = 0; // dejamos los minutos en 0
                        y2k.tm_sec = 0; // dejamos los segundos en 0
                        y2k.tm_year = aaux.CheckOut.Year; //igualamos el anio al de la fecha de la consulta
                        y2k.tm_mon = aaux.CheckOut.Month; //igualamos el mes al de la fecha de la consulta
                        y2k.tm_mday = aaux.CheckOut.Day; //igualamos el dia al de la fecha de la consulta
                        double seconds = difftime(timer, mktime(&y2k)); // hacemos la diferencia en segundos entre el dia de hoy y la consulta
                        if (seconds >= anios || aux.Hs == 4) // si la diferencia en segundos es mayor a que 10 anios en segundo o esta nuerto
                        {
                            std::cout << "El paciente es IRRECUPERABLE, y su ficha está ARCHIVADA";

                            patients_irre[conti] = aux; //guardamos los paciente irrecuperables en una lista
                            conti++; //aumentamos el contador para guardar el proximo paciente irrecuperable
                        }
                        else
                        {
                            std::cout << "El paciente puede llegar a regresar";

                            patients_re[contr] = aux; //guardamos los paciente recuperables en una lista
                            contr++; //aumentamos el contador para guardar el proximo paciente recuperable
                            //random
                            // archivos
                        }

                    }
                }

            }

            archip.close();
            archic.close();
            archia.close();


        }
        creararchivo_irre(patients_irre, conti, "pacientesirrecuoerables.csv");
        secretaria(patients_re, contr);

    } while (archia.is_open(), archic.is_open(), archip.is_open());

}

void secretaria(Patient*& lista, int N)
{
    int i = 0;
    NewAppointment nuevacon; // nueva consulta
    Patient* vuelven = new Patient[0];
    int contv = 0;
    Patient* novuelven = new Patient[0];
    int contn = 0;

    for (i = 0; i < N; i++)
    {

        int respuesta = rand() % N;

        if (respuesta % 2 == 0) // si es par el valor va a ser verdadero
        {
            std::cout << "Programe una consulta, (ingresar fecha(dia, mes, año), doctor, motivo, departamento" << endl;
            cin >> nuevacon.NewDate.Day >> nuevacon.NewDate.Month >> nuevacon.NewDate.Year >> nuevacon.NewDoctor.Plate;
            lista[i].LastVisit.CheckOut.Day = nuevacon.NewDate.Day;
            lista[i].LastVisit.CheckOut.Month = nuevacon.NewDate.Month;
            lista[i].LastVisit.CheckOut.Year = nuevacon.NewDate.Year;
            lista[i].LastVisit.InfoDoctor.Plate = nuevacon.NewDate.Day;
            vuelven[contv] = lista[i];
            contv++;
        }
        else
        {
            std::cout << "El paciente no retorna entonces se archiva" << endl;
            novuelven[contn] = lista[i];
            contn++;
        }
        creararchivo_re(vuelven, contv, "pacientesrecuoerables.csv");
    }
}

void resize_iree(Patient*& lista_irre, int* tamactual, int* tam_aumentar)
{

    *tamactual = *tamactual + *tam_aumentar;
    int i = 0;
    Patient* aux = new Patient[*tamactual];
    while (i < *tamactual - *tam_aumentar)
    {
        aux[i] = lista_irre[i];
        i++;
    }

    delete[] lista_irre;
    lista_irre = aux;

    return;
}