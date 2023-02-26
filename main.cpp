#include <iostream>
#include<cstring>
#include<vector>
#include"meniu.h"
#include"masini.h"
using namespace std;

int main()
{
    meniu *m=meniu::get_instanta();
    m->afisare_meniu();
    return 0;
}
