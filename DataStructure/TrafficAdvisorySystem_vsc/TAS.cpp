#pragma once
#include "includes.h"

int main()
{
    // IOS
    // freopen("./data.in","r",stdin);
    // freopen("./out.out","w",stdout);

    Citys city;
    while (1)
    {
        printf(
            "\n------------------------------\n"
            "Enter number to select function:\n\n"
            );
        printf(
            // "------------------------------\n"
            "1.addCityByNumber\n"
            "2.addCity\n"
            "3.reviseCityName\n"
            "4.eraseCity\n"
            "5.addPath\n"
            "6.revisePath\n"
            "7.erasePath\n"
            "8.findCheapestPath\n"
            "9.findFastestPath\n"
            "10.listCitys\n"
            "11.listPathsOfOneCity\n"
            "\n-1.esc\n"
            "------------------------------\n"
            );
        int opCode; cin >> opCode;
        switch (opCode)
        {
        case 1:
            city.addCityByNumber();
            break;
        case 2:
            city.addCity();
            break;
        case 3:
            city.reviseCityName();
            break;
        case 4:
            city.eraseCity();
            break;
        case 5:
            city.addPath();
            break;
        case 6:
            city.revisePath();
            break;
        case 7:
            city.erasePath();
            break;
        case 8:
            city.findCheapestPath();
            break;
        case 9:
            city.findFastestPath();
            break;
        case 10:
            city.listCitys();
            break;
        case 11:
            city.listPathsOfOneCity();
            break;
        case -1:
            return 0;

        default:
            break;
        }
    }

    return 0;
}