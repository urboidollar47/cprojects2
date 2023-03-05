# include <stdio.h>
# include <string.h>

int input_matrix_entities(int* row1, int* row2, int* column1, int* column2, int flag){
    printf("\nEnter the number of rows and columns of matrix 1: ");   // prompt
    scanf("%d %d", &(*row1), &(*column1));
    printf("Enter the number of rows and columns of matrix 2: ");   // prompt
    scanf("%d %d", &(*row2), &(*column2));
    if(flag == 0){
        if(*row1 != *row2 && *column1 != *column2){
            puts("\n!! For this operation the number of rows and columns in both matrices should be equal !!\n");
            return 1;
        }
        else if(*row1 != *row2){
            puts("\n!! For this operation the number of rows in both matrices should be equal !!\n");
            return 1;
        }
        else if(*column1 != *column2){
            puts("\n!! For this operation the number of columns in both matrices should be equal !!\n");
            return 1;
        }
    }
    else{
        if(*column1 != *row2){
            puts("\n!! For this operation the number of columns in first matrix should be equal to the number of rows in the second matrix !!\n");
            return 1;
        }
    }
}



void input_values(int* m, int n){   // inputs the matrix value
    for(int i = 0; i < n; ++i)
        scanf("%d", &m[i]);
}
void print_matrix(int* m, int n){   // prints the matrix
    for(int i = 0; i < n; ++i)
        printf("%d ", m[i]);
}


void add_matrix(int* m1, int* m2, int* m3, int r, int c);  // matrix1, matrix2, resultant matrix, row, column
void sub_matrix(int* m1, int* m2, int* m3, int r, int c);  // matrix1, matrix2, resultant matrix, row, column
void product_matrix(int* m1, int r1, int c1, int* m2, int r2, int c2, int* m3); // matrix1, row1, column1, matrix2, row2, column2, resultant matrix

int main(){
    int select1;
    int m1[1000], m2[1000], m3[1000]; // matrix1, matrix2, matrxi3 (resultant matrix)
    int row1, row2, column1, column2; // matrix1 row and coulumn, matrix2 row and column
    int check = 0;

    do{
        puts("Select one option: ");
        puts("1. Add matrices");
        puts("2. Subtract matrices");
        puts("3. Multiply matrices");
        // puts("4. Transpose matrices");
        // puts("5. Adjoint martix");
        // puts("6. Inverse matrix");
        puts("4. Exit");

        printf("select option: ");
        scanf("%d", &select1);

        switch(select1){
            case 1: 
                    check = input_matrix_entities(&row1, &row2, &column1, &column2, 0);
                    if(check == 1)
                        break;
                    // printf("%d %d", row2 , column2);
                    // printf("%d %d", row1, column1);
                    printf("%s", "\nMatrix 1: \n");
                    input_values(m1, row1*column1);
                    printf("\n%s", "Matrix 2: \n");
                    // print_matrix(m1, row1*column1);
                    input_values(m2, row2*column2);
                    puts("");
                    // puts("");
                    // print_matrix(m2, row2*column2);
                    printf("Result: \n");
                    add_matrix(m1, m2, m3, row1, column1);
                    
                    puts("");
                    break;
            
            case 2:
                    check = input_matrix_entities(&row1, &row2, &column1, &column2, 0);
                    if(check == 1)
                        break;
                    // printf("%d %d", row2 , column2);
                    // printf("%d %d", row1, column1);
                    printf("%s", "\nMatrix 1: \n");
                    input_values(m1, row1*column1);
                    printf("\n%s", "Matrix 2: \n");
                    // print_matrix(m1, row1*column1);
                    input_values(m2, row2*column2);
                    puts("");
                    // puts("");
                    // print_matrix(m2, row2*column2);
                    printf("Result: \n");
                    sub_matrix(m1, m2, m3, row1, column1);

                    puts("");
                    break;
                    
            case 3: 
                check = input_matrix_entities(&row1, &row2, &column1, &column2, 1);
                if(check == 1)
                    break;
                printf("%s", "\nMatrix 1: \n");
                input_values(m1 ,row1*column1);
                printf("\n%s", "Matrix 2: \n");
                input_values(m2, row2*column2);

                puts("");
                printf("Result: \n");
                product_matrix(m1, row1,column1, m2, row2, column2, m3);

                puts("");
                break;

            case 4:
                break;         
            
            default :
                puts("!! INVALID OPTION !!");
                puts("Select a valid option");
        }
        puts("");
    }while(select1 != 4);
    return 0;
}

void add_matrix(int *m1, int *m2, int *m3, int r, int c)
{
    for(int i = 0; i < r*c; ++i)
        m3[i] = m1[i] + m2[i];
    
    for(int i = 0; i < r*c; ++i){
        if(i % c == 0 && i != 0)
            puts("");
        printf("%d ", m3[i]);
    }
}

void sub_matrix(int *m1, int *m2, int *m3, int r, int c)
{
    for(int i = 0; i < r*c; ++i)
        m3[i] = m1[i] - m2[i];
    
    for(int i = 0; i < r*c; ++i){
        if(i % c == 0 && i != 0)
            puts("");
        printf("%d ", m3[i]);
    }
}

void product_matrix(int *m1, int r1, int c1, int *m2, int r2, int c2, int *m3)
{
    int sum, i = 0;
    for(int k = 0; k < r1; ++k){
        for(int t = 0; t < c2; ++t){
            sum = 0;
            for(int j = k*c1, g = t; j < c1*(k+1); ++j, g += c2){
                sum += m1[j] * m2[g];
                // printf("(%d)\n", sum);
            }
            m3[i] = sum;
            ++i;
        }
    }
    
    for(int i = 0; i < r1*c2; ++i){
        if(i % c2 == 0 && i != 0)
            puts("");
        printf("%d ", m3[i]);
    }
}
