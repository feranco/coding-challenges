//algorithm to reverse words in a sentence
//O(n) time O(1) space

#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

#if 0
void reverseWords(string* sentence_ptr) {
  string& sentence = *sentence_ptr;

  //reverse each word
  int start_word = 0, end_word = 0;
  while ((end_word = sentence.find(" ", start_word)) != string::npos) {
    reverse(sentence.begin() + start_word, sentence.begin() + end_word);
    start_word = sentence.find_first_not_of(" ", end_word);
  }
  reverse(sentence.begin() + start_word, sentence.end());

  //reverse words in sentence
  reverse(sentence.begin(), sentence.end());
}
#endif

//with swap
void reverseWords(string* sentence_ptr) {
  string& sentence = *sentence_ptr;

  //reverse each word
  for (int i = 0, start_word = 0; i <= sentence.size(); ++i) {
    if (i == sentence.size() || sentence[i] == ' '  ) {
      int end_word = i - 1;
      while (start_word <= end_word) {
	swap(sentence[start_word++], sentence[end_word--]);
      }
      start_word = i + 1;
    }
  }

  //reverse words in sentence
  int left = 0, right = sentence.size() - 1;
  while (left <= right) {
    swap(sentence[left++], sentence[right--]);
  }
}

int main(void) {
  string sentence("Alice    likes    Bob");
  reverseWords(&sentence);
  cout << sentence;
}
