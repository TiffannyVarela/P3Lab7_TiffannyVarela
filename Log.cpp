#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#ifndef _CPP
#define _CPP

class Log{
	protected:
		string user;
		string comd;
		int num_log;
		
	public:
		Log(){
		}
		
		Log(int num_log, string user, string comd){
			this->num_log=num_log;
			this->user=user;
			this->comd=comd;
		}
		
		int getNum_log(){
			return this->num_log;
		}
		
		void setNum_log(int num_log){
			this->num_log=num_log;
		}
		
		string getUser(){
			return this->user;
		}
		
		void setUser(string user){
			this->user.assign(user);
		}
		
		string getComd(){
			return this->comd;
		}
		
		void setComd(string comd){
			this->user.assign(user);
		}
		
		~Log(){
		}
		
};

#endif

