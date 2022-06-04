#include<map>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int BinarySearchFromMapList(map<int,string> map, int key_value, int low, int high)
{
    if(low >= high) return -1; //찾는 값의 키가 없을 땐 -1을 돌려준다.

    int mid = (low + high) / 2;
    if(key_value > map[mid][0]) 
}


int main()
{
    map<int,string> map_List;
    int iter;
    cin >> iter;
    for(int i = 0; i < iter; ++i)
    {
        int temp;
        string temp_s;
        cin >> temp;
        getline(cin, temp_s); //문자열 받아주기
        map_List.insert({temp,temp_s});
    } 

    return 0;
}