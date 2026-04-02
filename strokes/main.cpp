#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

int getUtf8Char(const string& s, size_t& i) {
    unsigned char c = (unsigned char)s[i];
    if (c < 0x80) { 
        i++; return c; 
    }
    if ((c & 0xE0) == 0xC0 && i + 1 < s.size()) {
        int cp = ((c & 0x1F) << 6) | ((unsigned char)s[i+1] & 0x3F);
        i += 2;
        return cp;
    }
    i++;
    return c;
}

void appendUtf8(string& s, int cp) {
    if (cp < 0x80) {
        s += (char)cp;
    } else if (cp < 0x800) {
        s += (char)(0xC0 | (cp >> 6));
        s += (char)(0x80 | (cp & 0x3F));
    }
}

bool isRussianLetter(int cp) {
    return (cp >= 0x410 && cp <= 0x44F) || cp == 0x401 || cp == 0x451;
}

int toLowerRu(int cp) {
    if (cp >= 0x410 && cp <= 0x42F)  {
        return cp + 0x20;
    }
    if (cp == 0x401) {
        return 0x451;
    }
    return cp;
}

bool isRussianConsonant(int cp) {
    cp = toLowerRu(cp);
    int consonants[] = {
        0x431, 0x432, 0x433, 0x434, 0x436, 0x437, 0x439, 0x43A, 0x43B, 0x43C, 0x43D, 0x43F, 0x440, 0x441, 0x442, 0x444, 0x445, 0x446, 0x447, 0x448, 0x449
    };
    for (int i = 0; i < 21; i ++) {
        if (cp == consonants[i]) {
            return true;
        }
    }
    return false;
}

int charCount(const string& s) {
    int cnt = 0;
    for (size_t i = 0; i < s.size(); ) {
        unsigned char c = (unsigned char)s[i];
        if (c < 0x80) { 
            cnt++; i++; 
        }
        else if ((c & 0xE0) == 0xC0) {
            cnt++; i += 2; 
        }
        else { 
            i++; 
        }
    }
    return cnt;
}

void printSymbolTable() {
    cout << "Таблица символов:" << endl;
    cout << "Символ | Код" << endl;
    cout << "-------+----------------" << endl;

    for (char c = 'A'; c <= 'Z'; c++)
        printf("  %c    |    %3d\n", c, (int)c);
    for (char c = 'a'; c <= 'z'; c++)
        printf("  %c    |    %3d\n", c, (int)c);
    for (char c = '0'; c <= '9'; c++)
        printf("  %c    |    %3d\n", c, (int)c);

    const char* punct = ".,!?;:-()\"'";
    for (int i = 0; punct[i]; i++)
        printf("  %c    |    %3d\n", punct[i], (int)punct[i]);

    cout << "\nРусские буквы:" << endl;
    cout << "Символ | Код" << endl;
    cout << "-------+----------------" << endl;

    for (int cp = 0x410; cp <= 0x42F; cp++) {
        char buf[5] = {0};
        buf[0] = (char)(0xD0 | (cp >> 6));
        buf[1] = (char)(0x80 | (cp & 0x3F));
        printf("  %s   |    %5d\n", buf, cp);
    }
    printf("  \xD0\x81   |    %5d\n", 0x401);

    for (int cp = 0x430; cp <= 0x44F; cp++) {
        char buf[5] = {0};
        buf[0] = (char)(0xD0 | (cp >> 6));
        buf[1] = (char)(0x80 | (cp & 0x3F));
        printf("  %s   |    %5d\n", buf, cp);
    }
    printf("  \xD1\x91   |    %5d\n", 0x451);
}

void task1() {
    cout << "\n--- Задача 1: Удаление согласных ---" << endl;

    char str[201] = {0};
    cout << "Введите строку (не более 100 символов): ";
    cin.getline(str, 201);

    char result[201] = {0};
    int j = 0;
    int len = (int)strlen(str);

    for (int i = 0; i < len; ) {
        unsigned char c0 = (unsigned char)str[i];
        if (c0 < 0x80) {
            result[j++] = str[i++];
        } else if ((c0 & 0xE0) == 0xC0 && i + 1 < len) {
            int cp = ((c0 & 0x1F) << 6) | ((unsigned char)str[i+1] & 0x3F);
            if (!isRussianConsonant(cp)) {
                result[j++] = str[i];
                result[j++] = str[i+1];
            }
            i += 2;
        } else {
            result[j++] = str[i++];
        }
    }
    result[j] = '\0';

    cout << "Результат: " << result << endl;
}

string cleanWord(const string& word) {
    string result;
    size_t i = 0;
    while (i < word.size()) {
        unsigned char c0 = (unsigned char)word[i];
        if (c0 < 0x80) {
            i++;
        } else if ((c0 & 0xE0) == 0xC0 && i + 1 < word.size()) {
            int cp = ((c0 & 0x1F) << 6) | ((unsigned char)word[i+1] & 0x3F);
            if (isRussianLetter(cp)) {
                int lcp = toLowerRu(cp);
                appendUtf8(result, lcp);
            }
            i += 2;
        } else {
            i++;
        }
    }
    return result;
}

