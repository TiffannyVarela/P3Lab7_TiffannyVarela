#include <iostream>
#include <string>
#include <string.h>
#include "CmdError.cpp"
#include "Logger.cpp"
#include <direct.h>
using namespace std;

#ifndef CONSOLA_CPP
#define CONSOLA_CPP

class Consola{
	protected:
		string user;
		Logger* logge;
		int num;
		string nom_archv;
	public:
		Consola(){
		}
		
		Consola(string user, string nom_archv){
			this->user=user;
			logge = new Logger(user, nom_archv, logge->getN());
		}
		
		int cmd(){
			Log* log;
			string comd;
			cout<<"Comando: ";
			cin>>comd;
			int resp = system((comd.c_str()));
			if(resp==1){
				throw CmdError("ERROR COMANDO NO VALIDO");
				logge->clear(logge->getLogs());
			}
			log = new Log(logge->getN(), user, comd);
		}
};

#endif

