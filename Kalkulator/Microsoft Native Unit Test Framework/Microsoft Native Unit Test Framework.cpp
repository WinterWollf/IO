#include "pch.h"
#include "CppUnitTest.h"
#include "../Kalkulator/funkcje.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MicrosoftNativeUnitTestFramework
{
	TEST_CLASS(MicrosoftNativeUnitTestFramework)
	{
	public:
		
		TEST_METHOD(NaturalLogarithm)
		{
			double Wynik = ln(1);
			Assert::AreEqual(0.0, Wynik);
		}
		TEST_METHOD(StandardDeviationTest)
		{
			std::vector<double> liczby{ 10, 18, 26, 64, 28, 8, 10, 7, 14 };
			double Wynik = standard_deviation(liczby);
			Wynik = std::ceil(Wynik * 100.0) / 100.0;
			Assert::AreEqual(16.96, Wynik);
		}
		TEST_METHOD(ExponentTest)
		{
			double Wynik = exponent(5);
			Wynik = std::ceil(Wynik * 100.0) / 100.0;
			Assert::AreEqual(148.42, Wynik);
		}
	};
}
