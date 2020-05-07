// Problem set https://cs50.harvard.edu/x/2020/psets/4/filter/less/


#include "helpers.h"
#include <math.h>
#include <stdio.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            int av = (int) (average + 0.5);
            image[i][j].rgbtBlue = av;
            image[i][j].rgbtGreen = av;
            image[i][j].rgbtRed = av;
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
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j ++)
        {

            float avgb = 0;
            float avgg = 0;
            float avgr = 0;
            int n = 0;

            if (i == 0 && j == 0)
            {
                for (int k = i; k <= (i + 1); k ++)
                {
                    for (int l = j; l <= (j + 1); l ++)
                    {
                        avgb = avgb + image[k][l].rgbtBlue;
                        avgg = avgg + image[k][l].rgbtGreen;
                        avgr = avgr + image[k][l].rgbtRed;
                        n++;
                    }
                }
            image[i][j].rgbtBlue = (int)((avgb / n) + 0.5);
            image[i][j].rgbtGreen = (int)((avgg / n) + 0.5);
            image[i][j].rgbtRed = (int)((avgr / n) + 0.5);
            }
            if (i == 0 && j == (width - 1))
            {
                for (int k = i; k <= (i + 1); k ++)
                {
                    for (int l = (j - 1); l <= j; l ++)
                    {
                       avgb = avgb + image[k][l].rgbtBlue;
                       avgg = avgg + image[k][l].rgbtGreen;
                       avgr = avgr + image[k][l].rgbtRed;
                       n++;
                    }
                }
            image[i][j].rgbtBlue = (int)((avgb / n) + 0.5);
            image[i][j].rgbtGreen = (int)((avgg / n) + 0.5);
            image[i][j].rgbtRed = (int)((avgr / n) + 0.5);
            }
            if (i == (height - 1) && j == (width - 1))
            {
                for (int k = (i - 1); k <= i; k ++)
                {
                    for (int l = (j - 1); l <= j; l ++)
                    {
                       avgb = avgb + image[k][l].rgbtBlue;
                       avgg = avgg + image[k][l].rgbtGreen;
                       avgr = avgr + image[k][l].rgbtRed;
                       n++;
                    }
                }
            image[i][j].rgbtBlue = (int)((avgb / n) + 0.5);
            image[i][j].rgbtGreen = (int)((avgg / n) + 0.5);
            image[i][j].rgbtRed = (int)((avgr / n) + 0.5);
            }
            if (i == (height - 1) && j == 0)
            {
                for (int k = (i - 1); k <= i; k ++)
                {
                    for (int l = j; l <= (j + 1); l ++)
                    {
                       avgb = avgb + image[k][l].rgbtBlue;
                       avgg = avgg + image[k][l].rgbtGreen;
                       avgr = avgr + image[k][l].rgbtRed;
                       n++;
                    }
                }
            image[i][j].rgbtBlue = (int)((avgb / n) + 0.5);
            image[i][j].rgbtGreen = (int)((avgg / n) + 0.5);
            image[i][j].rgbtRed = (int)((avgr / n) + 0.5);
            }
            if (i == 0 && j >= 1 && j <= (width - 2))
            {
                for (int k = i; k <= (i + 1); k ++)
                {
                    for (int l = (j - 1); l <= (j + 1); l ++)
                    {
                       avgb = avgb + image[k][l].rgbtBlue;
                       avgg = avgg + image[k][l].rgbtGreen;
                       avgr = avgr + image[k][l].rgbtRed;
                       n++;
                    }
                }
            image[i][j].rgbtBlue = (int)((avgb / n) + 0.5);
            image[i][j].rgbtGreen = (int)((avgg / n) + 0.5);
            image[i][j].rgbtRed = (int)((avgr / n) + 0.5);

            }
            if (i == (height - 1) && j >= 1 && j <= (width - 2))
            {
                for (int k = (i - 1); k <= i; k ++)
                {
                    for (int l = (j - 1); l <= (j + 1); l ++)
                    {
                       avgb = avgb + image[k][l].rgbtBlue;
                       avgg = avgg + image[k][l].rgbtGreen;
                       avgr = avgr + image[k][l].rgbtRed;
                       n++;
                    }
                }
            image[i][j].rgbtBlue = (int)((avgb / n) + 0.5);
            image[i][j].rgbtGreen = (int)((avgg / n) + 0.5);
            image[i][j].rgbtRed = (int)((avgr / n) + 0.5);
            }
            if (j == 0 && i >= 1 && i <= (height - 2))
            {
                for (int k = (i - 1); k <= (i + 1); k ++)
                {
                    for (int l = j; l <= (j + 1); l ++)
                    {
                       avgb = avgb + image[k][l].rgbtBlue;
                       avgg = avgg + image[k][l].rgbtGreen;
                       avgr = avgr + image[k][l].rgbtRed;
                       n++;
                    }
                }
            image[i][j].rgbtBlue = (int)((avgb / n) + 0.5);
            image[i][j].rgbtGreen = (int)((avgg / n) + 0.5);
            image[i][j].rgbtRed = (int)((avgr / n) + 0.5);
            }
            if (j == (width - 1) && i >= 1 && i <= (height - 2))
            {
                for (int k = (i - 1); k <= (i + 1); k ++)
                {
                    for (int l = (j - 1); l <= j; l ++)
                    {
                       avgb = avgb + image[k][l].rgbtBlue;
                       avgg = avgg + image[k][l].rgbtGreen;
                       avgr = avgr + image[k][l].rgbtRed;
                       n++;
                    }
                }
            image[i][j].rgbtBlue = (int)((avgb / n) + 0.5);
            image[i][j].rgbtGreen = (int)((avgg / n) + 0.5);
            image[i][j].rgbtRed = (int)((avgr / n) + 0.5);
            }
            else if (i > 0 && i < (height - 1) && j > 0 && j < (width - 1))
            {
               for(int k = (i - 1); k <= (i + 1); k ++)
               {
                   for (int l = (j - 1); l <= (j + 1); l ++)
                   {
                       avgb = avgb + image[k][l].rgbtBlue;
                       avgg = avgg + image[k][l].rgbtGreen;
                       avgr = avgr + image[k][l].rgbtRed;
                       n++;
                   }
               }
            image[i][j].rgbtBlue = (int)((avgb / n) + 0.5);
            image[i][j].rgbtGreen = (int)((avgg / n) + 0.5);
            image[i][j].rgbtRed = (int)((avgr / n) + 0.5);
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    void get_Gx_Gy(int n, int gx[9], int gy[9], double Gx[3], double Gy[3], int k, int l, int height, int width, RGBTRIPLE image[height][width]);

    void sobel(double Gx[3], double Gy[3], int i, int j, int height, int width, RGBTRIPLE image[height][width]);

    int gx[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int gy[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    int n = 0;
    double Gx[3] = {0, 0, 0};
    double Gy[3] = {0, 0, 0};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            Gx[0] = 0;
            Gx[1] = 0;
            Gx[2] = 0;

            Gy[0] = 0;
            Gy[1] = 0;
            Gy[2] = 0;
            n = 0;


               for(int k = (i - 1); k <= (i + 1); k ++)
               {
                   for (int l = (j - 1); l <= (j + 1); l ++, n++)
                   {
                        get_Gx_Gy(n, &gx[n], &gy[n], &Gx[3], &Gy[3], k, l, height, width, image);
                   }
               }

                sobel(&Gx[3], &Gy[3], i, j, height, width, image);


        }
    }
    return;
}

void sobel(double Gx[3], double Gy[3], int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    image[i][j].rgbtBlue = (int)sqrt(pow(Gx[0], 2) + pow(Gy[0], 2));
    image[i][j].rgbtGreen = (int)sqrt(pow(Gx[1], 2) + pow(Gy[1], 2));
    image[i][j].rgbtRed = (int)sqrt(pow(Gx[2], 2) + pow(Gy[2], 2));

    if (image[i][j].rgbtBlue > 255)
    {
    image[i][j].rgbtBlue = 255;
    }
    if (image[i][j].rgbtGreen > 255)
    {
        image[i][j].rgbtGreen = 255;
    }
    if (image[i][j].rgbtRed > 255)
    {
        image[i][j].rgbtRed = 255;
    }


    printf("%i, %f, %f\n", image[i][j].rgbtBlue, Gx[0], Gy[0]);

    Gx[0] = 0;
    Gx[1] = 0;
    Gx[2] = 0;

    Gy[0] = 0;
    Gy[1] = 0;
    Gy[2] = 0;

}

void get_Gx_Gy(int n, int gx[9], int gy[9], double Gx[3], double Gy[3], int k, int l, int height, int width, RGBTRIPLE image[height][width])
    {
        if (k >= 0 && l >= 0 && n < 9 && l < width && k < height)
        {
        Gx[0] += (image[k][l].rgbtBlue * gx[n]);
        Gx[1] += (image[k][l].rgbtGreen * gx[n]);
        Gx[2] += (image[k][l].rgbtRed * gx[n]);

        Gy[0] += (image[k][l].rgbtBlue * gy[n]);
        Gy[1] += (image[k][l].rgbtGreen * gy[n]);
        Gy[2] += (image[k][l].rgbtRed * gy[n]);
        }
        return;

    }
//./filter -e images/yard.bmp out.bmp
