#include <iostream>
double dochod, spoleczne, zdrowotna, podatek, skladka_ee, skladka_er, health, social, health_er, social_er, pensja, x, KW, podatekLOK, podstawa, Dn, ulga_zdr, pod_KW, podst, tax_credit, NTCP_er, solidarity, doch_KW;
int nr_1, plec;
    // Definicja pełnej 27-progowej skali regionalnej dla Hiszpanii
    const float PROGI_LOK[] = {
        0, 12000, 12450, 13000, 13362, 17707, 19005, 21000, 21100, 22000,
        32000, 33007, 35200, 35426, 42000, 52000, 53407, 57320, 60000,
        62000, 72000, 90000, 100000, 120000, 150000, 175000, 200000
    };
    const float STALA_LOK[] = {
        0, 1098.24, 1141.86, 1195.16, 1235.86, 1748.71, 1901.85, 2148.18, 2160.53, 2279.32,
        3750.29, 3902.98, 4253.65, 4291.98, 5486.86, 7349.34, 7617.76, 8391.32, 8942.46,
        9376.59, 11592.26, 15629.04, 17927.16, 22559.39, 29590.93, 35495.54, 41469.48
    };
    const float STAWKI_LOK[] = {
        0.0915, 0.0969, 0.0969, 0.1124, 0.1180, 0.1180, 0.1235, 0.1235, 0.1320, 0.1471,
        0.1516, 0.1599, 0.1699, 0.1817, 0.1862, 0.1907, 0.1977, 0.2057, 0.2171, 0.2216,
        0.2243, 0.2298, 0.2316, 0.2344, 0.2362, 0.2390, 0.2408
    };
    const int ROZMIAR_SKALI = 27;

using namespace std;

