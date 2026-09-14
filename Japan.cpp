#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    double tablica[]={2773068.23,	2852706.28,	3247722.89,	3629557.63,	4090543.07,	4649643.79,	5319512.71,	6353381.01,	8515732.37,	17031464.74,	25547197.1};
    for (double i=2177962; i<=19885740; i+=94694) {
        double dochod=i;

        //(Employment Income Deduction - EID)
        double eid = 0;
        if (dochod <= 3600000.0) {
            eid = dochod * 0.30 + 80000.0;
            if (eid < 650000.0) eid = 650000.0; // Minimalna gwarantowana kwota potracenia
        }
        else if (dochod <= 6600000.0) {
            eid = dochod * 0.20 + 440000.0;
        }
        else if (dochod <= 8500000.0) {
            eid = dochod * 0.10 + 1100000.0;
        }
        else {
            eid = 1950000.0; // Maksymalne potracenie przychodów powyzej 8.5 mln JPY
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
        double skladka_ee = ssc_pens + ssc_sick + ssc_unemp;

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

        double podatek = c_tax_final + local_tax_final;

        //skladka pracodawcy
        double er_pens = 0.0915 * min(dochod, 7800000.0);
        double er_sick = 0.0500 * min(dochod, 16680000.0);
        double er_unemp = 0.0090 * dochod;
        double er_oth_no_acc = 0.0061 * dochod; // 0.36% skladka na dzieci (bez 0.25% wypadkowego)
        double skladka_er = er_pens + er_sick + er_unemp + er_oth_no_acc;

        cout << podatek/dochod << endl;
        cout << (podatek+skladka_ee)/dochod << endl;
        cout << (skladka_ee+skladka_er+podatek)/(dochod) << endl;
    }
    return 0;
}
