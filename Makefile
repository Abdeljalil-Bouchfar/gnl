all:
	@gcc -c get_next_line_utils.c
	@gcc get_next_line.c get_next_line_utils.o -D BUFFER_SIZE=42 && ./a.out

bonus:
	@gcc -c get_next_line_utils_bonus.c
	@gcc get_next_line_bonus.c get_next_line_utils_bonus.o -D BUFFER_SIZE=42 && ./a.out

fclean:
	@rm -f *.o a.out
re: fclean all