#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;

#ifndef ERROR_CPP
#define ERROR_CPP

class Error : public runtime_error{
	public:
		exceptiones(char* msg):runtime_error(msg){
			
		}
};
#endif


