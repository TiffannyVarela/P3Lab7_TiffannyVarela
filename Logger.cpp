#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>
#include "Log.cpp"
using namespace std;

#ifndef LOGGER_CPP
#define LOGGER_CPP

class Logger{
	protected:
		char user [100];
		char nom_archv[100];
		int num_log;
		vector <Log*> vect_logs;
		
	public:
		Logger(){
		}
		
		Logger(string user, string nom_archv, int num_log){
			setUser(user);
			setNom_archv(nom_archv);
			this->num_log=num_log;
		}
		
		string getUser()const{
			return this->user;
		}
		
		void setUser(string user1){
			const char *puser = user1.data();
			int num = user1.size();
			num = num < 100 ? num:99;
			strncpy(user, puser, num);
			user[num] = '\0';
		}
		
		string getNom_archv()const{
			return nom_archv;
		}
		
		void setNom_archv(string nom_archv1){
			const char *pnom_archv = nom_archv1.data();
			int num = nom_archv1.size();
			num = num < 100 ? num:99;
			strncpy(nom_archv, pnom_archv, num);
			nom_archv[num] = '\0';
		}
		
		int getNum_log()const{
			return num_log;
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
			fstream escribir(nom_archv, ios::out | ios::binary | ios::app);
			if(!escribir){
				cout<<"Problemas con apertura de archivo \n";
				system("pause");
				return ;
			}
			string usuario;
			string comando;
			int num_log;
			for(int i=0; i<getN(); i++){
				usuario = vect_logs.at(i)->getUser();
				comando = vect_logs.at(i)->getComd();
				num_log = i;
				Log log(num_log, usuario, comando);
				
				escribir.seekp(0, ios::end);
				escribir.write(reinterpret_cast<char*>(&log), sizeof(log));
				
				escribir.close();
			}
		}
		
		void Listar(){
			Log x;
			ifstream leer(nom_archv, ios::in | ios::binary);
			
			if(!leer){
				cout<<"Problemas con la apertura del archivo\n";
				system("pause");
				return ;
			}
			
			leer.seekg(0, ios::beg);
			leer.read(reinterpret_cast<char*>(&x), sizeof(x));
			while(!leer.eof()){
				leer.read(reinterpret_cast<char*>(&x), sizeof(x));
				cout<<endl;
				x.printLog();
				cout<<endl;
				leer.read(reinterpret_cast<char*>(&x), sizeof(x));
			}
			
			leer.close();
		}
		
		void clear(vector<Log*> x){
			x.clear();
			if(!x.empty()){
				x.clear();
			}
		}

		
		~Logger(){
		}
};

#endif

