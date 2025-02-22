# ---------------------------------------------------
# |                     Makefile                     |
# ---------------------------------------------------

.SILENT:

# Variables
CC = gcc
CFLAGS = -lglfw -lGL -lm
SRC_DIR = src
LIB_DIR = lib
OBJ_DIR = obj
LIB_OUTPUT_DIR = compiled_lib
LIB_NAME = $(LIB_OUTPUT_DIR)/compiled_lib.a
SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(LIB_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Colors
RED = \033[31m
GREEN = \033[32m
BLUE = \033[34m
RESET = \033[0m

# Rules
.PHONY: all clean fclean re

all: $(OBJ) $(LIB_NAME)
	@echo "$(BLUE)[INFO] Compilation completed successfully!$(RESET)"
	@echo "----------------------------------------"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@rm -f errors.txt; $(CC) -c $< -o $@ 2>> errors.txt || { echo "$(RED)[ERROR] Compilation error in $<$(RESET)"; exit 1; }
	@echo "$(GREEN)[OK] $< compiled successfully!$(RESET)"
	@echo "----------------------------------------"

$(LIB_NAME): $(OBJ)
	@mkdir -p $(LIB_OUTPUT_DIR)
	ar rcs $@ $^

clean:
	rm -f $(OBJ_DIR)/*.o
	@echo "$(BLUE)[INFO] Object files deleted.$(RESET)"

fclean: clean
	rm -f $(LIB_NAME)
	@echo "$(BLUE)[INFO] Library deleted.$(RESET)"

re: fclean all
