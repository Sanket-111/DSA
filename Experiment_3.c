// Practical:3 File Handling and command line arguement
// 1.To print the data from given file
#include<stdio.h>

int main(){
    FILE *fp;
    fp=fopen("FILE.txt","r");
    char c;
    
    while(1){
    c=fgetc(fp);
    if(c==EOF)
    break;

    printf("%c",c);
    }

    fclose(fp);
    return 0;
}

// 2.Writing into the file 
// Output:

// #include<stdio.h>

// int main(){
//     FILE *fp;
//     fp=fopen("FILE.txt","w");
//     fprintf(fp,"%s %s %s %s %s %s %s %s","Hello","and","Welcome","To","CODING."," Meet", "U", "Tommorow");
//     return 0;
// }