#pragma once
// #include<bits/stdc++.h>
// using namespace std;

class City;
class Citys;
class Path;

class Path {
public:
    int mode;
    string startingPoint, endingPoint;
    double lenth, cost, time;

    int inputInfo();
};

class City {
public:
    string name;
    map<int, vector<Path> >path;
    //map[mode,paths];

    double dis[5];
    double totalCost,totalTime;
    string fromWhichCity;
    int vis;

    int findPath(Path& targetPath);
    int listPaths();
};

class Citys {
    int cityNumber;
    map<string, int>mp;
    int floydFinished = 0;
    // int changed=0;
public:
    vector<City>citys;

    Citys();

    // void scanCityNumber();
    int  addCityByNumber();
    int  addCity();
    int  reviseCityName();
    int  eraseCity();

    int  addPath();
    int  revisePath();
    int  erasePath();

    int  listCitys();
    int  listPathsOfOneCity();

    int  findCheapestPath();
    int  findFastestPath();
    // int  floyd();
};