#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include "analyzer.h"

//std::string ciphertext = "VVHQWVVRHMUSGJGTHKIHTSSEJCHLSFCBGVWCRLRYQTFSVGAHWKCUHWAUGLQHNSLRLJSHBLTSPISPRDXLJSVEEGHLQWKASSKUWEPWQTWVSPGOELKCQYFNSVWLJSNIQKGNRGYBWLWGOVIOKHKAZKQKXZGYHCECMEIUJOQKWFWVEFQHKIJRCLRLKBIENQFRJLJSDHGRHLSFQTWLAUQRHWDMWLGUSGIKKFLRYVCWVSPGPMLKASSJVOQXEGGVEYGGZMLJCXXLJSVPAIVWIKVRDRYGFRJLJSLVEGGVEYGGEIAPUUISFPBTGNWWMUCZRVTWGLRWUGUMNCZVILE";
std::string ciphertext = "ABCBABBBAC";
std::unordered_map<char, double> p({
    {'A', .7},
    {'B', .2},
    {'C', .1}
});

int main() {
    /*
    std::vector<int> c = disp_coin(ciphertext);

    double SD = calculateSD(c);
    // prnt any with 2 SD of max, weeds out non relevant data
    int max_coin = *std::max_element(c.begin(),c.end());
    for (int i = 0; i < c.size(); i++){
        if (c[i] > max_coin-SD)
            std::cout << "Displacement: " << i+1 << ", Coincedednces: " << c[i] << "\n";
    }
    */

    std::string y1 = splice(ciphertext,2,0);
    std::cout << "Y1 = " << y1 << '\n';
    std::vector<double> q1 = letter_frequency(y1);
    double m = 0;
    int i = 0;
    for(auto it = p.begin(); it != p.end(); ++it)
    {
        m += it->second*q1[i];
        i++;
    }
    std::cout << "m0 = " << m << '\n';
    


    std::string y2 = splice(ciphertext,2,1);
    std::cout << "Y2 = " << y2 << '\n';
    std::vector<double> q2 = letter_frequency(y2);
    for(auto it = p.begin(); it != p.end(); ++it)
    {
        m += it->second*q2[i];
        i++;
    }
    std::cout << "m0 = " << m << '\n';
    return 1;
}