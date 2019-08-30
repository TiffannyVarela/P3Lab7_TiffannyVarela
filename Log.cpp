#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#ifndef LOG_CPP
#define LOG_CPP

class Log{
	protected:
		char user [100];//usuario
		char comd [100];//comando
		int num_log;//numero de log
		
	public:
		Log(){
		}//fin constructor vacio
		
		Log(int num_log, string user, string comd){
			this->num_log=num_log;
			setUser(user);
			setComd(comd);
		}//fin constructor sobrecargado
		
		int getNum_log()const{
			return this->num_log;
		}
		
		void setNum_log(int num_log){
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
		
		string getComd()const{
			return this->comd;
		}
		
		void setComd(string comd1){
			const char *pcomd = comd1.data();
			int num = comd1.size();
			num = num < 100 ? num:99;
			strncpy(comd, pcomd, num);
			comd[num] = '\0';
		}
		
		void printLog(){
			cout<<"Num: "<<num_log<<", usuario: "<<user<<", cmd: \""<<comd<<"\""<<endl;
		}
		
		~Log(){
		}
		
};

#endif

