// SYMBOL       VALUE
//   I            1
//   IV           4
//   V            5
//   IX           9
//   X            10
//   XL           40
//   L            50
//   XC           90
//   C            100
//   CD           400
//   D            500
//   CM           900 
//   M            1000
    
// Approach: A number in Roman Numerals is a string of these symbols written in descending order(e.g. M’s first, followed by D’s, etc.). 
// However, in a few specific cases, to avoid four characters being repeated in succession(such as IIII or XXXX), 
// subtractive notation is often used as follows: 
// 
// I placed before V or X indicates one less, so four is IV (one less than 5) and 9 is IX (one less than 10).
// X placed before L or C indicates ten less, so forty is XL (10 less than 50) and 90 is XC (ten less than a hundred).
// C placed before D or M indicates a hundred less, so four hundred is CD (a hundred less than five hundred) and nine hundred is CM (a hundred less than a thousand).
// 
//     Algorithm to convert Roman Numerals to Integer Number:  
// 
// Split the Roman Numeral string into Roman Symbols (character).
// Convert each symbol of Roman Numerals into the value it represents.
// Take symbol one by one from starting from index 0: 
// If current value of symbol is greater than or equal to the value of next symbol, then add this value to the running total.
// else subtract this value by adding the value of next symbol to the running total.

    
#include <iostream>
  
using namespace std; 

    int roman_to_integer(string rstr) {
        int n = int(rstr.length());
        if (0 == n) {
            return 0;
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            switch (rstr[i]) {
                case 'I':
                    result += 1;
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'X':
                    result += 10;
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'C':
                    result += 100;
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'M':
                    result += 1000;
                    break;
            }
        }

        for (int i = 1; i < n; i++) {
            if ((rstr[i] == 'V' || rstr[i] == 'X') && rstr[i - 1] == 'I') {
                result -= 1 + 1;
            }

            if ((rstr[i] == 'L' || rstr[i] == 'C') && rstr[i - 1] == 'X') {
                result -= 10 + 10;
            }

            if ((rstr[i] == 'D' || rstr[i] == 'M') && rstr[i - 1] == 'C') {
                result -= 100 + 100;
            }
        }
        return result;
    }

  
int main()  
{  
    string s = "VII";
	cout << "Roman " << s << " -> Integer " << roman_to_integer(s) << endl;
    s = "XIX";
	cout << "Roman " << s << " -> Integer " << roman_to_integer(s) << endl;  
    s = "DCCLXXXIX";
	cout << "Roman " << s << " -> Integer " << roman_to_integer(s) << endl;   
    s = "MXCIX";
	cout << "Roman " << s << " -> Integer " << roman_to_integer(s) << endl; 
    s = "MMMMMMMMMMMMMMMMMMMMMMMCDLVI";
	cout << "Roman " << s << " -> Integer " << roman_to_integer(s) << endl;

    return 0;  
}  
