#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include "analyzer.h"

std::string ciphertext = "VVHQWVVRHMUSGJGTHKIHTSSEJCHLSFCBGVWCRLRYQTFSVGAHWKCUHWAUGLQHNSLRLJSHBLTSPISPRDXLJSVEEGHLQWKASSKUWEPWQTWVSPGOELKCQYFNSVWLJSNIQKGNRGYBWLWGOVIOKHKAZKQKXZGYHCECMEIUJOQKWFWVEFQHKIJRCLRLKBIENQFRJLJSDHGRHLSFQTWLAUQRHWDMWLGUSGIKKFLRYVCWVSPGPMLKASSJVOQXEGGVEYGGZMLJCXXLJSVPAIVWIKVRDRYGFRJLJSLVEGGVEYGGEIAPUUISFPBTGNWWMUCZRVTWGLRWUGUMNCZVILE";

int m = 5; // key len
std::string key = "CODES";
// statistical norm for letter frequency
std::map<char, double> p({
    {'A', 8.2},
    {'B', 1.5},
    {'C', 2.8},
    {'D', 4.3},
    {'E', 12.7},
    {'F', 2.2},
    {'G', 2},
    {'H', 6.1},
    {'I', 7},
    {'J', .2},
    {'K', .8},
    {'L', 4},
    {'M', 2.4},
    {'N', 6.7},
    {'O', 7.5},
    {'P', 1.9},
    {'Q', .1},
    {'R', 6},
    {'S', 6.3},
    {'T', 9.1},
    {'U', 2.8},
    {'V', 1},
    {'W', 2.3},
    {'X', .1},
    {'Y', 2},
    {'Z', .1}
});

int main() {
    
    std::vector<int> c = disp_coin(ciphertext);

    double SD = calculateSD(c);
    // prnt any with 2 SD of max, weeds out non relevant data
    int max_coin = *std::max_element(c.begin(),c.end());
    for (int i = 0; i < c.size(); i++){
        if (c[i] > max_coin-SD)
            std::cout << "Displacement: " << i+1 << ", Coincedednces: " << c[i] << "\n";
    }
    
    std::string sub;
    double d;
    int j;
    std::deque<double> q_vec;
    std::deque<double> m_vals;
    auto max = std::max_element(m_vals.begin(),m_vals.end());
    for (int substr = 0; substr < m; substr++){
        q_vec = letter_frequency(sub);
        sub = splice(ciphertext, m, substr);

        // sho substrinct
        std::cout << "sub = " << sub << '\n';

        // shift and take cross produces
        for (int g = 0; g < p.size(); g++){
            j = 0;
            d = 0;
            // do dot product
            for(auto it = p.begin(); it != p.end(); ++it)
            {
                d += it->second*q_vec[j];
                j++;
            }
            m_vals.push_back(d);

            // display cross product
            std::cout << (char)('A' + g) << ' '<< g << ", " << d << '\n'; 

            // circular shift q vec
            q_vec.push_back(q_vec.front());
            q_vec.pop_front();
        }

        max = std::max_element(m_vals.begin(),m_vals.end());
        std::cout << "Largest val: " << *max << " letter: " << (char) ('A' + (max-m_vals.begin())) << '\n';
        m_vals.clear();
    }
    
    // decipher 
    std::cout << vigenre_dec(ciphertext, key);

    return 1;
}