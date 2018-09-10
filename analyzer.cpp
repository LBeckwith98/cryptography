#include "analyzer.h"


std::map<char, double> alphabet_null({
    {'A', 0},
    {'B', 0},
    {'C', 0},
    {'D', 0},
    {'E', 0},
    {'F', 0},
    {'G', 0},
    {'H', 0},
    {'I', 0},
    {'J', 0},
    {'K', 0},
    {'L', 0},
    {'M', 0},
    {'N', 0},
    {'O', 0},
    {'P', 0},
    {'Q', 0},
    {'R', 0},
    {'S', 0},
    {'T', 0},
    {'U', 0},
    {'V', 0},
    {'W', 0},
    {'X', 0},
    {'Y', 0},
    {'Z', 0}
});



double calculateSD(std::vector<int> data)
{
    double sum = 0.0, mean, SD = 0.0, standardDeviation = 0;;

    for(int i = 0; i < data.size(); i++)
        sum += data[i];
    
    mean = sum/data.size();

    for(int i = 0; i < data.size(); ++i)
        standardDeviation += pow(data[i] - mean, 2);

    return sqrt(standardDeviation / data.size());
}

std::vector<int> disp_coin(std::string ctext){
    int num_same;
    std::vector<int> coins;

    // shift cipher
    for (int shift = 1; shift < ctext.size();  shift++){
        num_same = 0;
        // check for coincedences on shift
        for (int shift_index = shift, index = 0; shift_index < ctext.size(); shift_index++, index++){
            if(ctext[index] == ctext[shift_index]){
                num_same++;
            }
        }
        //std::cout << "Displacement: " << shift << ", Coincedednces: " << num_same << "\n";
        coins.push_back(num_same);
    }
    return coins;
}

std::deque<double> letter_frequency(std::string text){
    std::map<char, double> freq(alphabet_null);
        
    for (int i = 0; i < text.size(); i++){
        freq[text[i]] += 1.0/text.size();
    }    

    std::deque<double> v;
    for(auto it = freq.begin(); it != freq.end(); ++it ) {
        v.push_back(it->second);
    }
    return v;
}

std::string splice(std::string text, int interval, int shift){
    std::string s = "";
    for (int i = shift; i < text.size(); i = i + interval){
        s += text[i]; 
    }
    return s;
}

std::string vigenre_dec(std::string ctext, std::string key) {
    std::string ptext = "";
    char c, k, p;
    for (int i = 0; i < ctext.size(); i++){
        c = ctext[i] - 'A';
        k = key[i % key.size()] - 'A';
        p = (c - k + 26)%26;
        ptext += (p+'A');
    }
    return ptext;
}