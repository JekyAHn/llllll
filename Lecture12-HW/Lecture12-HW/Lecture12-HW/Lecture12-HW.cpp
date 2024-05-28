#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    int count = 0;

    chrono::steady_clock::time_point prev_end = chrono::steady_clock::now();
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    //프로그램 시작시 시간 기록

    int delay_time_ms = 0;

    // 1초 대기를 합니다.
    this_thread::sleep_for(chrono::seconds(1));
    //이대로 반복문이 실행된다면 현재 프로그램이 시작한 시간에 비해 반복문이 빠르게 실행되어
    //delay_time_ms의 계산이 되지 않을 수 있어 첫번째 값의 값이 이상하게 나오는걸 방지

    while (count < 10)
    {
        // 시작 시간과 끝 시간을 기록
        prev_end = end;
        end = chrono::steady_clock::now();

        // 시간 차를 구합니다.
        chrono::steady_clock::duration diff = end - prev_end;
        delay_time_ms = chrono::duration_cast<chrono::milliseconds>(diff).count();

        count++;
        cout << count << "초" << "   dur:" << delay_time_ms << endl;

        // 1초 대기를 합니다.
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    return 0;
}