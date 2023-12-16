#include "pch.h"
#include "CppUnitTest.h"
#include "../Testy jednostkowe - zarowka/Zarowka.cpp"
#include "../Testy jednostkowe - zarowka/Dane.cpp"
#include "../Testy jednostkowe - zarowka/Wyjatki.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Unit_Test
{
	TEST_CLASS(Unit_Test)
	{
	public:

		Zarowka zarowka;

		TEST_METHOD(Zapalona)
		{
			bool Status = zarowka.czy_zapalona();
			const wchar_t* napis = L"Zly stan logiczny";
			Assert::IsTrue(Status, napis);
		}
		TEST_METHOD(Zgaszona)
		{
			bool Status = zarowka.czy_zapalona();
			const wchar_t* napis = L"Zly stan logiczny";
			Assert::IsFalse(!Status, napis);
		}
		TEST_METHOD(Czas_Zapalenia)
		{
			const wchar_t* BlednaGodzinaZapalenia = L"Bledna godzina zapalenia";
			const wchar_t* BlednaMinutaZapalenia = L"Bledna minuta zapalenia";

			int h_zap = zarowka.get_godzina_zapalenia();
			int min_zap = zarowka.get_minuta_zapalenia();

			Assert::AreEqual(10, h_zap, BlednaGodzinaZapalenia);
			Assert::AreEqual(20, min_zap, BlednaMinutaZapalenia);
		}
		TEST_METHOD(Czas_Zgaszenia)
		{
			const wchar_t* BlednaGodzinaZgaszenia = L"Bledna godzina zgaszenia";
			const wchar_t* BlednaMinutaZgaszenia = L"Bledna minuta zgaszenia";

			int h_zgasz = zarowka.get_godzina_zgaszenia();
			int min_zgasz = zarowka.get_minuta_zgaszenia();

			Assert::AreEqual(22, h_zgasz, BlednaGodzinaZgaszenia);
			Assert::AreEqual(25, min_zgasz, BlednaMinutaZgaszenia);
		}
		TEST_METHOD(Parametry)
		{
			const wchar_t* BledneNatezenie = L"Bledna intensywnosc";
			const wchar_t* BlednaTemperaturaBarwowa = L"Bledna temperatura barwowa";

			int natezenie = zarowka.get_natezenie();
			int temperatura_barwy = zarowka.get_temperatura_barwy();

			Assert::AreEqual(65, natezenie, BledneNatezenie);
			Assert::AreEqual(3300, temperatura_barwy, BlednaTemperaturaBarwowa);
		}
	};
}