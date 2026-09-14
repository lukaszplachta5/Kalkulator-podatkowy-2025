#include <iostream>

using namespace std;
double dochod, zdrowotna, ulga_zdr, max_spol, spoleczne, skladka_ee, skladka_er, pod_KW, podstawa, KW, wypadkowa, NTCP_er, podst;
double podatek;
int main()
{double tab[]={15491.51,	15936.4,	18143.13,	20276.22,	22851.47,	25974.84,	29717.01,	35492.62,	47572.42,	95144.83,	142717.25};
for (double i=10051; i<=111090; i+=529) {
            dochod=i;

        //ULGA NA SKLADKE ZDROWOTNA
        if (dochod <= 4560) {
            ulga_zdr = 4560;
        }
        else {
            ulga_zdr = 4560 - 2 * (dochod - 4560);
        }
        if (ulga_zdr < 0) { ulga_zdr = 0; }

        //skladki pracownika (podatkowe)
        float max_spol = 188760.0;
        float podstawa_spol_ee = (dochod < max_spol) ? dochod : max_spol;
        spoleczne = podstawa_spol_ee * 0.094;
        float zdrowotna_base = dochod - ulga_zdr;
        if (zdrowotna_base < 0) { zdrowotna_base = 0; }
        zdrowotna = zdrowotna_base * 0.04;
        float min_health_combined = 273.99 * 0.15 * 12.0; // 493.18 EUR
        if (zdrowotna + dochod * 0.11 < min_health_combined) {
            zdrowotna = min_health_combined - dochod * 0.11;
            if (zdrowotna < 0) { zdrowotna = 0; }
        }

        skladka_ee = zdrowotna + spoleczne;

        //skladki pracodawcy (podatkowe)
        float social_ins_er = (dochod < max_spol) ? dochod * 0.204 : max_spol * 0.204;
        // Wykluczono ubezpieczenie wypadkowe (0.8%)
        skladka_er = social_ins_er + dochod * 0.11;

        //NTCP PRACODAWCY
        float pillar_ii_er = (dochod < max_spol) ? dochod * 0.04 : max_spol * 0.04;
        NTCP_er = pillar_ii_er + dochod * 0.006;

        //KWOTA WOLNA
        pod_KW = dochod - skladka_ee;

        if (pod_KW <= 25426.27) {
            KW = 5753.79; // Maksymalna kwota wolna (21 * MLS)
        }
        else {
            KW = 12110.36 - 0.25 * pod_KW;
        }
        if (KW < 0) { KW = 0; }

        podstawa = pod_KW - KW;
        if (podstawa < 0) { podstawa = 0; }
        podst = podstawa;

        //podatek
        if (podst <= 48441.43) {
            podatek = podst * 0.19;
        }
        else {
            podatek = 48441.43 * 0.19 + (podst - 48441.43) * 0.25;
        }

     //   cout << podatek/dochod << endl;
     //   cout <<  (podatek+skladka_ee)/dochod << endl;
        cout << (podatek+skladka_ee+skladka_er+NTCP_er)/(dochod) << endl;
}
    return 0;
}
