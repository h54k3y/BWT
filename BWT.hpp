#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
int BWT_encode(const string text,string &encoded_text);
int BWT_decode(const string encoded_text, string &decoded_text);