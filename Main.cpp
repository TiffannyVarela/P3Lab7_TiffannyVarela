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
	}
	catch(CmdError &e){
		cout<<e.what();
	}
	
	return 0;
}

