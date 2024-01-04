#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    printf("Enter the number of words in each language: ");
    scanf("%d", &n);

    char language1[n][100], language2[n][100];
    printf("Enter %d words for language 1 and their equivalents in language 2: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", language1[i], language2[i]);
       
        for (int j = 0; language1[i][j] != '\0'; j++) {
            language1[i][j] = tolower(language1[i][j]);
        }
        for (int j = 0; language2[i][j] != '\0'; j++) {
            language2[i][j] = toupper(language2[i][j]);
        }
    }

    char input[1000];
    printf("Enter a sentence in language 1: ");
    getchar(); 
    fgets(input, sizeof(input), stdin);
    
    
    char *token = strtok(input, " \n");
    printf("Equivalent sentence in language 2: ");
    while (token != NULL) {
        int len = strlen(token);
        
        for (int i = 0; i < len; i++) {
            token[i] = tolower(token[i]);
        }
       
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(token, language1[i]) == 0) {
                printf("%s ", language2[i]);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s ", token);
        }
        token = strtok(NULL, " \n");
    }
    
    return 0;
}