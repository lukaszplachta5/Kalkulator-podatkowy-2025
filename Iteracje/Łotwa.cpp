#include <iostream>

using namespace std;
double KW, skladka_ee, skladka_er, doch_KW;
double podatek, dochod;
int main()
{ double tablica[]={15579.36,	16026.78,	18246.02,	20391.2,	22981.06,	26122.15,	29885.53,	35693.91,	47842.2,	95684.41,	143526.61};
for (double i=9044; i<=111720; i+=532) {
            dochod=i;

                   KW = 6120;

            //Skladki pracownika + Solidarity Tax
        if (dochod <= 105300.0) {
            skladka_ee = dochod * 0.105;
        } else {
            double ssc_empee = 105300.0 * 0.10;
            double health_ins2 = dochod * 0.005;
            double sol_tax_ee = (dochod - 105300.0) * 0.10;
            skladka_ee = ssc_empee + health_ins2 + sol_tax_ee;
        }

            //podatek i KW
            doch_KW=dochod-KW-skladka_ee;
            if (doch_KW<0) {doch_KW=0;}

            if (dochod <= 105300) {
                podatek = doch_KW * 0.255;
            }
            else {
                double sol_tax_ee = (dochod - 105300.0) * 0.10;
            podatek = doch_KW * 0.255 + sol_tax_ee;
            }

            if (dochod > 200000.0) {
            podatek = podatek + (dochod - 200000.0) * 0.03;
        }

            //Skladki pracodawcy
        if (dochod <= 105300.0) {
            skladka_er = dochod * 0.2325;
        }
        else {
            skladka_er = (105300.0 * 0.2325) + ((dochod - 105300.0) * 0.145);
        }

            // Dodanie podatku od ryzyka
            skladka_er = skladka_er + 4.32;


        cout << podatek/dochod << endl;
        cout <<  (podatek+skladka_ee)/dochod << endl;
        cout << (podatek+skladka_ee+skladka_er)/(dochod) << endl;
}

    return 0;
}
