/**
 * Elements separated by .
 * variables separated by ,
 * message endindicated by ;
 *
 * element[0] = umbrella
 * element[1] = animation
 * element[2] = speed
 * element[3] = color[3]
 *
 */

#include <string>
#include <iostream>
#include <vector>

#include "Format.h"

using namespace std;

Format::Format(void) {
    msgElementPos = 0;
    msgElementVariablePos = 0;
    memset(colour, 0, sizeof(colour));
}

void Format::decode(string& input) {

	string element = "";

    for (int i = 0; i < input.length(); i++) {

        if (input[i] == '.' || i == (input.length() - 1)) {

            if (i == (input.length() - 1)) {
                element += input[i];
            }

            // set variables
			if (msgElementPos == 0) {
                umbrella = stringToInteger(element);
            }  else if (msgElementPos == 1) {
                animation = stringToInteger(element);
            }  else if (msgElementPos == 2) {
                speed = stringToInteger(element);
            }  else if (msgElementPos == 3) {
                cout << element << " : " << msgElementVariablePos << endl;
            }

            element = "";
            msgElementPos++;
            msgElementVariablePos = 0;
        }

        if (input[i] == ',') {
            element += input[i];
            msgElementVariablePos++;
        }

        if (input[i] != ',' && input[i] != '.' && input[i] != ';') {
            element += input[i];
        }

    }
}

vector<int> Format::split(std::string& splitDelegate, char delimiter) {

    vector<int> elements;

    string numberStr = "";

    for (int i = 0; i < splitDelegate.length(); i++) {
        if (splitDelegate[i] != delimiter) {
            numberStr += splitDelegate[i];
        } else if (splitDelegate[i] == delimiter || i == (splitDelegate.length() - 1)) {
            elements.push_back(stringToInteger(numberStr));
            numberStr = "";
        }
    }

    return elements;
}

int Format::stringToInteger(string& input) {
    if (input.length() > 0) {
        return stoi(input);
    } else {
        return 0;
    }
}
