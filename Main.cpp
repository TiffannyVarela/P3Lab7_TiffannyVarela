#include <iostream>
#include "Error.cpp"
#include "Consola.cpp"

using namespace std;

int main(){
	string user;
	cout<<"Usuario: ";
	cin>>user;
	
	Consola* consola = new Consola(user, "logs.tavb");
	
	try{
		consola->cmd();
	}
	catch(Error &e){
		cout<<e.what();
	}
	
	return 0;
}
