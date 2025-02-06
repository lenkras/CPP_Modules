#pragma once

#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>

typename std::vector<T>::iterator easyfind(std::vector<T>& arr, int num)
{
	auto it = std::find(arr.begin(), arr.end(), num);
	if (it != arr.end())
		return it;
	throw std::runtime_error("Value not found.");
}