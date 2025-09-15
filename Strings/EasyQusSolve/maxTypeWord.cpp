// Leetcode problem 1935 -> Maximum Number of Words You Can Type
#include <bits/stdc++.h>
using namespace std;

int canBeTypedWords(string text, string brokenLetters)
{
    // Store broken letters in a hash set for fast lookup
    unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());

    // Split text into words using stringstream
    stringstream ss(text);

    string word;
    int count = 0;

    // Process each word in the text
    while (ss >> word)
    {
        bool ok = true;
        // Check if the word contains any broken letter
        for (char c : word)
        {
            if (broken.count(c)) // found a broken letter
            {
                ok = false;
                break;
            }
        }
        // If no broken letter found, the word can be typed
        if (ok)
            count++;
    }
    return count; // total number of typeable words
}

int main()
{
    string text = "hello world", brokenLetters = "ad";

    cout << "Result: " << canBeTypedWords(text, brokenLetters) << endl;

    return 0;
}

/*
TC: O(n*L) here, n = number of words, L = average word length
SC: O(K) here, k = brokenLetters.size()
*/