#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<sys/types.h>
#include<vector>
#include<dirent.h>
#include<stdlib.h>
using namespace std;
class Operation
{
    private:
    vector<string>fname;
    vector<string>address;
    string formaddress;
    public:
    Operation(){address.clear();};
    ~Operation(){};
     void input_window();
    void setaddress (int num);
    void Operate();
    void clearfile();
};