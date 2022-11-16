#include"operation.h"
#include"handle.h"
void Operation::input_window()//读出文件夹名
{  
    DIR* dirStream;
    const char* pat="input/";
    dirStream=opendir(pat);
    //vector<string>filename;
    struct dirent* dirInfo;
    while((dirInfo=readdir(dirStream))!=0)
    {
        if(strcmp(dirInfo->d_name,".")!=0&&strcmp(dirInfo->d_name,"..")!=0)
        {
            //cout<<"folder_name"<<dirInfo->d_name<<endl;
            fname.push_back(dirInfo->d_name);
        }
    }
}
void Operation::setaddress(int num)//读出文件的地址
{
    address.clear();
    DIR* dirStream;
    char pat[100]="input/";
    strcat(pat,fname[num].c_str());
    dirStream=opendir(pat);
    //vector<string>filename;
    struct dirent* dirInfo;
    while((dirInfo=readdir(dirStream))!=0)
    {
        if(strcmp(dirInfo->d_name,".")!=0&&strcmp(dirInfo->d_name,"..")!=0)
        { if(strcmp(dirInfo->d_name,"stdin_format.txt")!=0)
            {
                
                char addr[100]={0};
                strcpy(addr,pat);
                strcat(addr,"/");
                strcat(addr,dirInfo->d_name);
                address.push_back(addr);
            }
            else 
            {
                 char addr[100]={0};
                strcpy(addr,pat);
                strcat(addr,"/");
                strcat(addr,dirInfo->d_name);
                formaddress=addr;
            }
        }
    }
}
void Operation::Operate()
{   input_window(); 
    clearfile();
    for(int i=0;i<fname.size();i++)
    {
     setaddress(i);//一次操作程序地址
    Input in;
    Judge ju;
    ju.set_round(10);
    in.findinput(formaddress);//读取格式
    Output ou;
    for(int r=0;r<ju.get_round();r++)
    {   A:in.random_input();//生成随机输入
            ju.outclear();//
        for(int j=0;j<address.size();j++)//两两比较
            {  
                //cout<<"addr:"<<address[j]<<endl;
                 if(!ju.run_program(address[j]))  //运行程序，结果地址储存
                goto A;
            } 
            ou.build(ju.outaddr.size());//初始化结果数组
          for(int j=0;j<ju.outaddr.size();j++)//判断结果
          for(int k=j+1;k<ju.outaddr.size();k++)
            {   
                //cout<<"addr:"<<ju.outaddr[j]<<ju.outaddr[k]<<endl;
                bool ans=ju.compareoj(ju.outaddr[j],ju.outaddr[k]);
                //cout<<ans<<endl;
                ou.Set_Result(ans,j,k);
            }
        }
    for(int j=0;j<address.size();j++)
          for(int k=j+1;k<address.size();k++)
            {    //cout<<"fileaddr:"<<address[j]<<address[k]<<endl;
                ou.writeinfile(address[j],address[k],j,k);
            }
    }
}
void Operation::clearfile()
{
    ofstream e1("output/inequal.csv");
    ofstream e2("output/equal.csv");
    if(!e1.is_open()||!e2.is_open())
    {
        cerr<<"clear faild"<<endl;
        exit(-1);
    }
    e1.close();
    e2.close();
return;
}

