#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //create temporary storage for pixel info
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;
            //calculate average
            float average = ((blue + green + red) / 3) + 0.5;
            int av = (int) average;
            //assign back to variables
            image[i][j].rgbtBlue = av;
            image[i][j].rgbtGreen = av;
            image[i][j].rgbtRed = av;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            //separate into temp variables
            float orig_red = image[i][j].rgbtRed;
            float orig_green = image[i][j].rgbtGreen;
            float orig_blue = image[i][j].rgbtBlue;

            //calculate sepia values for each colour using formula
            float sepiared = ((0.393 * orig_red) + (0.769 * orig_green) + (0.189 * orig_blue) + 0.5);
            float sepiagreen = ((0.349 * orig_red) + (0.686 * orig_green) + (0.168 * orig_blue) + 0.5);
            float sepiablue = ((0.272 * orig_red) + (0.534 * orig_green) + (0.131 * orig_blue) + 0.5);
            //cap at 255
            if (sepiared <= 255)
            {
                image[i][j].rgbtRed = (int)sepiared;
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }
            if (sepiagreen <= 255)
            {
                image[i][j].rgbtGreen = sepiagreen;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }
            if (sepiablue <= 255)
            {
                image[i][j].rgbtBlue = sepiablue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < (width / 2); j ++)
        {
            //make temp vriable to hold one pixel while they exchange places
            int temp[3] = {image[i][j].rgbtBlue, image[i][j].rgbtGreen, image[i][j].rgbtRed};
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][width - 1 - j].rgbtBlue = temp[0];
            image[i][width - 1 - j].rgbtGreen = temp[1];
            image[i][width - 1 - j].rgbtRed = temp[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //mimic image rgbttriple structure to temporariy store blurred pixels
    typedef struct
    {
        int red;
        int blue;
        int green;
    }
    pixel;
    //create 2d array pixels
    pixel pixels[height][width];

    double a = 0;

    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j ++)
        {
            //temporary variables to add up colour values of each pixel in block
            float avgb = 0;
            float avgg = 0;
            float avgr = 0;
            int n = 0;

            for (int k = (i - 1); k <= (i + 1); k ++)
            {
                for (int l = (j - 1); l <= (j + 1); l ++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        //storing colour values temporarily in new variables
                        float blue = image[k][l].rgbtBlue;
                        float green = image[k][l].rgbtGreen;
                        float red = image[k][l].rgbtRed;
                        avgb += blue;
                        avgg += green;
                        avgr += red;
                        n++;
                    }
                }
            }
            // create array to temporarily hold the values for the red grren blue values of each pixel
            pixels[i][j].blue = (int)((avgb / n) + 0.5);
            pixels[i][j].green = (int)((avgg / n) + 0.5);
            pixels[i][j].red = (int)((avgr / n) + 0.5);
            a ++;
        }
    }

    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j ++)
        {
            //assign new pixel values to the original input variables
            image[i][j].rgbtBlue = pixels[i][j].blue;
            image[i][j].rgbtGreen = pixels[i][j].green;
            image[i][j].rgbtRed = pixels[i][j].red;
        }
    }
    return;
}
