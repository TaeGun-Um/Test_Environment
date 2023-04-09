// 8move.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

// 좌표 구조체
struct Point
{
    float x;
    float y;
};

// 비행기 구조체
struct Airplane
{
    Point position; // 비행기 위치
    Point direction; // 비행기 이동 방향
};

// 비행기를 8자 방향으로 이동하는 함수
void MoveAirplane(Airplane& airplane)
{
    // 비행기 위치 갱신
    airplane.position.x += airplane.direction.x;
    airplane.position.y += airplane.direction.y;

    // 비행기 이동 방향 변경
    if (airplane.position.x < 0 || airplane.position.x > 800) // x축 경계선에 도달한 경우
    {
        airplane.direction.x = -airplane.direction.x; // x축 방향 반전
    }
    else if (airplane.position.y < 0 || airplane.position.y > 600) // y축 경계선에 도달한 경우
    {
        airplane.direction.y = -airplane.direction.y; // y축 방향 반전
    }
}

int main()
{
    Airplane airplane;
    airplane.position.x = 400;
    airplane.position.y = 300;
    airplane.direction.x = 10;
    airplane.direction.y = 10;

    for (int i = 0; i < 100; i++) // 100번 이동
    {
        MoveAirplane(airplane);
        cout << "Airplane position: (" << airplane.position.x << ", " << airplane.position.y << ")" << endl;
    }

    return 0;
}
