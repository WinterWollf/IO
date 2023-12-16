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
	}
	/*TEST_F(Test_Zarowka, Zgaszona)
	{
		bool Status = zarowka.czy_zapalona();
		const wchar_t* napis = L"Zly stan logiczny";
		Assert::IsFalse(!Status, napis);
	}
	TEST_F(Test_Zarowka, Czas_Zapalenia)
	{
		const wchar_t* BlednaGodzinaZapalenia = L"Bledna godzina zapalenia";
		const wchar_t* BlednaMinutaZapalenia = L"Bledna minuta zapalenia";

		int h_zap = zarowka.get_godzina_zapalenia();
		int min_zap = zarowka.get_minuta_zapalenia();

		Assert::AreEqual(10, h_zap, BlednaGodzinaZapalenia);
		Assert::AreEqual(20, min_zap, BlednaMinutaZapalenia);
	}
	TEST_F(Test_Zarowka, Czas_Zgaszenia)
	{
		const wchar_t* BlednaGodzinaZgaszenia = L"Bledna godzina zgaszenia";
		const wchar_t* BlednaMinutaZgaszenia = L"Bledna minuta zgaszenia";

		int h_zgasz = zarowka.get_godzina_zgaszenia();
		int min_zgasz = zarowka.get_minuta_zgaszenia();

		Assert::AreEqual(22, h_zgasz, BlednaGodzinaZgaszenia);
		Assert::AreEqual(25, min_zgasz, BlednaMinutaZgaszenia);
	}
	TEST_F(Test_Zarowka, Parametry)
	{
		const wchar_t* BledneNatezenie = L"Bledna intensywnosc";
		const wchar_t* BlednaTemperaturaBarwowa = L"Bledna temperatura barwowa";

		int natezenie = zarowka.get_natezenie();
		int temperatura_barwy = zarowka.get_temperatura_barwy();

		Assert::AreEqual(65, natezenie, BledneNatezenie);
		Assert::AreEqual(3300, temperatura_barwy, BlednaTemperaturaBarwowa);
	}*/
    TEST_F(Test_Zarowka, Komunikacja)
    {
        std::string filePath = "C:\\Users\\wikto\\Desktop\\IO\\Testy jednostkowe - zarowka\\Testy jednostkowe - zarowka\\dane.txt";

        bool fileExists = std::ifstream(filePath).good();

        ASSERT_TRUE(fileExists);
        EXPECT_TRUE(true);
    }
}