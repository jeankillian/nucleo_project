################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Aff_Jeu.c \
../src/Ct_Jeu.c \
../src/Pup_Jeu.c \
../src/main.c 

OBJS += \
./src/Aff_Jeu.o \
./src/Ct_Jeu.o \
./src/Pup_Jeu.o \
./src/main.o 

C_DEPS += \
./src/Aff_Jeu.d \
./src/Ct_Jeu.d \
./src/Pup_Jeu.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"

