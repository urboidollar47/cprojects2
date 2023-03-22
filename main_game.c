# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# include <unistd.h>
# include <stdbool.h>
# include <time.h>

int fixX = 30, fixY = 20;
int x, y;
int set = 0;
int flag = 1;   // used to navigate in main menu
int score, highScore[5] = {100, 70, 40, 30, 20};
int foodx, foody;   // for the position of the food in the field
// int eat = 0;    // tells if the fruit is eaten or not
int snake_x, snake_y;   // snakes movement
int reset = 1;
int pause_menu_flag = 1;    // to navigate the pause menu

// main menu
void draw_main_menu();
void input_main_menu();
void setup_main_menu();

// main game
void draw_main_game();
void setup_main_game();
void input_main_game();
void logic_main_game();

// pause menu
void input_pause_menu();
void setup_pause_menu();

// highScore
void draw_high_score();
void highscore_count();


int main(){

    while(true){
        sleep(0.5);
        input_main_menu();
        draw_main_menu();
        if(set){
            if (set == 1){
                reset  = 1; // if 0 then game over
                snake_x = fixX/2;
                snake_y = fixY/2;
                score = 0;  // initial score set to 0
                setup_main_game();
                while(true){
                    sleep(0.5);
                    input_main_game();
                    logic_main_game();
                    draw_main_game();
                    highscore_count();  // manages the highScore
                    if(reset == -1) // pause menu
                    {
                        while(true){
                            sleep(0.5);
                            input_pause_menu();
                            draw_main_game();
                            if(reset == 0 || reset == 1)
                                break;
                            system("cls");
                        }
                    }
                    if(reset == 0)  // game over
                    {
                        sleep(3);   // displays score {hold screen for 3 secs}
                        draw_main_game();
                        break;
                    }
                    system("cls");
                }
                set = 0;
            }
            else if(set == 2){  // highscore
                system("cls");
                draw_high_score();
                sleep(5);   // hold for 5 secs
                set = 0;
            }
            else if(set == 3)
                break;
        }
        system("cls");
        // scanf("%[a-z]");
    }

    // draw_main_menu();
    return 0; 
}

// main menu
void draw_main_menu()
{
    for(y = 1; y <= fixY; ++y){      // vertically printed
        for(x = 1; x <= fixX; ++x){     // horizontally printed
            if(y == 1 || y == fixY){    // top and bottom border
                if(x % 2 == 0)
                    printf("*");
                else
                    printf(" ");
            }
            
            else if(x == 1 || x == fixX)    // left and right border
                printf("*");
            
            else if(y == 3 && x == fixX/2-5){   // display game name
                printf("Snake Game ");
                x += 10;
            }
            
            else if(y == 4 && x == fixX/2-4){     // underline game name
                printf("--------");
                x += 7;
            }

            else if(y == 18 && x == fixX/4-4){   // option selection instruction printed below the screen - part1
                printf("Use 'w' or 's' to navigate");
                x  += 25;
            }

            else if(y == 19 && x == fixX/4){  // option selection instruction printed below the screen - part2
                printf("press 'e' to select");
                x += 18;
            }

            else
                printf(" ");
            
            setup_main_menu();
        }
        puts("");
    }
}

void input_main_menu()
{
    if(kbhit()){
        switch (getch())
        {
        case 's':
            flag++;

            if(flag == 4)
                flag = 1;
            break;
        
        case 'w':
            flag--;
            
            if(flag == 0)
                flag = 3;
            break;

        case 'e':
            if(flag == 1)   // if option 1 is selected
                set = 1;  
            else if(flag == 2)  // if option 2 is selected
                set = 2;
            else if(flag == 3)  // if option 3 is selected
                set = 3;            
        }

    }
}

void setup_main_menu()
{
            // menu options
            if((flag == 1) && (y == 6 || y == 8 || y == 10)){ //option 1 (these are for navigations)
                if(y == 6 && x == fixX/2-5){
                    printf("> Play");
                    x += 6;
                }
                else if(y == 8 && x == fixX/2-3){
                    printf("HigScore");
                    x += 8;
                }
                else if(y == 10 && x == fixX/2-3){
                    printf("Exit");
                    x += 4;
                }
            }
            else if((flag == 2) && (y == 6 || y == 8 || y == 10)){ //option 2 (these are for navigations)
                if(y == 6 && x == fixX/2-3){
                    printf("Play");
                    x += 4;
                }
                else if(y == 8 && x == fixX/2-5){
                    printf("> HigScore");
                    x += 10;
                }
                else if(y == 10 && x == fixX/2-3){
                    printf("Exit");
                    x += 4;
                }
            }
            else if((flag == 3) && (y == 6 || y == 8 || y == 10)){ //option 2 (these are for navigations)
                if(y == 6 && x == fixX/2-3){
                    printf("Play");
                    x += 4;
                }
                else if(y == 8 && x == fixX/2-3){
                    printf("HigScore");
                    x += 8;
                }
                else if(y == 10 && x == fixX/2-5){
                    printf("> Exit");
                    x += 6;
                }
            }
}


