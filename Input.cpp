#include"handle.h"
#include"operation.h"
void Input::findinput(string str)
{
ifstream stdin(str);
if(!stdin.is_open())
{
    cout<<"findinput cerror!"<<endl;
    exit(-1);
}
string tmp;
getline(stdin,tmp);
form.clear();
char*result=NULL;
result=strtok((char*)tmp.c_str()," ");
while(result!=NULL)
{
    form.push_back(result);
    result=strtok(NULL," ");
}
stdin.close();
}

void Input::random_input()
{
//vector<std::any>input;
srand(time(0));
ofstream rinput("rinput.txt");
if(!rinput.is_open())
{
    cout<<"rinputcerror!"<<endl;
    exit(-1);
}
for(int i=0;i<form.size();i++)
{   
    if(form[i].find("int")!=string::npos)
    {
        int p1=form[i].find_first_of(",");
        int p2=form[i].find_first_of(")");
        if(p1==string::npos||p2==string::npos)
        {
            cout<<"form wrong !"<<endl;
            return;
        }
        string str1=form[i].substr(4,p1-4);
        int left=atoi(str1.c_str());
        string str2=form[i].substr(p1+1,p2-p1-1);
        int right=atoi(str2.c_str());
        
        int input1=rand()%(right-left+1)+left;
        rinput<<input1<<endl;
        //cout<<"randominput:"<<input1<<endl;
    }
    else if (form[i].find("char")!=string::npos)
    {   
        //srand(time(0));
        char input2=rand()%58+65;
        while(input2>=91&&input2<=96)
        {
             input2=rand()%58+65;
        } 
        rinput<<input2<<endl;
       // cout<<"charinput"<<input2<<endl;
       
    }
    else if (form[i].find("string")!=string::npos)
    {
         int p1=form[i].find_first_of(",");
        int p2=form[i].find_first_of(")");
        if(p1==string::npos||p2==string::npos)
        {
            cout<<"form wrong !"<<endl;
            return;
        }
        string str1=form[i].substr(7,p1-7);
        int left=atoi(str1.c_str());
        string str2=form[i].substr(p1+1,p2-p1-1);
        int right=atoi(str2.c_str());
        int num=rand()%(right-left+1)+left;
        string  ans;
        for(int i=0;i<num;i++)
        {
              char input3=rand()%58+65;
        while(input3>=91&&input3<=96)
        {
             input3=rand()%58+65;
        }
       ans+=input3;
        }
        rinput<<ans<<endl;
    }

}
rinput.close();
}