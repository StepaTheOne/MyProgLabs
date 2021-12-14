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
        } else if (str[index] == 'I' && str[index + 1] != 'X') { 
            ++ArNum;
        } else if (str[index] == 'I' && str[index + 1] == 'X') {
            ArNum += 9;
        } else if (str[index] == 'X' && str[index + 1] == 'L') {
            ArNum += 40;
        } else if (str[index] == 'X' && str[index + 1] == 'C') {
            ArNum += 90;
        } else if (str[index] == 'C' && str[index + 1] == 'D') {
            ArNum += 400;
        } else if (str[index] == 'C' && str[index + 1] == 'M') {
            ArNum += 900;
        } else if(str[index] == 'M'){
            ArNum += 1000;
        } else if (str[index] == 'D') {
            ArNum += 500;
        } else if (str[index] == 'C') {
            ArNum += 100;
        } else if (str[index] == 'L') {
            ArNum += 50;
        } else if (str[index] == 'X') {
            ArNum += 10;
        } else if (str[index] == 'V') {
            ArNum += 5;
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
