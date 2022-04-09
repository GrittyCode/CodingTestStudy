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
    if(A.origin == B.origin) //제조구역이 같다면 mpg 비교
    {
        return A.mpg < B.mpg;   
    }

    //의외에는 제조구역 순으로 비교
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

    //입력 반복
    for (int i = 0; i < iter; ++i)
    {
        string name; //오류
        float mpg;
        float accerleration;
        int origin;

        //차종 정보 받아오기
        // cin에서 받아온 \n은 제외해줘 오류를 없애준다.
        cin.ignore(32767, '\n');
        getline(cin, name);
        cin >> mpg >> accerleration >> origin;

        //배열에 차종 정보 입력
        array_Car[i].name = name;
        array_Car[i].mpg = mpg;
        array_Car[i].accerleration = accerleration;
        array_Car[i].origin = origin;
    }

    sort(array_Car,array_Car + iter,CompareToName);

    cout << "차종 알파벳 순 : \n";
    CoutForCarInformation(array_Car,iter);

    sort(array_Car, array_Car + iter, ComparToAccerleration);

    cout << "가속시간 순 : \n";
    CoutForCarInformation(array_Car,iter);

    sort(array_Car,array_Car + iter, ComapreToOriginOrMpg);

    cout << "제조지역 순 => 연비 순\n";
    CoutForCarInformation(array_Car,iter);

    return 0;
}