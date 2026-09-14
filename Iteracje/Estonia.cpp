#include <iostream>

using namespace std;
double skladka_ee, KW, skladka_er;
double podatek, dochod;
int main()
{
        double tablica[] = {17980.69, 18497.07, 21058.38, 23534.21, 26523.26,	30148.49,
	34491.95,	41195.6, 55216.38, 110432.76, 165649.13};

for (double i=11052; i<=128940; i+=614) {
            dochod=i;

        if (dochod<=14400)
            {KW=7848;}
        else if(dochod>14400 && dochod<=25200)
            {KW=7848*(25200-dochod)/10800;}
        else {
            KW=0;}

        skladka_ee=dochod*0.016; //od bezrobocia //nie uwzględniam drugiego filaru, ponieważ jest dobrowolny
        podatek=(dochod-KW-skladka_ee)*0.22;
        if (podatek<0)
        {
            podatek=0;
        }

        skladka_er=dochod*0.338;
        if (dochod<820*12) {skladka_er = dochod*0.008+3247.2;}

       // cout << podatek/dochod << endl;
       //cout <<  (podatek+skladka_ee)/dochod << endl;
        cout << (podatek+skladka_ee+skladka_er)/(dochod) << endl;

}
    return 0;
}
