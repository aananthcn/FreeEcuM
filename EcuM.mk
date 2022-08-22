#COMPILER=
#CC=${COMPILER}gcc
#LD=${COMPILER}gcc
#AS=${COMPILER}as
#OBJCOPY=${COMPILER}objcopy
#ARCH = x86

INCDIRS  += -I ${ECUM_PATH}/src

LDFLAGS  += -g
CFLAGS   += -Werror ${INCDIRS} -g
ASFLAGS  += ${INCDIRS} -g

$(info compiling Test Application source files)


MCU_OBJS := \
	${ECUM_PATH}/src/EcuM.o

