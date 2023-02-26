#ifndef EXPOZITIE_H_INCLUDED
#define EXPOZITIE_H_INCLUDED
#include"masini.h"
template <class T>
class expozitie
{
    protected:
        vector<T> vandute;
        vector<T> stoc;
        static int nr_vandute;
        static int nr_stoc;
    public:
        expozitie& operator-=(T &ob)
         {
            vandute.push_back(ob);
            nr_stoc--;
            nr_vandute++;
            for(auto p = stoc.begin(); p != stoc.end(); p++)
                if((*p) == ob)
                    stoc.erase(p);
        }
};
template<class T>
int expozitie<T>::nr_stoc = 0;
template <class T>
int expozitie<T>::nr_vandute = 0;
#endif // EXPOZITIE_H_INCLUDED
