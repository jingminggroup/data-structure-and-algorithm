CC = g++
CFLAGS = -g
TARGET = hello
SRC = ./src ./  
FILES = $(foreach dir, $(SRC), $(wildcard $(dir)/*.cpp))
OBJS = $(patsubst %.cpp, %.o,$(FILES))
BUILD_DIR := ./build
INC = ./src/include
SRC_PATH = ./src

$(TARGET): CHECKDIR $(OBJS)
	$(CC)  -o $(BUILD_DIR)/$(TARGET) $(addprefix $(BUILD_DIR)/, $(notdir $(OBJS)))

CHECKDIR:
	mkdir -p ${BUILD_DIR}
	mkdir -p ${INC}
	
$(OBJS): %.o:%.cpp
	$(CC) -MD -MF $(BUILD_DIR)/$(notdir $*.d) -MP -I $(INC) -c $< -o $(BUILD_DIR)/$(notdir $@) $(CFLAGS)

.PHONY: clean
clean:
	-rm -rf $(BUILD_DIR)
