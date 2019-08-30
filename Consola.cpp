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
		}//fin constructor vacio
		
		Consola(string user, string nom_archv){
			this->user=user;
			logge = new Logger(user, nom_archv, logge->getN());
		}//fin constructor sobrecargado
		
		void cmd(){//inicio metodo cmd
			Log* log;
			string comd;
			
			while (comd != "exit") {//inicio while salir
				int err = 0;
				cout<<"Comando: ";
				cin>>comd;
				
				if(comd == "cls"){//inicio if guardar cls
					log = new Log(logge->getN(), user, comd);
					logge->addLog(log);
					logge->Escribir();
					system("pause");
				}//fin if guardar cls
				
				if(comd == "exit"){//inicio if guardar exit
					log = new Log(logge->getN(), user, comd);
					logge->addLog(log);
					logge->Escribir();
					system("pause");
				}//fin if guardar exit
				
				if (comd == "listar") {//inicio if listar
					logge->Listar();
				} //fin if listar
				else if (comd.size() > 3 && comd.substr(0, 3) == "cd ") {//inicio else if
					err = _chdir(comd.substr(3, comd.size()).c_str());
				} //fin else if
				else {//inicio else
					err = system(comd.c_str());
				}//fin else
				log = new Log(logge->getN(), user, comd);
				logge->addLog(log);
				logge->Escribir();
				if (err) {//inicio if error
					logge->clear(logge->getLogs());
					delete logge;
					throw CmdError("ERROR COMANDO NO VALIDO");
				}//fin if error
			}//fin while salir	
		}//fin del metodo cmd
		
		~Consola(){
		}
};

#endif

