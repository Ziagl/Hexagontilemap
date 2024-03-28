#include "pch.h"
#include "CppUnitTest.h"
#include "..\HexagonTileMap\Hex.h"
#include "..\HexagonTileMap\FractionalHex.h"
#include "..\HexagonTileMap\Layout.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HexagonTileMapTest
{
	TEST_CLASS(FractionalHexTest)
	{
	public:
		const double epsilon = 0.01;

		TEST_METHOD(initialization)
		{
			auto h = new FractionalHex(0.1, 0.2, -0.3);
			Assert::IsNotNull(h);
		}

		TEST_METHOD(badinitialization)
		{
			try
			{
				auto h = new FractionalHex(0.1, 0.2, 0.3);
				Assert::Fail();
			}
			catch (...)
			{
				// nothing to do
			}
		}

		TEST_METHOD(pixeltohex)
		{
			auto origin = Point(0.0, 0.0);
			auto size = Point(1.0, 1.0);
			auto orientation = Orientation::layoutFlat;
			auto l = new Layout(orientation, size, origin);

			auto coordinate = Point(3.5, -5.1);
			auto fractionalHex = l->pixelToHex(coordinate);

			Assert::IsTrue(fractionalHex.q() - 2.33 < epsilon);
			Assert::IsTrue(fractionalHex.r() + 4.11 < epsilon);
			Assert::IsTrue(fractionalHex.s() - 1.77 < epsilon);

			auto hex = fractionalHex.hexRound();

			Assert::IsTrue(hex.q() == 2);
			Assert::IsTrue(hex.r() == -4);
			Assert::IsTrue(hex.s() == 2);
		}
	};
}
