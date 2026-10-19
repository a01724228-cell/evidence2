#ifndef DRAFTEVIDENCE2_DATE_H
#define DRAFTEVIDENCE2_DATE_H

#include <iostream>
using namespace std;
#include <string>

class Date {
private:
    int month;
    int day;
    int hour;
    int minute;
    int second;

    /*
     * Description: Converts a three-letter month abbreviation into its number.
     * Parameters: monthStr - month abbreviation ("Jan" ... "Dec").
     * Return value: the month number (1-12), or 0 if it is not valid.
     * Complexity: O(1)
     */
    int monthInt(const string& monthStr) {
        if (monthStr == "Jan") {
            return 1;
        }
        else if (monthStr == "Feb") {
            return 2;
        }
        else if (monthStr == "Mar") {
            return 3;
        }
        else if (monthStr == "Apr") {
            return 4;
        }
        else if (monthStr == "May") {
            return 5;
        }
        else if (monthStr == "Jun") {
            return 6;
        }
        else if (monthStr == "Jul") {
            return 7;
        }
        else if (monthStr == "Aug") {
            return 8;
        }
        else if (monthStr == "Sep") {
            return 9;
        }
        else if (monthStr == "Oct") {
            return 10;
        }
        else if (monthStr == "Nov") {
            return 11;
        }
        else if (monthStr == "Dec") {
            return 12;
        }
        return 0;
    }

public:

    /*
     * Description: Default constructor, creates a date with all its values in 0.
     * Parameters: none.
     * Return value: none.
     * Complexity: O(1)
     */
    Date() {
        month = 0;
        day = 0;
        hour = 0;
        minute = 0;
        second = 0;
    }

    /*
     * Description: Creates a date with the given values.
     * Parameters: m - month abbreviation.
     *             d - day.
     *             hr, min, sec - hour, minute and second.
     * Return value: none.
     * Complexity: O(1)
     */
    Date(const string& m, int d, int hr, int min, int sec) {
        month = monthInt(m);
        day = d;
        hour = hr;
        minute = min;
        second = sec;
    }

    /*
     * Description: Checks if the month and day of the date exist.
     * Parameters: none.
     * Return value: true if the date is valid, false otherwise.
     * Complexity: O(1)
     */
    bool isValid() {
        return month != 0 && day >= 1 && day <= 31;
    }

    /*
     * Description: Compares this date with another date.
     * Parameters: otherDate - date to compare with.
     * Return value: -1 if this date is before, 1 if it is after, 0 if they are equal.
     * Complexity: O(1)
     */
    int beforeAfter(const Date& otherDate) {
        if (month != otherDate.month) {
            if (month < otherDate.month) {
                return -1;
            }
            else if (month > otherDate.month) {
                return 1;
            }
        }
        if (day != otherDate.day) {
            if (day < otherDate.day) {
                return -1;
            }
            else if (day > otherDate.day) {
                return 1;
            }
        }
        if (hour != otherDate.hour) {
            if (hour < otherDate.hour) {
                return -1;
            }
            else if (hour > otherDate.hour) {
                return 1;
            }
        }
        if (minute != otherDate.minute) {
            if (minute < otherDate.minute) {
                return -1;
            }
            else if (minute > otherDate.minute) {
                return 1;
            }
        }
        if (second != otherDate.second) {
            if (second < otherDate.second) {
                return -1;
            }
            else if (second > otherDate.second) {
                return 1;
            }
        }
        return 0;
    }
};

#endif //DRAFTEVIDENCE2_DATE_H
