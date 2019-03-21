CC := gcc
CFLAGS := -w -O3
Libs = -lpthread -lsqlite3
Target := address_list
Source := $(wildcard src/*.c)
Objs := $(patsubst %.c,%.o,$(Source))
Modules += add delete updata search main windows
AllObjs := $(addsuffix /src/*.o,$(Modules))
