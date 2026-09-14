#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

double tax_credit, dochod, podatek;
double tablica[]={107884.17,	110982.43,	126350.26,	141205.25,	159139.55,	180890.95,	206951.71,	247173.59,	331298.27,	662596.53,	993894.8};
int main()
{
    for(double i=73680; i<=773640; i+=3684) {
    dochod=i;

        //PIT
        if (dochod <= 84120.0) {
            podatek = dochod * 0.10;
        }
        else if (dochod <= 120720.0) {
            podatek = 8412.00 + (dochod - 84120.0) * 0.14;
        }
        else if (dochod <= 193800.0) {
            podatek = 13536.00 + (dochod - 120720.0) * 0.20;
        }
        else if (dochod <= 269280.0) {
            podatek = 28152.00 + (dochod - 193800.0) * 0.31;
        }
        else if (dochod <= 560280.0) {
            podatek = 51550.80 + (dochod - 269280.0) * 0.35;
        }
        else if (dochod <= 721560.0) {
            podatek = 153400.80 + (dochod - 560280.0) * 0.47;
        }
        else { // dochod > 721560.0
            podatek = 229202.40 + (dochod - 721560.0) * 0.50;
        }

        // ulga dla mezczyzn (6534 ILS), dla kobiet (7986 ILS)
        tax_credit = 7260;
        podatek=podatek-tax_credit;
        if (podatek<0) {podatek=0;}

        //skladki
        double ssc_ee = 0.0;
        if (dochod <= 90264.0) {
            ssc_ee = dochod * 0.0427;
        } else {
            ssc_ee = (90264.0 * 0.0427) + (min(dochod, 608340.0) - 90264.0) * 0.1217;
        }

        double ssc_er = 0.0;
        if (dochod <= 90264.0) {
            ssc_er = dochod * 0.0451;
        } else {
            ssc_er = (90264.0 * 0.0451) + (min(dochod, 608340.0) - 90264.0) * 0.0760;
        }

        //NTCP
        double base_ntcp = min(dochod, 159792.0);
        double ntcp_ee = base_ntcp * 0.06;  // 6.0% pracownik
        double ntcp_er = base_ntcp * 0.125; // 12.5% pracodawca

        double skladka_ee=ssc_ee+ntcp_ee;
        double skladka_er=ssc_er+ntcp_er;


        cout <<  podatek/dochod << endl;
        cout << (podatek+skladka_ee)/dochod << endl;
        cout << (skladka_ee+skladka_er+podatek)/(dochod) << endl;

    }

    return 0;
}
