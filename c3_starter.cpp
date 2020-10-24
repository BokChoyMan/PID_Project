//YOUR NAME:
//LAST UPDATED:

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

//normalizeAngle: returns the inverse tangent aka arctan(y, x)
//note: this angle is normalized to (0, 2pi) instead of (-pi/2, pi/2)
const double normalizeAngle(double x, double y);

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
    const double ANGLE_RAD = M_PI / 180 * 18;
    double targetAngle = ANGLE_RAD;
    double currentTime = 0;
    const double velocity = M_PI;
    // go to circle .cpp

    while (currentPoint < totalPoints)
    {                      //keep revolving if we have not completed 1 revolution
        currentPoint += 1; //move onto next point
        currentTime += timeGap;
        //period is technically our 'target time'

        // x_pos = velocity * cos(errorAngle) * currentTime;
        // y_pos = velocity * sin(errorAngle) * currentTime;
        //increment the angle by 18 degrees each loop
        targetAngle = currentPoint * ANGLE_RAD;
        /*
        Acceleration = Velocity / Time
        Acceleration (for object travelling in circular motion) = Velocity * Velocity / Radius
        Velocity = Distance / Time
        X Position = Velocity * cos(Angle)
        Y Position = Velocity * sin(Angle)
*/
        double angle = ((currentPoint - 1) * M_PI) / 10;
        double errorAngle = normalizeAngle(x_pos, y_pos) - targetAngle;
        x_pos = 5 * sin(angle);
        y_pos = 5 * cos(angle);
        double R_2 = pow(x_pos, 2) + pow(y_pos, 2);
        cout << "errorAngle: " << errorAngle << " radius^2: " << R_2 << endl;
        cout << "(" << x_pos << ", " << y_pos << ")" << endl; //display
    }

    return 0;
}