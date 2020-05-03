https://cs50.harvard.edu/x/2020/psets/4/recover/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//create new variable type for storing bytes
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check the user haAs written command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    char *infile = argv[1];

    //open file user specifies
    FILE *file = fopen(infile, "r");
    if (!file)
    {
        return 1;
    }

    //array called buffer to store bytes
    BYTE buffer[512];

    char filename[20];
    int filenum = 0;
    FILE *img = NULL;

    //condition to iterate through file (hopefully!)
    while (fread(buffer, 512, 1, file) == 1)
    {
        //check if jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //check if not first image
            if (filenum != 0)
            {
                 fclose(img);//close current image writing to
            }

            sprintf(filename, "%03i.jpg", filenum); //sets format of filename to three integer digits
            img = fopen(filename, "w"); //open new image file and name it
            fwrite(&buffer, sizeof(buffer), 1, img); //write 512 bytes you just read to the file you just opened
            filenum ++; //int representing file name
        }
        else if (img)
        {
            fwrite(&buffer, sizeof(buffer), 1, img);
        }
    }
    fclose(file);
    return 0;


}
