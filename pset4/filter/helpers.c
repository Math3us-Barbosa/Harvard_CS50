#include<math.h>
#include "helpers.h"
#include<stdio.h>
#include<stdlib.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
     for(int i = 0; i < height; i++)
    {
        for(int j=0; j < width; j++)
        {


            image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0);
            image[i][j].rgbtRed = image[i][j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][j].rgbtBlue;
        }
    }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE aux;
    for(int i = 0; i < height; i++)
    {
        for(int j=0; j < width-1-j; j++)
        {
                    aux = image[i][width-1-j];
                    image[i][width-1-j] = image[i][j];
                    image[i][j] = aux;
        }
    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE **image2;
    image2 = malloc (height * sizeof(RGBTRIPLE*));
    for(int i = 0; i < height; i++)
    {
        image2[i] = malloc(width * sizeof(RGBTRIPLE));
    }


    for(int i = 0; i < height; i++)
    {
        for(int j=0; j < width; j++)
        {
            image2[i][j] = image[i][j];
        }
    }
    float cont;
    int soma1,soma2,soma3;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            soma1 = 0;
            soma2 = 0;
            soma3 = 0;
            cont = 0;
            for(int x = (i-1);x <= i+1;x++)
            {
                    for(int y = (j-1); y <= j+1;y++)
                    {
                        if(y>=0 && y<width && x >= 0 && x < height)
                        {
                                soma1 += image2[x][y].rgbtBlue;
                                soma2 += image2[x][y].rgbtGreen;
                                soma3 += image2[x][y].rgbtRed;
                                cont++;
                        }
                    }
            }
            image[i][j].rgbtBlue = round(soma1/cont);
            image[i][j].rgbtGreen = round(soma2/cont);
            image[i][j].rgbtRed = round(soma3/cont);
        }
    }
for(int i = 0; i < height; i++)
    {
        free(image2[i]);
    }
free(image2);
    return;
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE **image2 = malloc(height *sizeof(RGBTRIPLE));
    for(int i = 0; i < width; i++)
    {
        *image[i] = malloc(w)
    }
    int gx[3][3] = { {-1, 0, 1},
                     {-2, 0, 2},
                     {-1, 0, 1} };


    int gy[3][3] = { {-1, -2, -1},
                     {0, 0, 0},
                     {1, 2, 1} };
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int sxred = 0, syred = 0, sxgreen = 0, sygreen = 0, sxblue = 0, syblue = 0, cont1 = 0, cont2 = 0;
            BYTE rred, rgreen, rblue;
            for(int x = (i-1); x < i+2; x++,cont1++)
            {
                    for(int y = (j-1); y < j+2; y++,cont2++)
                    {
                        if(x > -1 && x < height && y > -1 && y < width)
                        {
                        sxred += gx[cont1][cont2]*image[x][y].rgbtRed;
                        syred += gy[cont1][cont2]*image[x][y].rgbtRed;
                        sxgreen += gx[cont1][cont2]*image[x][y].rgbtGreen;
                        sygreen += gy[cont1][cont2]*image[x][y].rgbtGreen;
                        sxblue += gx[cont1][cont2]*image[x][y].rgbtBlue;
                        syblue += gy[cont1][cont2]*image[x][y].rgbtBlue;
                        }
                    }
            }
            rred = round(sqrt((sxred*sxred)+(syred*syred)));
            rgreen = round(sqrt((sxgreen*sxgreen)+(sygreen*sygreen)));
            rblue = round(sqrt((sxblue*sxblue)+(syblue*syblue)));
            if(rred > 255)
            {
                rred = 255;
            }
            if(rgreen > 255)
            {
                rgreen = 255;
            }
            if(rblue > 255)
            {
                rblue = 255;
            }
            image[i][j].rgbtBlue = rblue;
            image[i][j].rgbtRed = rred;
            image[i][j].rgbtGreen = rgreen;
        }
    }
    return;
}

