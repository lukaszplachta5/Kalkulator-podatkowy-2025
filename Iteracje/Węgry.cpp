#include <iostream>

using namespace std;
float skladka_ee, skladka_er, podatek;
float dochod;
int main()
{ double tab[]={5489441.62,	5647089.54,	6429046.73,	7184909.67,	8097455.81,	9204226.54,	10530269.04,	12576868.41,	16857362.28,	33714724.56,	50572086.84};
  for (double i=3374136; i<=39364920; i+=187452) {
            dochod=i;
        skladka_ee=dochod*0.185;
        skladka_er=dochod*0.13;

        podatek=dochod*0.15;

        cout << podatek/dochod << endl;
       cout <<  (podatek+skladka_ee)/dochod << endl;
        cout << (podatek+skladka_ee+skladka_er)/(dochod) << endl;
  }
    return 0;
}
