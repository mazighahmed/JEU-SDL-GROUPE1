#include <stdio.h>   
#include <unistd.h>  
#include <fcntl.h>  
#include <errno.h>   
#include <termios.h>  
#include <string.h>  
#include <sys/ioctl.h>
#include <stdint.h> 


int arduinoReadData(char *x)
{
    char chemin[]="/dev/ttyS3";
    FILE*f;
    f=fopen(chemin,"r");

    if(f == NULL)
        return(-1);

    fscanf(f,"%c",x);

    fclose(f);

    return(0);
}
