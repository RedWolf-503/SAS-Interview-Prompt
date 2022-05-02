/**
 * @file SAS_Interview_Prompt.c
 * @author Ryan Rice (rnrice2@gmail.com)
 * @date 2022-05-01
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Checks to see if the string matches the format of YYYY-MM-DDTHH:MM:SSTZD.
 * 
 * @param date The date being checked.
 * @return true if the date is in the correct format, false otherwise.
 */
bool isValidDate(char *date)
{
    // First check the length of the string
    int length = strlen(date);
    // If the length of the string is less than 20 characters, go ahead and return false.
    // The string does not fit the format.
    if (length < 20)
    {
        return false;
    }
    // A few variables to help with the parsing of the string.
    bool monthIsGreaterThanTen = false;
    bool dayIsGreaterThanThirty = false;
    bool hourIsGreaterThanTwenty = false;
    // Next, go character by character and check to see if the string matches the format.
    for (int i = 0; i < length; i++)
    {
        // The first four characters should be the YEAR
        if (i < 4)
        {
            if (date[i] < '0' || date[i] > '9')
            {
                return false;
            }
        }
        // Check to see if the next character is a DASH
        else if (i == 4 || i == 7)
        {
            if (date[i] != '-')
            {
                return false;
            }
        }
        
        // Check to see if the MONTH is valid
        else if (i == 5) 
        {
            // If the month does not have 0 or 1, then it is not valid.
            if (date[i] < '0' || date[i] > '1')
            {
                return false;
            }
            // If the date is 1, then add bound checking for the next entry.
            else if (date[i] == '1')
            {
                monthIsGreaterThanTen = true;
            }
        }
        else if (i == 6) 
        {
            if (monthIsGreaterThanTen && (date[i] < '0' || date[i] > '2'))
            {
                return false;
            }
            else if (date[i] < '0' || date[i] > '9')
            {
                return false;
            }
        }

        // Check to see if the DAY is valid
        else if (i == 8)
        {
            // If the day is not between 0 and 3, then it is not valid.
            if (date[i] < '0' || date[i] > '3')
            {
                return false;
            }
            // If the date is 3, then add bound checking for the next entry.
            else if (date[i] == '3')
            {
                dayIsGreaterThanThirty = true;
            }
        }
        else if (i == 9)
        {
            if (dayIsGreaterThanThirty && (date[i] < '0' || date[i] > '1'))
            {
                return false;
            }
            else if (date[i] < '0' || date[i] > '9')
            {
                return false;
            }
        }

        // Confirm that there is a T
        else if (i == 10)
        {
            if (date[i] != 'T')
                return false;
        }

        // Check to see if the HOUR is valid
        else if (i == 11)
        {
            // If the hour is out of bounds, then it is not valid.
            if (date[i] < '0' || date[i] > '2')
            {
                return false;
            }
            // If the hour starts with 2, then add bound checking for the next entry.
            else if (date[i] == '2')
            {
                hourIsGreaterThanTwenty = true;
            }
        }
        else if (i == 12)
        {
            // If the hour starts in the 20s, then reduce the bounds
            if (hourIsGreaterThanTwenty && (date[i] < '0' || date[i] > '3'))
            {
                return false;
            }
            // other wise, bound checking is normal
            else if (date[i] < '0' || date[i] > '9')
            {
                return false;
            }
        }

        // Check to see if the next character is a COLON
        else if (i == 13 || i == 16)
        {
            if (date[i] != ':')
            {
                return false;
            }
        }

        // Check to see if the MINUTES and SECONDS are valid
        else if (i == 14 || i == 17)
        {
            // If the minutes are out of bounds, then it is not valid.
            if (date[i] < '0' || date[i] > '5')
            {
                return false;
            }
        }
        else if (i == 15 || i == 18)
        {
            // Normal Bound checking
            if (date[i] < '0' || date[i] > '9')
            {
                return false;
            }
        }

        // Check to see if there is a Z, a plus or a minus
        else if (i == 19) 
        {
            if (date[i] == 'Z')
            {
                continue;
            }
            else if (date[i] == '+' || date[i] == '-')
            {
                // Go ahead and check the next five spots
                // Check hours first, then the colon, and finally the minutes
                i += 1; // Move to the next char
                // Check to see if the HOUR is valid
                // If the hour is out of bounds, then it is not valid.
                hourIsGreaterThanTwenty = false;
                if (date[i] < '0' || date[i] > '2')
                {
                    return false;
                }
                // If the hour starts with 2, then add bound checking for the next entry.
                else if (date[i] == '2')
                {
                    hourIsGreaterThanTwenty = true;
                }
                i += 1; // Move to the next char
                // If the hour starts in the 20s, then reduce the bounds
                if (hourIsGreaterThanTwenty && (date[i] < '0' || date[i] > '3'))
                {
                    return false;
                }
                // other wise, bound checking is normal
                else if (date[i] < '0' || date[i] > '9')
                {
                    return false;
                }

                i += 1; // Move to the next char
                // Check to see if the next character is a COLON
                if (date[i] != ':')
                {
                    return false;
                }

                i += 1; // Move to the next char
                // Check to see if the MINUTE is valid
                // If the minutes are out of bounds, then it is not valid.
                if (date[i] < '0' || date[i] > '5')
                {
                    return false;
                }
                i += 1; // Move to the next char
                // Normal Bound checking
                if (date[i] < '0' || date[i] > '9')
                {
                    return false;
                }
            }
        }

        // If after all the processing, 
        else if (i > 20)
        {
            // If the last character is not the null operater,
            if (date[i] != '\0')
            {
                // Then something is wrong and a false needs to be returned.
                return false;
            }
        }
    }

    return true;
}

