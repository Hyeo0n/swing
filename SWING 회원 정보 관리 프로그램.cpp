#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Information {
private:
    string name;
    string tel;
    vector<pair<string, string>> nameTel;
public:

    //생성자
    Information(string n) : name(n) {}

    //이름과 전화번호 추가(회원가입)
    void addNameTel(string newName, string newTel) {
        nameTel.push_back(make_pair(newName, newTel));
    }

    string getName() {
        return name;
    }
    string getTel() {
        return tel;
    }
    vector<pair<string, string>>& getNameTel() {
        return nameTel;
    }

    // 로그인 시 이름과 전화번호가 일치하는지 확인하는 함수
    bool Check(vector<Information>* members, string* inputName, string* inputTel) {
        for (Information& member : *members) {
            for (auto& pair : member.getNameTel()) {
                if (pair.first == *inputName && pair.second == *inputTel) {
                    return true; //이름과 전화번호가 일치한 경우
                }
            }

        }
        return false; //일치하는 정보 없는 경우
    }
    //이미 등록된 회원인지 확인하는 함수
    bool isRegistered(string newName, string newTel) {
        for (auto& pair : nameTel) {
            if (pair.first == newName && pair.second == newTel) {
                return true; // 이미 등록된 회원인 경우
            }
        }
        return false; // 등록되지 않은 회원인 경우
    }
};

int main(void) {
    vector<Information> members; //회원 정보를 저장할 벡터

    int choice = 0;  //초기 화면 선택
    string name;
    string tel;

    while (true) {
        cout << endl << endl;
        cout << "***** SWING 회원 정보 관리 프로그램 *****";
        cout << endl << endl;
        cout << "1. 회원가입" << endl;
        cout << "2. 로그인" << endl;
        cout << "3. 회원 정보 수정" << endl;
        cout << "4. 종료" << endl << endl;
        cout << "번호를 입력하세요 : ";
        cin >> choice;
        cout << endl << endl;

        if (choice == 1) {
            cout << endl << endl;
            cout << "***** 회원가입을 진행합니다 *****" << endl << endl;
            cout << "이름을 입력하세요 : ";
            cin >> name;
            cout << endl;
            cout << "전화번호를 입력하세요 : ";
            cin >> tel;
            cout << endl << endl;

            bool duplicate = false;  //중복 확인
            for (Information& member : members) {
                if (member.isRegistered(name, tel)) {
                    duplicate = true;
                    cout << "이미 등록된 정보입니다." << endl;
                    break;
                }
            }
            if (!duplicate) {
                Information newMember(name);
                newMember.addNameTel(name, tel);
                members.push_back(newMember);  //회원 정보를 벡터에 추가
                cout << "회원가입이 완료되었습니다.";
            }
        }

        else if (choice == 2) {
            cout << endl << endl;
            cout << "***** 로그인을 진행합니다 *****" << endl << endl;
            cout << "이름을 입력하세요 : ";
            cin >> name;
            cout << endl;
            cout << "전화번호를 입력하세요 : ";
            cin >> tel;
            cout << endl << endl;

            bool login = false;
            if (Information(name).Check(&members, &name, &tel)) {
                login = true;
                cout << endl << endl;
                cout << "로그인이 완료되었습니다.";
                cout << endl << endl;
                cout << " ****** SWING " << name << "님을 응원합니다 ******" << endl;
            }
            else {
                cout << "회원 정보가 일치하지 않습니다." << endl << endl;
            }
        }
        else if (choice == 3) {
            string newName, newTel;
            cout << endl << endl;
            cout << "***** 회원 정보 수정을 진행합니다 *****" << endl << endl;
            cout << "현재 회원 정보" << endl;
            cout << "이름: ";
            cin >> name;
            cout << endl;
            cout << "전화번호: ";
            cin >> tel;
            cout << endl << endl;
            cout << "새로운 회원 정보" << endl;
            cout << "이름: ";
            cin >> newName;
            cout << endl;
            cout << "전화번호: ";
            cin >> newTel;
            cout << endl << endl;

            bool duplicate = false;
            for (Information& member : members) {
                if (member.isRegistered(newName, newTel)) {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate) {
                bool found = false;  //특정 조건을 만족하는 항목을 찾았는지를 나타내기 위한 변수 초기화
                for (auto& member : members) {
                    for (auto& pair : member.getNameTel()) {
                        if (pair.first == name && pair.second == tel) {
                            pair.first = newName;
                            pair.second = newTel;
                            found = true; //만족하는 항목 찾음
                            cout << "회원 정보 수정이 완료되었습니다." << endl << endl;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                }
                if (!found) {
                    cout << "해당하는 회원 정보를 찾을 수 없습니다." << endl;
                }
            }
            else {
                cout << "이미 등록된 회원 정보입니다." << endl;
            }
        }
        else if (choice == 4) {
            cout << "SWING 회원 정보 관리 프로그램을 종료합니다." << endl;
            return 0;
        }
        else {
            cout << "정확한 번호를 입력해주세요." << endl;
            continue;
        }
    }
    return 0;
}