int main()
{
 do {
  cout << "KALKULATOR PODATKOWY 2025" << endl;
        cout << "Wybierz panstwo, dla ktorego chcesz policzyc podatek: " << endl;
        cout << "1. Czechy" << endl;
        cout << "2. Estonia" << endl;
        cout << "3. Hiszpania" << endl;
        cout << "4. Izrael" << endl;
        cout << "5. Japonia" << endl;
        cout << "6. Litwa" << endl;
        cout << "7. Lotwa" << endl;
        cout << "8. Nowa Zelandia" << endl;
        cout << "9. Polska" << endl;
        cout << "10. Portugalia" << endl;
        cout << "11. Slowacja" << endl;
        cout << "12. Slowenia" << endl;
        cout << "13. Wegry" << endl;
        cout << "14. Zakonczenie dzialania programu" << endl;
        cout << "Wybierz kraj: ";
        cin >> nr_1;

        switch (nr_1)
        {
            case 1:
               {//Czechy
                cout << "Wprowadz roczne wynagrodzenie brutto (waluta krajowa): ";
                cin >> dochod;

            //składki
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

            //podatek
            if (dochod<=1676052) {
                podatek=dochod*0.15-30840;
            }
            else
            {   podatek=(1676052*0.15)+(dochod-1676052)*0.23-30840;}

            if (podatek<0) {podatek=0;}

                cout << "skladka zdrowotna wynosi: " << skladka_ee << ", a koszt pracodawcy: " << skladka_er << endl;
                cout << "Podatek: " << podatek << endl;
                cout << "Obciazenie podatkowe: " << (podatek)/dochod*100 << "%" << endl;
                cout << "Efektywne opodatkowanie po stronie pracownika: " << (podatek+skladka_ee)/dochod*100 << "%" << endl;
                cout << "Calkowite efektywne opodatkowanie wynagrodzenia: " << (podatek+skladka_ee+skladka_er)/(dochod)*100 << "%" << endl;
                cout << "Klin podatkowy: " << (podatek+skladka_ee+skladka_er)/(dochod+skladka_er)*100 << "%" << endl;
                cout << endl;}
            break;

            case 2:
            {//Estonia
                cout << "Wprowadz roczne wynagrodzenie brutto (waluta krajowa): ";
                cin >> dochod;

                //kwota wolna
                if (dochod<=14400)
                {KW=7848;}
                else if(dochod>14400 && dochod<=25200)
                {KW=7848*(25200-dochod)/10800;}
                else {
                KW=0;}

                //składki
                skladka_ee=dochod*0.016; //od bezrobocia //nie uwzględniam drugiego filaru, ponieważ jest dobrowolny
                skladka_er=dochod*0.338;
                if (dochod<820*12) {skladka_er = dochod*0.008+3247.2;}

                //podatek
                podatek=(dochod-KW-skladka_ee)*0.22;
                if (podatek<0)
                {
                podatek=0;
                }

                cout << "Skladki pracownika wynosza: " << skladka_ee << ", a pracodawcy: " << skladka_er << endl;
                cout <<"Podatek: " << podatek << endl;
                cout << "Obciazenie podatkowe: " << podatek/dochod*100 << "%" << endl;
                cout << "Efektywne opodatkowanie pracownika: " << (podatek+skladka_ee)/dochod*100 << "%" << endl;
                cout << "Calkowite efektywne opodatkowanie wynagrodzenia: " << (podatek+skladka_ee+skladka_er)/(dochod)*100 << "%" << endl;
                cout << "Klin podatkowy: " << (skladka_er+podatek+skladka_ee)/(dochod+skladka_er)*100 << "%" << endl;
                cout << endl;
            }
            break;

            case 3:
            {//Hiszpania
                cout << "Wprowadz roczne wynagrodzenie brutto (waluta krajowa): ";
                cin >> pensja;

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

            //kwota wolna
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

            //podatek krajowy
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

            //podatek regionalny
            int idx = ROZMIAR_SKALI - 1;
            while (idx > 0 && podstawa < PROGI_LOK[idx]) {
                idx--;
            }
            podatekLOK = STALA_LOK[idx] + (podstawa - PROGI_LOK[idx]) * STAWKI_LOK[idx];

            x=podatek+podatekLOK-1035;
            if (x<0) {x=0;}

            cout << "Skladka pracownika wynoszi: " << spoleczne << ", a natomiast skladka pracodawcy wynosi: " << skladka_er << endl;
            cout <<"Podatek: " << x << endl;
            cout << "Obciazenie podatkowe: " << x/pensja*100 << "%" << endl;
            cout << "Obciazenia podatkowo-skladkowe: " << (x+spoleczne)/pensja << endl;
            cout << "Calkowite efektywne opodatkowanie wynagrodzenia: " << (x+spoleczne+skladka_er)/(pensja)*100 << "%" << endl;
            cout << "klin podatkowy: " << (x+spoleczne+skladka_er)/(pensja+skladka_er)*100 << "%" << endl;
            }

            break;

            case 4:
            {//Izrael
                cout << "Wprowadz roczne wynagrodzenie brutto (waluta krajowa): ";
                cin >> dochod;
                cout << "Wybierz płec podatnika w celu wyboru ulgi podatkowej (1 - M, 2 - K, 3 - usredniona ulga): ";
                cin >> plec;

                //ulga podatkowa
                if (plec == 1) {tax_credit = 6534;}
                else if (plec == 2) {tax_credit = 7986;}
                else if (plec == 3) {tax_credit = 7260;}

               //podatek
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
        podatek=podatek-tax_credit;
        if (podatek<0) {podatek=0;}

        //składki (podatkowe)
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

        double base_ntcp = min(dochod, 159792.0);
        double ntcp_ee = base_ntcp * 0.06;  // 6.0% pracownik
        double ntcp_er = base_ntcp * 0.125; // 12.5% pracodawca

        skladka_ee=ssc_ee+ntcp_ee;
        skladka_er=ssc_er+ntcp_er;

                cout << "Skladki pracownika wynosza: " << skladka_ee << ", a pracodawcy: " << skladka_er << endl;
                cout <<"Podatek: " << podatek << endl;
                cout << "Obciazenie podatkowe: " << podatek/dochod*100 << "%" << endl;
                cout << "Efektywne opodatkowanie: " << (podatek+skladka_ee)/dochod*100 << "%" << endl;
                cout << "Calkowite efektywne opodatkowanie wynagrodzenia: " << (podatek+skladka_ee+skladka_er)/(dochod)*100 << "%" << endl;
                cout << "Klin podatkowy: " << (podatek+skladka_ee+skladka_er)/(dochod+skladka_er)*100 << "%" << endl;
                cout << endl;
            }

            break;

            case 5:
            {//Japonia
                cout << "Wprowadz roczne wynagrodzenie brutto (waluta krajowa): ";
                cin >> dochod;

        //(Employment Income Deduction - EID)
        double eid = 0;
        if (dochod <= 3600000.0) {
            eid = dochod * 0.30 + 80000.0;
            if (eid < 650000.0) eid = 650000.0; // Minimalna gwarantowana kwota potr¹cenia
        }
        else if (dochod <= 6600000.0) {
            eid = dochod * 0.20 + 440000.0;
        }
        else if (dochod <= 8500000.0) {
            eid = dochod * 0.10 + 1100000.0;
        }
        else {
            eid = 1950000.0; // Maksymalne potr¹cenie przychodów powy¿ej 8.5 mln JPY
        }

        //Reference Income
        double ref_inc = dochod - eid;
        if (ref_inc < 0) ref_inc = 0;

        //Central Basic Allowance
        double basic_al = 0;
        if (ref_inc <= 1320000.0) {
            basic_al = 950000.0;
        }
        else if (ref_inc <= 3360000.0) {
            basic_al = 880000.0;
        }
        else if (ref_inc <= 4890000.0) {
            basic_al = 680000.0;
        }
        else if (ref_inc <= 6550000.0) {
            basic_al = 630000.0;
        }
        else if (ref_inc <= 23500000.0) {
            basic_al = 580000.0;
        }
        else if (ref_inc <= 24000000.0) {
            basic_al = 480000.0;
        }
        else if (ref_inc <= 24500000.0) {
            basic_al = 320000.0;
        }
        else if (ref_inc <= 25000000.0) {
            basic_al = 160000.0;
        }
        else {
            basic_al = 0.0;
        }

        //Local Basic Allowance
        double local_basic_al = 0;
        if (ref_inc <= 24000000.0) {
            local_basic_al = 430000.0;
        }
        else if (ref_inc <= 24500000.0) {
            local_basic_al = 290000.0;
        }
        else if (ref_inc <= 25000000.0) {
            local_basic_al = 150000.0;
        }
        else {
            local_basic_al = 0.0;
        }

        //składki pracownika
        double ssc_pens = 0.0915 * min(dochod, 7800000.0);    // Emerytalne (limit 7.8 mln)
        double ssc_sick = 0.0500 * min(dochod, 16680000.0);   // Zdrowotne (limit 16.68 mln)
        double ssc_unemp = 0.0055 * dochod;                    // Bezrobocie (nielimitowane)
         skladka_ee = ssc_pens + ssc_sick + ssc_unemp;

        //podatek centralny
        double central_tax_al = basic_al + eid + skladka_ee;
        double central_tax_inc = dochod - central_tax_al;
        if (central_tax_inc < 0) central_tax_inc = 0;

        double c_tax = 0;
        if (central_tax_inc <= 1950000.0) {
            c_tax = central_tax_inc * 0.05;
        }
        else if (central_tax_inc <= 3300000.0) {
            c_tax = central_tax_inc * 0.10 - 97500.0;
        }
        else if (central_tax_inc <= 6950000.0) {
            c_tax = central_tax_inc * 0.20 - 427500.0;
        }
        else if (central_tax_inc <= 9000000.0) {
            c_tax = central_tax_inc * 0.23 - 636000.0;
        }
        else if (central_tax_inc <= 18000000.0) {
            c_tax = central_tax_inc * 0.33 - 1536000.0;
        }
        else if (central_tax_inc <= 40000000.0) {
            c_tax = central_tax_inc * 0.40 - 2796000.0;
        }
        else {
            c_tax = central_tax_inc * 0.45 - 4796000.0;
        }

        // Dodanie surtaxu
        double c_tax_final = c_tax * 1.021;
        if (c_tax_final < 0) c_tax_final = 0;

        //lokalny podatek
        double loc_tax_al = local_basic_al + eid + skladka_ee;
        double local_tax_inc = dochod - loc_tax_al;
        if (local_tax_inc < 0) local_tax_inc = 0;

        double local_tax_excl = 0;
        if (ref_inc > 450000.0) {
            local_tax_excl = local_tax_inc * 0.10 + 4000.0; // Stawka 10% + 4000 JPY ryczaltu
        }

        // Ulga wyrównawcza
        double local_tax_cr = 0;
        if (local_tax_inc > 2000000.0) {
            local_tax_cr = max(2500.0, (50000.0 - (local_tax_inc - 2000000.0)) * 0.05);
        } else {
            local_tax_cr = min(50000.0, local_tax_inc) * 0.05;
        }

        double local_tax_final = local_tax_excl - local_tax_cr;
        if (local_tax_final < 0) local_tax_final = 0;

        podatek = c_tax_final + local_tax_final;

        //skladka pracodawcy
        double er_pens = 0.0915 * min(dochod, 7800000.0);
        double er_sick = 0.0500 * min(dochod, 16680000.0);
        double er_unemp = 0.0090 * dochod;
        double er_oth_no_acc = 0.0061 * dochod; // 0.36% skladka na dzieci (bez 0.25% wypadkowego)
        skladka_er = er_pens + er_sick + er_unemp + er_oth_no_acc;


                cout << "Skladka pracownika wynosi: " << skladka_ee << ", a skladka pracodawcy: " << skladka_er << endl;
                cout << "Podatek: " << podatek << endl;
                cout << "Obciazenie podatkowe: " << podatek/dochod*100 << "%" << endl;
                cout << "Efektywne opodatkowanie pracownika: " << (podatek+skladka_ee)/dochod*100 << "%" << endl;
                cout << "Calkowite efektywne opodatkowanie wynagrodzenia: " << (podatek+skladka_ee+skladka_er)/(dochod)*100 << "%" << endl;
                cout << "Klin podatkowy: " << (podatek+skladka_ee+skladka_er)/(dochod+skladka_er)*100 << "%" << endl;
                cout << endl;
            }
            break;

            case 6:
            {//Litwa
                cout << "Wprowadz roczne wynagrodzenie brutto (waluta krajowa): ";
                cin >> dochod;

            //kwota wolna
            double min_wage=12456;
            if (dochod<=min_wage) {KW=8964;}
            else if (dochod>min_wage && dochod<=28647.48) {KW=8964-0.49*(dochod-min_wage);}
            else if (dochod>28647.48) {KW=4800-0.18*(dochod-7704);}

            if (KW<0) KW=0;

            //podatek
            doch_KW=dochod-KW;
            if (doch_KW<0) {doch_KW=0;}

            if (doch_KW<=126532.8)
                {podatek=doch_KW*0.2;}
            else {podatek=126532.8*0.2+(dochod-126532.8)*0.32;}

            //skladki
            if (dochod<=126532.8)
                {skladka_ee=dochod*0.195;}
            else {skladka_ee=126532.8*0.1252+dochod*0.0698;}

            skladka_er = (dochod * 0.0131) + (dochod * 0.0032);

            cout << "skladka pracownika wynosi: " << skladka_ee << ", a skladka pracodawcy: " << skladka_er << endl;
            cout << "Podatek: " << podatek << endl;
            cout << "Obciazenia podatkowe: " << podatek/dochod*100 << "%" << endl;
            cout << "Efektywne opodatkowanie pracownika: " << (podatek+skladka_ee)/dochod*100 << "%" << endl;
                cout << "Calkowite efektywne opodatkowanie wynagrodzenia: " << (podatek+skladka_ee+skladka_er)/(dochod)*100 << "%" << endl;
            cout << "Klin podatkowy: " << (skladka_ee+skladka_er+podatek)/(dochod+skladka_er)*100 << "%" << endl;
            cout << endl;
            }
            break;

            case 7:
            {//Lotwa
                cout << "Wprowadz roczne wynagrodzenie brutto (waluta krajowa): ";
                cin >> dochod;

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



                cout << "Podatek: " << podatek << endl;
                cout << "Skladka pracownika wynosi: " << skladka_ee << ", a skladka pracodawcy: " << skladka_er << endl;
                cout << "Obciazenia podatkowe: " << (podatek/dochod)*100 << "%" << endl;
                cout << "Efektywne opodatkowanie pracownika: " << (podatek+skladka_ee)/dochod*100 << "%" << endl;
                cout << "Calkowite efektywne opodatkowanie wynagrodzenia: " << (podatek+skladka_ee+skladka_er)/(dochod)*100 << "%" << endl;
                cout << "Klin podatkowy: " << (skladka_ee+skladka_er+podatek)/(dochod+skladka_er)*100 << "%" << endl;
                cout << endl;
            }
            break;

            case 8:
            {//Nowa Zelandia
                cout << "Wprowadz roczne wynagrodzenie brutto (waluta krajowa): ";
                cin >> dochod;

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


                cout << "Skladka pracownika wynosi: 0" << ", a pracodawcy: 0" << endl;
                cout <<"Podatek: " << podatek << endl;
                cout << "Obciazenie podatkowe: " << podatek/dochod*100 << "%" << endl;
                cout << "Efektywne opodatkowanie pracownika: " << podatek/dochod*100 << "%" << endl;
                cout << "Calkowite efektywne opodatkowanie wynagrodzenia: " << (podatek)/(dochod)*100 << "%" << endl;
                cout << "Klin podatkowy: " << (podatek)/dochod*100 << "%" << endl;
                cout << endl;
            }
            break;

            case 9:
            {//Polska
                cout << "Wprowadz roczne wynagrodzenie brutto (waluta krajowa): ";
                cin >> dochod;

            //skladki
            spoleczne=dochod*0.1371;
            if (dochod>260190) {spoleczne=dochod*0.0245+0.1126*260190;}

            zdrowotna=(dochod-spoleczne)*0.09;
            skladka_ee=spoleczne+zdrowotna;
            //nie uwzgledniono skladki wypadkowej
            skladka_er=dochod*0.1995;
            if (dochod>260190) {skladka_er=260190*0.1626+dochod*0.0369;}

            //podatek
            podstawa=dochod-3000-spoleczne;
            if (podstawa<0) {podstawa=0;}

            if (podstawa<=120000)
            {podatek = podstawa*0.12-3600;}
            else if (podstawa>120000)
            {podatek = 10800+(podstawa-120000)*0.32;}

            if (podatek<0) {podatek=0;}

            //solid
            double solid=0;
           double pod_solid=dochod-spoleczne;
            if (pod_solid>1000000) {solid=(pod_solid-1000000)*0.04;}

            podatek=podatek+solid;

                cout << "Podatek: " << podatek << endl;
                cout << "skladka pracownika wynosi: " << skladka_ee << ", a skladka pracodawcy: " << skladka_er << endl;
                cout << "Obciazenia podatkowe: " << podatek/(dochod)*100 << "%" << endl;
                cout << "Efektywne opodatkowanie pracownika: " << (podatek+skladka_ee)/(dochod)*100 << "%" << endl;
                cout << "Calkowite efektywne opodatkowanie wynagrodzenia: " << (podatek+skladka_ee+skladka_er)/(dochod)*100 << "%" << endl;
                cout << "Klin podatkowy: " << (podatek+skladka_er+skladka_ee)/(dochod+skladka_er)*100 << "%" << endl;
                cout << endl;
            }
            break;

            case 10:
            {//Portugalia
                cout << "Wprowadz roczne wynagrodzenie brutto (waluta krajowa): ";
                cin >> dochod;

        //skladki i kwota wolna
        skladka_ee=dochod*0.11;
        if (skladka_ee<4462.15)
            {KW=4462.15;}
        else {KW=skladka_ee;}

        skladka_er=dochod*0.2375;

        //podatek
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

        float solidarity = 0;
        if (podstawa > 80000 && podstawa <= 250000) {
            solidarity = 0.025 * (podstawa - 80000);
        }
        else if (podstawa > 250000) {
            solidarity = 0.025 * (250000 - 80000) + 0.05 * (podstawa - 250000);
        }
        podatek = podatek + solidarity;

                cout << "Skladki pracownika wynosza: " << skladka_ee << ", a pracodawcy: " << skladka_er << endl;
                cout <<"Podatek: " << podatek << endl;
                cout << "Obciazenie podatkowe: " << podatek/dochod*100 << "%" << endl;
                cout << "Efektywne opodatkowanie pracownika: " << (podatek+skladka_ee)/dochod*100 << "5" << endl;
                cout << "Calkowite efektywne opodatkowanie wynagrodzenia: " << (podatek+skladka_ee+skladka_er)/(dochod)*100 << "%" << endl;
                cout << "Klin podatkowy: " << (podatek+skladka_ee+skladka_er)/(dochod+skladka_er)*100 << "%" << endl;
                cout << endl;
            }
            break;

            case 11:
            {//Slowacja
                cout << "Wprowadz roczne wynagrodzenie brutto (waluta krajowa): ";
                cin >> dochod;

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

                cout << "Skladki pracownika wynosza: " << skladka_ee << ", a pracodawcy: " << skladka_er << endl;
                cout << "Podatek: " << podatek << endl;
                cout << "Obciazenie podatkowe: " << podatek/dochod*100 << "%" << endl;
                cout << "Efektywne opodatkowanie pracownika: " << (podatek+skladka_ee)/dochod*100 << "%" << endl;
                cout << "Calkowite efektywne opodatkowanie wynagrodzenia: " << (podatek+skladka_er+NTCP_er+skladka_ee)/(dochod)*100 << "%" << endl;
                cout << "Klin podatkowy: " << (podatek+skladka_er+NTCP_er+skladka_ee)/(dochod+skladka_er+NTCP_er)*100 << "%" << endl;
                cout << endl;
            }
            break;

            case 12:
            {//Slowenia
                cout << "Wprowadz roczne wynagrodzenie brutto (waluta krajowa): ";
                cin >> dochod;

    //kwota wolna
    KW=5260+(19736.99-1.17259*dochod);
    if (KW <5260) {KW=5260;}

    //skladki
    skladka_ee = dochod * 0.226 + 441.7;//przyjeto taka stawke, poniewaz przez polowe roku podatkowego funkcjonowal wzrost stawki o 1%
    double er_rate = 0.166;
    double ee_rate = 0.226;
    double ssc_minbase = 17243.42;

    if (dochod < ssc_minbase) {
            skladka_er = (dochod * er_rate) + ((ssc_minbase - dochod) * (er_rate + ee_rate));
    } else {
            skladka_er = dochod * er_rate;
            }

    //podatek
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

                cout << "Skladki pracownika wynosza: " << skladka_ee << ", a pracodawcy: " << skladka_er << endl;
                cout <<"Podatek: " << podatek << endl;
                cout << "Obciazenie podatkowe: " << podatek/dochod*100 << "%" << endl;
                cout << "Efektywne opodatkowanie pracownika: " << (podatek+skladka_ee)/dochod*100 << "%" << endl;
                cout << "Calkowite efektywne opodatkowanie wynagrodzenia: " << (podatek+skladka_ee+skladka_er)/(dochod)*100 << "%" << endl;
                cout << "Klin podatkowy: " << (podatek+skladka_er+skladka_ee)/(dochod+skladka_er)*100 << "%" << endl;
                cout << endl;
            }
            break;

            case 13:
            {//Wegry
                cout << "Wprowadz roczne wynagrodzenie brutto (waluta krajowa): ";
                cin >> dochod;

                skladka_ee=dochod*0.185;
                skladka_er=dochod*0.13;

                podatek=dochod*0.15;
                cout << "Skladka pracownika wynosi: " << skladka_ee << ", natomiast skladka pracodawcy: " << skladka_er << endl;
                cout << "Podatek: " << podatek << endl;
                cout << "Obciazenie podatkowe: " << (podatek)/dochod*100 << "%" << endl;
                cout << "Efektowne opodatkowanie pracownika: " << (podatek+skladka_ee)/dochod*100 << "%" << endl;
                cout << "Calkowite efektywne opodatkowanie wynagrodzenia: " << (podatek+skladka_ee+skladka_er)/(dochod)*100 << "%" << endl;
                cout << "Klin podatkowy: " << (podatek+skladka_ee+skladka_er)/(dochod+skladka_er)*100 << "%" << endl;
                cout<< endl;
            }
            break;}


 } while (nr_1!=14);
    return 0;
}
