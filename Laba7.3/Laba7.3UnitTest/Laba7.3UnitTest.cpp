#include "pch.h"
#include "CppUnitTest.h"
#include "../Laba7.3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Laba73UnitTest
{
	TEST_CLASS(Laba73UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int i = 5;
			int B[i] = { 5, 5, 2, 6, 0 };
			double actual;
			double exp = 2;
			actual = MaxSeria(B, i);
			Assert::AreEqual(actual, exp);
		}
	};
}
