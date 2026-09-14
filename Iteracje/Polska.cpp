#include <iostream>

using namespace std;
double dochod, spoleczne, podstawa, podatek, zdrowotna, skladka_er, skladka_ee, solid, pod_solid;
int main()
{double tablica[]={55992,	57600,	65575.92,	73285.68,	82593.6,	93882.6,	107408.16,	128283.36,	171944.16,	343888.32,	515832.48};
for (double i=57360; i<=401520; i+=1912) {
            dochod=i;
            spoleczne=dochod*0.1371;
            if (dochod>260190) {spoleczne=dochod*0.0245+0.1126*260190;}

            zdrowotna=(dochod-spoleczne)*0.09;
            //nie uwzgledniono skladki wypadkowej
            skladka_er=dochod*0.1995;
            if (dochod>260190) {skladka_er=260190*0.1626+dochod*0.0369;}

            podstawa=dochod-3000-spoleczne;
            if (podstawa<0) {podstawa=0;}

            if (podstawa<=120000)
            {podatek = podstawa*0.12-3600;}
            else if (podstawa>120000)
            {podatek = 10800+(podstawa-120000)*0.32;}

            if (podatek<0) {podatek=0;}

            skladka_ee=spoleczne+zdrowotna;

            //solid
            solid=0;
            pod_solid=dochod-spoleczne;
            if (pod_solid>1000000) {solid=(pod_solid-1000000)*0.04;}

            podatek=podatek+solid;

            cout << (podatek+skladka_er+skladka_ee)/(dochod) << endl;
            cout << (skladka_ee+podatek)/dochod << endl;
            cout << podatek/dochod << endl;

}


    return 0;
}
