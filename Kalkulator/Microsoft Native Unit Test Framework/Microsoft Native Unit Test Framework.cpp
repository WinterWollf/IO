#include "pch.h"
#include "CppUnitTest.h"
#include "../Kalkulator/funkcje.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MicrosoftNativeUnitTestFramework
{
	TEST_CLASS(MicrosoftNativeUnitTestFramework)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double Wynik = ln(1);
			Assert::AreEqual(0.0, Wynik);
		}
		TEST_METHOD(TestMethod2)
		{
			std::vector<double> liczby{ 10, 18, 26, 64, 28, 8, 10, 7, 14 };
			double Wynik = standard_deviation(liczby);
			Assert::AreEqual(16.9516, Wynik);
		}
		TEST_METHOD(TestMethod3)
		{
			double Wynik = ln(1);
			Assert::AreEqual(0.0, Wynik);
		}
	};
}
