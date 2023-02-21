#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
char find_file_by_name(char filename[256]){
    char cmd[] = "find / -iname %s 2>/dev/null | tail -n 1";
    FILE* shell = popen(cmd,"r");

    char shell_output[512];  //will be full filepath of filename

    fgets(shell_output, sizeof(shell_output), shell);

    if(shell_output){
        return shell_output;
    }

    printf("ERROR -- file not found on this system. Nothing to return.");
    return NULL;
}
*/


int get_num_vowels(char filepath[512]){

    FILE* fp = fopen(filepath, "r");

    if(!fp){
        printf("ERROR -- file could not be opened. Exiting program with code 1.\n");
        return 1;
    }

    char curr;

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

    printf("\nNumber of vowels in given file: \n\n");
    printf("a:  %d \ne:  %d \ni:  %d \no:  %d \nu:  %d \n\n", a, e, i, o, u);

    fclose(fp);

    return 0;
}



int main(int argc, char *argv[]){

    //check for filename in argument
    if(argc < 2){
        printf("ERROR -- filename and extention not present as cmd line argument. \nUsage: ./count-vowels.out filename.txt\n\n");
        return 1;
    }

    char filename[] = "";
    strcpy(filename, argv[1]);


    char cmd[512];
    sprintf(cmd, "find / -iname %s 2>/dev/null | tail -n 1", filename);
    FILE* shell = popen(cmd, "r");

    char shell_output[512];  //will be full filepath of filename

    fgets(shell_output, sizeof(shell_output), shell);

    pclose(shell);


/*
    if(shell_output == ""){
        printf("ERROR -- file not found on this system. Nothing to return.");
        return 1;
    }
*/
    get_num_vowels(shell_output);


    return 0;
}