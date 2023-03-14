# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <stdbool.h>

void set_game_values(int level, int* num, int* lives, int* ul){
    if(level == 1){
        puts("Level: Easy");
        puts("[Range: 0 - 50, Lives: 10]\n");
        *num = rand() % 51;
        *lives = 10;
        *ul = 50;
    }
    else if(level == 2){
        puts("Level: Normal");
        puts("[Range: 0 - 100, Lives: 15]\n");
        *num = rand() % 101;
        *lives = 15;
        *ul = 100;
    }
    else if(level == 3){
        puts("Level: Hard");
        puts("[Range: 0 - 300, Lives: 15]\n");
        *num = rand() % 301;
        *lives = 15;
        *ul = 300;
    }
}

int main_game(int lives, int num, int ul);
int highScore_updater(int level, int score);

int main(){
    printf("\nNumber guessing game V.1\n\n");

    
    int op1;    // option 1
    // int highScore[15] = {0};
    int lives, num;
    int ul; // upper limit
    do{
        ul = 0;
        srand(time(0));
        puts("Select one option: ");
        puts("1. Play");
        puts("2. Exit");

        printf("<> ");  // prompt
        scanf("%d", &op1);
        
        if(op1 == 1){
            while(true){
                puts("\n|| Level select ||");
                puts("1. Easy");
                puts("2. Normal");
                puts("3. Hard");
                puts("4. Exit");
                puts("");

                int op2;    // option 
                printf("# ");  // prompt
                scanf("%d", &op2);

                if(op2 == 1){
                    set_game_values(1, &num, &lives, &ul);
                    
                    main_game(lives, num, ul);
                    break;
                }
                else if(op2 == 2){
                    set_game_values(2, &num, &lives, &ul);
                    main_game(lives, num, ul);
                    break;
                }
                else if(op2 == 3){
                    set_game_values(3, &num, &lives, &ul);
                    main_game(lives, num, ul);
                    break;
                }
                else if(op2 == 4)
                    break;
            }
            
        }
        else if(op1 != 2)
            puts("\nWrong option selected, try again");
        
        puts("\n");

    }while(op1 != 2);
    return 0;
}

int main_game(int lives, int num, int ul)
{
    int value;
    int score = lives * 100;
    while(lives--){
        printf("Num: ");    // prompt
        scanf("%d", &value);

        if(value < 0 || value > ul){
            printf("Stay under the limit [0 to %d]\n", ul);
            ++lives;
            continue;
        }
        if(num == value){
            puts("|| -- You won -- ||");
            break;
        }
        else if(num > value){
            puts("|| -- The number is greater -- ||");
        }
        else{
            puts("|| -- The number is smaller -- ||");
        }
        puts("");
        score -= 100;
    }

    lives++;
    if(lives != 0){
        printf("Lives remaining: %d", lives);
        printf("\nScore: %d", score);
    }
    else{
        printf("|| -- You Lost -- ||");
        printf("\n Score: %d", score);
    }
    return 0;
}

