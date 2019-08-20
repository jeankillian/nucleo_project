################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/affichage.c \
../src/changement_joueur.c \
../src/deplacement.c \
../src/init.c \
../src/main.c \
../src/winner.c 

OBJS += \
./src/affichage.o \
./src/changement_joueur.o \
./src/deplacement.o \
./src/init.o \
./src/main.o \
./src/winner.o 

C_DEPS += \
./src/affichage.d \
./src/changement_joueur.d \
./src/deplacement.d \
./src/init.d \
./src/main.d \
./src/winner.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"

