#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <deque>

double calculateSD(std::vector<int> data);
std::vector<int> disp_coin(std::string ctext);
std::deque<double> letter_frequency(std::string text);
std::string splice(std::string text, int interval, int shift);
std::string vigenre_dec(std::string ctext, std::string key);