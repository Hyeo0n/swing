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

    //������
    Information(string n) : name(n) {}

    //�̸��� ��ȭ��ȣ �߰�(ȸ������)
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

    // �α��� �� �̸��� ��ȭ��ȣ�� ��ġ�ϴ��� Ȯ���ϴ� �Լ�
    bool Check(vector<Information>* members, string* inputName, string* inputTel) {
        for (Information& member : *members) {
            for (auto& pair : member.getNameTel()) {
                if (pair.first == *inputName && pair.second == *inputTel) {
                    return true; //�̸��� ��ȭ��ȣ�� ��ġ�� ���
                }
            }

        }
        return false; //��ġ�ϴ� ���� ���� ���
    }
    //�̹� ��ϵ� ȸ������ Ȯ���ϴ� �Լ�
    bool isRegistered(string newName, string newTel) {
        for (auto& pair : nameTel) {
            if (pair.first == newName && pair.second == newTel) {
                return true; // �̹� ��ϵ� ȸ���� ���
            }
        }
        return false; // ��ϵ��� ���� ȸ���� ���
    }
};

int main(void) {
    vector<Information> members; //ȸ�� ������ ������ ����

    int choice = 0;  //�ʱ� ȭ�� ����
    string name;
    string tel;

    while (true) {
        cout << endl << endl;
        cout << "***** SWING ȸ�� ���� ���� ���α׷� *****";
        cout << endl << endl;
        cout << "1. ȸ������" << endl;
        cout << "2. �α���" << endl;
        cout << "3. ȸ�� ���� ����" << endl;
        cout << "4. ����" << endl << endl;
        cout << "��ȣ�� �Է��ϼ��� : ";
        cin >> choice;
        cout << endl << endl;

        if (choice == 1) {
            cout << endl << endl;
            cout << "***** ȸ�������� �����մϴ� *****" << endl << endl;
            cout << "�̸��� �Է��ϼ��� : ";
            cin >> name;
            cout << endl;
            cout << "��ȭ��ȣ�� �Է��ϼ��� : ";
            cin >> tel;
            cout << endl << endl;

            bool duplicate = false;  //�ߺ� Ȯ��
            for (Information& member : members) {
                if (member.isRegistered(name, tel)) {
                    duplicate = true;
                    cout << "�̹� ��ϵ� �����Դϴ�." << endl;
                    break;
                }
            }
            if (!duplicate) {
                Information newMember(name);
                newMember.addNameTel(name, tel);
                members.push_back(newMember);  //ȸ�� ������ ���Ϳ� �߰�
                cout << "ȸ�������� �Ϸ�Ǿ����ϴ�.";
            }
        }

        else if (choice == 2) {
            cout << endl << endl;
            cout << "***** �α����� �����մϴ� *****" << endl << endl;
            cout << "�̸��� �Է��ϼ��� : ";
            cin >> name;
            cout << endl;
            cout << "��ȭ��ȣ�� �Է��ϼ��� : ";
            cin >> tel;
            cout << endl << endl;

            bool login = false;
            if (Information(name).Check(&members, &name, &tel)) {
                login = true;
                cout << endl << endl;
                cout << "�α����� �Ϸ�Ǿ����ϴ�.";
                cout << endl << endl;
                cout << " ****** SWING " << name << "���� �����մϴ� ******" << endl;
            }
            else {
                cout << "ȸ�� ������ ��ġ���� �ʽ��ϴ�." << endl << endl;
            }
        }
        else if (choice == 3) {
            string newName, newTel;
            cout << endl << endl;
            cout << "***** ȸ�� ���� ������ �����մϴ� *****" << endl << endl;
            cout << "���� ȸ�� ����" << endl;
            cout << "�̸�: ";
            cin >> name;
            cout << endl;
            cout << "��ȭ��ȣ: ";
            cin >> tel;
            cout << endl << endl;
            cout << "���ο� ȸ�� ����" << endl;
            cout << "�̸�: ";
            cin >> newName;
            cout << endl;
            cout << "��ȭ��ȣ: ";
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
                bool found = false;  //Ư�� ������ �����ϴ� �׸��� ã�Ҵ����� ��Ÿ���� ���� ���� �ʱ�ȭ
                for (auto& member : members) {
                    for (auto& pair : member.getNameTel()) {
                        if (pair.first == name && pair.second == tel) {
                            pair.first = newName;
                            pair.second = newTel;
                            found = true; //�����ϴ� �׸� ã��
                            cout << "ȸ�� ���� ������ �Ϸ�Ǿ����ϴ�." << endl << endl;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                }
                if (!found) {
                    cout << "�ش��ϴ� ȸ�� ������ ã�� �� �����ϴ�." << endl;
                }
            }
            else {
                cout << "�̹� ��ϵ� ȸ�� �����Դϴ�." << endl;
            }
        }
        else if (choice == 4) {
            cout << "SWING ȸ�� ���� ���� ���α׷��� �����մϴ�." << endl;
           
        }
        else {
            cout << "��Ȯ�� ��ȣ�� �Է����ּ���." << endl;
            continue;
        }
    }
    return 0;
}
