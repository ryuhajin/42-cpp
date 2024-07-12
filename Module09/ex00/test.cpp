#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <ctime>
#include <iomanip>

bool isValidDate(const std::string& date) {
    std::tm tm = {};
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail() || tm.tm_year < 0 || tm.tm_mon < 0 || tm.tm_mon > 11 || tm.tm_mday < 1 || tm.tm_mday > 31) {
        return false;
    }
    // Attempt to convert the time to see if it's a valid date
    std::mktime(&tm);
    return ss.eof() && tm.tm_year > 0;  // EOF 검사로 형식 외 문자가 없는지 확인
}

bool isValidValue(const std::string& valueStr, float& value) {
    std::istringstream ss(valueStr);
    ss >> value;
    return !ss.fail() && value >= 0 && value <= 1000 && ss.eof();  // 숫자 외에 다른 문자가 없는지도 확인
}

bool parseDateAndValue(const std::string& line, char delimiter, std::string& date, float& value) {
    if (line.find_first_not_of(" \t\n\r") == std::string::npos) {
        // 공백 또는 빈 줄인 경우
        return false;
    }

    std::istringstream ss(line);
    std::string valueStr;
    if (!std::getline(ss, date, delimiter) || !std::getline(ss, valueStr) || !isValidDate(date) || !isValidValue(valueStr, value)) {
        return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    // 기본 파일 파싱 및 검증 로직 이후 사용 예시
    std::string date;
    float value;
    std::string line = "2011-01-03|3.5";
    if (parseDateAndValue(line, '|', date, value)) {
        std::cout << "Date: " << date << ", Value: " << value << std::endl;
    } else {
        std::cout << "Invalid input: " << line << std::endl;
    }
    return 0;
}
