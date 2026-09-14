#include <iostream>

using namespace std;
double dochod, skladka_ee, KW, skladka_er, podstawa;
double podatek, solidarity;
int main()
{double tablica[]={16604.32, 17081.17,	19446.42,	21732.73,	24492.98,	27840.71,	31851.69,	38042.19,	50989.72,	101979.43,	152969.15};
for (double i=12474; i<=119070; i+=567) {
            dochod=i;
        skladka_ee=dochod*0.11;

        if (skladka_ee<4462.15)
            {KW=4462.15;}
        else {KW=skladka_ee;}

        skladka_er=dochod*0.2375;

        podstawa=dochod-KW;
        if (podstawa < 0) {podstawa=0;}

        if (podstawa <= 8059) {
            podatek = podstawa * 0.125;
        }
        else if (podstawa > 8059 && podstawa <= 12160) {
            podatek = 1007.38 + (podstawa - 8059) * 0.16;
        }
        else if (podstawa > 12160 && podstawa <= 17233) {
            podatek = 1663.54 + (podstawa - 12160) * 0.215;
        }
        else if (podstawa > 17233 && podstawa <= 22306) {
            podatek = 2754.24 + (podstawa - 17233) * 0.244;
        }
        else if (podstawa > 22306 && podstawa <= 28400) {
            podatek = 3992.05 + (podstawa - 22306) * 0.314;
        }
        else if (podstawa > 28400 && podstawa <= 41629) {
            podatek = 5905.57 + (podstawa - 28400) * 0.349;
        }
        else if (podstawa > 41629 && podstawa <= 44987) {
            podatek = 10522.49 + (podstawa - 41629) * 0.431;
        }
        else if (podstawa > 44987 && podstawa <= 83696) {
            podatek = 11969.79 + (podstawa - 44987) * 0.446;
        }
        else if (podstawa > 83696) {
            podatek = 29234.00 + (podstawa - 83696) * 0.48;
        }

        double solidarity = 0;
        if (podstawa > 80000 && podstawa <= 250000) {
            solidarity = 0.025 * (podstawa - 80000);
        }
        else if (podstawa > 250000) {
            solidarity = 0.025 * (250000 - 80000) + 0.05 * (podstawa - 250000);
        }
        podatek = podatek + solidarity;

        cout << podatek/dochod << endl;
       cout <<  (podatek+skladka_ee)/dochod << endl;
        cout << (podatek+skladka_ee+skladka_er)/(dochod) << endl;

 }
    return 0;
}
