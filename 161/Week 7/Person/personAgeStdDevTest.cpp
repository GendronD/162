#include "Person.hpp"
#include <cmath>
#include <iostream>
#include <string>
const double EPS = 0.00001;
 

double stdDev(Person arrPerson[], int);

int main() 
{
	Person a("alice", 92);
	Person b("bernice", 77);
	Person arrPerson[] = {a,b};
	double result = stdDev(arrPerson, 2);
	bool ASSERT_TRUE(fabs(result-7.5) < EPS);

	return 0;

}
