#include <iostream>

int main(int ac, char *av[])
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		int i = 1;
		while (i < ac)
		{
			int j = 0;
			while (av[i][j] != '\0')
			{
				std::cout << (char)std::toupper(av[i][j]);
				j++;
			}
			i++;
		}
	}
	std::cout << std::endl;
	return 0;
}

/**
 * "!": shell program skip this. So it should be " ! "
 * std::cout (standard output stream)
 */