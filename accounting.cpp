#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> collect_amounts(int ppl, int *avg);

int main(){
    
    int ppl {0}, avg {0};

    cout << "Enter number of people in this trip: ";
    cin >> ppl;

    map<string, int> amounts = collect_amounts(ppl, &avg), positive, negative;

    for(auto it = amounts.begin(); it != amounts.end(); it++){
        if(it->second > avg)
            positive[it->first] = it->second - avg;
        else if (it->second < avg)
            negative[it->first] = avg - it->second;
    }
    for(int i {0}; i<5;i++){
        cout << endl;
    }
    cout << "--------------------------------------" << endl;
    cout << "----------- GENERATED BILL -----------" << endl;
    cout << "--------------------------------------" << endl;
    cout << endl;
    cout << "AMOUNT PAID BY EACH PERSON: " << endl;
    cout << "--------------------------------------" << endl;
    for (auto it = amounts.begin(); it != amounts.end(); it++){
        cout << it->first << ": " << it->second << endl;
    }
    cout << endl;
    cout << "TOTAL AMOUNT SPENT: " << avg * ppl << endl;
    cout << "AVERAGE AMOUNT SPENT PER HEAD: " << avg << endl;
    cout << "--------------------------------------" << endl;
    cout << endl;
    cout << "AMOUNT PAYABLE BY EACH PERSON: " << endl;
    cout << "--------------------------------------" << endl;
    int n {1};
    for (auto it = negative.begin(); it != negative.end(); it++){
        cout << it->first << " pays: " << endl;
        for (auto it2 = positive.begin(); it2 != positive.end(); it2++){
            if (((it->second != 0) && (it2->second != 0)) && (it->second > it2->second)){
                cout << "\t" << n << ") " << it2->first << ": " << it2->second << endl;
                it->second -= it2->second;
                it2->second = 0;
            }else if (((it->second != 0) && (it2->second != 0)) && (it->second < it2->second)){
                cout << "\t" << n << ") " << it2->first << ": " << it->second << endl;
                it2->second -= it->second;
                it->second = 0;
            }else if(((it->second != 0) && (it2->second != 0))){
                cout << "\t" << n << ") " << it2->first << ": " << it2->second << endl;
                it->second = 0;
                it2->second = 0;
            }
        }
        n = 1;
    }
    return 0;
}

map<string, int> collect_amounts(int ppl, int *avg){

    int counter {1};
    map<string, int> amounts;

    while(counter <= ppl){

        string name;
        int amount;

        cout << "Enter name " << counter << ": ";
        cin >> name;

        cout << "Enter amount he/she paid totally: ";
        cin >> amount;

        amounts[name] = amount;
        *avg += amount;
        counter++;

    }
    *avg /= ppl;
    return amounts;
}
