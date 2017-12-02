#include <stdio.h>
#include <time.h>
#include <math.h>


#define bool int
#define true 1
#define false 0

bool val_in_array(double roots[], double value, double find);
bool in_array(double roots[],double value);


bool is_prime(double num){

    //Doesn't for for num =2, but I felt that was okay for the large numbers
    if(fmod(num,2) == 0){
        return false;
    }
    for(int i = 3; i < sqrt(num)+1;i++){
        if(fmod(num,i)== 0){
            return false;
        }
    }

    return true;
}

bool is_primative_root(double value,double num){
    double roots[(int)value-1];
    for(int i = 1; i < value; i++){
        double ex = pow(num,i);
        roots[i-1] = fmod(ex,value);
    }
    int x = in_array(roots,value);
    return x;
}

bool in_array(double roots[],double value){
    for(int num = 0; num < value-1; num++){
        if(val_in_array(roots,value,num+1) == 0){
            return false;
        }
    }
    return true;
}

bool val_in_array(double roots[],double value,double find){
    for(int num = 0; num < value; num++){
        if(roots[num] == find){
            return true;
        }
    }
    return false;
}

double prime_number_gen(int size){
    return 19;
}

double get_alpha(double value){

    double rand_val;
    bool check = false;
    while(check == false){
        //random value for 13 here
        rand_val = 13;
        check = is_primative_root(rand_val,value);
    }
    return rand_val;
}

int get_digits(int size){
    int return_val = 1;
    for(int i =0; i < size; i++){
        return_val*=10;
    }
    return return_val;
}

double compute_y(double alpha,double random,double prime){
        double ex = pow(alpha,random);
        return fmod(ex,prime);
}

int main(){
    double Alice_num = 4;
    double Bob_num = 3;
    double p = 23;
    double alpha = 5;
    double A;
    double B;
    printf("%d\n",is_primative_root(17,3));
    A = compute_y(alpha,Alice_num,p);
    B = compute_y(alpha,Bob_num,p);
    printf("%lf,%lf\n",A,B);
    double s1 = (double)fmod(pow(B,Alice_num),p);
    double s2 = (double)fmod(pow(A,Bob_num),p);
    printf("%lf,%lf\n",s1,s2);
    if(s1==s2){
        printf("We've got a working secret key!\n");
    }
    
}
