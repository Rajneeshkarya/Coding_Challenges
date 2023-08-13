//Reverse_Engineering game
//Created by :- Rajneesh K. Arya

#include <stdio.h>
#include <string.h>

int eval(){
    int a = (((((((10 / 10) + 10)/10)-10)*10)-10)/10)+10;
    further(a);
}
int further(int a){
    a = (((a+sizeof(int)+sizeof(char))*10)-20)/10;
    return a;
}

int main(){

    char hash[20] = "r81o26g91g44u71lyh";
    char salt[12] = "8126914471";
    char new_pass[19];
    char int_pass[9];

    int l = strlen(hash);
    int sl = strlen(salt);


    printf("Your Task is to guess the password (HINT : Analyse the code to retrieve the password)\n\n");

    printf("Password:");
    fgets(int_pass,9,stdin);

    int i=0,j=0,k=0;


    while(i<l){
        if(i%3==0 || i == 0){
            new_pass[i] = int_pass[j] + eval();
            j++;
        }
        else{
            if(k<10){
                new_pass[i] = salt[k];
                k++;
            }
            else{
                new_pass[i] = int_pass[j] + eval();
                j++;
            }
        }
        i++;
    }

    new_pass[l] = '\0';

    int ans = strcmp(hash,new_pass);
    
    if(!ans){
        printf("YOu got a correct Answer\n");
    }
    else{
        printf("Wrong Answer !!!!\nYou need more Practice\n");
    }
    return 0;
}
