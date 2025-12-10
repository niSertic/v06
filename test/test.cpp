
#include "CppUnitTest.h"
#include "../app/money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;
using namespace std::string_literals;

namespace test
{
	TEST_CLASS(test)
	{
	public:

		TEST_METHOD(Constructor_Zero)
		{
			money m(0);
			std::ostringstream os;
			os << m;
			Assert::AreEqual("0 eur, 00 ct"s, os.str());
		}

		TEST_METHOD(CentsOnly)
		{
			money m(0, 15);
			std::ostringstream os;
			os << m;
			Assert::AreEqual("15 ct"s, os.str());
		}


		TEST_METHOD(EurosOnly)
		{
			money m(500, 0);
			std::ostringstream os;
			os << m;
			Assert::AreEqual("500 eur"s, os.str());
		}

		TEST_METHOD(EurosAndCents)
		{
			money m(31, 5);
			std::ostringstream os;
			os << m;
			Assert::AreEqual("31 eur, 05 ct"s, os.str());
		}

		TEST_METHOD(CentsMoreThan99)
		{
			money m(3, 150);

			std::ostringstream os;
			os << m;

			Assert::AreEqual("4 eur, 50 ct"s, os.str());
		}

		TEST_METHOD(PlusEquals)
		{
			money total(0);
			total += money(6, 80);
			total += money(7, 20);

			std::ostringstream os;
			os << total;
			Assert::AreEqual("14 eur"s, os.str());
		}

		TEST_METHOD(MinusEquals)
		{
			money total(10, 0);
			total -= money(3, 50);

			std::ostringstream os;
			os << total;
			Assert::AreEqual("6 eur, 50 ct"s, os.str());
		}

		TEST_METHOD(Negative)
		{
			money total(5, 0);
			total -= money(10, 50);

			std::ostringstream os;
			os << total;
			Assert::AreEqual("-5 eur, 50 ct"s, os.str());
		}

		TEST_METHOD(Negative_Cents)
		{
			money total(0, 0);
			total -= money(0, 50);

			std::ostringstream os;
			os << total;
			Assert::AreEqual("-50 ct"s, os.str());
		}

		TEST_METHOD(Carry_CentsToEuros)
		{
			money total(99, 55);
			total += money(0, 75);

			std::ostringstream os;
			os << total;
			Assert::AreEqual("100 eur, 30 ct"s, os.str());
		}

		TEST_METHOD(Borrow_EurosToCents)
		{
			money total(10, 20);
			total -= money(0, 50);

			std::ostringstream os;
			os << total;
			Assert::AreEqual("9 eur, 70 ct"s, os.str());
		}

	};

}
