#ifndef MENIU_H_INCLUDED
#define MENIU_H_INCLUDED
#include"masini.h"
#include"expozitie.h"
#include<cstring>
#include<vector>

class meniu
{
    meniu(){}
    meniu & operator=(meniu& ob){return *this;}
    meniu(const meniu& ob){}
    ~meniu(){}
    static meniu* instanta;
    vector<masini_sport*>vms;
    vector<hot_hatch*>vhh;
    vector<cabrio*>vc;
    vector<supersport*>vss;

public:
    static meniu* get_instanta()
    {
        if(!instanta)instanta=new meniu();
        return instanta;
    }
    void adaugarea_unei_masini(string);
    void prezentarea_masinilor_de_la_targ();
    void prezentarea_masinilor_de_un_anumit_tip(string);
    void cautarea_unui_anumit_model(string);
    void cumpararea_unei_masini_supersport(supersport&);
    void afisare_meniu();
};
meniu* meniu::instanta;
void meniu::adaugarea_unei_masini(string tip)
{
    if(tip=="hot-hatch"){vhh.push_back(new hot_hatch());(*vhh.back()).citire();vms.push_back(vhh.back());}
    if(tip=="cabrio"){vc.push_back(new cabrio());(*vc.back()).citire();vms.push_back(vc.back());}
    if(tip=="supersport"){vss.push_back(new supersport());(*vss.back()).citire();vms.push_back(vss.back());}

}
void meniu::prezentarea_masinilor_de_la_targ()
{
    for(auto p=vms.begin();p!=vms.end();p++)(*p)->afisare();
    cout<<endl;
}
void meniu::prezentarea_masinilor_de_un_anumit_tip(string tip)
{
    if(tip=="hot-hatch"){for(auto p=vhh.begin();p!=vhh.end();p++)(*p)->afisare();cout<<endl;}
    if(tip=="cabrio"){for(auto p=vc.begin();p!=vc.end();p++)(*p)->afisare();cout<<endl;}
    if(tip=="supersport"){for(auto p=vss.begin();p!=vss.end();p++)(*p)->afisare();cout<<endl;}
}
 void meniu::cautarea_unui_anumit_model(string s)
 {
    if(s=="hot-hatch")
        {
            hot_hatch *h=new hot_hatch;
            h->citire();
            for(auto p=vhh.begin();p!=vhh.end();p++)
                if((*p)==h)
                    cout<<"Avem masina la targ";
        }
        else if(s=="cabrio")
                {
                    cabrio *c=new cabrio;
                    c->citire();
                    for(auto p=vc.begin();p!=vc.end();p++)if((*p)==c)cout<<"Avem masina la targ";
                }
                else if(s=="supersport")
                        {
                            supersport *ss=new supersport;
                            ss->citire();
                            for(auto p=vss.begin();p!=vss.end();p++)if((*p)==ss)cout<<"Avem masina la targ";
                        }
                            else cout<<"Nu avem acest model la targ!";
 }
 void meniu::cumpararea_unei_masini_supersport(supersport &s)
 {
     for(auto p=vss.begin();p!=vss.end();p++)
        if((**p)==s)
    {
        cout<<"Cumparatorul cere atat: "<<(*p)->get_pret();
        int optiune;
        cout<<endl<<"Va convine pretul?(1-DA;2-NU)"<<endl;cin>>optiune;
        float pret_client;
        while(optiune==2)
     {
         cout<<"Introduceti suma pe care vreti sa o dati: "<<endl;cin>>pret_client;
         (*p)->set_pret(((*p)->get_pret()+pret_client)/2);
         cout<<"Suma este prea mica.Va convine pretul acesta?(1-DA;2-NU)"<<(*p)->get_pret();cin>>optiune;
     }
     expozitie <supersport*>e;
        e-=(*p);
    }


 }
void meniu::afisare_meniu()
{
    int x;
        try{
            cout<<"Bine ati venit la targul nostru de masini!"<<endl;
            cout<<"1.Adauga o masina noua"<<endl;
            cout<<"2.Prezentarea masinilor de la targ"<<endl;
            cout<<"3.Prezentarea tuturor masinilor de un anumit tip(hot-hatch,cabrio sau supersport)"<<endl;
            cout<<"4.Cautarea unei anumite masini"<<endl;
            cout<<"5.Cumpararea unei masini supersport"<<endl;
            cout<<"6.Iesire"<<endl;
            cout<<"Ce doriti?"<<endl;
            cin>>x;
            if(x < 1 || x > 6)
                throw 1;
            }
        catch(...){
            do{
                cout << "Optiunea aleasa trebuie sa fie cuprinsa intre 1 si 6." << endl;
                cout<<"Ce doriti?"<<endl;
                cin>>x;
               }
            while(x < 1 || x > 5);
                   }
            switch(x)
        {
            case 1:
                {
                    string s;
                    cout<<"Ce tip de masina vreti sa adaugati?(Hot-Hatch/Cabrio/Supersport)"<<endl;
                    cin>>s;
                    adaugarea_unei_masini(s);
                    break;
                }
            case 2:
                {
                    prezentarea_masinilor_de_la_targ();
                    break;
                }
            case 3:
                {
                    string s;
                    cout<<"Ce tip de masini vreti sa vedeti?(Hot-Hatch/Cabrio/Supersport)"<<endl;
                    cin>>s;
                    prezentarea_masinilor_de_un_anumit_tip(s);
                    break;
                }
            case 4:
                {
                    string s;
                    cout<<"Ce fel de masina vreti sa cautati?(Hot-Hatch/Cabrio/Supersport)";
                    cin>>s;
                    cautarea_unui_anumit_model(s);
                    break;
                }

            case 5:
                {
                    supersport s;
                    cout<<"Ce masina vreti sa cumparati?"<<endl;
                    s.citire();
                    cumpararea_unei_masini_supersport(s);
                    break;
                }
            case 6:
                {

                        break;
                }
        }
        cout << endl;
        meniu::afisare_meniu();

}
#endif // MENIU_H_INCLUDED
