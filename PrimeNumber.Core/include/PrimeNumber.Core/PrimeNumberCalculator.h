#pragma once

#include <PrimeNumber.Core/PrimeNumber.Core.API.h>

#include <vector>
#include <set>
#include <type_traits>
#include <string>

class PRIMENUMBERCORE_API PrimeNumberCalculator
  {
    std::vector<size_t> m_foundPrimeNumbers = {2,3};
  public:
    PrimeNumberCalculator();
    std::vector<size_t> GetPrimeNumbers(size_t i_till_value);
  };

template<typename T>
class PrimeNumberCalculatorParam 
{
    std::vector<size_t> m_foundPrimeNumbers = { 2,3 };
public:
	PrimeNumberCalculatorParam() = default;
    std::vector<T> GetPrimeNumbers(size_t i_till_value)
	{
		PrimeNumberCalculator calc;
		std::vector<size_t> tempResult = calc.GetPrimeNumbers(i_till_value);
		
		std::vector<T> result;
		result.reserve(tempResult.size());
		
		if constexpr (std::is_arithmetic<T>::value)
		{
			for (auto primeNumber : tempResult)
				result.push_back(static_cast<T>(primeNumber));
		}
		else if constexpr (std::is_same<T, std::string>::value)
		{
			for (auto primeNumber : tempResult)
				result.emplace_back(std::to_string(primeNumber));
		}
		return result;
	}
};