# 定义编译器
CC = gcc
# 定义编译选项：-g 方便调试, -Wall 显示所有警告, -fsanitize 检查内存错误
CFLAGS = -g -Wall -fsanitize=address

# 目标文件
TARGET = num_island
# 源文件
SRCS = main.c solution.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# 运行程序
run: all
	./$(TARGET)

# 清理编译结果
clean:
	rm -f $(TARGET)