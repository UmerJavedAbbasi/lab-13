#include<iostream>
#include<string>
using namespace std;  
class Packing
{
    public:
    int price_;
    string packk="abc";

    string pack()
    {
        cout<<"Packing is:"<<this->packk<<endl;
        return this->packk;
    }
    int price()
    {
        cout<<"Price is:"<<price_<<endl;
        return price_;
    }

};

class CD:public Packing
{
    public:

};

class Company:public CD
{
    public:

};
class Sony:public Company
{
    public:
    Sony()
    {
        this->packk="Sony";
        this->price_=50;
    }   

};

class Samsung:public Company
{
    public:
    Samsung()
    {
        this->packk="Samsung";
        this->price_=60;
    }   

};

class CDType:public CD
{
    public:

};
class CDBuilder:public CDType
{
    public:
    CDType buildSony()
    {
        CDType c;
        c.packk="sony";
        c.price_=50;
        return c;

    }
    CDType buildSamsung()
    {
        CDType c;
        c.packk="Samsug";
        c.price_=60;
        return c;

    }
};


class Builderdemo:public CDBuilder
{
    public:


};

int main()
{
Builderdemo obj;
obj.buildSony();
obj.pack();
obj.price();

Sony s;
s.pack();
s.price();

}