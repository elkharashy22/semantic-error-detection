#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include<set>

using namespace std;
string coll(int i,int l,string a)
{
    string out;

    while(i<l)
    {
        stringstream ss;
        string s="line";
        char c = a[i];
        ss << c;
        ss >> s;
        out+=s;
        i++;
    }
    return out;

}

string filter(string arr)//ÃãÇ ÈÊÑÌÚ ÈÇáŞíãÉ áæ åæ ÏÇÈíá Ãæ ÇäÊÌÑ Ãæ ÈÊÒæÏ ÕİÑ İí ÇáÃæá ÚáÔÇä äÚÑİ Ãä Ïí ÌãáÉ ãÚÇÏáÉ
{
    bool Int=(arr[4]=='i')&&(arr[5]=='n')&&(arr[6]=='t');
    bool Double=arr[4]=='d'&&arr[5]=='o'&&arr[6]=='u'&&arr[7]=='b'&&arr[8]=='l'&&arr[9]=='e';
    if(Int){
    int i,l=4;
    i=arr.find("t")+1;
    l=arr.find("=");
    if(l==-1){l=arr.size()-1;}
    string out=coll(i,l,arr);
    return out;
    }
    else if(Double)
    {
    int i,l=4;
    i=arr.find("b")+3;
    l=arr.find("=");
    if(l==-1){l=arr.size()-1;}
    string out=coll(i,l,arr);
    return out;

    }
    else
    {
    int i=4,l=4;
    l=arr.find("=");
    if(l==-1){l=arr.size()-1;}
    string out="0";
    out+=coll(i,l,arr);
    return out;
    }
}

int main()
{
    vector<string>input; //ÈíÈŞì İíåÇ ÇáÌãáÉ ßÇãáÉ áÍÏ Çáß";"
  //  vector<string>dec;//ÈíÊÍØ İíåÇ ÇáãÊÛíÑÇÊ
    set<string>sety;//ÚáÔÇä ãßÑÑ Ô ÊÚÑíİ Ãæ ÃÊÃßÏ Ãäí ãÚÑİ ŞÈá ßÏå
    vector<string>semerror;//Ïí Çáí İíåÇ ÇáÃíÑæÑ
    int n=0,co=0;
    cin>>n;
    input.push_back("linr");
    for(int i=0;i<n;i++)
    {
        string s="ddDddD";
        cin>>s;
        int l= s.find(';');

        input[co]+=s;
        if(i+1==n){break;}
        if(l!=-1){input.push_back("linr");co++;}
    }

    for(int i=0;i<input.size();i++)
    {
        int cous=sety.size();
        string lee=filter(input[i]),lee2="0";
      //  cout<<lee<<endl;
       // dec.push_back(lee);

       // sety.insert(lee);
        if(lee[0]!='0')
        {
            lee2+=lee;
            sety.insert(lee2);
            if(cous==sety.size())

            {
                semerror.push_back("this variable was already declared");
            }
            else
            {
                int divv=input[i].find('/');
                if(divv!=-1)
                {
                    string m=input[i];
                    if(m[divv+1]=='0')
                    {
                        semerror.push_back("divide by zero");
                    }
                    else
                    {

                        semerror.push_back("correct");
                    }
                }
                else
                {

                    semerror.push_back("correct");
                }
            }

        }
        else
        {
            sety.insert(lee);

            if(cous==sety.size())
            {
                int divv=input[i].find('/');
                string m=input[i];
                if(m[divv+1]=='0')
                {
                    semerror.push_back("divide by zero");
                }
                else
                {

                    semerror.push_back("correct");
                }
            }
            else
            {
                semerror.push_back("this variable is not declared ");
            }
        }
    }
    for(int i=0;i<semerror.size();i++)
    {
        if(semerror[i]=="correct")
        {
            continue;
        }

	cout<<semerror[i]<< " in line "<<i+1<<endl;
    }
    return 0;
}
