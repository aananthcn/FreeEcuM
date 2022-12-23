CC=${COMPILER}gcc
LD=${COMPILER}ld
AS=${COMPILER}as
AR=${COMPILER}ar
RANLIB=${COMPILER}ranlib
OBJCOPY=${COMPILER}objcopy

include ${ROOT_DIR}/path_defs.mk

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



$(info compiling EcuM source files)

ECUM_OBJS := \
	${ECUM_PATH}/src/EcuM.o \
	${ECUM_PATH}/src/EcuM_Callout_Stubs.o \
	${ECUM_PATH}/cfg/EcuM_cfg.o

LDFLAGS := -g
CFLAGS  := -Werror ${INCDIRS} -g
ASFLAGS := ${INCDIRS} -g
TARGET  := libEcuM.la
# include c_l_flags.mk to add more definitions specific to micro-controller
include ${ROOT_DIR}/c_l_flags.mk

all: $(TARGET)

LIB_OBJS := $(ECUM_OBJS)

$(TARGET): $(LIB_OBJS)
	$(AR) r $@ $^
	$(RANLIB) $@

clean:
	$(RM) $(LIB_OBJS) $(TARGET)