#include <iostream>
#include <vector>
#include <cmath>

//Testfunktionen als Funktor
class Pol1 {
public:
  double operator()(double x)
  {
    return 3 * x + 2;
  }
};

class Gauss {
public:
  double operator()(double x)
  {
    return 1/(sqrt(M_PI * 2)) * exp(-x*x/2);
  }
};

//berechnet Werte nach Trapezformel von I_0 bis I_N
std::vector<double> trapez(double a, double b, int N) {
  Pol1 f;
  std::vector<double> I(N+1);//Feld mit N+1 Eintraegen
  const double h = b - a;
  I[0] = h/2 *(f(a) + f(b)); 
  for(int k = 1 ; k <= N ; ++k) {
    //...
    I[k] = 0;//setze k-ten Wert im Feld
  }
  return I;
}

int main()
{
  //Testfunktion:
  Pol1 f;
  std::cout << "f(0) = " << f(0) << '\n';
  // berechne Trapezformel fuer f
  std::vector<double> tf = trapez(0.,3.,3);
  std::cout << "#############################################################\n";
  //Ausgabe:
  std::cout << "Trapez:\n";
  for(unsigned int i = 0; i < tf.size() ; ++i) {//Schleife ueber Werte im Feld
    std::cout << "I_" << i <<  " = " << tf[i] << std::endl;  
  }
}