bool containsLetterFrom(const string& word, const string& forbidden) {
    size_t i = 0;
    while (i < word.size()) {
        size_t i2 = i;
        int cpW = getUtf8Char(word, i2);
        i = i2;

        size_t j = 0;
        while (j < forbidden.size()) {
            size_t j2 = j;
            int cpF = getUtf8Char(forbidden, j2);
            j = j2;
            if (cpW == cpF) return true;
        }
    }
    return false;
}

void task2() {
    cout << "\n--- Задача 2: Поиск слов без букв из заданного слова ---" << endl;

    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Ошибка: не удалось открыть файл input.txt" << endl;
        return;
    }

    int N;
    string forbiddenWord;
    inputFile >> N >> forbiddenWord;
    cout << "N = " << N << endl;
    cout << "Запрещенное слово = " << forbiddenWord << endl;
    inputFile.close();

    forbiddenWord = cleanWord(forbiddenWord);

    if (N <= 0) {
        cerr << "N должно быть положительным числом" << endl;
        return;
    }

    cout << "Запрещённые буквы из слова: " << forbiddenWord << endl;
    cout << "Нужно найти " << N << " самых длинных слов без этих букв" << endl;

    ifstream textFile("text.txt");
    if (!textFile) {
        cerr << "Ошибка: не удалось открыть файл text.txt" << endl;
        return;
    }

    vector<string> best;
    string word;

    while (textFile >> word) {
        string cleaned = cleanWord(word);
        if (cleaned.empty()) {
            continue;
        }
        if (containsLetterFrom(cleaned, forbiddenWord)) {
            continue;
        }

        if ((int)best.size() < N || charCount(cleaned) > charCount(best.back())) {
            int pos = (int)best.size();
            for (int k = 0; k < (int)best.size(); k++) {
                if (charCount(cleaned) > charCount(best[k])) {
                    pos = k;
                    break;
                }
            }
            best.insert(best.begin() + pos, cleaned);
        }
        if ((int)best.size() > N) {
            best.pop_back();
        }
    }
    textFile.close();

    cout << "Подходящих уникальных слов: " << best.size() << endl;

    if (best.empty()) {
        cout << "Нет подходящих слов" << endl;
        return;
    }

    ofstream resultFile("result.txt");
    if (!resultFile) {
        cerr << "Ошибка: не удалось создать файл result.txt" << endl;
        return;
    }

    resultFile << "Запрещённые буквы из слова: " << forbiddenWord << endl;
    resultFile << "Самые длинные слова без этих букв:" << endl;
    for (int i = 0; i < (int)best.size(); i++) {
        resultFile << i + 1 << ". " << best[i] << " (длина: " << charCount(best[i]) << ")" << endl;
    }
    resultFile.close();

    cout << "\nРезультат:" << endl;
    for (int i = 0; i < (int)best.size(); i++) {
        cout << i + 1 << ". " << best[i] << " (длина: " << charCount(best[i]) << ")" << endl;
    }
    cout << "Результаты сохранены в result.txt" << endl;
}

int main() {
    printSymbolTable();

    task1();

    task2();

    return 0;
}



















void task2() {
    cout << "\n-----п2: поиск слов, в которых все буквы упорядочены по алфавиту-----" << endl;
    
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "не удалось открыть файл input.txt" << endl;
        return;
    }
    int N;
    inputFile >> N;
    inputFile.close();
    
    if (N <= 0) {
        cout << "N должно быть положительным числом" << endl;
        return;
    }
    
    ifstream textFile("text.txt");
    if (!textFile) {
        cout << "не удалось открыть файл text.txt" << endl;
        return;
    }
    vector<string> biggest_words;
    string word;
    
    while (textFile >> word) {
        string cleaned = cleanWord(word);
        if (cleaned.empty()) {
            continue;
        }

        if (!isAlphabetical(cleaned)) {
            continue;
        }
        
        bool found = false;
        for (size_t k = 0; k < biggest_words.size(); k++)
            if (biggest_words[k] == cleaned) { 
                found = true; break; 
            }
        if (found) {
            continue;
        }

        if ((int)biggest_words.size() < N || charCount(cleaned) > charCount(biggest_words.back())) {
            int pos = (int)biggest_words.size();
            for (int k = 0; k < (int)biggest_words.size(); k++) {
                if (charCount(cleaned) > charCount(biggest_words[k])) {
                    pos = k;
                    break;
                }
            }
            biggest_words.insert(biggest_words.begin() + pos, cleaned);

            if ((int)biggest_words.size() > N) {
                biggest_words.pop_back();
            }
        }
    }
    textFile.close();

    cout << "Подходящих слов найдено: " << biggest_words.size() << endl;

    if (biggest_words.empty()) {
        cout << "Нет подходящих слов" << endl;
        return;
    }

    ofstream resultFile("result.txt");
    if (!resultFile) {
        cerr << "Ошибка: не удалось создать файл result.txt" << endl;
        return;
    }

    resultFile << "Самые длинные слова с буквами по алфавиту:" << endl;
    for (int i = 0; i < (int)biggest_words.size(); i++) {
        resultFile << i + 1 << ". " << biggest_words[i] << " (длина: " << charCount(biggest_words[i]) << ")" << endl;
    }
    resultFile.close();

    cout << "\nРезультат:" << endl;
    for (int i = 0; i < (int)biggest_words.size(); i++) {
        cout << i + 1 << ". " << biggest_words[i] << " (длина: " << charCount(biggest_words[i]) << ")" << endl;
    }
    cout << "Результаты сохранены в result.txt" << endl;
}