#include <stdio.h>
#include <stdlib.h>
#include <math.h>





void questionone (void);
void questiontwo (void);
void questionthree(void);
int main (void){
questionone();
questiontwo();
questionthree();

return 0;
}
void questionone(void){
int weight, height; // height in inches, weight in lbs
printf("Enter your height in inches ");
scanf("%d", &height);//added & and "

printf("Enter your weight in lbs: ");
scanf("%d", &weight);

if (weight<100 && height >=72)
printf("You are very tall for your weight. \n");
else if (weight<72&& height>64)// i put height before >64
    printf("You are tall for your weight. \n");
else if (weight>300 && height < 48)
    printf("You are quite short for your weight. \n");
//removed  if (!(height>=48)
               else
                printf("You are ideal for your weight. \n");
}
void questiontwo (void){
double n;

printf("Enter a Richter Scale value ");
scanf("%lf", &n);

if (n<5.0)
printf("Little or no damage");
else if (n>=5 && n<5.5)
printf("Some damage");
else if(n>=5.5 && n<6.5)
printf("Serious damage: walls may crack or fall");
else if (n>=6.5 && n<7.5)
printf("Disaster: houses and buildings may collapse");
else
printf("Catastrophe:most buildings destroyed");

}

void questionthree (void){
int taxcategory;
double income;
double tax;
printf("\nEnter your taxable income and tax category(Single=1, Head of Household=2, Married Joint=3, and Married Separate=4 ");
scanf("%lf%d", &income, &taxcategory);
switch (taxcategory){
case 1:
if (income>0 && income <=18750){
    tax=0.15*income;
    printf("Your tax equals %lf", tax);
}

break;
case 2:
if (income>0 &&income <=23900){
    tax=0.15*income;
    printf("Your tax equals %lf", tax);
}
break;
case 3:
if (income>0 && income <=29750){
    tax=0.15*income;
    printf("Your tax equals %lf", tax);
}
break;
case 4:
if (income>=0 && income <=14875){
    tax=0.15*income;
    printf("Your tax equals %lf", tax);
}
break;
default:
printf("Your tax is invalid");
}

}
















