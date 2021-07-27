#include "PrimeNumber.Core/PrimeNumberCalculator.h"

PrimeNumberCalculator::PrimeNumberCalculator() = default;

using myType = size_t;

std::vector<myType> PrimeNumberCalculator::GetPrimeNumbers(myType i_till_value)
  {
	std::vector<myType> result;
	//firstly use foundNumbers
	for(auto number: m_foundPrimeNumbers)
	{
		if (number > i_till_value)
			return result;
		result.push_back(number);
	}
	//than find numbers, that wasn't found before
	myType from_value = *(m_foundPrimeNumbers.end()-1) + 1;
	bool primeNumberFound;
	for (myType i = from_value; i <= i_till_value; i++)
	{
		primeNumberFound = true;
		for (auto primeNumber : m_foundPrimeNumbers)
		{
			if (i % primeNumber == 0)
				primeNumberFound = false;
		}
		if (primeNumberFound)
		{
			m_foundPrimeNumbers.push_back(i);
			result.push_back(i);
		}
	}
	return result;
  }