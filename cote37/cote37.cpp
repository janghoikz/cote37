#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    int previous = 0;
    int current = 0;

    vector<int> num;
    num.clear();

    //curent 함수를 알고있어야 풀기 편함 찾는데 오래걸림
    current = s.find(' ');
    //find는 찾을게 없으면 npos를 리턴함
    while (current != string::npos) {
        string substring = s.substr(previous, current - previous);
        num.push_back(stoi(substring));
        previous = current + 1;
        current = s.find(' ', previous);
    }
    num.push_back(stoi(s.substr(previous, current - previous)));

    //원소 정렬
    sort(num.begin(), num.end());

    //제일낮은거랑 제일높은거를 answer에다가 추가
    answer = to_string(num.front()) + ' ' + to_string(num.back());
    return answer;
}

int main()
{
    string s = "1 2 3 4";
    solution(s);
}