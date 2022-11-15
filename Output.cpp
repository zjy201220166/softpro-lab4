#include"handle.h"
void Output::Set_Result(bool res,int i,int j)
{
    if(result[i][j]==false)
    return;
    else result[i][j]=res;
    return;
}
void Output::writeinfile(string addr1,string addr2,int i,int j)
{
    if(result[i][j]==false)
    {
        ofstream inequal("output/inequal.csv",ios::app);
        if(!inequal.is_open())
        {
            cout<<"inequal wrong"<<endl;
            exit(-1);
        }
        inequal<<addr1<<","<<addr2<<endl;
        inequal.close();
    }
    else if(result[i][j])
    {
        ofstream equal("output/equal.csv",ios::app);
        if(!equal.is_open())
        {
            cout<<"equal wrong"<<endl;
            exit(-1);
        }
        equal<<addr1<<","<<addr2<<endl;
        equal.close();
    }
return;
}
