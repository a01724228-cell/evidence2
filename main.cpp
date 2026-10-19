/*
 * File name: main.cpp
 * Description: Reads the log file, sorts its records by date, asks the user for a start
 * date and an end date, shows the records in that range and saves them
 * in an output file.
 * Authors: Edgardo Meade Hernández A01254666, Sofía Montserrat García Lozano A01724228,
 * Emilio Alejandro Ávila Almaguer A01199645
 * Created: September 25, 2026
 */
#include <iostream>
using namespace std;
#include "Date.h"
#include "DoublyLinkedList.h"
#include "SortedLog.h"
#include <fstream>
#include <sstream>
#include <vector>

string threeDigits(int number) {
    if (number < 10) {
        return "00" + to_string(number);
    }
    else if (number < 100) {
        return "0" + to_string(number);
    }
    return to_string(number);
}

/*
 * Description: Asks the user for a date until a valid one is entered.
 * Parameters: message - text shown to the user.
 *             hr, min, sec - hour, minute and second assigned to the date.
 * Return value: date - the date entered by the user.
 * Complexity: O(1)
 */
Date askDate(const string& message, int hr, int min, int sec) {
    string monthStr = "";
    int day = 0;
    Date date;
    bool valid = false;

    while (!valid && !cin.eof()) {
        cout << message;
        cin >> monthStr >> day;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            day = 0;
        }
        date = Date(monthStr, day, hr, min, sec);
        valid = date.isValid();
        if (!valid) {
            cout << "Invalid date, use the format: Jun 1" << endl;
        }
    }
    return date;
}

/*
 * Description: Reads the log file, sorts the records by date, searches the records
 * between the dates given by the user, shows them and saves them.
 * Parameters: inputFileStr - name of the log file.
 *             outputFileStr - name of the file where the results are saved.
 * Return value: nothing.
 * Complexity: O(nlog(n))
 */
void files (const string& inputFileStr, const string& outputFileStr) {
    ifstream inputFile(inputFileStr);
    ofstream outputFile(outputFileStr);
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error opening the files" << endl;
        return;
    }

    DoublyLinkedList list;
    string completeLine;

    while (getline(inputFile, completeLine)) {
        stringstream line(completeLine);
        string monthStr;
        int day, hr, min, sec, ip1, ip2, ip3, ip4, port;
        char colon1, colon2, dot1, dot2, dot3, colon3;

        line >> monthStr >> day >> hr >> colon1 >> min >> colon2 >> sec;
        Date date(monthStr, day, hr, min, sec);

        line >> ip1 >> dot1 >> ip2 >> dot2 >> ip3 >> dot3 >> ip4 >> colon3 >> port;
        string ipStr = threeDigits(ip1) + threeDigits(ip2) + threeDigits(ip3) + threeDigits(ip4);

        list.addNode(ipStr, date, completeLine);
    }
    inputFile.close();

    list.quickSort(list.getHead(), list.getTail());

    Date startDate = askDate("Start date (example: Jun 1): ", 0, 0, 0);
    Date endDate = askDate("End date (example: Jun 5): ", 23, 59, 59);

    int first = logSort.searchFirst(startDate);
    int last = logSort.searchLast(endDate);

    NodeDoubly* current = list.getHead();
    NodeDoubly* end = list.getTail();

    while (current != nullptr) {
        outputFile << current->line << endl;
        if (current == end) {
            break;
        }
        current = current->next;
    }

    if (first < last) {
        cout << last - first << " records found" << endl;
    }
    else {
        cout << "No records found" << endl;
    }
    outputFile.close();
}

/*
 * Description: Runs the program using the files that are in the folder of the executable.
 * Parameters: argc - number of arguments.
 *             argv - arguments, argv[0] is the path of the executable.
 * Return value: 0 when the program ends.
 * Complexity: O(1)
 */
int main(int argc, char* argv[]) {
    string folder = argv[0];
    folder = folder.substr(0, folder.find_last_of("/\\") + 1);

    files(folder + "bitacora.txt", folder + "testCase1.txt");
    files(folder + "bitacora.txt", folder + "testCase2.txt");
    files(folder + "bitacora.txt", folder + "testCase3.txt");
    files(folder + "bitacora.txt", folder + "testCase4.txt");

    return 0;
}
