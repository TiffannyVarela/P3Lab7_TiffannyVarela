#include <iostream>
#include "CmdError.cpp"
#include "Consola.cpp"

using namespace std;

int main(){
	string user;
	cout<<"Usuario: ";
	cin>>user;
	
	Consola* consola = new Consola(user, "logs.tavb");
	
	try{
		consola->cmd();
		consola = NULL;
		delete[] consola;
	}
	catch(CmdError &e){
		cout<<e.what();
	}
	
	return 0;
}

