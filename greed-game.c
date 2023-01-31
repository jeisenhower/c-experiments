#include <stdio.h>
#include <stdlib.h>

/*

Greed is a dice game played with five six-sided dice. Your mission, should you choose to accept it, is to score a throw according to these rules. You will always be given an array with five six-sided dice values.

 Three 1's => 1000 points
 Three 6's =>  600 points
 Three 5's =>  500 points
 Three 4's =>  400 points
 Three 3's =>  300 points
 Three 2's =>  200 points
 One   1   =>  100 points
 One   5   =>   50 point

A single die can only be counted once in each roll. For example, a given "5" can only count as part of a triplet (contributing to the 500 points) or as a single 50 points, but not both in the same roll.

Example scoring

 Throw       Score
 ---------   ------------------
 5 1 3 4 1   250:  50 (for the 5) + 2 * 100 (for the 1s)
 1 1 1 3 1   1100: 1000 (for three 1s) + 100 (for the other 1)
 2 4 4 5 4   450:  400 (for three 4s) + 50 (for the 5)

*/

int score(const int dice[5]);

int main() {
    int dice[5] = {2, 4, 4, 5, 4};

    printf("Score: %d\n", score(dice));

    return 0;
}

int score(const int dice[5]) {
    int total = 0;

    int oneCount = 0;
    int twoCount = 0;
    int threeCount = 0;
    int fourCount = 0;
    int fiveCount = 0;
    int sixCount = 0;

    for (int i=0; i<5; i++) {
        switch(dice[i]) {
            case 1:
                oneCount++;
                break;
            case 2:
                twoCount++;
                break;
            case 3:
                threeCount++;
                break;
            case 4:
                fourCount++;
                break;
            case 5:
                fiveCount++;
                break;
            case 6:
                sixCount++;
                break;
        }
    }

    if (oneCount >= 3) {
        total += 1000;
        oneCount -= 3;
    }

    if (twoCount >= 3) total += 200;

    if (threeCount >= 3) total += 300;

    if (fourCount >= 3) total += 400;

    if (fiveCount >= 3) {
        total+= 500;
        fiveCount -=3;
    }

    if (sixCount >= 3) total += 600;

    total += (oneCount * 100);
    total += (fiveCount * 50);



    return total;

}


