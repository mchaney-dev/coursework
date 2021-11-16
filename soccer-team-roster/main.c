#include <stdio.h>
#include <stdbool.h>

/* FUNCTION DEFINITIONS */

// prints menu
void printMenu() {
    
    printf("MENU\n");
    printf("o - Output roster\n");
    printf("u - Update player rating\n");
    printf("a - Output players above a rating\n");
    printf("r - Replace player\n");
    printf("q - Quit\n");
    
    printf("Choose an option:\n");
}

// gets roster length from input
int getRosterLength(void) {
    int rosterLength;
    printf("How many players to enter: \n");
    scanf("%d", &rosterLength);
    
    return rosterLength;
}

// populate arrays with values
int createArrays(int* roster, int* rating, int rosterLength) {
    int i;
    int k;
    int tempJerseyNum;
    int tempRating;
    bool validJersey = false;
    bool validRating = false;
    
    k = 1;
    for (i = 0; i < rosterLength; i++) {
        printf("Enter player %d's jersey number:\n", k);
        scanf("%d", &tempJerseyNum);
        // jersey numbers can only be 0 - 99
        if ((tempJerseyNum >= 0) && (tempJerseyNum <= 99)) {
            roster[i] = tempJerseyNum;
            validJersey = true;
        }
        printf("Enter player %d's rating:\n", k);
        scanf("%d", &tempRating);
        // ratings can only be 1 - 10
        if ((tempRating >= 1) && (tempRating <= 10)) {
            rating[i] = tempRating;
            validRating = true;
        }
        
        // get new jersey number if not valid
        while (validJersey == false) {
            scanf("%d", &tempJerseyNum);
            // jersey numbers can only be 0 - 99
            if ((tempJerseyNum >= 0) && (tempJerseyNum <= 99)) {
                roster[i] = tempJerseyNum;
                validJersey = true;
            }
        }
        
        // get new rating if not valid
        while (validRating == false) {
            scanf("%d", &tempRating);
            // ratings can only be 1 - 9
            if ((tempRating >= 1) && (tempRating <= 9)) {
                rating[i] = tempRating;
                validRating = true;
            }
        }
        k = k + 1;
        printf("\n");
    }
}

// outputs roster
char printRoster(int* roster, int* rating, int rosterLength) {
    int i;
    int k;
    
    printf("ROSTER\n");
    k = 1;
    for (i = 0; i < rosterLength; i++) {
        printf("Player %d -- Jersey number: %d, Rating: %d\n", k, roster[i], rating[i]);
        k = k + 1;
    }
}

// updates player rating
char updateRating(int* roster, int* rating, int rosterLength) {
    int i;
    int newRating;
    int jerseyNumber;
    bool matchFound = false;
    
    printf("Enter a jersey number:\n");
    scanf("%d", &jerseyNumber);
    
    // check if jersey number is in roster
    for (i = 0; i < rosterLength; i++) {
        if (jerseyNumber == roster[i]) {
            // update rating if player is in roster
            printf("Enter a new rating for player:\n");
            scanf("%d", &newRating);
            rating[i] = newRating;
            matchFound = true;
        }
    }
    
    // if player is not in roster, print error message
    if (matchFound == false) {
        printf("Player not in roster.\n");
    }
}

// output players above rating
char outputAboveRating(int* roster, int* rating, int rosterLength) {
    int i = 0;
    int k;
    int ratingAbove;
    
    printf("Enter a rating:\n");
    scanf("%d", &ratingAbove);
    
    printf("ABOVE %d\n", ratingAbove);
    for (i = 0; i < rosterLength; i++) {
        if (rating[i] > ratingAbove) {
            k = i + 1;
            printf("Player %d -- Jersey number: %d, Rating: %d\n", k, roster[i], rating[i]);
        }
    }
}

// replace player
char replacePlayer(int* roster, int* rating, int rosterLength) {
    int i;
    int newRating;
    int jerseyNumber;
    int newJerseyNumber;
    bool matchFound = false;
    
    printf("Enter a jersey number:\n");
    scanf("%d", &jerseyNumber);
    
    // check if jersey number is in roster
    for (i = 0; i < rosterLength; i++) {
        if (jerseyNumber == roster[i]) {
            // update jersey number if player is in roster
            printf("Enter a new jersey number:\n");
            scanf("%d", &newJerseyNumber);
            roster[i] = newJerseyNumber;
            
            // update rating if player is in roster
            printf("Enter a rating for the new player:\n");
            scanf("%d", &newRating);
            rating[i] = newRating;
            matchFound = true;
        }
    }
    
    // if player is not in roster, print error message
    if (matchFound == false) {
        printf("Player not in roster.\n");
    }
}

// get menu input
void getInput(char input, int* roster, int* rating, int rosterLength) {
    char newInput;
    
    if (input == 'o') {
        printRoster(roster, rating, rosterLength);
    }
    else if (input == 'u') {
        updateRating(roster, rating, rosterLength);
    }
    else if (input == 'a') {
        outputAboveRating(roster, rating, rosterLength);
    }
    else if (input == 'r') {
        replacePlayer(roster, rating, rosterLength);
    }
    else if (input == 'q') {
        return;
    }
    
    printMenu();
    scanf(" %c", &newInput);
    getInput(newInput, roster, rating, rosterLength);
}

/* MAIN FUNCTION */

int main(void) {
    int arrayLength;
    char menuInput;
    
    // get arrayLength for array initialization
    arrayLength = getRosterLength();
    // initialize arrays
    int playerNum[arrayLength];
    int playerRating[arrayLength];
    
    // populate arrays with values
    createArrays(playerNum, playerRating, arrayLength);
    
    // get menu input
    printMenu();
    scanf(" %c", &menuInput);
    if (menuInput != 'q') {
        getInput(menuInput, playerNum, playerRating, arrayLength);
    }
    else {
        return 0;
    }
}
