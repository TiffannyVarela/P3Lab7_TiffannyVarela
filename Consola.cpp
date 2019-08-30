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
			
			while (comd != "exit") {
				int err = 0;
				cout<<"Comando: ";
				cin>>comd;
				
				if(comd == "cls"){
					log = new Log(logge->getN(), user, comd);
					logge->addLog(log);
					logge->Escribir();
					system("pause");
				}
				
				if (comd == "listar") {
					logge->Listar();
				} else if (comd.size() > 3 && comd.substr(0, 3) == "cd ") {
					err = _chdir(comd.substr(3, comd.size()).c_str());
				} else {
					err = system(comd.c_str());
				}
				log = new Log(logge->getN(), user, comd);
				logge->addLog(log);
				logge->Escribir();
				if (err) {
					logge->clear(logge->getLogs());
					logge = NULL;
					delete[] logge;
					throw CmdError("ERROR COMANDO NO VALIDO");
				}

		}
			
	}
};

#endif

