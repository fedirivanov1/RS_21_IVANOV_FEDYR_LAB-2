#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#define eps 0.00001

unsigned int method_select(void);
double f(double x);
void print_result(double a, double b, unsigned int n, double result);
double left_rectange(double a, double b, unsigned int n);
double right_rectange(double a, double b, unsigned int n);
double trap(double a, double b, unsigned int n);
double simpson(double a, double b, unsigned int n);

int main()
{
    unsigned int num_of_method; // 1 - left, 2 - right, 3 - trap, 4 - simpsons
    const double a = 0; // low limit
    const double b = 1; // high limit
    unsigned int n; // the num of spaces
    double result;
    double I1, I2;
    unsigned int N;

    num_of_method = method_select();

    switch(num_of_method)
    {
    case 1:
        {
            printf("\nEnter N\n");
            scanf("%u", &n);//
            result = left_rectange(a, b, n);
            print_result(a,b,n,result);

            N=0;
            do{
                 N=N+2;
                 I1 = left_rectange(a, b, N);
                 I2 = left_rectange(a, b, N+2);
            } while( fabs(I2-I1) > eps );
             printf("\nN= %u I(N)= %lf", N, I1);
             break;
        }
    case 2:
        {
            printf("\nEnter N\n");
            scanf("%u", &n);//
            result = right_rectange(a, b, n);
            print_result(a,b,n,result);

            N=0;
            do{
                 N=N+2;
                 I1 = right_rectange(a, b, N);
                 I2 = right_rectange(a, b, N+2);
            } while( fabs(I2-I1) > eps );
            printf("\nN= %u I(N)= %lf", N, I1);
            break;
        }
    case 3:
        {
            printf("\nEnter N\n");
            scanf("%u", &n);//
            result = trap(a, b, n);
            print_result(a,b,n,result);

            N=0;
            do{
                 N=N+2;
                 I1 = trap(a, b, N);
                 I2 = trap(a, b, N+2);
            } while( fabs(I2-I1) > eps );
            printf("\nN= %u I(N)= %lf", N, I1);
            break;
        }
    case 4:
        {
            printf("\nEnter N\n");
            scanf("%u", &n);//
            result = simpson(a, b, n);
            print_result(a,b,n,result);

            N=0;
            do{
                 N=N+2;
                 I1 = simpson(a, b, N);
                 I2 = simpson(a, b, N+2);
            } while( fabs(I2-I1) > eps );
            printf("\nN= %u I(N)= %lf", N, I1);
            break;
        }

    }



    return 0;
}

///////////////////////////////////

unsigned int method_select(void){
    unsigned int temp;

    printf("\n\n Choose your method:\n1. left\n2. right\n3. trap\n4.simspon\n>>>");
    scanf("%u", &temp);

    while(temp < 1 || temp > 4){
        printf("\nInvalid data. Enter again: ");
        scanf("%u", &temp);
    }

    system("cls");

    switch(temp){

        case 1:

            printf("You choose 1.");
        break;

        case 2:
            printf("You choose 2.");
        break;

        case 3:
            printf("You choose 3.");
        break;

        case 4:
         printf("You choose 1.");
        break;

    }

   return temp;
}

///////////////////////////

double f(double x){
    double y;
    y=pow(x,2)*sqrt(1+pow(x,3));
    return y;
}

///////////////////////////

double left_rectange(double a, double b, unsigned int n){

    double h;
    unsigned int k;
    double x;
    double sum = 0;

    h=(b-a)/n;

    x=a;

    for(k=0; k<=n-1; k++){

        sum = sum + f(x);
        x = x + h;

    }

    return sum * h;
}

///////////////////////////////

double right_rectange(double a, double b, unsigned int n){

    double h;
    unsigned int k;
    double x;
    double sum = 0;

    h=(b-a)/n;

    x=a+h;

    for(k=0; k<=n; k++){

        sum = sum + f(x);
        x = x + h;

    }

    return sum * h;

}

///////////////////////////////


double trap(double a, double b, unsigned int n){

    double sum = 0, x = 0, h;
    unsigned int k;
    h=(b-a)/n;
    x=a+h;
    for(k=0; k<=(n-1); k++){
        sum += (f(x) + (f(x)+h))/2;
        x+=h;
    }
    return sum * h;

}


///////////////////////////////

double simpson(double a, double b, unsigned int n){

    double sum1 = 0, sum2 = 0, h=0;
    unsigned int k;
    h=(b-a)/n;
    for(k=0; k<(n-1); k++){
        if(k%2==0){
            sum1 += f(a + h*k);
        }else {
            sum2 += f(a + h*k);
        }

    }
    return (f(a)+f(b) + 4*sum1 + 2*sum2)*h/3;

}

/////////////////////////////

void print_result(double a, double b, unsigned int n, double result){

    system("cls");

    printf("\n\n\n*****RESULTS*****\n\n\n");
    printf("a=%.10f b=%.10f  n=%u   Result=%.10f", a, b, n, result);

}
