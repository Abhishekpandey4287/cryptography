#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;

int main()
{
    char fileName[30];
    char ch;
    fstream fps;
    fstream fpt;
    cout<<"Enter the location, name and extension of file:";
    gets(fileName);
    fps.open(fileName,fstream::out);
    if(!fps)
    {
        cout<<"\nError Occured while openning the source file!";
        return 0;
    }
    fpt.open("tmp.txt",fstream::in);
    if(!fpt)
    {
        cout<<"\n Error occurred while Openning /creating tmp file!";
        return 0;
    }
    while(fpt>>noskipws>>ch)
    {
        ch=ch-100;
        fps<<ch;
    }
    fps.close();
    fpt.close();
    cout<<"\nFile '"<<fileName<<"'Decrypted Successfully!";
    cout<<endl;
    return 0;
}

