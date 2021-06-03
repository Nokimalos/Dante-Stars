##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

all:	compil

compil:
	cd solver
	$(MAKE) -C solver/
	cd generator
	$(MAKE) -C generator/

clean:
	$(MAKE) clean -C solver/
	$(MAKE) clean -C generator/
	$(RM) lib/my/*.o
	$(RM) $(OBJ)
	$(RM) *.html
	$(RM) *.o
	$(RM) *~

fclean:	clean
	$(RM) $(NAME)
	$(RM) *.gcda
	$(RM) *.gcno

re:	compil
