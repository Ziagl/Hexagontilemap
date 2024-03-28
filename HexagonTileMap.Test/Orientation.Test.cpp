#include "pch.h"
#include "CppUnitTest.h"
#include "..\HexagonTileMap\Layout.h"
#include "..\HexagonTileMap\Orientation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HexagonTileMapTest
{
	TEST_CLASS(OrientationTest)
	{
	public:
		const double epsilon = 0.01;

		TEST_METHOD(layout_pointy)
		{
			auto origin = Point(0.0, 0.0);
			auto size = Point(1.0, 1.0);
			auto orientation = Orientation::layoutPointy;
			auto l = new Layout(orientation, size, origin);

			auto coordinate1 = l->hexToPixel(Hex(3, 0, -3));
			Assert::IsTrue(coordinate1.x - 5.19 < epsilon);
			Assert::IsTrue(coordinate1.y - 0.0 < epsilon);

			auto coordinate2 = l->hexToPixel(Hex(1, 1, -2));
			Assert::IsTrue(coordinate2.x - 2.59 < epsilon);
			Assert::IsTrue(coordinate2.y - 1.5 < epsilon);
		}

		TEST_METHOD(layout_flat)
		{
			auto origin = Point(0.0, 0.0);
			auto size = Point(1.0, 1.0);
			auto orientation = Orientation::layoutFlat;
			auto l = new Layout(orientation, size, origin);

			auto coordinate1 = l->hexToPixel(Hex(3, 0, -3));
			Assert::IsTrue(coordinate1.x - 4.5 < epsilon);
			Assert::IsTrue(coordinate1.y - 2.59 < epsilon);

			auto coordinate2 = l->hexToPixel(Hex(1, 1, -2));
			Assert::IsTrue(coordinate2.x - 1.5 < epsilon);
			Assert::IsTrue(coordinate2.y - 2.59 < epsilon);
		}
	};
}
