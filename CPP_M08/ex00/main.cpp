#include "easyfind.hpp"

int main()
{
	std::vector<int> arr= {1, 2, 3, 4, 5};
	//std::vector<double> arrDo = {1.1, 2.2, 3.3};
	try{
		auto it = easyfind(arr, 4);
		std::cout<< "Value found: "<< *it<<std::endl;

		// auto itD = easyfind(arrDo, 2);
		// std::cout<< "Value in double array found: "<< *itD<<std::endl;
		it = easyfind(arr, 15);
		
	}catch(const std::runtime_error& e ){
		std::cout << "Error: "<< e.what()<< std::endl;
	}
}