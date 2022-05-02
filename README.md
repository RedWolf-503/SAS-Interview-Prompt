# SAS Interview Prompt

This file was created for the SAS Sr. Associate Software Engineering position interview.
It is written in C and does not use any parsing.
To compile the file, please use `gcc -Wall --std=c99 SAS_Interview_Prompt.c -o SAS`. Then run the program using `./SAS`
There are no warnings or issues as of this writing.

While the main function uses a hard-coded value for testing purposes, the two core functions `checkDates` and `isValidDate` can be used with a submission of almost any size.

## Assumptions

- Since one of the instructions was to not use any parsing libraries, this included common functions such as `sscanf`, `atoi`, `strtok` and anything token related.
- Any string that is too short or too long is automatically invalid.
- Initially, I thought the Z from TZD represented a string. The assumption was made that Z meant a single character.
- Regarding reporting the list, the `checkDates` function will return a new list containing only the valid strings.
- All strings will have a null operator to mark the end of the string.

## Challenges

- One of the challenges that I came across was determining the best approach for scanning the strings. My initial desire was to use Regex, however I was unsure if that was considered parsing. To simplify my decision making, I deemed any parsing of characters to be offlimits for this interview.
- This led to the next issue, while it is doable to compare only characters, it does get messy when working on multiple cases and large strings. I had to refactor my code to use `isValidDate` to make the code more readable.
- The last major issue I ran into was determining how the list of data would be inserted into the program.
