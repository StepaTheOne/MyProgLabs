#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

#define    NUMS    13

char* to_roman(unsigned int num, char* buff)
{
    int p = NUMS;
    unsigned int a_num[NUMS] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
    char* r_str[NUMS] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };

    *buff = '\0';
    while (p--)
        while (num >= a_num[p])
        {
            num -= a_num[p];
            strcat(buff, r_str[p]);
        }

    return buff;
}

int toArabic(string str) {
    int arabNum = 0;
    for (int index = 0; index <= str.length(); ++index) {
        if (str[index] == 'I' && str[index + 1] == 'V') {
            arabNum += 4;
        }
        else if (str[index] == 'I' && str[index + 1] != 'V' && str[index + 1] != 'X') {
            ++arabNum;
        }
        if (str[index] == 'I' && str[index + 1] == 'X') {
            arabNum += 9;
        }
        if (str[index] == 'X' && str[index + 1] == 'L') {
            arabNum += 40;
        }
        if (str[index] == 'X' && str[index + 1] == 'C') {
            arabNum += 90;
        }
        if (str[index] == 'C' && str[index + 1] == 'D') {
            arabNum += 400;
        }
        if (str[index] == 'C' && str[index + 1] == 'M') {
            arabNum += 900;
        }

    }
    return arabNum;
}


int main(void)
{
    char* roman;
    unsigned int arabian = 123;       // .тут вводим число
    string romanNum = "CI";
    roman = (char*)malloc(256);
    cout << arabian << " : " << to_roman(arabian, roman) << endl;
    free(roman);
    cout << toArabic(romanNum);
    return 0;
}
