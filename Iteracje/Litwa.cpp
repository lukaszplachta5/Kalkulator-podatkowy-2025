#include <iostream>

using namespace std;
double KW, skladka_ee, skladka_er, doch_KW;
double podatek, dochod;
int main()
{ double tablica[]={14730.11,	15153.14,	17251.41,	19279.65,	21728.34,	24698.19,	28256.44,	33748.19,	45234.26,	90468.53,	135702.79};
for (double i=12575; i<=105630; i+=503) {
            dochod=i;

            double min_wage=12456;
            if (dochod<=min_wage) {KW=8964;}
            else if (dochod>min_wage && dochod<=28647.48) {KW=8964-0.49*(dochod-min_wage);}
            else if (dochod>28647.48) {KW=4800-0.18*(dochod-7704);}

            if (KW<0) KW=0;
            doch_KW=dochod-KW;

            if (doch_KW<0) {doch_KW=0;}

            if (doch_KW<=126532.8)
                {podatek=doch_KW*0.2;}
            else {podatek=126532.8*0.2+(dochod-126532.8)*0.32;}

            if (dochod<=126532.8)
                {skladka_ee=dochod*0.195;}
            else {skladka_ee=126532.8*0.1252+dochod*0.0698;}

            skladka_er = (dochod * 0.0131) + (dochod * 0.0032);

        cout << podatek/dochod << endl;
        cout <<  (podatek+skladka_ee)/dochod << endl;
        cout << (podatek+skladka_ee+skladka_er)/(dochod) << endl;
}

    return 0;
}
