# SRC_DIR := ./
# OBJ_DIR := ./
# SRC_FILES := main.cpp
# OBJ_FILES := main.o
# LDFLAGS := -L /usr/local/lib64 -L /root/clickhouse-cpp/build/clickhouse -l clickhouse-cpp-lib
# CPPFLAGS := -I /usr/local/include -I /root/clickhouse-cpp/ -I /root/clickhouse-cpp/contrib -I /root/clickhouse-cpp/contrib/gtest/include

# CXXFLAGS := -Wall -std=c++17 -g
# CFLAGS := -g

# # main:main.o utils.o
# main:main.o
# 	/opt/rh/devtoolset-8/root/usr/bin/g++   $(CXXFLAGS) $(LDFLAGS) $(CPPFLAGS) main.o -o main
# main.o:main.cpp
# 	/opt/rh/devtoolset-8/root/usr/bin/g++   $(CXXFLAGS) $(LDFLAGS) $(CPPFLAGS) -c main.cpp -o main.o
# # utils.o:/root/clickhouse-cpp/ut/utils.cpp
# # 	/opt/rh/devtoolset-8/root/usr/bin/g++   $(CXXFLAGS) $(LDFLAGS) $(CPPFLAGS) -c /root/clickhouse-cpp/ut/utils.cpp -o utils.o

# clean:
# 	rm -rf *.o main 


SRC=$(wildcard *.c)
LIB=-L/usr/lib64 -l clickhouse-cpp-lib
# LIB=
INC := -I /usr/local/include -I /root/clickhouse-cpp/ -I /root/clickhouse-cpp/contrib -I /root/clickhouse-cpp/contrib/gtest/include
OBJ=$(addprefix ./, $(addsuffix .o, $(basename $(SRC))))
TARGET=main
all: $(TARGET)
$(TARGET): $(SRC)
	gcc -g -o $@  $^ $(CFLAGS) $(LDFLAGS) $(INC) $(LIB)
clean:
	rm -f $(TARGET) $(OBJ)
