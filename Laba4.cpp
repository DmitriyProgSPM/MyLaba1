#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <list>
#include <vector>
#include <functional>
#include <cctype>
#include<string>


std::list<std::string> ReadStream(std::istream& source)
{
    std::list<std::string> ret;
    while (!source.eof())
    {
        std::string word;
        source >> word;
        if (!word.empty())
        {
            ret.push_back(word);
            if (word.c_str()[word.length() - 1] == '.')
            {
                break;
            }
        }
    }
    return ret;
}



void PrintWords(const std::string& title, const std::list<std::string>& words)
{
    std::cout << std::endl << "-------" << title << "-------" << std::endl;

    for (const auto& word : words)
    {
        std::cout << word << ' ';
    }
    std::cout << std::endl;
}


std::string InputSubString()
{
    std::cout << std::endl << "Enter a substring to search" << std::endl;
    std::string ret;
    std::cin >> ret;
    return ret;
}


void Task2EditText(std::list<std::string>& words)
{
    for (auto& word : words)
    {
        //масив символов, составляющих исследуемое слово
        char* wordBuffer = new char[word.size() + 1];
        std::strcpy(wordBuffer, word.c_str());
        //знак препинания, который мы обнаружили в предыдущем символе
        char punktMark{ '\0' };
        //количество подряд идущих точек
        int dotCount{ 0 };
        //просмотрим каждую букву
        for (char* letter = wordBuffer; *letter != '\0'; letter++)
        {
            if (std::isalnum(*letter))
            {
                //это буква или цифра, а не знак препинания
                //если это не первый символ, то сделаем букву строчной
                if (letter != wordBuffer && std::isalpha(*letter))
                {
                    *letter = std::tolower(*letter);
                }
                //посмотрим, не было ли перед этой буквой неправильного числа точек
                if (punktMark == '.')
                {
                    if (dotCount ==2)
                    {
                        //убираем одну лишнюю точку
                        strcpy(letter, letter + 1);
                        //чтобы не пропустить новый символ в проверке
                        --letter;
                    }
                    else if(dotCount > 3)
                    {
                        //убираем commaCount - 3 лишних точек
                        strcpy(letter, letter + dotCount - 3);
                        --letter;
                    }
                }
                //забыли про предыдущий знак препианния
                punktMark = '\0';
                dotCount = 0;
            }
            else
            {
                //это не буква и не цифра, а значит - знак препинания
                //посмотрим, не было ли перед ним другого знака
                if (punktMark == '\0')
                {
                    //первый знак препинания - запомним его
                    punktMark = *letter;
                    if (punktMark == '.')
                    {
                        ++dotCount;
                    }
                }
                else
                {
                    //знак препинания не первый - посмотрим, не с точкой ли мы имеем дело
                    if (punktMark == '.' && *letter == '.')
                    {
                        //если это точка, то просто посчитаем ее
                        ++dotCount;
                    }
                    else
                    {
                        //текущий знак - точно лишний, удалим
                        strcpy(letter, letter + 1);
                        --letter;
                    }
                }
            }
        }
        //если все закончилось точками, то нужно снова проверить, верно ли их количество
        if (punktMark == '.')
        {
            if (dotCount == 2)
            {
                //убираем одну лишнюю точку в конце
                wordBuffer[std::strlen(wordBuffer) - 1] = '\0';
            }
            else if (dotCount > 3)
            {
                //убираем commaCount - 3 лишних точек в конце
                wordBuffer[std::strlen(wordBuffer) - (dotCount - 3)] = '\0';
            }
        }

        //запомним отредактированное слово
        word = wordBuffer;
        //удалим не нужный более временный буфер
        delete[] wordBuffer;
    }
}


void Task3Variant5(const std::list<std::string>& words)
{
    std::cout << std::endl << "--------Words, where the first letter is repetitive again-------" << std::endl;
    int count{ 0 };
    for (auto& word : words)
    {
        bool shallBePrinted{ false };
        auto buffer{ word.c_str() };
        auto first{ *buffer };
        for (auto letter = buffer + 1; *letter != '\0'; letter++)
        {
            if (*letter == first)
            {
                shallBePrinted = true;
                break;
            }
        }

        if (shallBePrinted)
        {
            std::cout << word << std::endl;
            ++count;
        }
    }
    std::cout << "------Total " << count << " words found-----" << std::endl;
}


void Task4Variant4(std::list<std::string> words)
{
    for (auto& word : words)
    {
        //масив символов, составляющих исследуемое слово
        char* wordBuffer = new char[word.size() + 1];
        std::strcpy(wordBuffer, word.c_str());
        for (char* letter = wordBuffer; *letter != '\0'; letter++)
        {
            //не цифру ли мы повстречали?
            if (std::isdigit(*letter))
            {
                //заменаем цифру буквой
                //будем считать, что буквы нум еруются с нуля, тогда 0 заменяем на A, 1 - на B, и так далее
                *letter = 'A' + *letter - '0';
            }
        }
        //запомним отредактированное слово
        word = wordBuffer;
        //удалим не нужный более временный буфер
        delete[] wordBuffer;
    }
    //выведем отредактированную последовательность
    PrintWords("Words, where digits are replaced with letters", words);
}


void Task5Search(const std::list<std::string>& words, std::function<bool(const std::string& source, const std::string& key)> searchAlg)
{
    const auto key = InputSubString();
    std::list<std::string> found;
    for (const auto& word : words)
    {
        if(word.size() >= key.size())
        {
            if(searchAlg(word, key))
            {
                found.push_back(word);
            }
        }
    }
    PrintWords(std::string("Words containing key '") + key + "'", found);
}


bool LineSearch(const std::string& source, const std::string& key)
{
    for (const char* s = source.c_str(); *s != '\0'; s++)
    {
        for (int j = 0; ; j++)
        {
            if (!key[j])
                return true;

            if (*(s + j) == '\0' || *(s + j) != key[j])
                break;
        }
    }
    return false;
}


std::vector<size_t> PrefixFunction(std::string s)
{
    auto n = s.length();
    std::vector<decltype(n)> prefixLen(n);
    for (decltype(n) i = 1; i < n; ++i)
    {
        auto j = prefixLen[i - 1];
        while ((j > 0) && (s[i] != s[j]))
            j = prefixLen[j - 1];

        if (s[i] == s[j])
            ++j;
        prefixLen[i] = j;
    }
    return prefixLen;
}


bool KMPSearch(const std::string& source, const std::string& key)
{
    auto prefixLen = PrefixFunction(key + ' ' + source);
    for (auto p : prefixLen)
    {
        if (p == key.size())
            return true;
    }

    return false;
}



void Laba4(std::list<std::string> text)
{
    PrintWords("Source text", text);
    Task2EditText(text);
    PrintWords("Extra Punctuation mark are removed; register is fixed", text);
    Task3Variant5(text);
    Task4Variant4(text);
    Task5Search(text, &LineSearch);
    Task5Search(text, &KMPSearch);
}

//https://github.com/DmitriyProgSPM/MyLaba1/blob/main/%D0%9E%D1%82%D1%87%D1%91%D1%82%20%D0%BF%D0%BE%20Lab4.docx  ОТЧЁТ
