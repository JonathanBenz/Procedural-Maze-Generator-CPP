#pragma once
#include <random>

class Utils
{
public:
	static std::mt19937& GetRNG()
	{
		static std::mt19937 rng(std::random_device{}());
		return rng;
	}

	// Return a random number in the domain of (0, Range]. 
	template <typename T>
	static T BoundedRand(T Range)
	{
		std::uniform_int_distribution<T> dist(0, Range - 1);
		return dist(GetRNG());
	}
};