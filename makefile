CC=${COMPILER}gcc
LD=${COMPILER}ld
AS=${COMPILER}as
AR=${COMPILER}ar
RANLIB=${COMPILER}ranlib
OBJCOPY=${COMPILER}objcopy

include ${ROOT_DIR}/pathdefs.mk

INCDIRS  += -I ${ECUM_PATH}/src \
	    -I ${ECUM_PATH}/api	\
	    -I ${OS_PATH}/include \
	    -I ${MCU_MICRO_PATH} \
	    -I ${MCU_PATH}/api \
	    -I ${MCU_PATH}/src/bsp \
	    -I ${MCU_PATH}/src/common/api \
	    -I ${MCU_PATH}/src/common/src \
	    -I ${MCU_PATH}/src/common/toolchain \
	    -I ${OS_BUILDER_PATH}/src \
	    -I ${PORT_PATH}/api \
	    -I ${PORT_PATH}/cfg \
	    -I ${PORT_PATH}/src \
	    -I ${SPI_PATH}/api \
	    -I ${SPI_PATH}/cfg \
	    -I ${SPI_PATH}/src

LDFLAGS  += -g
CFLAGS   += -Werror ${INCDIRS} -g
ASFLAGS  += ${INCDIRS} -g

$(info compiling EcuM source files)


ECUM_OBJS := \
	${ECUM_PATH}/src/EcuM.o \
	${ECUM_PATH}/src/EcuM_Callout_Stubs.o \
	${ECUM_PATH}/cfg/EcuM_cfg.o

CFLAGS := ${INCDIRS}
TARGET := libEcuM.la

all: $(TARGET)

LIB_OBJS := $(ECUM_OBJS)

$(TARGET): $(LIB_OBJS)
	$(AR) r $@ $^
	$(RANLIB) $@

clean:
	$(RM) $(LIB_OBJS) $(TARGET)