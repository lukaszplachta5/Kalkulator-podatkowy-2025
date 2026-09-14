#include <iostream>


using namespace std;
float dochod, spoleczne, zdrowotna, podatek, skladka_ee, skladka_er, health, social, health_er, social_er;
int main ()
{
    double tablica[] = {379468.79,	390366.53,	444420.91,	496671.47,	559753.07,	636260.84,	727926.22,	869401.56,	1165299.39,	2330598.77,	3495898.16};
for (double i=259160; i<=2721180; i+=12958) {
            dochod=i;

            health=dochod*0.045;
            social=dochod*0.076;
            if (dochod>2234736) {social=2234736*0.076;}
            skladka_ee=health+social;

            health_er=dochod*0.09;
            social_er=dochod*0.248;
            if (dochod>2234736) {social_er=2234736*0.248;}
            skladka_er=health_er+social_er;

            if (dochod>2234736) {
                spoleczne=2234736*0.071;
                zdrowotna=dochod*0.045;
                skladka_ee=spoleczne+zdrowotna;
                skladka_er=2234736*0.248+dochod*0.09;
            }

            if (dochod<=1676052) {
                podatek=dochod*0.15-30840;
            }
            else
            {   podatek=(1676052*0.15)+(dochod-1676052)*0.23-30840;}

            if (podatek<0) {podatek=0;}

        cout << podatek/dochod << endl;
        cout <<  (podatek+skladka_ee)/dochod << endl;
        cout << (podatek+skladka_ee+skladka_er)/(dochod) << endl;

}


return 0;}

