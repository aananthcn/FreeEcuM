#COMPILER=
#CC=${COMPILER}gcc
#LD=${COMPILER}gcc
#AS=${COMPILER}as
#OBJCOPY=${COMPILER}objcopy
#ARCH = x86

INCDIRS  += -I ${ECUM_PATH}/src \
	    -I ${ECUM_PATH}/api	\
	    -I ${MCU_PATH}/src/common/toolchain

LDFLAGS  += -g
CFLAGS   += -Werror ${INCDIRS} -g
ASFLAGS  += ${INCDIRS} -g

$(info compiling EcuM source files)


ECUM_OBJS := \
	${ECUM_PATH}/src/EcuM.o \
	${ECUM_PATH}/src/EcuM_Callout_Stubs.o \
	${ECUM_PATH}/cfg/EcuM_cfg.o

