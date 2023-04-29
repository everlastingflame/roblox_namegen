#include <stdio.h>
#include <string.h>

void generate_combinations(char arr[], int n, int r, FILE *fp)
{
    char data[r];
    for (int i = 0; i < n; i++) {
        data[0] = arr[i];
        for (int j = 0; j < n; j++) {
            data[1] = arr[j];
            for (int k = 0; k < n; k++) {
                data[2] = arr[k];
                if (data[0] == '_') continue;  // underscore can't be the first character
                if (data[1] != '_' && data[2] == '_') continue;  // underscore can only be in the middle
                if (arr[k] != '_' || (arr[k] == '_' && strchr(data, '_') == NULL)) {  // allow repetition for every character except '_'
                    fprintf(fp, "%c%c%c\n", data[0], data[1], data[2]);
                }
            }
        }
    }
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '_'};
    int n = sizeof(arr)/sizeof(arr[0]);
    int r = 3;

    // Open a file for writing
    FILE *fp = fopen("3char.txt", "w");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    // Generate and write the combinations to file
    generate_combinations(arr, n, r, fp);

    // Close the file
    fclose(fp);

    return 0;   
}
