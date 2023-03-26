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
    cout<<"Enter the name, location and extension of file:";
    gets(fileName);
    fps.open(fileName,fstream::in);
    if(!fps)
    {
        cout<<"\nERROR Occured , openning the source file (to Read)!";
        return 0;
    
    }
    fpt.open("tmp.txt",fstream::out);
    if(!fpt)
    {
        cout<<"\nError Occureed, openning/creating the tmp File! ";
        return 0;
    }

    while(fps>>noskipws>>ch)
    {
        ch=ch+100;
        fpt<<ch;

    }

    fps.close();
    fpt.close();
    fps.open(fileName,fstream::out);
    if(!fps)
    {
        cout<<"\n Error Occured , opening the source File (to write)!";
        return 0;
    }
    fpt.open("tmp.txt", fstream::in);
    if(!fpt)
    {
        cout<<"\n Error occured , Opening the tmp file!";
        return 0;
    }

    while(fpt>>noskipws>>ch)
    {
        fps<<ch;
    }

    fps.close();
    fpt.close();
    cout<<"\nFile '"<<fileName<<"'Encrypted Succesfully!";
    cout<<endl;
    return 0;
}