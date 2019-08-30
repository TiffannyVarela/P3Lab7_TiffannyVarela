#include <iostream>
#include "CmdError.cpp"
#include "Consola.cpp"

using namespace std;

int main(){//inicio main
	string user;
	cout<<"Usuario: ";
	cin>>user;
	
	Consola* consola = new Consola(user, "logs.tavb");
	
	try{//inicio try
		consola->cmd();
		
	}//fin try
	catch(CmdError &e){//inicio catch
		cout<<e.what();
	}//fin catch
	delete consola;
	return 0;
}//fin main

