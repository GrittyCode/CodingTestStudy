#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Car
{
public:
    string name{};
    float mpg;
    float accerleration;
    int origin;

    Car()
    {
    }
};

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


bool CompareToName(Car A, Car B)
{
    return A.name < B.name;
}

bool ComparToAccerleration(Car A, Car B)
{
    return A.accerleration < B.accerleration;
}

bool ComapreToOriginOrMpg(Car A, Car B)
{
    if(A.origin == B.origin) //?????????? ????? mpg ??
    {
        return A.mpg < B.mpg;   
    }

    //?????? ???????? ?????? ??
    return A.origin < B.origin;

}

void CoutForCarInformation(Car array_Car[], int iter)
{
    for(int i = 0; i < iter; ++i)
    {
        cout << array_Car[i].name << " " << array_Car[i].mpg << " " 
            << array_Car[i].accerleration << " " << array_Car[i].origin;
        cout << endl;
    }
}

int main()
{
    Init();

    int iter;
    cin >> iter;
    Car array_Car[iter];

    //??? ???
    for (int i = 0; i < iter; ++i)
    {
        string name; //????
        float mpg;
        float accerleration;
        int origin;

        //???? ???? ??????
        // cin???? ???? \n?? ???????? ?????? ???????.
        cin.ignore(32767, '\n');
        getline(cin, name);
        cin >> mpg >> accerleration >> origin;

        //?��?? ???? ???? ???
        array_Car[i].name = name;
        array_Car[i].mpg = mpg;
        array_Car[i].accerleration = accerleration;
        array_Car[i].origin = origin;
    }

    sort(array_Car,array_Car + iter,CompareToName);

    cout << "???? ????? ?? : \n";
    CoutForCarInformation(array_Car,iter);

    sort(array_Car, array_Car + iter, ComparToAccerleration);

    cout << "????��? ?? : \n";
    CoutForCarInformation(array_Car,iter);

    sort(array_Car,array_Car + iter, ComapreToOriginOrMpg);

    cout << "???????? ?? => ???? ??\n";
    CoutForCarInformation(array_Car,iter);

    return 0;
}