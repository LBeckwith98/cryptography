#include "analyzer.h"


// statistical norm for letter frequency
std::map<char, double> alphabet_f({
    {'A', 12.7},
    {'B', 9.1},
    {'C', 8.2},
    {'D', 7.5},
    {'E', 7},
    {'F', 6.7},
    {'G', 6.3},
    {'H', 6.1},
    {'I', 6},
    {'J', 4.3},
    {'K', 4},
    {'L', 2.8},
    {'M', 2.8},
    {'N', 2.4},
    {'O', 2.3},
    {'P', 2.2},
    {'Q', 2},
    {'R', 2},
    {'S', 1.9},
    {'T', 1.5},
    {'U', 1},
    {'V', .8},
    {'W', .2},
    {'X', .1},
    {'Y', .1},
    {'Z', .1}
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

std::vector<double> letter_frequency(std::string text){
    std::map<char, double> freq;
        
    for (int i = 0; i < text.size(); i++){
        // If the key does exist in the dictionary
        if(freq.count(text[i]) == 1){
            freq[text[i]] += 1.0/text.size();
        }
        // If its a new key
        else{
            freq.insert(std::make_pair(text[i],1.0/text.size()));
        }
    }    

    std::vector<double> v;
    for( auto it = freq.begin(); it != freq.end(); ++it ) {
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