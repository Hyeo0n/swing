#include <iostream>
using namespace std;

// 원 클래스
class Circle {
private:
    double radius; // 반지름

public:
    Circle(double r) : radius(r) {
        cout << endl << endl << "***원 계산기 접속***" << endl << endl;
    }

    ~Circle() {
        cout << endl << endl << "원 계산기 종료...." << endl << endl;
    }

    // 원의 넓이
    double calculate넓이() {
        return 3.14 * radius * radius;
    }

    // 원의 둘레
    double calculate둘레() {
        return 2 * 3.14 * radius;
    }
};

// 원기둥 클래스
class Cylinder {
private:
    double radius; // 반지름
    double height; // 높이

public:
    Cylinder(double r, double h) : radius(r), height(h) {
        cout << endl << endl << "***원기둥 계산기 접속***" << endl << endl;
    }

    ~Cylinder() {
        cout << endl << endl << "원기둥 계산기 종료...." << endl << endl;
    }

    // 원기둥의 부피
    double calculate부피() {
        return 3.14 * radius * radius * height;
    }

    // 원기둥의 겉넓이
    double calculate겉넓이() {
        return 2 * 3.14 * radius * (radius + height);
    }
};

// 구 클래스
class Sphere {
private:
    double radius; // 반지름

public:
    Sphere(double r) : radius(r) {
        cout << endl << endl << "***구 계산기 접속***" << endl << endl;
    }

    ~Sphere() {
        cout << endl << endl << "구 계산기 종료...." << endl << endl;
    }

    // 구의 부피
    double calculate부피() {
        return (4.0 / 3) * 3.14 * radius * radius * radius;
    }

    // 구의 겉넓이
    double calculate겉넓이() {
        return 4 * 3.14 * radius * radius;
    }
};

// 원뿔 클래스
class Cone {
private:
    double radius; // 반지름
    double height; // 높이

public:
    Cone(double r, double h) : radius(r), height(h) {
        cout << endl << endl << "***원뿔 계산기 접속***" << endl << endl;
    }

    ~Cone() {
        cout << endl << endl << "원뿔 계산기 종료...." << endl << endl;
    }

    // 원뿔의 부피
    double calculate부피() {
        return (1.0 / 3) * 3.14 * radius * radius * height;
    }
};

int main() {
    int choice;
    double radius, height;

    while (true) {
        cout << endl << endl;
        cout << "원하는 계산을 선택하세요" << endl;
        cout << "1. 원의 넓이 계산" << endl;
        cout << "2. 원의 둘레 계산" << endl;
        cout << "3. 원기둥의 부피 계산" << endl;
        cout << "4. 원기둥의 겉넓이 계산" << endl;
        cout << "5. 원뿔의 부피 계산" << endl;
        cout << "6. 구의 부피 계산" << endl;
        cout << "7. 구의 겉넓이 계산" << endl;
        cout << "8. 종료" << endl;
        cout << "선택: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1: {
            cout << "반지름 입력: ";
            cin >> radius;
            Circle circle(radius);
            cout << endl << endl << "원의 넓이: " << circle.calculate넓이() << endl << endl;
            break;
        }
        case 2: {
            cout << "반지름 입력: ";
            cin >> radius;
            Circle circle(radius);
            cout << endl << endl << "원의 둘레: " << circle.calculate둘레() << endl << endl;
            break;
        }
        case 3: {
            cout << "반지름 입력: ";
            cin >> radius;
            cout << "높이 입력: ";
            cin >> height;
            Cylinder cylinder(radius, height);
            cout << endl << endl << "원기둥의 부피: " << cylinder.calculate부피() << endl << endl;
            break;
        }
        case 4: {
            cout << "반지름 입력: ";
            cin >> radius;
            cout << "높이 입력: ";
            cin >> height;
            Cylinder cylinder(radius, height);
            cout << endl << endl << "원기둥의 겉넓이: " << cylinder.calculate겉넓이() << endl << endl;
            break;
        }
        case 5: {
            cout << "반지름 입력: ";
            cin >> radius;
            cout << "높이 입력: ";
            cin >> height;
            Cone cone(radius, height);
            cout << endl << endl << "원뿔의 부피: " << cone.calculate부피() << endl << endl;
            break;
        }
        case 6: {
            cout << "반지름 입력: ";
            cin >> radius;
            Sphere sphere(radius);
            cout << endl << endl << "구의 부피: " << sphere.calculate부피() << endl << endl;
            break;
        }
        case 7: {
            cout << "반지름 입력: ";
            cin >> radius;
            Sphere sphere(radius);
            cout << endl << endl << "구의 겉넓이: " << sphere.calculate겉넓이() << endl << endl;
            break;
        }
        case 8:
            return 0;
        default:
            cout << "다시 선택하세요." << endl << endl;
        }
    }

    return 0;
}