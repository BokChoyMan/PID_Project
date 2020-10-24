//YOUR NAME: Jackie Chen, Shivani Sista, Anushka Lodha
//LAST UPDATED: 10/14/2020

#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

//Setup: Will ask for you to input your name to determine the random
//       road conditions that will affect your distance travelled
void setup(); // (This function has been implemented for you. You do not need to write it.)

//Travel: Moves a certain distance closer to the destination
//        given a velocity (v) and a time (t)
void travel(double v, double t); // (This function has been implemented for you. You do not need to write it.)

//GPS: Returns the distance to the destination
const double gps(); // (This function has been implemented for you. You do not need to write it.)

/* DEFINE ANY OTHER FUNCTIONS HERE */

int main()
{
    //Setup: causes different "temperature" variations for each person
    setup();

    //Decimal Formatting: fixes numbers to output to exactly 2 decimal places
    cout << fixed;
    cout << setprecision(2);

    //PID Constants (Hint: Only 1 of them need to be nonzero!)
    const double k_p = .3;
    const double k_i = 0;
    const double k_d = 0;

    //Constant Variables: variables that do not change (given in Challenge Description)
    const double targetTime = 600;     //minutes
    const double timeGap = 30;         //minutes
    const double targetDistance = 500; //miles

    //State Variables: keeps track of current state
    double currentTime = 0; //the current time (minutes)

    /* DECLARE OTHER VARIABLES HERE */

    while (currentTime < targetTime)
    {
        //cout << currentTime << endl; //if the current time has not been 10 hours yet, keep driving
        currentTime += timeGap; //adds 30 minutes to the clock

        //How far are you from the target time
        double errorTime = targetTime - currentTime;
        double velocity = 500 / 600;
        //When the car is almost at the destination, check how far it is and go exactly that velocity
        if (currentTime == 600)
        {
            //If you are 0.1 miles above or below the target, change the velocity of the car to travel the exact velocity needed.
            if (gps() > 1)
                velocity = gps() / 30;
            else if (gps() < -1)
                velocity = -1 * gps() / 30;
            else
                velocity = 0;
            travel(velocity, 30);
            cout << "Current Time: " << currentTime << " minutes; Distance Left: " << gps() << " miles." << endl;
            continue;
        }
        double errorVelocity = (gps() / errorTime);
        //Take the average velocity and add it to the proportional component
        velocity += errorVelocity * k_p;

        //Travel at
        travel(velocity, errorTime);

        cout << "Current Time: " << currentTime << " minutes; Distance Left: " << gps() << " miles." << endl; //formatting
    }

    return 0;
}