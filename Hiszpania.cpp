#include <iostream>

using namespace std;
double x;
double pensja, spoleczne, zdrowotna, KW, podatek, podatekLOK, podstawa, Dn, skladka_er;
      // Definicja pelnej 27-progowej skali regionalnej
    const double PROGI_LOK[] = {
        0, 12000, 12450, 13000, 13362, 17707, 19005, 21000, 21100, 22000,
        32000, 33007, 35200, 35426, 42000, 52000, 53407, 57320, 60000,
        62000, 72000, 90000, 100000, 120000, 150000, 175000, 200000
    };
    const double STALA_LOK[] = {
        0, 1098.24, 1141.86, 1195.16, 1235.86, 1748.71, 1901.85, 2148.18, 2160.53, 2279.32,
        3750.29, 3902.98, 4253.65, 4291.98, 5486.86, 7349.34, 7617.76, 8391.32, 8942.46,
        9376.59, 11592.26, 15629.04, 17927.16, 22559.39, 29590.93, 35495.54, 41469.48
    };
    const double STAWKI_LOK[] = {
        0.0915, 0.0969, 0.0969, 0.1124, 0.1180, 0.1180, 0.1235, 0.1235, 0.1320, 0.1471,
        0.1516, 0.1599, 0.1699, 0.1817, 0.1862, 0.1907, 0.1977, 0.2057, 0.2171, 0.2216,
        0.2243, 0.2298, 0.2316, 0.2344, 0.2362, 0.2390, 0.2408
    };
    const int ROZMIAR_SKALI = 27;

int main ()
{
    double tablica[]={17395,	17894.56,	20372.44,	22767.62,	25659.31,	29166.46,	33368.43,	39853.72,	53417.8,	106835.6,	160253.4};
for (double i=16632; i<=124740; i+=594) {
            pensja=i;

            //SKLADKI
            if (pensja <= 16574.40) {
                spoleczne = 16574.40 * 0.0648;
                skladka_er = 16574.40 * 0.3057;
            }
            else if (pensja > 16574.40 && pensja <= 58914.00) {
                spoleczne = pensja * 0.0648;
                skladka_er = pensja * 0.3057;
            }
            else if (pensja > 58914.00) {
                spoleczne = 58914.00 * 0.0648;
                skladka_er = 58914.00 * 0.3057;
            }


            Dn=pensja-spoleczne;
            if (Dn <= 14852.00) {
                KW = 7302.00;
            }
            else if (Dn > 14852.00 && Dn <= 17673.52) {
                KW = 7302.00 - (Dn - 14852.00) * 1.75;
            }
            else if (Dn > 17673.52 && Dn <= 19748.00) {
                KW = 2364.34 - (Dn - 17673.52) * 1.14;
            }
            else {
                KW = 0.00;
            }

            podstawa=pensja-spoleczne-2000-KW;
            if (podstawa<0) {
                podstawa=0;
            }

            if (podstawa <= 12450)
            {
                podatek = podstawa * 0.095;
            }
            else if (podstawa > 12450 && podstawa <= 20200)
            {
                podatek = 1182.75 + (podstawa - 12450) * 0.12;
            }
            else if (podstawa > 20200 && podstawa <= 35200)
            {
                podatek = 2112.75 + (podstawa - 20200) * 0.15;
            }
            else if (podstawa > 35200 && podstawa <= 60000)
            {
                podatek = 4362.75 + (podstawa - 35200) * 0.185;
            }
            else if (podstawa > 60000 && podstawa <= 300000)
            {
                podatek = 8950.75 + (podstawa - 60000) * 0.225;
            }
            else if (podstawa > 300000)
            {
                podatek = 62950.75 + (podstawa - 300000) * 0.245;
            }

            int idx = ROZMIAR_SKALI - 1;
            while (idx > 0 && podstawa < PROGI_LOK[idx]) {
                idx--;
            }
            podatekLOK = STALA_LOK[idx] + (podstawa - PROGI_LOK[idx]) * STAWKI_LOK[idx];


            x=podatek+podatekLOK-1035;
            if (x<0) {x=0;}


        //cout << x/pensja << endl;
      // cout <<  (x+spoleczne)/pensja << endl;
        cout << (x+spoleczne+skladka_er)/(pensja) << endl;
}

           return 0;
}
