#include "pch.h"
#include "../Testy jednostkowe - zarowka/Zarowka.cpp"
#include "../Testy jednostkowe - zarowka/Dane.cpp"
#include "../Testy jednostkowe - zarowka/Wyjatki.h"


namespace Testy_Jednostkowe
{
    class Test_Zarowka : public ::testing::Test {
    protected:
        void SetUp() override {}
        void TearDown() override {}
    };

	TEST_F(Test_Zarowka, Zapalona)
	{
		Zarowka zarowka;
		bool Status = zarowka.czy_zapalona();
		ASSERT_TRUE(Status);
		EXPECT_TRUE(true);
	}
	TEST_F(Test_Zarowka, Czas_Zapalenia)
	{
		Zarowka zarowka;
		Dane dane;
		int h_zar = zarowka.get_godzina_zapalenia();
		int min_zar = zarowka.get_minuta_zapalenia();
		int h_dane = dane.get_godzina_zapalenia();
		int min_dane = dane.get_minuta_zapalenia();

		ASSERT_EQ(h_dane, h_zar);
		ASSERT_EQ(min_dane, min_zar);
	}
	TEST_F(Test_Zarowka, Czas_Zgaszenia)
	{
		Zarowka zarowka;
		Dane dane;
		int h_zar = zarowka.get_godzina_zgaszenia();
		int min_zar = zarowka.get_minuta_zgaszenia();
		int h_dane = dane.get_godzina_zgaszenia();
		int min_dane = dane.get_minuta_zgaszenia();

		ASSERT_EQ(h_dane, h_zar);
		ASSERT_EQ(min_dane, min_zar);
	}
	TEST_F(Test_Zarowka, Parametry)
	{
		Zarowka zarowka;
		Dane dane;
		int natezenie_zar = zarowka.get_natezenie();
		int temperatura_barwy_zar = zarowka.get_temperatura_barwy();
		int natezenie_dane = dane.get_natezenie();
		int temperatura_barwy_dane = dane.get_temperatura_barwy();

		ASSERT_EQ(natezenie_dane, natezenie_zar);
		ASSERT_EQ(temperatura_barwy_dane, temperatura_barwy_zar);
	}
    TEST_F(Test_Zarowka, Komunikacja)
    {
        std::string filePath = "C:\\Users\\wikto\\Desktop\\IO\\Testy jednostkowe - zarowka\\Testy jednostkowe - zarowka\\dane.txt";

        bool fileExists = std::ifstream(filePath).good();

        ASSERT_TRUE(fileExists);
        EXPECT_TRUE(true);
    }
}