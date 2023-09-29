#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

int temperature_scale(){
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP){
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32));
    }
    return 0;
}

int count_input(){
    // Do not run unless you want another program stuck in the kernel :) Restart comp to fix?
    double nc;
    for (nc = 0; getchar() != EOF; ++nc){
        printf("%.0f\n", nc);
    }
    return 0;
}

int line_counter(){
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF){
        if (c == '\n'){
            ++nl;
            printf("%d\n", nl);
        }
        if (c == '0'){
            return 0;
        }
    }
}

int tab_newline_space_counter(){
    int c, counter;

    counter = 0;
    while ((c = getchar()) != EOF){
        if (c == '\n'){
            ++counter;
        }
        if (c == '\t'){
            ++counter;
        }
        if (c == ' '){
            ++counter;
        }
        printf("%.d\n", counter);
        if (c == '0'){
            return 0;
        }
    }
}


#define OUT 0
#define IN 1
int word_line_char_counter_input(){
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    printf("Input '0' to quit program.\n");
    while ((c = getchar()) != EOF){
        ++nc;
        if (c == 10){ // int 10 indiciates '\n', program didn't recognize non-carriage strings for comparision but IDE gave me integer values for what I wanted so I traded :)
            ++nl;
        }
        if (c == 32 || c == 9 || c == 10){ // int 32 indicates ' ', int 9 indicates '\t' 
            state = OUT;
        }
        else if (state == OUT){
            state = IN;
            ++nw;
        }
        if (c == 48){ // int 48 indicates '0'
            return 0;
        }
        printf("%d %d %d\n", nl, nw, nc);
    }
    return 0;
}

int array_example(){
    // this is how you declare an array in c
    int ndigit[10];
    int i;
    for (i = 0; i < 10; ++i){
        ndigit[i] = 0;
    }
    printf("This is your array: ");
    for (i = 0; i < 10; ++i){
        printf(" %d", ndigit[i]);
    }
    return 0;
}

int power(int base, int n){ // function creation example
    int i, p;

    p = 1;
    for (i = 0; i < n; ++i){
        p = p * base;
    }
    return p;
}

int pointer_example(){
    int x = 4;
    int * pX = &x; // read as: int point pX equals address (location) of x
    int y = *pX; // de-refernce -- go to this address and copy this value and set it equal to y
    printf("%d %d %d\n", x, pX, y);
    return 0;
} // for altering variables within a function you will need to pass a pointer variable if you would like to actually change the value at the address of the variable
// however with arrays, the actual address location is what is passed to the function so pointers are not required when passing arrays to functions.

// getline: read a line into s, return length
int getline(char s[], int lim){
    int c, i, length;
    length = 0;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i){
        if (c == '\n'){
            return length;
        }
        else {
            s[i] = c;
            ++length;
        }
    }
}

// Copy(to array, from array, array length limit) - copies one array to another array of the same type (unless personalized to change data type) within a given range
void copy(int to_array[], int from_array[], int limit){
    int i;
    for (i = 0; i < limit; ++i){
        to_array[i] = from_array[i];
    }
}

// takes in an input year and if the year is a leap year the program returns 1 otherwise it returns -1
int leapyear_checker(int year){
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 ==0){
        return 1;
    }
    else{
        return -1;
    }
}

// It appears that C is quite good at changing types by itself but does fail in some test cases and ofc functions require the type value they specify
int type_example(){
    int i;
    double c, temp, temp2;
    c = 12;
    i = 5;
    temp = c * (double) i;
    temp2 = c * i;
    printf("This is with type changing: %f\n", temp);
    printf("This is without type changing: %f\n", temp2);
    printf("This is with trying to do the calculation within the print statement: %f\n", (c * i));
    return 0;
}

int main(){
    printf("I am a pp hole.\n");
    return 0;
}