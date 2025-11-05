#include "parsingrt.h"

static float deci_part(char *str, int *i)
{
	float	num;
	float	div;

	num = 0.0;
	div = 0.1;
	while (str[*i] &&  ft_isdigit((int)str[*i]))
	{
		num += (str[*i] - 48) * div;
		div *= 0.1;
		*i += 1;
	}
	return (num);
}

static float ent_part(char *str, int *i)
{
	float	num;

	num = 0.0;
	while (str[*i] &&  ft_isdigit((int)str[*i]))
	{
		num = num * 10 + str[*i] - 48;
		*i += 1;
	}
	return (num);
}
		
int	ft_atof(float *number, char *str)
{
	float	num;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	num = ent_part(str, &i);
	if (str[i] && str[i] != '.')
		return (1);
	if (str[i] == '.')
		i++;
	num += deci_part(str, &i);
	if (str[i])
		return (1);
	*number = num * sign;
	return (0);
}

/*int	main(int argc, char **argv)
{
	float	num;
	
	(void)argc;
	if (ft_atof(&num, argv[1]))
	{
		printf("error\n");
		return (0);
	}
	printf("%f\n", num);
	return (0);
}*/
