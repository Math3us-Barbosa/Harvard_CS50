#include "helpers.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


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


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE** image2 = malloc(height*sizeof(RGBTRIPLE*));
    for(int i = 0; i < height; i++)
    {
        image2[i] = malloc(width * sizeof(RGBTRIPLE));
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width;j++)
        {
            image2[i][j] = image[i][j];
        }
    }
    for(int i = 0; i < height; i++)
    {
        for(int j=0; j < width; j++)
        {
            image[i][j].rgbtRed = round((.393 * image2[i][j].rgbtRed) + (.769 * image2[i][j].rgbtGreen) + (.189 * image2[i][j].rgbtBlue));
            image[i][j].rgbtGreen = round((.349 * image2[i][j].rgbtRed) + (.686 * image2[i][j].rgbtGreen) + (.168 * image2[i][j].rgbtBlue));
            image[i][j].rgbtBlue = round((0.272 * image2[i][j].rgbtRed) + (0.534 * image2[i][j].rgbtGreen) + (0.131 * image2[i][j].rgbtBlue));
            if(image[i][j].rgbtRed > 255)
                image[i][j].rgbtRed = 255;
            if(image[i][j].rgbtGreen > 255)
                image[i][j].rgbtGreen = 255;
            if(image[i][j].rgbtBlue > 255)
                image[i][j].rgbtBlue = 255;
        }
    }
    for(int i = 0; i < height; i++)
    {
        free(image2[i]);
    }
    free(image2);
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

