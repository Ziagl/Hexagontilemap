#include "pch.h"
#include "CppUnitTest.h"
#include "..\HexagonTileMap\Hex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HexagonTileMapTest
{
	TEST_CLASS(HexTest)
	{
	public:

		TEST_METHOD(initialization)
		{
			auto h = new Hex(0, 0, 0);
			Assert::IsNotNull(h);
		}

		TEST_METHOD(badinitialization)
		{
			try
			{
				auto h = new Hex(1, 0, 0);
				Assert::Fail();
			}
			catch (...)
			{
				// nothing to do
			}
		}

		TEST_METHOD(equal)
		{
			auto first = Hex(0, 0, 0);
			auto second = Hex(0, 0, 0);

			Assert::IsTrue(first == second);

			auto third = Hex(-1, 0, 1);

			Assert::IsFalse(first == third);
		}

		TEST_METHOD(notequal)
		{
			auto first = Hex(0, 0, 0);
			auto second = Hex(0, 0, 0);

			Assert::IsFalse(first != second);

			auto third = Hex(-1, 0, 1);

			Assert::IsTrue(first != third);
		}

		TEST_METHOD(add)
		{
			auto first = Hex(0, 0, 0);
			auto second = Hex(1, -2, 1);
			auto result1 = Hex(1, -2, 1);

			Assert::IsTrue(first + second == result1);

			auto third = Hex(-1, 0, 1);
			auto result2 = Hex(0, -2, 2);

			Assert::IsTrue(second + third == result2);
		}

		TEST_METHOD(subtract)
		{
			auto first = Hex(0, 0, 0);
			auto second = Hex(1, -2, 1);
			auto result1 = Hex(-1, 2, -1);

			Assert::IsTrue(first - second == result1);

			auto third = Hex(-1, 0, 1);
			auto result2 = Hex(2, -2, 0);

			Assert::IsTrue(second - third == result2);
		}

		TEST_METHOD(multiply)
		{
			auto first = Hex(1, 0, -1);
			auto result1 = Hex(3, 0, -3);

			Assert::IsTrue(first * 3 == result1);

			auto second = Hex(-3, 2, 1);
			auto result2 = Hex(-6, 4, 2);

			Assert::IsTrue(second * 2 == result2);
		}

		TEST_METHOD(length)
		{
			auto first = Hex(1, 0, -1);
			auto second = Hex(7, -3, -4);

			Assert::AreEqual(1, first.length());
			Assert::AreEqual(7, second.length());
		}

		TEST_METHOD(distance)
		{
			auto first = Hex(1, 0, -1);
			auto second = Hex(7, -3, -4);

			Assert::AreEqual(6, first.distance(second));

			auto third = Hex(-5, 10, -5);

			Assert::AreEqual(10, first.distance(third));
		}

		TEST_METHOD(neighbor)
		{
			auto first = Hex(1, 0, -1);
			auto result1 = Hex(2, 0, -2);

			Assert::IsTrue(result1 == first.neighbor(HexDirection::EAST));

			auto result2 = Hex(1, -1, 0);

			Assert::IsTrue(result2 == first.neighbor(HexDirection::NORTHWEST));
		}
	};
}
