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


    RGBTRIPLE **image2;
    image2 = malloc (height * sizeof(RGBTRIPLE*));
    for(int i = 0; i < height; i++)
    {
        image2[i] = malloc(width * sizeof(RGBTRIPLE));
    }
    int gx[3][3];
    int gy[3][3];

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                for(int l = 0; l < 3; l++)
                {
                    
                }
            }
        }
    }
    int sxred,sxgreen,sxblue,syred,sygreen,syblue;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            sxred = 0, syred = 0, sxgreen = 0, sygreen = 0, sxblue = 0, syblue = 0;


            for(int x = (i-1), cont1 = 0; x <= i+1; x++,cont1++)
            {
                    for(int y = (j-1), cont2 = 0; y <= j+1; y++,cont2++)
                    {


                        if(x > 0 && x < height && y > 0 && y < width)
                        {
                        sxred += gx[cont1][cont2]*image2[x][y].rgbtRed;
                        syred += gy[cont1][cont2]*image2[x][y].rgbtRed;
                        sxgreen += gx[cont1][cont2]*image2[x][y].rgbtGreen;
                        sygreen += gy[cont1][cont2]*image2[x][y].rgbtGreen;
                        sxblue += gx[cont1][cont2]*image2[x][y].rgbtBlue;
                        syblue += gy[cont1][cont2]*image2[x][y].rgbtBlue;
                        }
                    }
            }
            image[i][j].rgbtRed = round(sqrt((sxred*sxred)+(syred*syred)));
            image[i][j].rgbtGreen = round(sqrt((sxgreen*sxgreen)+(sygreen*sygreen)));
            image[i][j].rgbtBlue = round(sqrt(sxblue*sxblue)+(syblue*syblue));
            if(image[i][j].rgbtRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            if(image[i][j].rgbtGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            if(image[i][j].rgbtBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }
    for(int i = 0; i < height; i++)
    {
        free(image2[i]);
    }
    free(image2);


    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%i \n",gx[i][j]);
        }
    }
      for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%i \n",gy[i][j]);
        }
    }


    return;
}

