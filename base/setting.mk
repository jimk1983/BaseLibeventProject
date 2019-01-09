#公共部分
CC=gcc
CFLAGS=-c 
MAKE=make
AR=ar cr
RM=-rm -rf
CFLAGS +=-Wall -g #-Werror -O3  	#将-Werror将告警当作错误处理


###########################
#公共属性定义
TARGET=BaseServer
OUTPUTBINSDIR=$(CURDIR)
OUTPUTOBJSDIR=$(CURDIR)

##################################
#添加系统配置的头文件目录
CFLAGS+=-I$(CURDIR)
##################################
#添加内部库的头文件目录
#lib头文件包含目录
CFLAGS += -I$(ROOTDIR)/3thrd/include
#依赖的库放置有顺序的，需要按依赖前后来放置,对后面有依赖的放前面
LSFLAGS +=-L$(ROOTDIR)/3thrd/Bin 

##################################
#添加的是/usr/local/lib下的libevent动态库
LDFLAGS = -levent
#这些是系统的库
LDFLAGS += -ldl -lpthread -lrt -lm #-ldb


















