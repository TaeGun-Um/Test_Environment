#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const float PI = 3.14159265358979323846f;
    const float amplitude = 10.0f; // 진폭
    const float frequency = 0.1f; // 주파수
    float time = 0.0f;

    int Count = 0;

    while (Count != 100)
    {
        // sin 함수를 사용하여 y좌표를 계산
        float y = amplitude * sin(frequency * time * 2.0f * PI);

        // 화면에 출력
        cout << "y = " << y << endl;

        // 시간 증가
        time += 0.1f;
        ++Count;
    }

    return 0;
}