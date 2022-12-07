#include "gmock/gmock.h"
#include "funciones.h"
#include "iri.cpp"

namespace Casos_Base::tests {

	TEST(Casos_Base, Test_Caso1) {
		ASSERT_THAT(1, 1);
	}

	TEST(Casos_Base, Test_Caso2) {
		ASSERT_THAT(1, 1);
	}

	TEST(Casos_Base, Test_Caso3) {
		ASSERT_THAT(1, 1);
	}
}

    TEST(Patient, leer_archivo) {

        int n = 0;
        int* largo = &n;
        Patient* lista = new Patient[*largo];
        (BASE_PATH + "../data_files/input/Pacientes.csv");
        leer_archivos();
        EXPECT_EQ(lista[2].ID, 10242582);
        EXPECT_EQ(lista[2].PatientName, "Certy");
        EXPECT_EQ(lista[2].PatientSurname, "Thurston");
        EXPECT_EQ(lista[2].Sex, 'F');
        EXPECT_EQ(lista[2].DateOfBirth.Day, 9);
        EXPECT_EQ(lista[2].DateOfBirth.Month, 6);
        EXPECT_EQ(lista[2].DateOfBirth.Year, 1970);
        EXPECT_EQ(lista[2].Hs, "internado");
        EXPECT_EQ(lista[2].Data, "Medicus");

        EXPECT_EQ(lista[*largo - 1].ID, 48363884);
        EXPECT_EQ(lista[*largo - 1].PatientName, "Yelle");
        EXPECT_EQ(lista[*largo - 1].PatientSurname, "Mangum");
        EXPECT_EQ(lista[*largo - 1].Sex, 'F');
        EXPECT_EQ(lista[*largo - 1].DateOfBirth.Day, 29);
        EXPECT_EQ(lista[*largo - 1].DateOfBirth.Month, 1);
        EXPECT_EQ(lista[*largo - 1].DateOfBirth.Year, 2002);
        EXPECT_EQ(lista[*largo - 1].Hs, "n/c");
        EXPECT_EQ(lista[*largo - 1].Data, "Italiano");


        delete[] lista;
    }

    
    TEST(Patient * lista) {
            EXPECT_EQ(chequear.ID("45684810"), true);		
            EXPECT_EQ(chequear.ID("45684810"), true);		
            EXPECT_EQ(chequear.ID("456848+10"), false);		
            EXPECT_EQ(chequear.ID("456/4810"), false);		
            EXPECT_EQ(chequear.ID("45684"), false);		
            EXPECT_EQ(chequear.ID("456848105"), false);
      
    }

    TEST(Date * lista) {
        EXPECT_EQ(esBisiesto(2002), true);
        EXPECT_EQ(esBisiesto(2008), true);
        EXPECT_EQ(esBisiesto(1842), true);
        EXPECT_EQ(esBisiesto(2026), true);
        EXPECT_EQ(esBisiesto(1903), false);
        EXPECT_EQ(esBisiesto(2007), false);
        EXPECT_EQ(esBisiesto(180+), false);
        EXPECT_EQ(esBisiesto(a023), false);
    }
