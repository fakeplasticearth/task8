#include "pch.h"
#include "CppUnitTest.h"
#include "../task8/task8.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		//умножение числа на одночлен
		TEST_METHOD(TestMethod1)
		{
			monomial test_input_m(2, 3);
			float test_input_num = 3.5;
			monomial true_output(7, 3);
			Assert::IsTrue(true_output.coef == (test_input_num * test_input_m).coef &&
			true_output.degree == (test_input_num * test_input_m).degree);
		}
		//умножение одночлена на одночлен
		TEST_METHOD(TestMethod2)
		{
			monomial test_input_m1(2, 3);
			monomial test_input_m2(3.5, 6);
			monomial true_output(7, 9);
			Assert::IsTrue(true_output.coef == (test_input_m1 * test_input_m2).coef &&
				true_output.degree == (test_input_m1 * test_input_m2).degree);
		}
		//умножение многочлена на число
		TEST_METHOD(TestMethod3)
		{
			float input_num = 8;

			polynomial input_p1, input_p2, input_p3;
			input_p1.curr = monomial(2, 5);
			input_p2.curr = monomial(4, 3);
			input_p3.curr = monomial(5, 0);
			input_p1.next = &input_p2;
			input_p2.next = &input_p3;
			input_p3.next = NULL;

			polynomial true_p1, true_p2, true_p3;
			true_p1.curr = monomial(16, 5);
			true_p2.curr = monomial(32, 3);
			true_p3.curr = monomial(40, 0);
			true_p1.next = &true_p2;
			true_p2.next = &true_p3;
			true_p3.next = NULL;

			Assert::IsTrue(input_num * input_p1 == true_p1);
		}
		//умножение одночлена на многочлен
		TEST_METHOD(TestMethod4)
		{
			monomial test_input_m(3, 4);

			polynomial p1, p2, p3;
			p1.curr = monomial(5, 10);
			p1.next = &p2;
			p2.curr = monomial(7, 7);
			p2.next = &p3;
			p3.curr = monomial(2, 4);
			p3.next = NULL;

			polynomial true_p1, true_p2, true_p3;
			true_p1.curr = monomial(15, 14);
			true_p1.next = &true_p2;
			true_p2.curr = monomial(21, 11);
			true_p2.next = &true_p3;
			true_p3.curr = monomial(6, 8);
			true_p3.next = NULL;

			Assert::IsTrue(test_input_m * p1 == true_p1);
		}
		//сложение одночлена и многочлена
		TEST_METHOD(TestMethod5)
		{
			monomial test_input_m(3, 4);

			polynomial p1, p2, p3;
			p1.curr = monomial(5, 10);
			p1.next = &p2;
			p2.curr = monomial(7, 7);
			p2.next = &p3;
			p3.curr = monomial(2, 4);
			p3.next = NULL;

			polynomial true_p1, true_p2, true_p3;
			true_p1.curr = monomial(5, 10);
			true_p1.next = &true_p2;
			true_p2.curr = monomial(7, 7);
			true_p2.next = &true_p3;
			true_p3.curr = monomial(5, 4);
			true_p3.next = NULL;

			Assert::IsTrue(test_input_m + p1 == true_p1);
		}
		//еще сложение одночлена и многочлена
		TEST_METHOD(TestMethod6)
		{
			monomial test_input_m(3, 4);

			polynomial p1, p2, p3;
			p1.curr = monomial(5, 10);
			p1.next = &p2;
			p2.curr = monomial(7, 7);
			p2.next = &p3;
			p3.curr = monomial(2, 3);
			p3.next = NULL;

			polynomial true_p1, true_p2, true_p3, true_p4;
			true_p1.curr = monomial(5, 10);
			true_p1.next = &true_p2;
			true_p2.curr = monomial(7, 7);
			true_p2.next = &true_p3;
			true_p3.curr = monomial(3, 4);
			true_p3.next = &true_p4;
			true_p4.curr = monomial(2, 3);
			true_p4.next = NULL;

			Assert::IsTrue(test_input_m + p1 == true_p1);
		}
		//и еще раз сложение одночлена и многочлена
		TEST_METHOD(TestMethod7)
		{
			monomial test_input_m(3, 4);

			polynomial p1, p2, p3;
			p1.curr = monomial(5, 10);
			p1.next = &p2;
			p2.curr = monomial(7, 7);
			p2.next = &p3;
			p3.curr = monomial(2, 5);
			p3.next = NULL;

			polynomial true_p1, true_p2, true_p3, true_p4;
			true_p1.curr = monomial(5, 10);
			true_p1.next = &true_p2;
			true_p2.curr = monomial(7, 7);
			true_p2.next = &true_p3;
			true_p3.curr = monomial(2, 5);
			true_p3.next = &true_p4;
			true_p4.curr = monomial(3, 4);
			true_p4.next = NULL;

			Assert::IsTrue(test_input_m + p1 == true_p1);
		}
		//сложение двух многочленов
		TEST_METHOD(TestMethod8)
		{
			polynomial p1_1, p1_2, p1_3;
			p1_1.curr = monomial(5, 10);
			p1_1.next = &p1_2;
			p1_2.curr = monomial(7, 7);
			p1_2.next = &p1_3;
			p1_3.curr = monomial(2, 5);
			p1_3.next = NULL;

			polynomial p2_1, p2_2;
			p2_1.curr = monomial(1, 7);
			p2_1.next = &p2_2;
			p2_2.curr = monomial(3, 4);
			p2_2.next = NULL;

			polynomial true_p1, true_p2, true_p3, true_p4;
			true_p1.curr = monomial(5, 10);
			true_p1.next = &true_p2;
			true_p2.curr = monomial(8, 7);
			true_p2.next = &true_p3;
			true_p3.curr = monomial(2, 5);
			true_p3.next = &true_p4;
			true_p4.curr = monomial(3, 4);
			true_p4.next = NULL;

			Assert::IsTrue(p1_1 + p2_1 == true_p1);
		}
		//еще сложение двух многочленов
		TEST_METHOD(TestMethod9)
		{
			polynomial p1_1, p1_2, p1_3;
			p1_1.curr = monomial(5, 12);
			p1_1.next = &p1_2;
			p1_2.curr = monomial(7, 10);
			p1_2.next = &p1_3;
			p1_3.curr = monomial(2, 8);
			p1_3.next = NULL;

			polynomial p2_1, p2_2;
			p2_1.curr = monomial(1, 6);
			p2_1.next = &p2_2;
			p2_2.curr = monomial(3, 4);
			p2_2.next = NULL;

			polynomial true_p1, true_p2, true_p3, true_p4, true_p5;
			true_p1.curr = monomial(5, 12);
			true_p1.next = &true_p2;
			true_p2.curr = monomial(7, 10);
			true_p2.next = &true_p3;
			true_p3.curr = monomial(2, 8);
			true_p3.next = &true_p4;
			true_p4.curr = monomial(1, 6);
			true_p4.next = &true_p5;
			true_p5.curr = monomial(3, 4);
			true_p5.next = NULL;

			Assert::IsTrue(p1_1 + p2_1 == true_p1);
		}
		//i-й многочлен Лукаса
		TEST_METHOD(TestMethod10)
		{
			polynomial true_p1, true_p2, true_p3, true_p4;
			true_p1.curr = monomial(1, 6);
			true_p1.next = &true_p2;
			true_p2.curr = monomial(6, 4);
			true_p2.next = &true_p3;
			true_p3.curr = monomial(9, 2);
			true_p3.next = &true_p4;
			true_p4.curr = monomial(2, 0);
			true_p4.next = NULL;
			
			polynomial ans = lukas_p(6);

			Assert::IsTrue(true_p1 == ans);
		}
	};
}
