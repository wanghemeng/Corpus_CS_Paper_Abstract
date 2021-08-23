#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *fp_read = NULL;
    FILE *fp_write = NULL;
    char buff[10000];
    char filename[100];
    char temp;
    int first = 1;
    sprintf(filename, "abs_%s", argv[1]);

    fp_read = fopen(argv[1], "r");
    fp_write = fopen(filename, "w+");
    while (fscanf(fp_read, "%[^\n]", buff) != EOF)
    {
        fscanf(fp_read, "%c", &temp);
        if (buff[0] == 'a' &&
            buff[1] == 'b' &&
            buff[2] == 's' &&
            buff[3] == 't' &&
            buff[4] == 'r' &&
            buff[5] == 'a' &&
            buff[6] == 'c' &&
            buff[7] == 't')
        {
            first = 1;
            do
            {
                if (!first)
                {
                    fscanf(fp_read, "%c", &temp);
                }
                else
                {
                    first = 0;
                }
                fprintf(fp_write, "%s ", buff);
            } while ((fscanf(fp_read, "%[^\n]", buff) != EOF) &&
                     !(
                         buff[0] == 'b' &&
                         buff[1] == 'o' &&
                         buff[2] == 'o' &&
                         buff[3] == 'k' &&
                         buff[4] == 't' &&
                         buff[5] == 'i' &&
                         buff[6] == 't' &&
                         buff[7] == 'l' &&
                         buff[8] == 'e'));
            fprintf(fp_write, "\n");
        }
    }
    fclose(fp_read);
    fclose(fp_write);
}