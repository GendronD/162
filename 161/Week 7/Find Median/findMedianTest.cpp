#include "findMedian.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

const double EPS = 0.00001;

int main()
{
	int arr[] = {1, 5, 7, 4, 2, 6, 3, 9, 8, 10};
	double result = findMedian(arr, 10);
	bool ASSERT_TRUE(fabs(result-5.0) < EPS);

	if(ASSERT_TRUE = 1)
	std::cout << "true" << std::endl;

	if(ASSERT_TRUE = 0)
	std::cout << "false" << std::endl;

	return 0;
}