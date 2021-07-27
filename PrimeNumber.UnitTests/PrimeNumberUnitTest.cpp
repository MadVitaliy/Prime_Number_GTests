#include <PrimeNumber.Core/PrimeNumberCalculator.h>

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <type_traits>
#include <string>


struct PrimeNumberCalculatorTest : public ::testing::Test
{
	PrimeNumberCalculator calc;

	std::vector<size_t> primeTestNumbers = { 2,	3,	5,	7,	11,	13,	17,	19,	23,	29,	31,	37,	41,	43,	47,	53,	
		59,	61,	67,	71, 73,	79,	83, 89,	97,	101, 103, 107, 109,	113, 127, 131, 137, 139, 149, 151, 157, 163, 
		167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277,
		281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409 };

	static void SetUpTestSuite()
	{
		std::cout << "SetUpTestSuite" << std::endl;
	}

	static void TearDownTestSuite()
	{
		std::cout << "TearDowneTestSuite" << std::endl;
	}

	void SetUp() override
	{
		std::cout << "SetUp" << std::endl;
	}

	void TearDown() override
	{
		std::cout << "TearDown" << std::endl;
	}
};

TEST_F(PrimeNumberCalculatorTest, ReturnsEmptyRezult_When0)
{
	//setup in fixture
	const auto result = calc.GetPrimeNumbers(0);//act
	EXPECT_TRUE(result.empty());//assert
}

TEST_F(PrimeNumberCalculatorTest, ReturnsEmptyRezult_When1)
{
	const auto result = calc.GetPrimeNumbers(1);
	EXPECT_TRUE(result.empty());
}

TEST_F(PrimeNumberCalculatorTest, Returns2_When2)
{
	const auto result = calc.GetPrimeNumbers(2);
	ASSERT_EQ(result.size(), 1);
	EXPECT_EQ(result[0], 2);
}


TEST_F(PrimeNumberCalculatorTest, ReturnsFirst20PrimeNumbers_When71)
{
	const auto result = calc.GetPrimeNumbers(71);
	ASSERT_EQ(result.size(), 20);
	for (size_t i = 0; i < 20; i++)
	{
		EXPECT_EQ(result[i], primeTestNumbers[i]) << "Failed on " << i 
			<< "; Expected: "<< primeTestNumbers[i] << ", but get " << result[i];
	}
}

TEST_F(PrimeNumberCalculatorTest, ReturnsFirst20PrimeNumbers_When72)
{
	const auto result = calc.GetPrimeNumbers(71);
	ASSERT_EQ(result.size(), 20);
	for (size_t i = 0; i < 20; i++)
	{
		EXPECT_EQ(result[i], primeTestNumbers[i]);
	}
}

TEST_F(PrimeNumberCalculatorTest, Has3559_When3572)
{
	const auto result = calc.GetPrimeNumbers(3572);
	EXPECT_THAT(result, ::testing::Contains(3559));
}

//template<typename T>
//PrimeNumberCalculatorParamTest<T>* CreateCalculator;
//
//template<>
//PrimeNumberCalculatorParamTest<int>* CreateCalculator
//{
//	return new PrimeNumberCalculatorParamTest<int>;
//}


template <class T>
std::vector<T> CreateTestNumbers()
{
	std::vector<T> primeTestNumbers = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
	59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109,113, 127, 131, 137, 139, 149, 151, 157, 163,
	167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277,
	281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409 };
	return primeTestNumbers;
}

template <>
std::vector<std::string> CreateTestNumbers<std::string>()
{
	std::vector<std::string> primeTestNumbers = { "2", "3", "5", "7", "11", "13", "17", "19", "23", "29", "31", "37", "41", 
		"43", "47", "53", "59", "61", "67", "71", "73", "79", "83", "89", "97", "101", "103", "107", "109", "113", "127", 
		"131", "137", "139", "149", "151", "157", "163", "167", "173", "179", "181", "191", "193", "197", "199", "211", 
		"223", "227", "229", "233", "239", "241", "251", "257", "263", "269", "271", "277", "281", "283", "293", "307", 
		"311", "313", "317", "331", "337", "347", "349", "353", "359", "367", "373", "379", "383", "389", "397", "401", "409"};
	return primeTestNumbers;
}

