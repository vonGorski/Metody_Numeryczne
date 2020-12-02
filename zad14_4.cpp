// Develop a program using a programming or 
//macro language to implement the random search method.
// Design the subprogram so that it is expressly 
//designed to locate a maximum. 
//Test the program with f(x, y) from Prob. 14.7.
// Use a range of 22 to 2 for both x and y.
#include <iostream>
#include <math.h>
#include <ctime>
#include <climits>
#include <chrono>
#include <thread>
#define ITERACJE 1000
float f(float X, float Y)
{
    // wielomian funkcji
    return 4 * X + 2 * Y + pow(X, 2) - 2 * pow(X, 4) + 2 * X * Y - 3 * pow(Y, 2);
}
// losowanie w zakresie [a b]
float Random(float A, float B)
{
   
   float ans = A + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(B-A)));
   return ans;
}
int main() {
    srand(static_cast <unsigned> (time(0)));
    // zakres -2 do 2
    float MAX = LONG_MIN;
    float maxX, maxY;
    float tempX, tempY, fn;
    for (int i = 0; i < ITERACJE; i++) {
        tempX = Random(-2, 2);
       // std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        tempY = Random(-2, 2);
        fn = f(tempX, tempY);
        if (fn > MAX) {
            MAX = fn;
            maxX = tempX;
            maxY = tempY;
            std::cout << "znalezione nowe maximum  F("
                << maxX << "," << maxY << ") =" << MAX << std::endl;
        }
    }
        std::cout << std::endl;
    std::cout << "Wynik dla " << ITERACJE << "iteracji to " << std::endl;
    std::cout << "F("
        << maxX << "," << maxY << ") =" << MAX << std::endl;
    return 1;
}