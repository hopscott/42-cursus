int	run_algo3by3(t_node **st, t_node **st2)
{
	int	m1;
	int	m2;
	int	m3;
	int	i;
	int	arr[3];

	while (stack_size(st) > 3)
	{
		m1 = stack_findMin(st);
		m2 = stack_findNextMin(st, m1);
		m3 = stack_findNextNextMin(st, m1, m2);
		i = 0;
		while (i < 3)
		{
			if ((s_steps(st, m1) <= s_steps(st, m2)) && (s_steps(st, m1) <= s_steps(st, m3)))
			{
				arr[i] = m1;
				m1 = m2;
			}
			else if ((s_steps(st, m2) <= s_steps(st, m1)) && (s_steps(st, m2) <= s_steps(st, m3)))
			{
				arr[i] = m2;
				m2 = m1;
			}
			else if ((s_steps(st, m3) <= s_steps(st, m2)) && (s_steps(st, m3) <= s_steps(st, m1)))
			{
				arr[i] = m3;
				m3 = m1;
			}
			i++;
		}
		i = 0;
		while (i < 3)
		{
			stackA_gotoNum(st, stack_findMin(st));
			op_pb(st, st2);
			i++;
		}
		run_algo3b(st2);
	}
	run_algo3a(st);
	while (stack_size(st2) > 0)
		op_pa(st, st2);
	return (0);
}
