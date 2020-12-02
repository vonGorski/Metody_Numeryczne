#include <iostream>

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
        return ( a + b ) / 2;
}

int main() {
    
    
}



