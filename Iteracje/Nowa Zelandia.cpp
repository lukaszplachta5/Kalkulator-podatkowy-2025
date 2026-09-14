#include <iostream>

using namespace std;
double dochod, podatek, ietc;

int main()
{ double tablica[]={51342.65,	57379.01,	64666.64,	73505.36,	84095.2,	100439.43,	134623.64,	269247.29,	403870.93};
for (double i=49401; i<=314370; i+=1497) {
        dochod = i;

 //podatek
        if (dochod <= 15600.0) {
        podatek = dochod * 0.105;
        }
        else if (dochod <= 53500.0) {
            podatek = 1638.00 + (dochod - 15600.0) * 0.175;
        }
        else if (dochod <= 78100.0) {
            podatek = 8270.50 + (dochod - 53500.0) * 0.30;
        }
        else if (dochod <= 180000.0) {
            podatek = 15650.50 + (dochod - 78100.0) * 0.33;
        }
        else { // dochod > 180000.0
            podatek = 49277.50 + (dochod - 180000.0) * 0.39;
        }

        //ulga IETC
        double ietc = 0.0;
        if (dochod > 24000.0 && dochod < 70000.0) {
            if (dochod <= 66000.0) {
                ietc = 520.0;
            }
            else {
                ietc = 520.0 - 0.13 * (dochod - 66000.0);
            }
        }

        if (ietc < 0.0) { ietc = 0.0; }

        podatek = podatek - ietc;
        if (podatek < 0.0) { podatek = 0.0; }

        cout << podatek/dochod << endl;


}

        return 0;
}
