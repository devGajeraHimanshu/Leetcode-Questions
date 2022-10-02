// Suppose we have a string s. s can hold any English letters and white-spaces. We have to find the length of last word in the string.
// If there is no last word, then return 0.
// 
// So, if the input is like "I love Programming", then the output will be 11
// 
// To solve this, we will follow these steps −
// 
// n := 0
// 
// for each word temp in a string −
// 
// n := size of temp
// 
// return n

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   int lengthOfLastWord(string s){
      stringstream str(s);
      string temp;
      int n = 0;
      while (str >> temp)
         n = temp.size();
      return n;
   }
};

main(){
   Solution ob;
   cout << (ob.lengthOfLastWord("I love Programming"));
}