/**
 * Returns a list of valid inputs.
 *
 * @param list The strings being tested.
 * @return char** The list of valid inputs.
 */
char **checkDates(char **list, int size)
{
    char **validDates = malloc(sizeof(char *) * size);
    int idx = 0;
    for (int i = 0; i < size; i++)
    {
        if (isValidDate(list[i]))
        {
            validDates[idx] = list[i];
            idx++;
        }
    }

    return validDates;
}

/**
 * Runs the program.
 * 
 * @return int Exit status.
 */
int main() 
{
    char** testInput = malloc(sizeof(char *) * 13);
    // Valid dates
    testInput[0] = "1999-12-31T23:59:59Z"; // valid Bound checks
    testInput[1] = "2000-01-01T00:00:00Z"; // valid 
    testInput[2] = "2000-01-01T00:00:00+12:00"; // valid
    testInput[3] = "2000-01-01T00:00:00-12:00"; // valid
    // Create some invalid dates
    testInput[4] = "200-01-01T00:00:00Z";  // invalid - Invalid year
    testInput[5] = "2000-21-01T00:00:00"; // invalid - Missing TZD
    testInput[6] = "2000-01-01T00:00:00+12:0000"; // invalid TZD/too long of a message
    testInput[7] = "2000-01-01T00:60:00+12:00"; // invalid minutes
    testInput[8] = "2000-01-01T00:00:60+06:00"; // invalid second
    testInput[9] = "2000-01-01T00:00:00+30:00"; // invalid TZD
    testInput[10] = "2000-41-01T00:00:00+30:00"; // invalid Months
    testInput[11] = "2000-01-00T00:00:00+30:00"; // invalid Days
    testInput[12] = ""; // Empty String


    // Get the number of test inputs
    int numDates = 13;

    // Pass each test input to the function and store a list of each valid input.
    char **validDates = checkDates(testInput, numDates);

    // 
    int numValidDates = 0;
    while (validDates[numValidDates] != NULL)
    {
        numValidDates++;
    }

    // Print the list of valid inputs.
    for (int i = 0; i < numValidDates; i++)
    {
        printf("%s\n", validDates[i]);
    }

    free(validDates);
    free(testInput);

    return 0;
}
