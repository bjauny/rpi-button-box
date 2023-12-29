#
# Makefile
#

CIRCLEHOME = $(HOME)/Projects/circle

OBJS	= main.o kernel.o blinkTask.o serialLogger.o

LIBS	= $(CIRCLEHOME)/lib/sched/libsched.a \
		  $(CIRCLEHOME)/lib/libcircle.a

include $(CIRCLEHOME)/Rules.mk

-include $(DEPS)
