#include <vector>
#include <iostream>
#include <cmath>
#include <map>

//generates the expected points
int main()
{

    std::vector<double> xArr;
    std::vector<double> yArr;
    std::vector<std::pair<int, int>> arr;
    for (int i = 0; i < 20; i++)
    {
        double angle = (i * M_PI) / 10;
        double x = 5 * sin(angle);
        double y = 5 * cos(angle);
        double R_2 = pow(x, 2) + pow(y, 2);
        xArr.push_back(x);
        yArr.push_back(y);
        std::cout << R_2 << std::endl;
    }
    //um why are the values greater than 5 again :(
    // xD cri
    for (auto x : xArr)
    {
        std::cout << x << std::endl;
    }
    std::cout << "ok" << std::endl;
    for (auto y : yArr)
    {
        std::cout << y << std::endl;
    }
}