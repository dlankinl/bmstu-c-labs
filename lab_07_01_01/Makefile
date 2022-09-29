CC := gcc

C_DIR := ./src
H_DIR := ./inc
OBJ_DIR := ./out
UNIT_C_DIR := ./unit_tests

C_FILES := $(wildcard $(C_DIR)/*.c)
H_FILES := $(wildcard $(H_DIR)/*.h)
UNIT_C_FILES := $(wildcard $(UNIT_C_DIR)/*.c)
OBJ_FILES := $(C_FILES:$(C_DIR)/%.c=$(OBJ_DIR)/%.o)

UNIT_OBJ := $(UNIT_C_FILES:$(UNIT_C_DIR)/%.c=$(OBJ_DIR)/%.o)
UNIT_OBJ += $(filter-out $(OBJ_DIR)/main.o,$(OBJ_FILES))

C_FLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion
UNIT_FLAGS := -lcheck -lpthread -lrt -lsubunit -lm

APP := app.exe
UNIT := unit_tests.exe

$(APP) : $(OBJ_FILES)
	$(CC) $^ -o $@

$(UNIT): $(UNIT_OBJ)
	$(CC) $(UNIT_OBJ) -o $@ $(UNIT_FLAGS)

$(OBJ_DIR) :
	@mkdir -p $@

$(OBJ_DIR)/%.o : $(C_DIR)/%.c $(H_FILES) $(OBJ_DIR)
	$(CC) $(C_FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(UNIT_C_DIR)/%.c $(H_FILES) $(OBJ_DIR)
	$(CC) $(C_FLAGS) $(UNIT_FLAGS) -c $< -o $@

.PHONY: clean unit func

clean:
	$(RM) $(OBJ_DIR)/*.o *.exe

unit: $(UNIT)
	./$^