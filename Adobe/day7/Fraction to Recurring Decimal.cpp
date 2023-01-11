#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string s1 = "";
        if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) s1 += "-";
        long num = numerator < 0 ? (long)numerator * -1 : (long)numerator;
        long den = denominator < 0 ? (long)denominator * -1 : (long)denominator;
        long res = num / den;
        long reminder = num % den;
        s1 += to_string(res);
        if (reminder != 0) {
            string s2 = "";
            unordered_map<long,int> temp;
            int count = 0;
            while (reminder != 0) {
            	temp[reminder] = count++;
                while (reminder < den) {
                    reminder *= 10;
                    if (reminder < den) {
                    	s2 += '0';
                    	temp[reminder] = count++;
                    }
                }
                s2 += to_string(reminder / den);
                reminder = reminder % den;
                if (reminder == 0) return s1 + "." + s2;
                if (temp.find(reminder) != temp.end()) {
                    int pos = temp[reminder];
                    return s1 + "." + s2.substr(0, pos) + "(" + s2.substr(pos) + ")";
                }
            }
        }
        return s1;
    }
};