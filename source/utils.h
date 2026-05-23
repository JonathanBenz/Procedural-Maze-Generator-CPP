#pragma once
#include <random>
#include <vector>

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

	// 50/50 chance to return true.
	static bool FlipCoin()
	{
		return BoundedRand(2) == 0;
	}

	// Randomly pick an element from a vector of pointers
	template <typename T>
	static T* Sample(const std::vector<T*>& vec)
	{
		if (vec.empty()) return nullptr;
		return vec.at((Utils::BoundedRand(vec.size())));
	}
};