template <>
std::vector<std::wstring> CreateTestNumbers<std::wstring>()
{
	std::vector<std::wstring> primeTestNumbers = { L"2", L"3", L"5", L"7", L"11", L"13", L"17", L"19", L"23", L"29", 
		L"31", L"37", L"41", L"43", L"47", L"53", L"59", L"61", L"67", L"71", L"73", L"79", L"83", L"89", L"97",
		L"101", L"103", L"107", L"109", L"113", L"127", L"131", L"137", L"139", L"149", L"151", L"157", L"163",
		L"167", L"173", L"179", L"181", L"191", L"193", L"197", L"199", L"211", L"223", L"227", L"229", L"233", L"239",
		L"241", L"251", L"257", L"263", L"269", L"271", L"277", L"281", L"283", L"293", L"307", L"311", L"313", L"317", 
		L"331", L"337", L"347", L"349", L"353", L"359", L"367", L"373", L"379", L"383", L"389", L"397", L"401", L"409" };
	return primeTestNumbers;
}

template<typename T>
class PrimeNumberCalculatorParamTest :public testing::Test
{
public:

	PrimeNumberCalculatorParam<T> calc;
	std::vector<T> primeTestNumbers;

	PrimeNumberCalculatorParamTest() : primeTestNumbers(CreateTestNumbers<T>()) {}

	static void SetUpTestSuite()
	{
		std::cout << "SetUpTestSuite" << std::endl;
	}

	void SetUp() override
	{
		std::cout << std::endl << "SetUp template<" << typeid(std::declval<T>()).name() << ">" << std::endl;
	}

	void TearDown() override
	{
		std::cout << "TearDown template<" << typeid(std::declval<T>()).name() << ">" << std::endl << std::endl;
	}

};

typedef ::testing::Types<int, float, double, std::string, std::wstring> MyArithmeticTypes;

TYPED_TEST_SUITE(PrimeNumberCalculatorParamTest, MyArithmeticTypes);

TYPED_TEST(PrimeNumberCalculatorParamTest, ReturnsEmptyRezult_When0)
{
	//setup in fixture
	const auto result = calc.GetPrimeNumbers(0); 	//act
	EXPECT_TRUE(result.empty()); 	//assert
}

TYPED_TEST(PrimeNumberCalculatorParamTest, ReturnsEmptyRezult_When1)
{
	const auto result = calc.GetPrimeNumbers(1);
	EXPECT_TRUE(result.empty());
}

TYPED_TEST(PrimeNumberCalculatorParamTest, Returns2_When2)
{
	const auto result = calc.GetPrimeNumbers(2);
	ASSERT_EQ(result.size(), 1);
	EXPECT_EQ(result[0], primeTestNumbers[0]);
}


TYPED_TEST(PrimeNumberCalculatorParamTest, ReturnsFirst20PrimeNumbers_When71)
{
	const auto result = calc.GetPrimeNumbers(71);
	ASSERT_EQ(result.size(), 20);
	for (size_t i = 0; i < 20; i++)
	{
		EXPECT_EQ(result[i], primeTestNumbers[i]) << "Failed on " << i
			<< "; Expected: " << primeTestNumbers[i] << ", but get " << result[i];
	}
}

TYPED_TEST(PrimeNumberCalculatorParamTest, ReturnsFirst20PrimeNumbers_When72)
{
	const auto result = calc.GetPrimeNumbers(71);
	ASSERT_EQ(result.size(), 20);
	for (size_t i = 0; i < 20; i++)
	{
		EXPECT_EQ(result[i], primeTestNumbers[i]);
	}
}

TYPED_TEST(PrimeNumberCalculatorParamTest, Has409_When420)
{
	const auto result = calc.GetPrimeNumbers(420);
	EXPECT_THAT(result, ::testing::Contains(primeTestNumbers[79])); //primeTestNumbers[79] = 409
}