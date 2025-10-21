#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    int lower_bound = 0;
    int upper_bound = 0;
    int l_found = 0;
    int u_found = 0;
    int i;

    for (i = 1; i < argc; i++){
        if (strncmp(argv[i], "--lower_bound=", 14) == 0){
		lower_bound = atoi(argv[i]+14);
		l_found = 1;
        }
        else if (strncmp(argv[i], "--upper_bound=", 14) == 0){
		upper_bound = atoi(argv[i]+14);
		u_found = 1;
        }
    }

    if (l_found == 0 && u_found == 0){
        fprintf(stderr, "No flags found.");
        return 1;
    }

    if (upper_bound <= lower_bound){
        printf("The lower bound is greater than the upper bound.\n");
        return 1;
    }

    if (l_found == 0){
        fprintf(stderr, "Flag --lower_bound is missing.");
        return 1;
    }

    if (u_found == 0){
        fprintf(stderr, "Flag --upper_bound is missing.");
        return 1;
    }

    for (i = lower_bound; i <= upper_bound; i++){
        printf("%d ", i);
    }

    printf("\n");
    return 0;
}
