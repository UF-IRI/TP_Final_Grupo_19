#include <iostream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "iri.cpp"

using namespace std;

#define anios 31557600 // 10 anios en segundos

typedef enum Presente { presento = 0, ausente };

typedef struct date {
    int Day, Month, Year;
}Date;

typedef struct insurance {               //estructura de la obra social.
    string Name;
    string Code;                        //número de afiliado.
}Insurance;

typedef struct doctor {
    int IDDoctor;
    string DoctorName;
    string DoctorSurname;
    string Department;
    string Plate; //matritucula
}Doctor;

typedef struct appointment {            //estructura de la última consulta.
    int ID;
    Date CheckIn; // fecha de solicitado
    Date CheckOut; // fecha de turno
    string Motive;
    int Present;
    Doctor InfoDoctor;
}Appointment;

typedef struct contact {                //estructura de contacto
    string  PhoneNumber;
    string Email;
    int ID;
    string EmergencyName;
    string EmergencySurname;
    string EmergencyPhoneNumber;
    string EmergencyEmail;
    string Relationship;
    string Residency;
}Contact;

typedef struct patient {                 //estructura pacient
    int ID;
    string  PatientName;
    string PatientSurname;
    Date DateOfBirth;
    Insurance Data;
    int Hs; 
    char Sex;
    Contact PatientContact;
    Appointment LastVisit;
}Patient;

typedef struct newappointment {
    Date NewDate;
    string NewMotive;
    Doctor NewDoctor;
}NewAppointment;

void  leer_archivos();

void secretaria(Patient*& lista, int N);

void creararchivo_irre(Patient*& p_irrecuperables, int tam, string a_irrecuperables);

void creararchivo_re(Patient*& p_recuperables, int tam, string a_recuperables);

void resize_iree(Patient*& lista_irre, int* tamactual, int* tam_aumentar);
