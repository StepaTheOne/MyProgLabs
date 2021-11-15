/*****************************
* Новиков Степан, ПИ-211     *
* Задача 1                   *
* Количество повторений букв *
* И двухбуквенных сочетаний  *
******************************/

#include<iostream>
#include<fstream>
#include<string>
#define LOL 77

using namespace std;

struct OneLetter {
    char L;
    int count = 0;
}; OneLetter Letters[LOL];

struct TwoLetter {
    char TL[2];
    int TwoCount = 0;
}; TwoLetter Letter2s[LOL];

int Find1Letter(string slovo, int SIZE) {
    int count1L = 0;
    int i, j;
    bool log;
    for (i = 0; i < SIZE; ++i) {
        log = false;
        for (j = 0; j < count1L; ++j) {
            if (slovo[i] == Letters[j].L) {
                log = true;
                break;
            }
        }
        if (log) {
            Letters[j].count++;
        }
        else if(slovo[i] != ' ') {
            Letters[j].L = slovo[i];
            Letters[j].count++;
            count1L++;
        }
    }
    return count1L;
}

int Find2Letter(string slovo, int SIZE) {
    int i, j;
    int count2L = 0;
    bool log;
    int k;
    for (i = 0; i < SIZE-1; ++i) {
        log = false;
        k = i + 1;
        for (j = 0; j < count2L; ++j) {
            if (slovo[i] == Letter2s[j].TL[0] && slovo[k] == Letter2s[j].TL[1]) {
                log = true;
                break;
            }
        }
        if (log) {
            Letter2s[j].TwoCount++;
        }
        else if (slovo[i] != ' ' && slovo[k] != ' ') {
            Letter2s[j].TL[0] = slovo[i];
            Letter2s[j].TL[1] = slovo[k];
            Letter2s[j].TwoCount++;
            count2L++;
        }
    }
    return count2L;
}

int main() {
    fstream file;
    file.open("text.txt");

    if (!file.is_open()) {
        return 0;
    }

    string slovo;
    getline(file, slovo);
    int SIZE = slovo.length();

    int i;

    int count1Letters = 0;
    int count2Letters = 0;
    
    count1Letters = Find1Letter(slovo, SIZE);
    count2Letters = Find2Letter(slovo, SIZE);

    for (i = 0; i < count1Letters; ++i) {
        if (Letters[i].count > 1) {
            cout << Letters[i].L << ": " << Letters[i].count << endl;
        }
    }
    for (i = 0; i < count2Letters; ++i) {
        if (Letter2s[i].TwoCount > 1) {
            cout << Letter2s[i].TL[0] << Letter2s[i].TL[1] << ": " << Letter2s[i].TwoCount << endl;
        }
        
    }
    return 0;
    file.close();
}