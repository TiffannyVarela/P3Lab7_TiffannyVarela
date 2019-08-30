#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "Log.cpp"
using namespace std;

#ifndef _CPP
#define _CPP

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
		
		void setVectLogs( vector <Log*> vect_logs){
			this->vect_logs=vect_logs;
		}
		
		~Logger(){
		}
};

#endif

