/*
 * status: Disabled
 *
 *
 *
 * */


#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> known_words;

bool isKnown(const string words) {
    for (auto w : known_words) {
        if (w == words) {
            return true;
        }
    }
    return false;
}

void query_all() {
    cout << endl << endl;
    cout << "\t\t***************All known words**************" << endl << endl;
    int i = 1;
    for (auto w : known_words) {
        cout << w << "\t";
        if (i % 10 == 0) {
            cout << endl;
            i = 1;
        }
        i++;
    }
    cout << endl << endl;
}

void check_words(const string words) {
    if (!isKnown(words)) {
        string choice;
        do {
            cout << "whether or not check all known words(yes/no): ";
            cin >> choice;
        } while(choice != "no" && choice != "yes");
        
        if (choice == "yes") {
            query_all();
        }

        cout << "Please define of " << words << endl;
        cout << "Example:" << endl;
        cout << "\twords quantity:5" << endl;
        cout << "\tdefinition: aaa bbb ccc ddd eee" << endl << endl;
        

        int quantity;
        cout << "words quantity of definition: ";
        cin >> quantity;
        cout << "definition: ";
        vector<string> def;
        string temp;
        for (int i = 0; i < quantity; i++) {
            cin >> temp;
            def.push_back(temp);
        }
        for (auto w : def) {
            if (w != words) {
                check_words(w);
            }
        }
        known_words.push_back(words);
    }
}

void getVocabulary() {
    cout << "please input your vocabulary:" << endl;
    int n;
    cout << "quantify(words): ";
    cin >> n;
    string input;
    cout << "words(separate by space): ";
    for (int i = 0; i < n; i++) {
        cin >> input;
        known_words.push_back(input);
    }
    cout << endl << endl;
}

int main() {
    getVocabulary();
    string words;
    cout << "Pleas input a words that need checking: ";
    cin >> words;
    check_words(words);
    cout << words << " query successful." << endl;
    return 0;
}
