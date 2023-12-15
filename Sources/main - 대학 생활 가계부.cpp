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

void viewEntry() {
    string year;
    string month;
    string day;

    cout << "년도 입력: ";
    cin >> year;
    cout << "월 입력: ";
    cin >> month;
    cout << "일 입력: ";
    cin >> day;

    //벡터에 관해 반복문을 하기에 size_t, dates.size()로 적어서 사용
    //날짜 문자열에서 substr을 이용해서 해당하는 자릿수를 추출하여 년,월,일을 알아낸다.
    for (size_t i = 0; i < dates.size(); ++i) {
        if (dates[i].substr(0, 4) == year && dates[i].substr(5, 2) == month && dates[i].substr(8, 2) == day);
        cout << dates[i] << ": " << types[i] << " " << amounts[i] << " " << descriptions[i] << endl;
    }
}

void viewMonthTotal() {
    string year, month;
    double incomeTotal = 0, expenseTotal = 0;

    cout << "년도 입력: ";
    cin >> year;
    cout << "월 입력: ";
    cin >> month;

    //반복문을 이용해서 각 항목의 날짜가 사용자가 입력한 년도와 월에 해당하는 지 확인한다.
    //조건문을 이용해서 항목의 날짜가 사용자가 입력한 년도와 월에 해당하면, 해당 항목의 type을 확인하여 추가
    for (size_t i = 0; i < dates.size(); ++i) {
        if (dates[i].substr(0, 4) == year && dates[i].substr(5, 2) == month) {
            if (types[i] == "수입") {
                incomeTotal += amounts[i];
            }
            else if (types[i] == "지출") {
                expenseTotal += amounts[i];
            }
        }
    }
    cout << month << "월 수입 합계: " << incomeTotal << endl;
    cout << month << "월 지출 합계: " << expenseTotal << endl;
}

void editEntry() {
    string date;
    // 사용자에게 수정할 내역의 날짜를 입력받음
    cout << "수정할 내역의 날짜를 입력하세요 (YYYY-MM-DD): ";
    cin >> date;

    // 반복문을 이용해서 dates 벡터를 사용자가 입력한 날짜와 일치하는 항목 찾기
    for (size_t i = 0; i < dates.size(); ++i) {
        if (dates[i] == date) {
            // 일치하는 항목을 찾았을 때 수정할 항목 선택
            cout << "수정할 항목을 선택하세요 (1. 수입/지출 2. 금액 3. 설명): ";
            int choice;
            cin >> choice;

            // 줄 끝 개행 문자 무시
            cin.ignore(); 

            // 선택된 항목에 따라 해당 내용을 수정
            switch (choice) {
            case 1: // 수입/지출 타입 수정
                cout << "새로운 수입/지출 (수입 또는 지출): ";
                getline(cin, types[i]);
                break;
            case 2: // 금액 수정
                cout << "새로운 금액: ";
                cin >> amounts[i];
                cin.ignore(); 
                break;
            case 3: // 설명 수정
                cout << "새로운 설명: ";
                getline(cin, descriptions[i]);
                break;
            default:
                cout << "잘못된 선택입니다." << endl;
                break;
            }
            // 수정이 완료되었음을 알림
            cout << "내역이 수정되었습니다." << endl;
            return;
        }
    }

    // 일치하는 날짜의 항목을 찾지 못한 경우
    cout << "해당 날짜의 내역이 없습니다." << endl;
}