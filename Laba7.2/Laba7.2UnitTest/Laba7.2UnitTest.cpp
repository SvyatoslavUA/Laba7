#include "pch.h"
#include "CppUnitTest.h"
#include "../Laba7.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Laba72UnitTest
{
	TEST_CLASS(Laba72UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int i = 5;
			int B[i] = { 5, 4, 2, 6, 1 };

			double actual;
			double exp = 1;

			actual = FindMinElement(B, i);
			Assert::AreEqual(actual, exp);
		}
	};
}
