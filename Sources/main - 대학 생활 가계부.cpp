#include <iostream>
#include <vector>
#include <string>
using namespace std;

//각 데이터 유형을 위해 벡터 선언
vector<string> types;
vector<double> amounts;
vector<string> descriptions;
vector<string> dates;

void addEntry();
void viewEntry();
void viewMonthTotal();
void editEntry();
void deleteEntry();
void printMonthTable();


// 메인 메뉴 출력 및 사용자 선택
int mainMenu() {
    int choice;
    cout << "1. 내역 추가\n";
    cout << "2. 내역 조회\n";
    cout << "3. 월별 합계 조회\n";
    cout << "4. 내역 수정\n";
    cout << "5. 내역 삭제\n";
    cout << "6. 내역 보기\n";
    cout << "7. 종료\n";
    cout << "선택: ";
    cin >> choice;
    return choice;
}

// 메인 함수 반복문
int main() {
    int choice;
    do {
        choice = mainMenu();
        switch (choice) {
            // 각 기능에 대한 함수 호출
        case 1:
            addEntry();
            break;
        case 2:
            viewEntry();
            break;
        case 3:
            viewMonthTotal();
            break;
        case 4:
            editEntry();
            break;
        case 5:
            deleteEntry();
            break;
        case 6:
            printMonthTable();
            break;
        case 7:
            cout << "프로그램을 종료합니다." << std::endl;
            break;
        default:
            cout << "잘못된 선택입니다. 다시 시도해주세요." << std::endl;
        }
    } while (choice != 7); // 7번을 선택하면 프로그램 종료

    return 0;
}

void addEntry() {
    string type;
    double amount;
    string description;
    string date;

    //입력 받은 것에 대해 해당하는 vector에 추가한다.
    //추후 조회, 수정, 삭제 등에 수행할 때 사용된다.
    
    cout << "1. 수입 또는 지출: ";
    cin >> type;
    types.push_back(type);

    cout << "2. 금액: ";
    cin >> amount;
    amounts.push_back(amount);

    // 입력 버퍼 클리어
    getchar();

    cout << "3. 설명: ";
    getline(cin, description);
    descriptions.push_back(description);

    cout << "4. 날짜 (YYYY-MM-DD): ";
    cin >> date;
    dates.push_back(date);

    cout << "내역이 추가되었습니다.\n";
}
