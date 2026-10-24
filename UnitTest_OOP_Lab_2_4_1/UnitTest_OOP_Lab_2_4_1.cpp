#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_2_4_1/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestOOPLab241
{
	TEST_CLASS(UnitTestOOPLab241)
	{
    public:
        TEST_METHOD(TestMatrixNorm)
        {
            Matrix R(2);
            R.setElement(0, 0, 3);
            R.setElement(0, 1, 4);
            R.setElement(1, 0, 0);
            R.setElement(1, 1, 0);

            // Норма = sqrt(3^2 + 4^2 + 0 + 0) = sqrt(25) = 5
            Assert::AreEqual(5.0, R.norm(), 0.0001);
        }

        TEST_METHOD(TestMatrixMultiplication)
        {
            Matrix R1(2);
            R1.setElement(0, 0, 1);
            R1.setElement(0, 1, 2);
            R1.setElement(1, 0, 3);
            R1.setElement(1, 1, 4);

            Matrix R2(2);
            R2.setElement(0, 0, 2);
            R2.setElement(0, 1, 0);
            R2.setElement(1, 0, 1);
            R2.setElement(1, 1, 2);

            Matrix R3 = R1 * R2;

            // Перевірка результату множення
            Assert::AreEqual(4, R3.getElement(0, 0));
            Assert::AreEqual(4, R3.getElement(0, 1));
            Assert::AreEqual(10, R3.getElement(1, 0));
            Assert::AreEqual(8, R3.getElement(1, 1));
        }
    };
}