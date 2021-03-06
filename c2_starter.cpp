#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

//Setup: Will ask for you to input your name to determine the random
//       air conditions that will affect your distance travelled
void setup(); // (This function has been implemented for you. You do not need to write it.)

//Travel: Moves a certain distance closer to the destination
//        given a velocity (v), an angle a (a), and a time (t)
void travel(double v, double a, double t); // (This function has been implemented for you. You do not need to write it.)

//Radar: Returns the distance and angle to the destination
const double getDistance(); // (This function has been implemented for you. You do not need to write it.)
const double getAngle();    // (This function has been implemented for you. You do not need to write it.)

/* DEFINE ANY OTHER FUNCTIONS HERE */

int main()
{
    setup();

    //Decimal Formatting: fixes numbers to output to exactly 4 decimal places
    cout << fixed;
    cout << setprecision(4);

    //PID Constants (Needs to be changed!)
    double k_p = 10;
    double k_i = 0;
    double k_d = 0;

    //Constant Variables
    const double targetTime = 360;                               //minutes
    const double timeGap = 30;                                   //minutes
    const double targetDistance = sqrt(2700 * 2700 + 900 * 900); //miles

    //State Variables
    double currentTime = 0; //the current time (minutes)

    /* DECLARE OTHER VARIABLES HERE */
    double vel_x;
    double vel_y;
    double velocity;
    double errorTime;

    while (currentTime < targetTime)
    {                           //if the current time has not been 6 hours yet, keep driving
        currentTime += timeGap; //adds 30 minutes to the clock

        //get the amount of time left
        errorTime = targetTime - currentTime;

        //get the components of velocity
        vel_x = getDistance() * cos(getAngle()) / errorTime * k_p;
        vel_y = getDistance() * sin(getAngle()) / errorTime * k_p;

        //calculate the velocity
        velocity = sqrt(pow(vel_x, 2) + pow(vel_y, 2));

        if (abs(getDistance()) > 1)
            travel(velocity, getAngle(), 30); //travel(velocity, angle, time to travel)

                cout
            << "Current Time: " << currentTime << " minutes; Distance Left: "
            << getDistance() << " miles." << endl; //formatting
    }

    return 0;
}