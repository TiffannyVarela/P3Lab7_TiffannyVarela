#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>
#include "Log.cpp"
using namespace std;

#ifndef LOGGER_CPP
#define LOGGER_CPP

struct Log{
	char user[100];
	char comd [100];
	int num_log;
};

class Logger{
	protected:
		string user, nom_archv;
		int num_log;
		vector <Log*> vect_logs;
		
	public:
		Logger(){
		}
		
		Logger(string user, string nom_archv, int num_log){
			this->user=user;
			this->nom_archv=nom_archv;
			this->num_log=num_log;
		}
		
		string getUser(){
			return this->user;
		}
		
		void setUser(string user){
			this->user.assign(user);
		}
		
		string getNom_archv(){
			return this->nom_archv;
		}
		
		void setNom_archv(string nom_archv){
			this->nom_archv.assign(nom_archv);
		}
		
		int getNum_log(){
			return this->num_log;
		}
		
		void setNum_log(int num_log){
			this->num_log=num_log;
		}
		
		vector <Log*> getLogs(){
			return this->vect_logs;
		}
		
		void addLog(Log* l){
			vect_logs.push_back(l);
		}
		
		int getN(){
			vect_logs.size();
		}
		
		void setVectLogs( vector <Log*> vect_logs){
			this->vect_logs=vect_logs;
		}
		
		void Escribir(){
			string user, comd;
			int n_log;
			Log log;
			for(int i=0< i<getN(); i++){
				strcpy(log.user, vect_logs.at(i)->getUser().c_str());
			}
			
		}
		
		~Logger(){
		}
};

#endif

