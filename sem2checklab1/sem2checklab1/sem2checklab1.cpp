using namespace std;
#include<iostream>
#include<fstream>

struct Word
{
	char ch = 0;
	Word* next;
};

struct Line
{
	int count = 0;
	Word* word;
	Line* next;
};

void Search(Line* line, char find, char s)
{
	Word* wordNow;
	do
	{
		wordNow = line->word->next;
		while (wordNow != NULL)
		{
			if (find == wordNow->ch)
			{
				if (line->count == 0)
				{
					line->count++;
					wordNow->ch = s;
				}
			}
			cout << wordNow->ch;
			wordNow = wordNow->next;
		}

		cout << "   ";
		line = line->next;
	} while (line->next != NULL);


};

void Print(Line* line)
{
	Word* wordNow;
	do
	{
		wordNow = line->word->next;
		while (wordNow != NULL)
		{
			cout << wordNow->ch;
			wordNow = wordNow->next;
		}
		cout << "   ";
		line = line->next;
	} while (line->next != NULL);
}

void main()
{
	setlocale(LC_ALL, "Russian");
	char ch = 0;
	char find;
	char s;
	bool point = false;
	fstream file;
	file.open("input.txt");

	if (file.is_open())
	{
		Line headline;
		Line* lineNow;
		lineNow = &headline;
		headline.word = new Word;
		Word* wordNow = headline.word;


		while (!file.eof() && ch != '.')
		{
			ch = file.get();
			if (ch == '.') point = true;
			if (ch != ' ' && ch != '.')
			{
				wordNow->next = new Word;
				wordNow = wordNow->next;
				wordNow->ch = ch;

			}
			else if (wordNow->ch != 0)
			{
				lineNow->next = new Line;
				lineNow = lineNow->next;
				lineNow->word = new Word;
				wordNow->next = NULL;
				wordNow = lineNow->word;

			}
		}
		wordNow->next = NULL;
		lineNow->next = NULL;
		file.close();

		if (point == true)
		{
			cout << "Введите символ ,который нужно заменить.\n==> ";
			cin >> find;
			cout << "\nВведите символ на который меняем найденный.\n==> ";
			cin >> s;
			cout << endl;
			if (headline.word->next != 0)
			{
				cout << "Изначальный текст: ";
				Print(&headline);
				cout << "\n\n";
				cout << "Измененный текст: ";
				Search(&headline, find, s);
			}
			else cout << "Файл пуст.\n";
		}
		else cout << "Отсутствует точка в конце." << endl;
	}
	else cout << "Входной файл не найден." << endl;
}