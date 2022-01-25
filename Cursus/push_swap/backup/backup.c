//////////////////////////////////////////////////////////////////////
/*
int	run_selectionSort(t_node **stack)
{
	t_node	**stack2;

	*stack2 = 0;
	while (stack_size(stack) != 0)
	{
		stack_gotoNum(stack, stack_findMin(stack), 'a');
		op_pb(stack, stack2);
	}
	while (stack_size(stack2) != 0)
		op_pa(stack, stack2);
	return (0);	
}
*/
//////////////////////////////////////////////////////////////////////
/*
void	stack_sortpush(t_node **stack, t_node **stack2, int flag)
{
	t_node	*elem;
	t_node	*next;

	elem = *stack;
	next = elem->next;
	if (stack_size(stack) > 1)
	{
		if (flag && (elem->val < next->val))
			op_sa(stack);
		if (!flag && (elem->val > next->val))
			op_sa(stack);
		op_pb(stack, stack2);
	}
	op_pb(stack, stack2);
	stack_print(stack);
}

int run_mergeSort(t_node **stack)
{
	t_node	**stack2;
	
	// https://stackoverflow.com/questions/21897184/using-stacks-for-a-non-recursive-mergesort
	printf("============= START =============\n");
	stack_print(stack);
	printf("=================================\n");
	*stack2 = 0;
	while (!stack_ascend(stack))
	{
//		printf("============ STACK A ==================\n");
		while (stack_size(stack) > 0)
			stack_sortpush(stack, stack2, 1);
//		printf("============ STACK B ==================\n");
		while (stack_size(stack2) > 0)
			stack_sortpush(stack2, stack, 0);
	}
	printf("============= END =============\n");
	stack_print(stack);
	printf("=================================\n");
	return (0);
}
*/