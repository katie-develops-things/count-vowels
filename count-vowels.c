#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void get_full_file_path(char* filename){
    char cmd[256];
    sprintf(cmd, "find / -iname %s 2>/dev/null | tail -n 1", filename);
    
    //printf("CMD: %s \n", cmd);
    
    FILE* shell = popen(cmd,"r");

    char shell_output[256] = "\0";

    while(fgets(shell_output, sizeof(shell_output), shell)){
        //printf("SHELL OUTPUT:  %s \n", shell_output);
    }
    
    pclose(shell);

    if(shell_output[0] == '\0'){
        printf("ERROR -- nothing returned by 'find' shell cmd. File may not exist.\n");
        exit(1);
    }
    
    //remove newline char
    shell_output[strlen(shell_output)-1] = '\0';

    strcpy(filename, shell_output);
}


int get_num_vowels(char filepath[256]){

    FILE* fp = fopen(filepath, "r");

    if(!fp){
        printf("ERROR -- file could not be opened. Exiting program with code 1.\n");
        return 1;
    }

    char* curr;

    int a = 0;
    int e = 0;
    int i = 0;
    int o = 0;
    int u = 0;

    while((curr = fgetc(fp)) != EOF){
        if(curr == 'a' || curr == 'A')
            a++;
        else if(curr == 'e' || curr == 'E')
            e++;
        else if(curr == 'i' || curr == 'I')
            i++;
        else if(curr == 'o' || curr == 'O')
            o++;
        else if(curr == 'u' || curr == 'U')
            u++;
    }

    printf("\nNumber of vowels in the given file: \n\n");
    printf("a:  %d \ne:  %d \ni:  %d \no:  %d \nu:  %d \n\n", a, e, i, o, u);

    fclose(fp);

    return 0;
}


int main(int argc, char *argv[]){

    //check for filename in argument
    if(argc < 2){
        printf("ERROR -- filename and extention not present as cmd line argument. \nUsage: ./count-vowels.out filepath/filename.txt\n\n");
        return 1;
    }

    char filename[256];
    strcpy(filename, argv[1]);
    
    //printf("Filename arg: %s\n", filename);
    
    get_full_file_path(filename);
    printf("Full file path: %s \n", filename);
    
    get_num_vowels(filename);

    return 0;
}





