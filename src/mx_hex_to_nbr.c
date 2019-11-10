#include "libmx.h"
int mx_strlen(const char *s)
{
    int counter = 0;
    while(*s != '\0')
    {
	counter++;
	s++;
    }
    return counter;
}
unsigned long mx_pow(double n, int pow)
{
    if (pow < 0)
    {
	return 0;
    }
    if (pow == 0)
    {
	return 1;
    }
    int i = 1;
    unsigned long num = n;
    while(i < pow)
    {
	num = num * n;
	i++;
    }
    return num;
}
unsigned long mx_hex_to_nbr(const char *hex)
{
    int size = mx_strlen(hex) - 1;
    int lenght = size;
    unsigned long result = 0;
    for(int i = 0; i <= lenght; i++)
    {
	if ((hex[i] >= 65 && hex[i] <= 70) || (hex[i] >= 97 && hex[i] <= 102))
	{
	    if (hex[i] >= 65 && hex[i] <= 70)
	    {
		result += (hex[i] - 55) * mx_pow(16, size);
		size--;
	    }
	    else
	    {
		result += (hex[i] - 87) * mx_pow(16, size);
		size--;
	    }
	}
	else
	{
	    result += (hex[i] - 48) * mx_pow(16, size);
	    size--;
	}
    }
    return result;
}
