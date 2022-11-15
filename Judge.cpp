#include"handle.h"
bool Judge::run_program(string addr)
{
                char c1[100]="g++ ";
                strcat(c1,addr.c_str());//g++ .cpp
                strcat(c1," -o a.out");
                system(c1);
                char c2[100]="./a.out <rinput.txt >"; 
                char*c=NULL;
                c=strtok((char*)addr.c_str(),"/");
                c=strtok(NULL,"/");
                c=strtok(NULL,".");//1111111
                strcat(c,".txt");//11111.txt
                strcat(c2,c);
                //strcat(c2,c);
                //system("./a.out <rinput.txt >output1.txt");
                //cout<<c2<<endl;
               if(! system(c2))
                {   //char c3[100]="routput/";
                //strcat(c3,c);
                    outaddr.push_back(c);
                }
                else return false;
                return true;
}
bool Judge::compareoj(string addr1,string addr2)
{
    ifstream out1(addr1);
    ifstream out2(addr2);
    if(!out1.is_open()||!out2.is_open())
    {
        cerr<<"compare wrong"<<endl;
        exit(-1);
    }
    string tmp1,tmp2;
   while(1)
   {    getline(out1,tmp1);
        getline(out2,tmp2);
       //cout<<"output:"<<tmp1<<" "<<tmp2<<endl; 
        if(tmp1!=tmp2)return false;
        if(out1.eof()&&out2.eof())break;
        if(tmp1==tmp2)continue;
        //if(out1.eof()||out2.eof())return false;
   }
   return true;
}