char	*ft_move_tetrimin(char *str)
{
	int 	left_shift;
	int 	left_min;
	int 	up_min;
	int		up_shift;
	int		i;

	i = 0;
	left_shift = 0;
	left_min = 4;
	up_min = 0;
	up_shift = -1;
	while (str[i])
	{
		if (str[i] == '\n')
			left_shift = 0;
		while (str[i++] == '.')
			left_shift++;
		if (str[i] == '#' && up_shift < 0)
		{
			up_shift = i;
			while (up_shift > 5)
			{
				up_shift -= 5;
				up_min++;
			}
		}
		if (left_min > left_shift)
			left_min = left_shift;
		i++;
	}
	return (ft_move(str, left_min, up_min));
}