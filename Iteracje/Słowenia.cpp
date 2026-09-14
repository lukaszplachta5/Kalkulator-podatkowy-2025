#include <iostream>

using namespace std;
double KW, dochod, skladka_ee, skladka_er, podstawa, podatek;

int main()
{ double tab[]={16721.46,	17201.67,	19583.6,	21886.05,	24665.77,	28037.12,	32076.39,	38310.56,	51349.43,	102698.87,	154048.3};
for (double i=15417; i<=119910; i+=571) {
        dochod=i;

    KW=5260+(19736.99-1.17259*dochod);
    if (KW <5260) {KW=5260;}

    skladka_ee = dochod * 0.226 + 441.7;//przyjêto tak¹ stawkê, poniewa¿ przez po³owe roku podatkowego funkcjonowa³ wzrost stawki o 1%
    double er_rate = 0.166;
    double ee_rate = 0.226;
    double ssc_minbase = 17243.42;

    if (dochod < ssc_minbase) {
            // Dopłata wyrównawcza (ER+EE) płacona przez pracodawcę od różnicy do minimum
            skladka_er = (dochod * er_rate) + ((ssc_minbase - dochod) * (er_rate + ee_rate));
    } else {
            skladka_er = dochod * er_rate;
            }

    podstawa = dochod - KW - skladka_ee;

    if (podstawa < 9210.26) {podatek=podstawa*0.16;} //1473,64
    else if (podstawa >= 9210.26 && podstawa <= 27089)
    {
        podatek = 1473.64+(podstawa-9210.26)*0.26; //6122,11
    }
    else if (podstawa > 27089 && podstawa <= 54178)
    {
        podatek = 6122.11+(podstawa-27089)*0.33; //15061,48
    }
    else if (podstawa > 54178 && podstawa <= 78016.32)
    {
        podatek = 15061.48+(podstawa-54178)*0.39; //24358,42
    }
    else
    {
        podatek = 24358.42+(podstawa-78016.32)*0.50;
    }

        cout  << podatek/dochod << endl;
        cout <<  (podatek+skladka_ee)/dochod << endl;
        cout <<  (skladka_ee+skladka_er+podatek)/(dochod) << endl;

}
        return 0;
}
