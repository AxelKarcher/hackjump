##
## EPITECH PROJECT, 2021
## any
## File description:
## Makefile
##

CXX	?=		g++

# Binaries
NAME = HackJump

# Flags
CXXFLAGS +=	-std=c++17 -W -Wall -Wextra -g #-Werror
CPPFLAGS +=	-I src/ -I include/
LDLIBS +=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRC =	src/main.cpp								\
		\
		src/Game.cpp								\
		src/Utils.cpp								\
		\
		src/screens/credits/Main.cpp				\
		\
		src/screens/game/Main.cpp					\
		src/screens/game/Block.cpp					\
		src/screens/game/MainInit.cpp				\
		src/screens/game/MainUpdates.cpp			\
		src/screens/game/MainUtils.cpp				\
		src/screens/game/maps.cpp					\
		\
		src/screens/game/pause/Pause.cpp			\
		\
		src/screens/game/player/Player.cpp			\
		src/screens/game/player/PlayerUtils.cpp		\
		\
		src/screens/game/terminal/Terminal.cpp		\
		\
		src/screens/menu/Main.cpp					\
		src/screens/menu/MainUtils.cpp				\

# Object files
OBJ =	$(SRC:.cpp=.o)

# Rules
all:		$(NAME)

$(NAME):	$(OBJ) $(OBJM)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) $(LDLIBS)

debug:		CFLAGS += $(DEBUG)
debug:		fclean $(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME) $(NAME_TEST)

re:			fclean all

.PHONY:		all test tests_run cov debug clean fclean re
