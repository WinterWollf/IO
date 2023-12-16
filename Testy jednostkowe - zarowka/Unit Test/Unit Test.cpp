#include "pch.h"
#include "CppUnitTest.h"
#include "../Testy jednostkowe - zarowka/Zarowka.cpp"
#include "../Testy jednostkowe - zarowka/Dane.cpp"
#include "../Testy jednostkowe - zarowka/Wyjatki.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testy_Jednostkowe
{
	TEST_CLASS(Test_Zarowka)
	{
	public:

		Zarowka zarowka;
		Dane dane;

		TEST_METHOD(Zapalona)
		{
			bool Status = zarowka.czy_zapalona();
			const wchar_t* napis = L"Zly stan logiczny";
			Assert::IsTrue(Status, napis);
		}
		TEST_METHOD(Czas_Zapalenia)
		{
			const wchar_t* BlednaGodzinaZapalenia = L"Bledna godzina zapalenia";
			const wchar_t* BlednaMinutaZapalenia = L"Bledna minuta zapalenia";

			int h_zar = zarowka.get_godzina_zapalenia();
			int min_zar = zarowka.get_minuta_zapalenia();
			int h_dane = dane.get_godzina_zapalenia();
			int min_dane = dane.get_minuta_zapalenia();

			Assert::AreEqual(h_dane, h_zar, BlednaGodzinaZapalenia);
			Assert::AreEqual(min_dane, min_zar, BlednaMinutaZapalenia);
		}
		TEST_METHOD(Czas_Zgaszenia)
		{
			const wchar_t* BlednaGodzinaZgaszenia = L"Bledna godzina zgaszenia";
			const wchar_t* BlednaMinutaZgaszenia = L"Bledna minuta zgaszenia";

			int h_zar = zarowka.get_godzina_zgaszenia();
			int min_zar = zarowka.get_minuta_zgaszenia();
			int h_dane = dane.get_godzina_zgaszenia();
			int min_dane = dane.get_minuta_zgaszenia();

			Assert::AreEqual(h_dane, h_zar, BlednaGodzinaZgaszenia);
			Assert::AreEqual(min_dane, min_zar, BlednaMinutaZgaszenia);
		}
		TEST_METHOD(Parametry)
		{
			const wchar_t* BledneNatezenie = L"Bledna intensywnosc";
			const wchar_t* BlednaTemperaturaBarwowa = L"Bledna temperatura barwowa";

			int natezenie_zar = zarowka.get_natezenie();
			int temperatura_barwy_zar = zarowka.get_temperatura_barwy();
			int natezenie_dane = dane.get_natezenie();
			int temperatura_barwy_dane = dane.get_temperatura_barwy();

			Assert::AreEqual(natezenie_dane, natezenie_zar, BledneNatezenie);
			Assert::AreEqual(temperatura_barwy_dane, temperatura_barwy_zar, BlednaTemperaturaBarwowa);
		}
		TEST_METHOD(Komunikacja) {
			Zarowka zarowka;
			//std::string filePath = "C:\\Users\\wikto\\Desktop\\IO\\Testy jednostkowe - zarowka\\Testy jednostkowe - zarowka\\dane.txt";
			std::string filePath = "C:\\Users\\wikto\\OneDrive\\Pulpit\\IO\\Testy jednostkowe - zarowka\\Testy jednostkowe - zarowka\\dane.txt";

			bool fileExists = std::ifstream(filePath).good();

			Assert::IsTrue(fileExists);
		}
	};
}