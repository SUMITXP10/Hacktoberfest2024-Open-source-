class Solution {
    // Helper function to split the sentence into words
    void findWords(string& s, vector<string>& words) {
        string word;
        for(int i = 0; s[i] != '\0'; ++i) {       // Iterate through each character in the string
            if(s[i] == ' ') {                     // If space is found, store the word in the vector
                words.push_back(word);
                word = "";                        // Reset word after storing
            } else {
                word.push_back(s[i]);             // Otherwise, append the character to the current word
            }
        }
        words.push_back(word);                    // Push the last word after the loop ends
    }
public:
    // Function to check if two sentences are similar
    bool areSentencesSimilar(string& s1, string& s2) {
        vector<string> words1, words2;            // Vectors to store words of each sentence
        findWords(s1, words1);                    // Split sentence 1 into words
        findWords(s2, words2);                    // Split sentence 2 into words

        // Ensure words1 is always the smaller sentence
        if(words1.size() > words2.size())         
            swap(words1, words2);

        int l = 0;
        // Count matching words from the start
        while(l < words1.size() && words1[l] == words2[l]) {
            l++;
        }

        int r = words1.size() - 1;                // Start from the end of words1
        int w2_pos = words2.size() - 1;           // Start from the end of words2
        // Count matching words from the end
        while(r >= 0 && words1[r] == words2[w2_pos]) {
            r--;
            w2_pos--;
        }

        // Return true if the overlapping words cover the entire smaller sentence
        return l > r;
    }
};
