CC := gcc
CFLAGS := -w -O3
Libs = -lpthread
Target := address_list
Source := $(wildcard src/*.c)
Objs := $(patsubst %.c,%.o,$(Source))
Modules += check create delete give_data insert main modify search windows 
AllObjs := $(addsuffix /src/*.o,$(Modules))
