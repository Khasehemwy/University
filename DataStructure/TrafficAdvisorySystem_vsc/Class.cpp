#pragma once
#include "includes.h"

// void Citys::scanCityNumber()
// {
//     cin>>this->cityNumber;
// }

Citys::Citys()
{
    //Let input start at 1
    City guard;
    citys.push_back(guard);
    //
}

int Citys::addCityByNumber()
{
    printf("Enter the number of cities : ");
    cin >> this->cityNumber;
    for (int i = 1; i <= cityNumber; i++) {
        this->addCity();
    }
    return 1;
}
int Citys::addCity()
{
    City city;
    printf("Enter city name : ");
    cin >> city.name;
    this->citys.push_back(city);
    this->mp[city.name] = this->citys.size() - 1;
    return 1;
}

int Citys::reviseCityName()
{
    printf("Enter the name of the city to be modified : ");
    string originalName; cin >> originalName;
    if (!mp[originalName]) { printf("Error. Input error\n"); return 0; }
    printf("Enter the modified name : ");
    string reviseName; cin >> reviseName;
    this->citys[mp[originalName]].name = reviseName;
    mp[reviseName] = mp[originalName];
    mp.erase(mp.find(originalName));
    return 1;
}

int Citys::eraseCity()
{
    printf("Enter the name of the deleted city : ");
    string name; cin >> name;
    if (!mp[name]) { printf("Error. Input error\n"); return 0; }
    int indexOfEraseCity=mp[name];
    vector<City>::iterator it=this->citys.begin();
    for(int i=1;i<=indexOfEraseCity;i++)it++;
    this->citys.erase(it);
    mp.erase(mp.find(name));
    return 1;
}

int Citys::addPath()
{
    printf("Enter the start and end of the path:\n(Separate with spaces or newlines)\n");
    string startingPoint, endingPoint;
    cin >> startingPoint >> endingPoint;
    if (!mp[startingPoint]) {
        printf("Error. Starting point does not exist.\n"); return 0;
    }
    if (!mp[endingPoint]) {
        printf("Error. Ending point does not exist.\n"); return 0;
    }
    int startingIndex, endingIndex;
    startingIndex = mp[startingPoint];
    endingIndex = mp[endingPoint];

    printf("Enter the travel mode (1 for airplane and 2 for train)\n");
    int mode; cin >> mode;

    printf("Enter the [distance, cost, time] of the path:\n(Separate with spaces or newlines)\n");
    double distance, cost, time;
    cin >> distance >> cost >> time;

    Path tmpPath;
    tmpPath.startingPoint = startingPoint; tmpPath.endingPoint = endingPoint;
    tmpPath.mode = mode;
    tmpPath.lenth = distance; tmpPath.cost = cost; tmpPath.time = time;

    citys[startingIndex].path[mode].push_back(tmpPath);
    return 1;
}

int Citys::revisePath()
{
    printf("Enter the information of the path to be modified : \n");
    Path targetPath;
    targetPath.inputInfo();
    if (!mp[targetPath.startingPoint]) { return -1; }
    int indexOfCity = mp[targetPath.startingPoint];
    int indexOfPath = this->citys[indexOfCity].findPath(targetPath);
    if (indexOfPath == -1) { return -1; }
    printf("Find the target path.\n");
    printf("Enter the information that needs to be modified for the path : \n");
    targetPath.inputInfo();
    this->citys[indexOfCity].path[targetPath.mode][indexOfPath] = targetPath;
    return 1;
}

int Citys::erasePath()
{
    printf("Enter the information of the path to be Erased : \n");
    Path targetPath;
    targetPath.inputInfo();
    if (!mp[targetPath.startingPoint]) { return -1; }
    int indexOfCity = mp[targetPath.startingPoint];
    int indexOfPath = this->citys[indexOfCity].findPath(targetPath);
    if (indexOfPath == -1) { return -1; }
    printf("Find the target path.\n");
    vector<Path>::iterator it = this->citys[indexOfCity].path[targetPath.mode].begin();
    for (int i = 1; i <= indexOfPath; i++)it++;
    this->citys[indexOfCity].path[targetPath.mode].erase(it);
    return 1;
}

