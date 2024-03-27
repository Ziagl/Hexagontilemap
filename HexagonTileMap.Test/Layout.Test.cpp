#include "pch.h"
#include "CppUnitTest.h"
#include "..\HexagonTileMap\Layout.h"
#include "..\HexagonTileMap\Layout.cpp"
#include "..\HexagonTileMap\Orientation.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HexagonTileMapTest
{
	TEST_CLASS(LayoutTest)
	{
	public:
		const double epsilon = 0.01;

		TEST_METHOD(initialization)
		{
			auto origin = Point(0.0, 0.0);
			auto size = Point(1.0, 1.0);
			auto orientation = Orientation::layoutFlat;
			auto l = new Layout(orientation, size, origin);
		}

		TEST_METHOD(hextopixel)
		{
			auto origin = Point(0.0, 0.0);
			auto size = Point(1.0, 1.0);
			auto orientation = Orientation::layoutFlat;
			auto l = new Layout(orientation, size, origin);

			auto coordinate = l->hexToPixel(Hex(0, 0, 0));
			Assert::IsTrue(coordinate.x == 0.0);
			Assert::IsTrue(coordinate.y == 0.0);
		}

		TEST_METHOD(hextopixel_coordinates)
		{
			auto origin = Point(0.0, 0.0);
			auto size = Point(1.0, 1.0);
			auto orientation = Orientation::layoutFlat;
			auto l = new Layout(orientation, size, origin);

			auto coordinate = l->hexToPixel(Hex(3, 0, -3));
			Assert::IsTrue(coordinate.x - 4.5 < epsilon);
			Assert::IsTrue(coordinate.y - 2.59 < epsilon);
		}

		TEST_METHOD(hextopixel_scale)
		{
			auto origin = Point(0.0, 0.0);
			auto size = Point(0.5, 0.8);
			auto orientation = Orientation::layoutFlat;
			auto l = new Layout(orientation, size, origin);

			auto coordinate = l->hexToPixel(Hex(1, 0, -1));
			Assert::IsTrue(coordinate.x - 0.75 < epsilon);
			Assert::IsTrue(coordinate.y - 0.69 < epsilon);
		}
	};
}
