#include <iostream>
#include <cstring>
#include "Tools.h"
#include "Word.h"

using namespace std;

namespace sdds
{



    void toLowerCaseAndAlphabeticCopy(char des[], const char source[])
    {
        int i = 0, j = 0;
        char lower;
        for (; source[i] != 0; i++) {
            lower = tolower(source[i]);
            if (lower >= 'a' && lower <= 'z') {
                des[j++] = tolower(source[i]);
            }
        }
        des[j] = 0;
    }

    void report(const Word words[], int noOfWords, int longestWord)
    {
        int i;
        int total;
        title();
        for (total = 0, i = 0; i < noOfWords; i++)
        {
            sdds::print(&words[i], true);
            total += words[i].count;
        }
        endList();
        totalWordsStat(noOfWords, total, longestWord);
    }

    void sort(Word words[], int cnt)
    {
        int i, j;
        for (i = 0; i < cnt - 1; i++) {
            for (j = 0; j < cnt - i - 1; j++) {
                if (strcmp(words[j].letters, words[j + 1].letters) > 0) {
                    sdds::swap(&words[j], &words[j + 1]);
                }
            }
        }
    }

    void swap(Word* p1, Word* p2)
    {
        Word w;
        w = *p1;
        *p1 = *p2;
        *p2 = w;
    }

    void print(const Word* w, bool gotoNextLine)
    {
        cout << w->letters << ": " << w->count;
        if (gotoNextLine) cout << endl;
    }

    void addWord(Word words[], int* index, const char newWord[])
    {
        strcpy(words[*index].letters, newWord);
        words[*index].count++;
        (*index)++;
    }

    int searchWords(const Word words[], int num, const char word[])
    {
        int i;
        int foundIndex = -1;  // will be set to found index; if not found sould be less than 0
        for (i = 0; foundIndex == -1 && i < num; i++) { // while not found and i is less than number of words
            if (strcmp(words[i].letters, word) == 0) { // if word is already read and found in the list of previous words
                foundIndex = i;   // set the index to be returned.
            }
        }
        return foundIndex;
    }
}