int Citys::listCitys()
{
    printf("* The total number of cities is : ");cout<<this->citys.size()-1<<"\n\n";
    printf("* The list of cities is:\n");
    for(auto &city:this->citys){
        cout<<city.name<<"\n";
    }
    return 1;
}
int Citys::listPathsOfOneCity()
{
    printf("Enter the name of the city to find the path : \n");
    string name;cin>>name;
    if(!mp[name]){printf("Error. Input error\n"); return 0;}
    this->citys[mp[name]].listPaths();
    return 1;
}

struct Int
{
    string name;
    int id;
    double dis;
};
bool operator<(const Int& aa, const Int& bb) { return aa.dis > bb.dis; }
int Citys::findCheapestPath()
{
    printf("Enter the start and end of the path:\n(Separate with spaces or newlines)\n");
    string startingPoint, endingPoint;
    cin >> startingPoint >> endingPoint;
    if (!this->mp[startingPoint]) { return -1; }

    if (this->floydFinished)
    {
        //TODO
    }
    else
    {
        double transitTime[3]={0,2,1};
        for (int mk = 1; mk <= 2; mk++)
        {
            int n = this->citys.size() - 1;
            for (int i = 1; i <= n; i++) {
                this->citys[i].dis[mk] = INF;
                this->citys[i].vis = 0;
                this->citys[i].totalCost=this->citys[i].totalTime=0;
            }
            this->citys[mp[startingPoint]].dis[mk] = 0;

            priority_queue<Int>q; q.push({ startingPoint,mp[startingPoint],0 });
            while (!q.empty())
            {
                Int now = q.top(); q.pop();
                if (this->citys[now.id].vis)continue;
                this->citys[now.id].vis = 1;
                for (auto& to : this->citys[now.id].path[mk]) {
                    if (this->citys[now.id].dis[mk] + to.cost < this->citys[mp[to.endingPoint]].dis[mk]) {
                        this->citys[mp[to.endingPoint]].dis[mk] = this->citys[now.id].dis[mk] + to.cost;
                        this->citys[mp[to.endingPoint]].fromWhichCity = now.name;
                        this->citys[mp[to.endingPoint]].totalCost = this->citys[now.id].totalCost+to.cost;
                        this->citys[mp[to.endingPoint]].totalTime = this->citys[now.id].totalTime+to.time+transitTime[mk];
                        q.push({ to.endingPoint,mp[to.endingPoint],this->citys[mp[to.endingPoint]].dis[mk] });
                    }
                }
            }

            if (mk == 1)printf("The cheapest path from A to B by airplane is : \n");
            if (mk == 2)printf("The cheapest path from A to B by train is : \n");

            if(this->citys[mp[endingPoint]].dis[mk]==INF){
                cout<< "Not exist! \n";continue;
            }

            queue<int>q1; q1.push(mp[endingPoint]);
            vector<string>ans;ans.clear();
            while (!q1.empty())
            {
                int x = q1.front(); q1.pop();
                ans.push_back(this->citys[x].name);
                if (this->citys[mp[this->citys[x].fromWhichCity]].dis[mk] != 0)
                    q1.push(mp[this->citys[x].fromWhichCity]);
            }
            ans.push_back(startingPoint);
            for (int i = ans.size() - 1; i > 0; i--) {
                cout << ans[i] << "->";
            }
            if(!ans.empty()){
                cout << ans[0] << "\n";

                printf("Cost of money : %lf\n",this->citys[mp[endingPoint]].totalCost);
                printf("Cost of time : %lf\n",this->citys[mp[endingPoint]].totalTime);
            }
        }
    }
    return 1;
}
int Citys::findFastestPath()
{
    printf("Enter the start and end of the path : \n(Separate with spaces or newlines)\n");
    string startingPoint, endingPoint;
    cin >> startingPoint >> endingPoint;
    if (!this->mp[startingPoint]) { return -1; }

    if (this->floydFinished)
    {
        //TODO
    }
    else
    {
        double transitTime[3]={0,2,1};
        for (int mk = 1; mk <= 2; mk++)
        {
            int n = this->citys.size() - 1;
            for (int i = 1; i <= n; i++) {
                this->citys[i].dis[mk] = INF;
                this->citys[i].vis = 0;
                this->citys[i].totalCost=this->citys[i].totalTime=0;
            }
            this->citys[mp[startingPoint]].dis[mk] = 0;

            priority_queue<Int>q; q.push({ startingPoint,mp[startingPoint],0 });
            while (!q.empty())
            {
                Int now = q.top(); q.pop();
                if (this->citys[now.id].vis)continue;
                this->citys[now.id].vis = 1;
                for (auto& to : this->citys[now.id].path[mk]) {
                    if (this->citys[now.id].dis[mk] + to.time + transitTime[mk] < this->citys[mp[to.endingPoint]].dis[mk]) {
                        this->citys[mp[to.endingPoint]].dis[mk] = this->citys[now.id].dis[mk] + to.time + transitTime[mk];
                        this->citys[mp[to.endingPoint]].fromWhichCity = now.name;
                        this->citys[mp[to.endingPoint]].totalCost = this->citys[now.id].totalCost+to.cost;
                        this->citys[mp[to.endingPoint]].totalTime = this->citys[now.id].totalTime+to.time+transitTime[mk];
                        q.push({ to.endingPoint,mp[to.endingPoint],this->citys[mp[to.endingPoint]].dis[mk] });
                    }
                }
            }

            if (mk == 1)printf("The fastest path from A to B by airplane is : \n");
            if (mk == 2)printf("The fastest path from A to B by train is : \n");

            if(this->citys[mp[endingPoint]].dis[mk]==INF){
                cout<< "Not exist! \n";continue;
            }

            queue<int>q1; q1.push(mp[endingPoint]);
            vector<string>ans;ans.clear();
            while (!q1.empty())
            {
                int x = q1.front(); q1.pop();
                ans.push_back(this->citys[x].name);
                if (this->citys[mp[this->citys[x].fromWhichCity]].dis[mk] != 0)
                    q1.push(mp[this->citys[x].fromWhichCity]);
            }
            ans.push_back(startingPoint);
            for (int i = ans.size() - 1; i > 0; i--) {
                cout << ans[i] << "->";
            }
            if(!ans.empty()){
                cout << ans[0] << "\n";

                printf("Cost of money : %lf\n",this->citys[mp[endingPoint]].totalCost);
                printf("Cost of time : %lf\n",this->citys[mp[endingPoint]].totalTime);
            }
        }
    }
    return 1;
}

