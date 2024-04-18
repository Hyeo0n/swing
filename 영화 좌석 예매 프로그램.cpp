#include <iostream>
using namespace std;
#pragma warning(push)
#pragma warning(disable:6385)


int main(void)
{


    int a = 0;   // 첫 번째 화면 옵션
    int i;   // 영화관 행
    int j = 0; // 영화관 열
    int seat[10][6] = { 0 }; //10행 6열을 모두 0으로 초기화
    int b = 0; // 예약한 성인 수
    int c = 0; // 예약한 청소년 수
    int total_a = 0; //누적된 예약 성인 수
    int total_c = 0; // 누적된 예약 청소년 수
    int d;  // 예약한 성인 + 청소년 수
    int f; // 바꿀 좌석의 개수
    int rr = 0;
    int oc = 0;
    // 새로운 좌석 행과 열
    int total = 0; // 총 금액



    while (true) {
        cout << endl << endl;
        cout << "**영화 예약 시스템**";
        cout << endl << endl;
        cout << "1. 좌석 예약" << endl;
        cout << "2. 예약 변경" << endl;
        cout << "3. 프로그램 종료" << endl;
        cout << "번호를 입력하세요: ";
        cin >> a;
        cout << endl << endl;
        cout << "번호를 입력하세요:" << a;

        if (a == 1) {
            cout << endl << endl;
            cout << "1 2 3 4 5 6" << endl;
            cout << "-----------" << endl;
            cout << endl;

            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 6; ++j) {
                    cout << seat[i][j] << " ";
                }
                cout << endl; //10행 6열 출력
            }


            cout << endl << "성인(14000원): ";
            cin >> b;
            total_a += b;
            cout << endl;
            cout << endl << "청소년(11000원): ";
            cin >> c;
            total_c += c;
            cout << endl << endl;
            d = b + c;

            for (int e = 0; e < d; ++e)
            {
                while (true) {
                    cout << endl << "몇 열, 몇 번째 좌석을 예약하시겠습니까?" << endl;
                    cin >> j >> i;

                    cout << endl;
                    if ((i >= 1 && i <= 10) && (j >= 1 && j <= 6)) {
                        if (seat[i - 1][j - 1] == 0) {
                            seat[i - 1][j - 1] = 1;

                            cout << "예약되었습니다." << endl;
                            cout << endl;
                            break;
                        }
                        else
                        {
                            cout << "이미 예약되었습니다. 다른 자리를 선택하세요." << endl;

                            continue;
                        }
                    }
                    else {
                        cout << "예약가능한 좌석이 아닙니다." << endl;
                        continue;
                    }
                }
            }
            cout << endl << endl;
            cout << "1 2 3 4 5 6" << endl;
            cout << "-----------" << endl << endl;

            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 6; ++j) {
                    cout << seat[i][j] << " ";
                }
                cout << endl;
            }
        }
        else if (a == 2) {
            cout << endl << endl;
            cout << "1 2 3 4 5 6" << endl;
            cout << "-----------" << endl;
            cout << endl << endl;
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 6; ++j) {
                    cout << seat[i][j] << " ";
                }
                cout << endl;

            }

            cout << "바꿀 좌석의 갯수를 입력하세요: ";
            cin >> f;

            for (int h = 0; h < f; ++h) {

                while (true) {
                    cout << endl << "현재 좌석과 바꿀 좌석을 입력하세요." << endl;
                    cout << "현재 좌석 (N열, M번째): ";
                    cin >> j >> i;

                    if (i >= 1 && i <= 10 && j >= 1 && j <= 6) {
                        if (seat[i - 1][j - 1] == 1) {
                            int rr, oc;
                            cout << "변경 좌석 (n열, m번째): ";
                            cin >> oc >> rr;

                            if (rr >= 1 && rr <= 10 && oc >= 1 && oc <= 6) {
                                if (seat[rr - 1][oc - 1] == 0) {
                                    seat[rr - 1][oc - 1] = 1;
                                    seat[i - 1][j - 1] = 0;
                                    cout << "변경되었습니다." << endl << endl;
                                    break;
                                }
                                else {
                                    cout << "이미 예약된 좌석입니다. 다른 좌석을 선택해주세요." << endl;
                                    continue;
                                }
                            }
                            else {
                                cout << "예약 가능한 좌석이 아닙니다." << endl;
                                continue;
                            }
                        }
                        else {
                            cout << "현재 좌석이 틀렸습니다. 다시 입력하세요." << endl;
                            continue;
                        }
                    }
                    else {
                        cout << "현재 좌석이 예약 가능한 좌석이 아닙니다." << endl;
                        continue;
                    }
                }
            }

            cout << endl << endl;
            cout << "1 2 3 4 5 6" << endl;
            cout << "-----------" << endl << endl;

            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 6; ++j) {
                    cout << seat[i][j] << " ";
                }
                cout << endl;
            }
        }
        else if (a == 3) {

            total = (total_a * 14000) + (total_c * 11000);

            cout << endl << endl;
            cout << "총 " << total << "원입니다." << endl;
            return 0;
        }
        else {
            cout << endl << endl;
            cout << "올바른 숫자를 입력해주세요.";
            continue;
        }
    }

}
