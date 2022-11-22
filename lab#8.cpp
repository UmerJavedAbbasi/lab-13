#include<iostream>
using namespace std;
class Plan
{
    protected:
    double rate;
    
    public:
    void getRate()
    {
        cout<<"Rate is:"<<rate;
    }
    void calculateBill(int units)
    {
        int total=rate*units;
        cout<<"\nYour Bill is:"<<total<<endl;
    }

    void setdomesticrate(double r)
    {
        this->rate=r;        
    }
    void setCommercialrate(double r)
    {
        this->rate=r;        
    }
    void setInstitutionalrate(double r)
    {
        this->rate=r;        
    }

};

class DomesticPlan:public Plan
{
    public:
    DomesticPlan()
    {
        this->rate=10;
    }

};
class CommercialPlan:public Plan
{
    public:
    CommercialPlan()
    {
        this->rate=20;
    }

};
class InstitutionalPlan:public Plan
{
    public:
    InstitutionalPlan()
    {
        this->rate=30;
    }
};
class GetPlanFactory
{
    public:
    Plan getPlan(string plan)
    {
        if(plan == "domestic")
        {
            cout<<"Domestic Plan";
            DomesticPlan p;
            p.calculateBill(5);

        }
        else if(plan == "commercial")
        {
            cout<<"Commercial Plan";
            CommercialPlan p;
            p.calculateBill(5);

        }

        else if(plan == "institutional")
        {
            cout<<"Institutional Plan";
            InstitutionalPlan p;
            p.calculateBill(5);

        }
    }

};
int main()
{
GetPlanFactory obj;
obj.getPlan("domestic");
obj.getPlan("commercial");
obj.getPlan("institutional");


}
