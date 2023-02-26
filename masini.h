#ifndef MASINI_H_INCLUDED
#define MASINI_H_INCLUDED
#include<cstring>
#include<vector>
using namespace std;
class meniu;
class masini_sport
{protected:
    int capacitate;
    int an_fabricatie;
    string nume;
public:
    friend class meniu;
    masini_sport(){capacitate=0;an_fabricatie=2023;nume="";}
    masini_sport(int c,int a,string s){capacitate=c;an_fabricatie=a;nume=s;}
    masini_sport(const masini_sport& ob){capacitate=ob.capacitate;an_fabricatie=ob.an_fabricatie;nume=ob.nume;}
    virtual ~masini_sport(){nume="";}
    virtual void citire()
    {
        cout<<"Numele masinii: ";getline(cin,nume);
        cout<<"Capacitatea motorului: ";cin>>capacitate;
        cout<<"Anul fabricatiei: ";cin>>an_fabricatie;
    }
    virtual void afisare()
    {
        cout<<"Numele masinii: "<<nume<<endl;
        cout<<"Capacitatea motorului: "<<capacitate<<endl;
        cout<<"Anul fabricatiei: "<<an_fabricatie<<endl;
    }
};
class hot_hatch:public masini_sport
{string model_obisnuit;
public:
    friend class meniu;
    hot_hatch():masini_sport(){model_obisnuit="";}
    hot_hatch(int c, int a, string s, string m):masini_sport(c,a,s){model_obisnuit=m;}
    hot_hatch(const hot_hatch& ob):masini_sport(ob){model_obisnuit=ob.model_obisnuit;}
    ~hot_hatch(){model_obisnuit="";};
    bool operator==(const hot_hatch& ob)
    {
        return (nume == ob.nume && capacitate == ob.capacitate && an_fabricatie == ob.an_fabricatie);
    }
    void citire()
    {
        cin.clear(); cin.ignore(256, '\n');
        cout<<"Numele masinii: ";getline(cin,nume);
        cout<<"Capacitatea motorului: ";cin>>capacitate;
        cout<<"Anul fabricatiei: ";cin>>an_fabricatie;
        cin.clear(); cin.ignore(256, '\n');
        cout<<"Modelul din care provine: ";getline(cin,model_obisnuit);
    }
    void afisare()
    {
        cout<<"Numele masinii: "<<nume<<endl;
        cout<<"Capacitatea motorului: "<<capacitate<<endl;
        cout<<"Anul fabricatiei: "<<an_fabricatie<<endl;
        cout<<"Modelul din care provine: "<<model_obisnuit<<endl;
    }
};
class cabrio:public masini_sport
{int tip_acoperis;
public:
    friend class meniu;
    cabrio():masini_sport(){tip_acoperis=0;}
    cabrio(int c,int a,string s,int t):masini_sport(c,a,s){tip_acoperis=t;}
    cabrio(const cabrio& ob):masini_sport(ob){tip_acoperis=ob.tip_acoperis;}
    ~cabrio(){}
    bool operator==(const cabrio& ob)
    {
        return (nume == ob.nume && capacitate == ob.capacitate && an_fabricatie == ob.an_fabricatie&&tip_acoperis==ob.tip_acoperis);
    }
    void citire()
    {
        cin.clear(); cin.ignore(256, '\n');
        cout<<"Numele masinii: ";getline(cin,nume);
        cout<<"Capacitatea motorului: ";cin>>capacitate;
        cout<<"Anul fabricatiei: ";cin>>an_fabricatie;
        cout<<"Tipul acoperisului(1 pentru metalic,2 pentru textil): ";cin>>tip_acoperis;
    }
    void afisare()
    {
        cout<<"Numele masinii: "<<nume<<endl;
        cout<<"Capacitatea motorului: "<<capacitate<<endl;
        cout<<"Anul fabricatiei: "<<an_fabricatie<<endl;
        cout<<"Tipul acoperisului: ";if(tip_acoperis==1)cout<<"Metalic"<<endl;
                                            else cout<<"Material textil"<<endl;
    }
};
class supersport:public masini_sport
{
    int viteza;
    float pret;
public:
    friend class meniu;
    supersport():masini_sport(){pret=-1;}
    supersport(int c,int a, string s, float p):masini_sport(c,a,s){pret=p;}
    supersport(const supersport& ob):masini_sport(ob){pret=ob.pret;}
    ~supersport(){}
    float get_pret(){return pret;}
    void set_pret(float p){pret=p;}
    bool operator==(const supersport& ob)
    {
        return (nume == ob.nume && capacitate == ob.capacitate && an_fabricatie == ob.an_fabricatie&&viteza==ob.viteza);
    }
    void citire()
    {
        cin.clear(); cin.ignore(256, '\n');
        cout<<"Numele masinii: ";getline(cin,nume);
        cout<<"Capacitatea motorului: ";cin>>capacitate;
        cout<<"Anul fabricatiei: ";cin>>an_fabricatie;
        cout<<"Viteza la care ajunge masina: ";cin>>viteza;
        cout<<"Pretul: ";cin>>pret;
    }
    void afisare()
    {
        cout<<"Numele masinii: "<<nume<<endl;
        cout<<"Capacitatea motorului: "<<capacitate<<endl;
        cout<<"Anul fabricatiei: "<<an_fabricatie<<endl;
        cout<<"Viteza maxima: "<<viteza<<endl;
    }
};

#endif // MASINI_H_INCLUDED
