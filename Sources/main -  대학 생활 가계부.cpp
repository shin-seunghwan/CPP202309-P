#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Entry 구조체 정의
struct Entry 
{
    string type;
    double amount;
    string description;
    string date;
};

//Entry 구조체의 벡터
vector<Entry> entries;

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
    Entry newEntry;

    //입력 받은 것에 대해 해당하는 vector에 추가한다.
    //추후 조회, 수정, 삭제 등에 수행할 때 사용된다.

    cout << "1. 수입 또는 지출: ";
    cin >> newEntry.type;

    cout << "2. 금액: ";
    cin >> newEntry.amount;

    // 입력 버퍼 클리어
    getchar();

    cout << "3. 설명: ";
    getline(cin, newEntry.description);
    

    cout << "4. 날짜 (YYYY-MM-DD): ";
    cin >> newEntry.date;

    //새로운 항목을 벡터에 추가
    entries.push_back(newEntry);

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
    for (const auto& entry : entries) {
        if (entry.date.substr(0, 4) == year && entry.date.substr(5, 2) == month && entry.date.substr(8, 2) == day) {
            cout << entry.date << ": " << entry.type << " " << entry.amount << " " << entry.description << endl;
        }
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
    for (const auto& entry : entries) {
        if (entry.date.substr(0, 4) == year && entry.date.substr(5, 2) == month) {
            if (entry.type == "수입") {
                incomeTotal += entry.amount;
            }
            else if (entry.type == "지출") {
                expenseTotal += entry.amount;
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
    for (auto& entry : entries) {
        if (entry.date == date) {
            // 일치하는 항목을 찾았을 때 수정할 항목 선택
            cout << "수정할 항목을 선택하세요 (1. 수입/지출 2. 금액 3. 설명): ";
            int choice;
            cin >> choice;

            // 줄 끝 개행 문자 무시
            cin.ignore();

            // 선택된 항목에 따라 해당 내용을 수정
            switch (choice) {
            case 1:
                cout << "새로운 수입/지출 (수입 또는 지출): ";
                getline(cin, entry.type);
                break;
            case 2:
                cout << "새로운 금액: ";
                cin >> entry.amount;
                cin.ignore();
                break;
            case 3:
                cout << "새로운 설명: ";
                getline(cin, entry.description);
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

void deleteEntry() {
    string date;
    // 사용자에게 삭제할 내역의 날짜를 입력받음
    cout << "삭제할 내역의 날짜를 입력하세요 (YYYY-MM-DD): ";
    cin >> date;

    // dates 벡터를 순회하며 사용자가 입력한 날짜와 일치하는 항목 찾기
    for (size_t i = 0; i < entries.size(); ++i) {
        if (entries[i].date == date) {
            entries.erase(entries.begin() + i);
            cout << "내역이 삭제되었습니다." << endl;
            return;
        }
    }

    // 일치하는 날짜의 항목을 찾지 못한 경우
    cout << "해당 날짜의 내역이 없습니다." << endl;
}


void printMonthTable() {
    string year, month;
    // 사용자에게 출력할 월 테이블의 년도와 월을 입력받음
    cout << "년도를 입력하세요 (YYYY): ";
    cin >> year;
    cout << "월을 입력하세요 (MM): ";
    cin >> month;

    cout << "날짜\t\t타입\t금액\t설명\n";
    cout << "--------------------------------------------\n";

    // dates 벡터를 순회하며 해당 년도와 월에 맞는 항목을 찾아 출력
    for (const auto& entry : entries) {
        if (entry.date.substr(0, 4) == year && entry.date.substr(5, 2) == month) {
            cout << entry.date << "\t" << entry.type << "\t" << entry.amount << "\t" << entry.description << endl;
        }
    }
}