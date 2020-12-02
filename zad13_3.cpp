#include <iostream>
#include <math.h>

float f(float X)
{
// wielomian funkcji
return -1.5*pow(X,6) - 2*pow(X,4) +12*X;
}


float GoldenRatioMethod( float a, float b )
{
        // współczynnik k - złotego podziału
        // 0.618...
        float k = ( sqrt( 5 ) - 1 ) / 2;

        // lewa i prawa próbka
        float xL = b - k * ( b - a );
        float xR = a + k * ( b - a );
int i=0;   
       
        // pętla póki nie zostanie spełniony warunek stopu
        //while ( ( b - a ) > EPSILON )
        // petla iteracji
        while (i < 3)
        {
               
       std::cout << "iteracja " << i+1 << std::endl;
       std::cout << "Oblcizone probki:" << std::endl;
       std::cout << xL << "  lewa" << std::endl;
       std::cout << xR << "  prawa" << std::endl;
                 std::cout << "obliczone wartosci funkcji dla probki:" << std::endl;
       std::cout << f(xL) << " f(X) lewa" << std::endl;
       std::cout << f(xR) << " f(X) prawa" << std::endl;
                // porównaj wartości funkcji celu lewej i prawej próbki
                if ( f( xL ) < f( xR ) )
                {
                        // wybierz przedział [a, xR]
                        b = xR;
                        xR = xL;
                        xL = b - k * ( b - a );
                }
                else
                {
                        // wybierz przedział [xL, b]
                        a = xL;
                        xL = xR;
                        xR = a + k * ( b - a );
                }
               i++;
        }

        // zwróć wartość środkową przedziału
        std:: cout << "Wynik:   " << std::endl; 
        return ( a + b ) / 2;
}


int main() {
  
   std::cout << GoldenRatioMethod(0, 2);
        return 1;
}



