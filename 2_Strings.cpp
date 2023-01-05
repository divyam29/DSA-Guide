#include <bits/stdc++.h>
using namespace std;

int strLength(char *s)
{
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

void toUpper(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] = s[i] - 32;
        }
    }
}

void toLower(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            s[i] = s[i] + 32;
        }
    }
}

void strToggleCase(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            s[i] = s[i] + 32;
        }
        else if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] = s[i] - 32;
        }
    }
}

int countVowels(char *s)
{
    int vowels = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            vowels++;
        }
    }
    return vowels;
}

int countConsonants(char *s)
{
    int consonants = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] > 'A' && s[i] <= 'Z'))
        {
            if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U')
            {
                consonants++;
            }
        }
    }
    return consonants;
}

int countWords(char *s)
{
    int words = 1;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ' && s[i - 1] != ' ')
        {
            words++;
        }
    }
    return words;
}

int validateString(char *s)
{
    // check if string has only alphabets and numbers (no spaces no symbols)
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= '0' && s[i] <= '9'))
        {
            return 0;
        }
    }
    return 1;
}

char *strReverse(char *s)
{
    int i, j;
    for (j = 0; s[j] != '\0'; j++)
    {
    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        swap(s[i], s[j]);
    }
    return s;
}

void strComp(char *s1, char *s2)
{
    int i, j;
    toLower(s1);
    toLower(s2);
    for (i = 0, j = 0; s1[i] != '\0' && s2[j] != '\0'; i++, j++)
    {
        if (s1[i] != s2[j])
        {
            break;
        }
    }
    if (s1[i] == s2[j])
    {
        cout << "Strings are same\n";
    }
    else if (s1[i] > s2[j])
    {
        cout << "String 1 is greater\n";
    }
    else
    {
        cout << "String 2 is greater\n";
    }
}

int checkPalindrome(char *s)
{
    int i, j;
    for (j = 0; s[j] != '\0'; j++)
    {
    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            return 0;
        }
    }
    return 1;
}

void findDuplicates(char *s)
{
    toLower(s);
    int H[26] = {0};
    for (int i = 0; s[i] != '\0'; i++)
    {
        H[s[i] - 97]++;
        // s[i]-97 as 'a'=97 so value of 'a' in hash table is 97-97=0
    }
    for (int i = 0; i < 26; i++)
    {
        if (H[i] > 0)
        {
            printf("Character %c occurs %d times\n", i + 97, H[i]);
        }
    }
}

void findDuplicateUsingBitwise(char *s)
{
    int H = 0, x;
    for (int i = 0; s[i] != '\0'; i++)
    {
        x = 1;
        x = x << s[i] - 97;
        int a = x & H;
        bool flag = a > 0;
        if (flag)
        {
            cout << s[i] << " has a duplicate\n";
        }
        else
        {
            H = x | H;
        }
    }
}

void checkAnagram(char *s1, char *s2)
{
    if (strLength(s1) == strLength(s2))
    {
        int H[26] = {0}, i;
        for (i = 0; s1[i] != '\0'; i++)
        {
            H[s1[i] - 97]++;
        }
        for (i = 0; s2[i] != '\0'; i++)
        {
            H[s2[i] - 97]--;
            if (H[s2[i] - 97] < 0)
            {
                cout << "Strings are not anagram\n";
                break;
            }
        }
        if (s2[i] == '\0')
        {
            cout << "Strings are an Anagram...\n";
        }
    }
    else
    {
        cout << "Strings are not anagram\n";
    }
}

void generatePermutations(char *s, int k)
{
    // const int len=strLength(s)+1;
    static int A[10] = {0};
    static char result[10];
    int i;
    if (s[k] == '\0')
    {
        result[k] = '\0';
        cout << result << endl;
    }
    else
    {
        for (i = 0; s[i] != 0; i++)
        {
            if (A[i] == 0)
            {
                result[k] = s[i];
                A[i] = 1;
                generatePermutations(s, k + 1);
                A[i] = 0;
            }
        }
    }
}

int main()
{
    char str[] = "abc";
    char str2[] = "observe";
    // char *str1;
    cout << "String 1: " << str << endl;
    cout << "String 2: " << str2 << endl;

    // cout << "Length: " << strLength(str) << endl;

    // toUpper(str);
    // cout << "Uppercase String: " << str << endl;

    // toLower(str);
    // cout << "Lowercase String: " << str << endl;

    // strToggleCase(str);
    // cout << "Togglecase String: " << str << endl;

    // cout << "Consonants: " << countConsonants(str) << endl;
    // cout << "Vowels: " << countVowels(str) << endl;
    // cout << "Words: " << countWords(str) << endl;

    // if(validateString(str)){
    //     cout<<"String is valid\n";
    // }
    // else{
    //     cout<<"String is not valid\n";
    // }

    // str1=strReverse(str);
    // cout << "Reversed String: " << str1 << endl;

    // strComp(str,str2);

    // if(checkPalindrome(str)){
    //     cout<<"String is a palindrome\n";
    // }
    // else{
    //     cout<<"String is not a palindrome\n";
    // }

    // findDuplicates(str);

    // findDuplicateUsingBitwise(str);

    // checkAnagram(str, str2);

    // cout<<"Permutations:\n";
    generatePermutations(str,0);
}