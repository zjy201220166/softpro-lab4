#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<sys/types.h>
#include<vector>
#include<dirent.h>
#include<string.h>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
class Input
{  private:
            vector<string> form;
    public:
            void findinput(string str);
            Input(){form.clear();}
            ~Input(){};
            void random_input();
};
class Judge
{       private:
        int round;
        public:
        vector<string>outaddr;
        Judge(){outaddr.clear();};
        ~Judge(){};
        void set_round(int r){round=r;};
        int get_round(){return round;};
        void outclear(){outaddr.clear();};
        bool run_program(string addr);
        bool compareoj(string addr1,string addr2);
};
class Output
{
        private:
        vector<vector<bool>> result;
        public:
        Output(){result.clear();};
        ~Output(){};
         void build(int size){
                vector<vector<bool>>res (size,vector<bool>(size,true));
                result=res;
        };
        void Set_Result(bool res,int i,int j);
        void writeinfile(string addr1,string addr2,int i,int j);
};

