//YOUR NAME:
//LAST UPDATED:

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

/* DEFINE ANY OTHER FUNCTIONS HERE */

int main()
{
    //Decimal Formatting: fixes numbers to output to exactly 2 decimal places
    cout << fixed;
    cout << setprecision(2);

    //PID Constants (Needs to be changed!)
    const double k_p = 0;
    const double k_i = 0;
    const double k_d = 0;

    //Constant Variables
    const double period = 10; //time for 1 revolution
    const double totalPoints = 20;
    const double timeGap = period / totalPoints;
    const double a = M_PI * M_PI / 5; //acceleration is constant for circular motion

    //State Variables
    double currentPoint = 0; //current point

    double x_pos = 5; //current x position
    double y_pos = 0; //current y position

    /* DECLARE OTHER VARIABLES HERE */

    while (currentPoint < totalPoints)
    {                      //keep revolving if we have not completed 1 revolution
        currentPoint += 1; //move onto next point

        /* ADD YOUR IMPLEMENTATION HERE */

        cout << "(" << x_pos << ", " << y_pos << ")" << endl; //display
    }

    return 0;
}