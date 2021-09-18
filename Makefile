CLIENT_NAME	= client
SERVER_NAME	= server
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror
C_SRCS_LIST = client.c
S_SRCS_LIST = server.c
CLIENT_SRCS	= $(addprefix $(SRCS_DIR)/, $(C_SRCS_LIST))
SERVER_SRCS	= $(addprefix $(SRCS_DIR)/, $(S_SRCS_LIST))
LIB_FT		= -Llibft -lft
C_OBJ_LIST 	= $(patsubst %.c, %.o, $(C_SRCS_LIST))
S_OBJ_LIST 	= $(patsubst %.c, %.o, $(S_SRCS_LIST))
CLIENT_OBJ 	= $(addprefix $(OBJ_DIR)/, $(C_OBJ_LIST))
SERVER_OBJ 	= $(addprefix $(OBJ_DIR)/, $(S_OBJ_LIST))
SRCS_DIR	= srcs
OBJ_DIR		= obj
all:		$(CLIENT_NAME) | $(SERVER_NAME)
$(CLIENT_NAME):	$(CLIENT_OBJ)
			cd libft && make bonus
			$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIB_FT) -o $(CLIENT_NAME)
$(SERVER_NAME):	$(SERVER_OBJ)
			cd libft && make bonus
			$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIB_FT) -o $(SERVER_NAME)
$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR):
			mkdir -p $@
clean:
			cd libft && make clean
			$(RM) $(OBJ_DIR)
fclean:		clean
			cd libft && make fclean
			$(RM) $(CLIENT_NAME)
			$(RM) $(SERVER_NAME)
re:			fclean all
.PHONY:		all clean fclean re bonus