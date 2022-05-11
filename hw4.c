#include <stdio.h>
#include <math.h>
#include <ctype.h>
void question_one (void);
void question_two (void);
void letter_grade(char *gradep, int *just_missedp);
void question_four(void);
int letter_location(char ch);//goes with number 4


int main() {
 question_one();
 question_two();
 letter_grade (gradep*, int just_missedp*); //question three.
 question_four();
 int letter_location(char ch);
 return 0;
}

void question_one (void){
int x;

for (x=0; x<7; x++){
printf("%3d %3d\n", x, (int) pow(2,x));


}
}

void question_two (void){
int x;
int nums [10];
double number;

for (x=0; x<10;x++ ){
printf("Enter an integer");
scanf ("%d", &nums[x]);
}

printf("\nn   %% of total");

for (x=0; x<10; x++){
number= nums[x];

printf("\n %3d %3.2f", nums[x], number/2);

}
}


void letter_grade(char *gradep, int *just_missedp){

    int points;
    printf("Enter your grade");
    scanf("%d", &points);
if (points<101 && points>=-1){
    if (points>=90 && points<=100)
    {
        *gradep='A';
        printf("You got an A\n\n");
    }

    else if (points>=80 && points<=89) {
        *gradep='B';
        printf("You got a B");
        if (points==89){

            printf("You just missed an A");
        }
        else
            (*just_missedp=0);
    }
    else if (points>=70 && points<=79)
    {
        *gradep='C';
        printf("You got a C");
        if (points==79)
            printf("You just missed a B");
        else
            (*just_missedp=0);


    }
else if (points>=60 && points <=69){

    *gradep='D';
    printf("You got a D");
    if (points==69)
        printf("You just missed a C");
    else
        *just_missedp=0;

}
else
    printf("You failed\n");}
else
printf("Invalid grade entry");

return ;

}
















void question_four (void){

char ch;
	int location;

	while ((ch = getchar()) != EOF)
	{
		if ((location = letter_location(ch)) == -1)
			printf("%c is not a letter\n", ch);  //could not find out why it said "is not a letter" in the output
		else
			printf("%c is a letter: location = %d\n", ch, location);
	}
}

int letter_location(char ch)
{

	if (isalpha(ch))
	{
		ch = tolower(ch);
		return (ch - 96);
	}
	else
		return -1;
}


