#include <string>
#include <iostream>

using namespace std;

#define    NUMS    13

string toRoman(unsigned int num)
{
    int p = NUMS;
    unsigned int a_num[NUMS] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
    const char* r_num[NUMS] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };

    
    string str = "";
    while (p--)
        while (num >= a_num[p])
        {
            num -= a_num[p];
            str += r_num[p];
        }

    return str;
}

int toArabic(string str) {
    int ArNum = 0;
    for (int index = 0; index <= str.length(); ++index) {
        if (str[index] == 'I' && str[index + 1] == 'V') {
            ArNum += 4;
        }
        else if (str[index] == 'I' && str[index + 1] != 'X') { //del str[index + 1] != 'V'
            ++ArNum;
        }else
        if (str[index] == 'I' && str[index + 1] == 'X') {
            ArNum += 9;
        }else
        if (str[index] == 'X' && str[index + 1] == 'L') {
            ArNum += 40;
        }else
        if (str[index] == 'X' && str[index + 1] == 'C') {
            ArNum += 90;
        }else
        if (str[index] == 'C' && str[index + 1] == 'D') {
            ArNum += 400;
        }else
        if (str[index] == 'C' && str[index + 1] == 'M') {
            ArNum += 900;
        }
        else {
            int pos = -1; // символ не найден
            unsigned int a_num[NUMS] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
            const char* r_num[NUMS] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
            for (int i = 0; i < NUMS; i++){
                if (r_num[i] == str[index])
                {
                    pos = i;
                    break;
                }
            }
            ArNum += a_num[pos];
        }
    }
    return ArNum;
}


int main(void)
{
    setlocale(LC_ALL, "ru");
    unsigned int ArNum;    //объявляем переменные
    string RoNum;
    cout << "Введите арабское число: ";
    cin >> ArNum;
    cout << "\nВведите Римское число: ";
    cin >> RoNum;
    cout << endl;
    cout << ArNum << " : " << toRoman(ArNum) << endl;
    cout << RoNum << " : " << toArabic(RoNum) << endl;
    return 0;
}