// int  Citys::floyd()
// {
//     int a[100][100];
//     for(int k=1;k<=n;k++){
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=n;j++){
//                 a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
//             }
//         }
//     }
//     return 1;
// }


//*-----------------------------------------------------------------------*/



//************************************************************************/
//*------------------------------City-------------------------------------*/
int City::findPath(Path& targetPath)
//Returns the index of the target path, if it does not exist, return -1.
{
    int mode = targetPath.mode;
    for (int i = 0; i < this->path[mode].size(); i++) {
        auto& checkingPath = path[mode][i];
        if (checkingPath.endingPoint == targetPath.endingPoint
            && checkingPath.lenth == targetPath.lenth
            && checkingPath.cost == targetPath.cost
            && checkingPath.time == targetPath.time)
        {
            return i;
        }
    }
    return -1;
}

int City::listPaths()
{
    vector<string>WayOfTravel;
    WayOfTravel.push_back("guard");////Let vector start at 1
    WayOfTravel.push_back("airplane");
    WayOfTravel.push_back("train");
    for(int i=1;i<WayOfTravel.size();i++)
    {
        cout<<"* The paths to use the "<<WayOfTravel[i]<<" are : \n";
        for(auto& j:this->path[i]){
            cout<<this->name<<" -> "<<j.endingPoint<<" : \n";
            cout<<"The lenth : "<<j.lenth<<"\n";
            cout<<"The cost of money : "<<j.cost<<"\n";
            cout<<"The cost of time : "<<j.time<<"\n\n";
        }
        if(this->path[i].size()==0){
            cout<<"Not exist.\n";
        }
    }
    return 1;
}


//*-----------------------------------------------------------------------*/




//*************************************************************************/
//*------------------------------Path-------------------------------------*/
int Path::inputInfo()
{
    printf("Enter the startingPoint : \n");
    cin >> this->startingPoint;
    printf("Enter the endingPoint : \n");
    cin >> this->endingPoint;
    printf("Enter the travel mode (1 for airplane and 2 for train) : \n");
    cin >> this->mode;
    printf("Enter the lenth : \n");
    cin >> this->lenth;
    printf("Enter the cost of money : \n");
    cin >> this->cost;
    printf("Enter the time : \n");
    cin >> this->time;
    return 0;
}

//*-----------------------------------------------------------------------*/