void draw_main_game()
{
    for(y = 1; y <= fixY; ++y){ // height
        for(x =1; x <= fixX; ++x){  // breadth
            if(reset == 1)  // main game display
            {if(x == 1 || x == fixX)
                printf("*");
            else if(y == 1 || y == fixY){
                if(x % 2 == 0)
                    printf("*");    // top and bottom border
                else
                    printf(" ");
            }            
            else if(x == snake_x && y == snake_y){
                printf("O");
                // ++x;
                // ++y;
            }
            else if(x == foodx && y == foody)
                printf("+");

            else 
                printf(" ");
            }
            
            else if(reset == -1){   // pause menu display
                if(x == 1 || x == fixX)
                    printf("*");
                else if(y == 1 || y == fixY){
                    if(x % 2 == 0)
                        printf("*");
                    else
                        printf(" ");
                }
                else
                    printf(" ");
                setup_pause_menu();
            }

            else if(reset == 0){    // display score
                if(y == 1 || y == fixY){
                    if(x % 2 == 0)
                        printf("*");
                    else
                        printf(" ");
                }
                else
                    printf(" ");
                
                if(y == fixY/2-1 || y == fixY/2 + 1){
                    if(x == fixX/2 -4 && y == fixY/2 -1){
                        printf("Score: %d", score);
                    }
                    else if(x == fixX/2 -8 && y == fixY/2 +1){
                        printf("Highest score: %d", highScore[0]);
                    }
                }
            }
        }
        puts("");
    }
    printf("%17s %d", "Score:",score);  // display score
    puts("\n");
    printf("%23s", "Press x to pause");
}


void input_main_game(){
    if(kbhit()){
        switch(getch()){
            case 'w':
                --snake_y;
                break;
            case 's':
                ++snake_y;
                break;
            case 'a':
                --snake_x;
                break;
            case 'd':
                ++snake_x;
                break;
            case 'x':
                reset = -1;
        }
    }
}

void setup_main_game(){
    srand(time(0));
    label1: 
        foodx = rand() % fixX + 3;
    if(foodx <= 1 || foodx >= fixX)
        goto label1;
    
    label2:
        foody = rand() % fixY + 3;
    if(foody <= 1 || foody >= fixY)
        goto label2;
}

void logic_main_game(){
    if(snake_x == foodx && snake_y == foody){
        score += 10;
        setup_main_game();
    }
    else if(snake_x <= 1 || snake_x >= fixX || snake_y <= 1 || snake_y >= fixY){
        reset = 0;
    }
}   


void input_pause_menu(){
    if(kbhit()){
        switch(getch()){
            case 's':
                pause_menu_flag++;
                if(pause_menu_flag > 2)
                    pause_menu_flag = 1;
                break;
            
            case 'w':
                pause_menu_flag--;
                if(pause_menu_flag < 1)
                    pause_menu_flag = 2;
                break;

            case 'e':
                if(pause_menu_flag == 1)
                    reset = 1;
                else if(pause_menu_flag == 2)
                    reset = 0;
        }
    }
}

void setup_pause_menu()
{
    if((pause_menu_flag == 1) && (y == fixY/2-1 || y == fixY/2 +1)){
        if(x == fixX/2-4 && y == fixY/2-1){
            printf("> Resume");
            x += 8;
        }
        else if(x == fixX/2-2 && y == fixY/2+1){
            printf("Exit");
            x += 4;
        }
    }
    else if((pause_menu_flag == 2) && (y == fixY/2-1 || y == fixY/2+1)){
        if(x == fixX/2-2 && y == fixY/2-1){
            printf("Resume");
            x += 6;
        }
        else if(x == fixX/2-4 && y == fixY/2 +1){
            printf("> Exit");
            x += 6;
        }
    }
}

void draw_high_score()
{
    for(int i = 1, k = 0; i <= fixY; ++i){
        for(int j = 1; j <= fixX; ++j){
            if(i == 1 || i == fixY){
                if(j % 2 == 0)
                    printf("*");    // top and bottom border
                else
                    printf(" ");
            }
            else
                printf(" ");

            if(i == fixY/2 -5 && j == fixX/2 -4){
                printf("HighScore");
            }
            else if(i >= fixY/2 -3 && i <= fixY/2 + 6){
                if(i % 2 == 0 && j == fixX/2 -2){
                    printf("%d. %d", k+1, highScore[k]);
                    ++k;
                }
            }
        }
        puts("");
    }
}

void highscore_count()
{
    for(int i  = 0; i < 5; ++i){
        if(score > highScore[i]){
            for(int j = i; j < 4; ++j){
                highScore[j+1] = highScore[j];
            }
            highScore[i] = score;
            // break;
        }
    }
}
