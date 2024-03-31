#include "pch.h"
#include "CppUnitTest.h"
#include "..\HexagonTileMap\Map.h"

#include <random>
#include <set>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HexagonTileMapTest
{
	TEST_CLASS(MapTest)
	{
	public:
		const double epsilon = 0.01;

		int max = 2000;
		std::random_device dev;
		std::mt19937 randomNumberGenerator;
		std::uniform_int_distribution<std::mt19937::result_type> distribution;

		TEST_METHOD_INITIALIZE(initialize)
		{
			randomNumberGenerator = std::mt19937(dev());
			distribution = std::uniform_int_distribution<std::mt19937::result_type>(0, max);
		}

		TEST_METHOD(create)
		{
			auto map = Map<float>();
			map.add(Hex(1, 0, -1), 0.5);
			float height = map.get(Hex(1, 0, -1));

			Assert::IsTrue(height - 0.5 < epsilon);
		}

		TEST_METHOD(stresstest)
		{
			auto map = Map<float>();

			for (int i = 0; i < 500000; ++i)
			{
				auto hex = getRandomHex();
				float height = (float)hex.q() / (hex.r() == 0 ? 1.0f : (float)hex.r());
				map.add(hex, height);

				Assert::IsTrue(height - map.get(hex) < epsilon);
			}
		}

	private:
		Hex getRandomHex()
		{
			int q = distribution(randomNumberGenerator) - (max / 2);
			int r = distribution(randomNumberGenerator) - (max / 2);
			int s = (q + r) * (-1);

			return Hex(q, r, s);
		}
	};
}
