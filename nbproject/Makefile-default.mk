#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/EMS_PIC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/EMS_PIC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c adc/adc.c uart/uart.c timer/timer.c lcd/lcd.c interrupt/interrupt.c fsm/fsm_mode.c button/button.c fsm/fsm_display.c fsm/fsm_warning.c pwm/pwm.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/adc/adc.o ${OBJECTDIR}/uart/uart.o ${OBJECTDIR}/timer/timer.o ${OBJECTDIR}/lcd/lcd.o ${OBJECTDIR}/interrupt/interrupt.o ${OBJECTDIR}/fsm/fsm_mode.o ${OBJECTDIR}/button/button.o ${OBJECTDIR}/fsm/fsm_display.o ${OBJECTDIR}/fsm/fsm_warning.o ${OBJECTDIR}/pwm/pwm.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/adc/adc.o.d ${OBJECTDIR}/uart/uart.o.d ${OBJECTDIR}/timer/timer.o.d ${OBJECTDIR}/lcd/lcd.o.d ${OBJECTDIR}/interrupt/interrupt.o.d ${OBJECTDIR}/fsm/fsm_mode.o.d ${OBJECTDIR}/button/button.o.d ${OBJECTDIR}/fsm/fsm_display.o.d ${OBJECTDIR}/fsm/fsm_warning.o.d ${OBJECTDIR}/pwm/pwm.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/adc/adc.o ${OBJECTDIR}/uart/uart.o ${OBJECTDIR}/timer/timer.o ${OBJECTDIR}/lcd/lcd.o ${OBJECTDIR}/interrupt/interrupt.o ${OBJECTDIR}/fsm/fsm_mode.o ${OBJECTDIR}/button/button.o ${OBJECTDIR}/fsm/fsm_display.o ${OBJECTDIR}/fsm/fsm_warning.o ${OBJECTDIR}/pwm/pwm.o

# Source Files
SOURCEFILES=main.c adc/adc.c uart/uart.c timer/timer.c lcd/lcd.c interrupt/interrupt.c fsm/fsm_mode.c button/button.c fsm/fsm_display.c fsm/fsm_warning.c pwm/pwm.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/EMS_PIC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
MP_PROCESSOR_OPTION_LD=18f4620
MP_LINKER_DEBUG_OPTION=  -u_DEBUGSTACK
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main.o   main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/adc/adc.o: adc/adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/adc" 
	@${RM} ${OBJECTDIR}/adc/adc.o.d 
	@${RM} ${OBJECTDIR}/adc/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/adc/adc.o   adc/adc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/adc/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/adc/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/uart/uart.o: uart/uart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/uart" 
	@${RM} ${OBJECTDIR}/uart/uart.o.d 
	@${RM} ${OBJECTDIR}/uart/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/uart/uart.o   uart/uart.c 
	@${DEP_GEN} -d ${OBJECTDIR}/uart/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/uart/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/timer/timer.o: timer/timer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/timer" 
	@${RM} ${OBJECTDIR}/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/timer/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/timer/timer.o   timer/timer.c 
	@${DEP_GEN} -d ${OBJECTDIR}/timer/timer.o 
	@${FIXDEPS} "${OBJECTDIR}/timer/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/lcd/lcd.o: lcd/lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/lcd" 
	@${RM} ${OBJECTDIR}/lcd/lcd.o.d 
	@${RM} ${OBJECTDIR}/lcd/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/lcd/lcd.o   lcd/lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/lcd/lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/lcd/lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/interrupt/interrupt.o: interrupt/interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/interrupt" 
	@${RM} ${OBJECTDIR}/interrupt/interrupt.o.d 
	@${RM} ${OBJECTDIR}/interrupt/interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/interrupt/interrupt.o   interrupt/interrupt.c 
	@${DEP_GEN} -d ${OBJECTDIR}/interrupt/interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/interrupt/interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/fsm/fsm_mode.o: fsm/fsm_mode.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/fsm" 
	@${RM} ${OBJECTDIR}/fsm/fsm_mode.o.d 
	@${RM} ${OBJECTDIR}/fsm/fsm_mode.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/fsm/fsm_mode.o   fsm/fsm_mode.c 
	@${DEP_GEN} -d ${OBJECTDIR}/fsm/fsm_mode.o 
	@${FIXDEPS} "${OBJECTDIR}/fsm/fsm_mode.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button/button.o: button/button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/button" 
	@${RM} ${OBJECTDIR}/button/button.o.d 
	@${RM} ${OBJECTDIR}/button/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button/button.o   button/button.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button/button.o 
	@${FIXDEPS} "${OBJECTDIR}/button/button.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/fsm/fsm_display.o: fsm/fsm_display.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/fsm" 
	@${RM} ${OBJECTDIR}/fsm/fsm_display.o.d 
	@${RM} ${OBJECTDIR}/fsm/fsm_display.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/fsm/fsm_display.o   fsm/fsm_display.c 
	@${DEP_GEN} -d ${OBJECTDIR}/fsm/fsm_display.o 
	@${FIXDEPS} "${OBJECTDIR}/fsm/fsm_display.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/fsm/fsm_warning.o: fsm/fsm_warning.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/fsm" 
	@${RM} ${OBJECTDIR}/fsm/fsm_warning.o.d 
	@${RM} ${OBJECTDIR}/fsm/fsm_warning.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/fsm/fsm_warning.o   fsm/fsm_warning.c 
	@${DEP_GEN} -d ${OBJECTDIR}/fsm/fsm_warning.o 
	@${FIXDEPS} "${OBJECTDIR}/fsm/fsm_warning.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/pwm/pwm.o: pwm/pwm.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/pwm" 
	@${RM} ${OBJECTDIR}/pwm/pwm.o.d 
	@${RM} ${OBJECTDIR}/pwm/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/pwm/pwm.o   pwm/pwm.c 
	@${DEP_GEN} -d ${OBJECTDIR}/pwm/pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/pwm/pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main.o   main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/adc/adc.o: adc/adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/adc" 
	@${RM} ${OBJECTDIR}/adc/adc.o.d 
	@${RM} ${OBJECTDIR}/adc/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/adc/adc.o   adc/adc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/adc/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/adc/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/uart/uart.o: uart/uart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/uart" 
	@${RM} ${OBJECTDIR}/uart/uart.o.d 
	@${RM} ${OBJECTDIR}/uart/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/uart/uart.o   uart/uart.c 
	@${DEP_GEN} -d ${OBJECTDIR}/uart/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/uart/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/timer/timer.o: timer/timer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/timer" 
	@${RM} ${OBJECTDIR}/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/timer/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/timer/timer.o   timer/timer.c 
	@${DEP_GEN} -d ${OBJECTDIR}/timer/timer.o 
	@${FIXDEPS} "${OBJECTDIR}/timer/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/lcd/lcd.o: lcd/lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/lcd" 
	@${RM} ${OBJECTDIR}/lcd/lcd.o.d 
	@${RM} ${OBJECTDIR}/lcd/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/lcd/lcd.o   lcd/lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/lcd/lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/lcd/lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/interrupt/interrupt.o: interrupt/interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/interrupt" 
	@${RM} ${OBJECTDIR}/interrupt/interrupt.o.d 
	@${RM} ${OBJECTDIR}/interrupt/interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/interrupt/interrupt.o   interrupt/interrupt.c 
	@${DEP_GEN} -d ${OBJECTDIR}/interrupt/interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/interrupt/interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/fsm/fsm_mode.o: fsm/fsm_mode.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/fsm" 
	@${RM} ${OBJECTDIR}/fsm/fsm_mode.o.d 
	@${RM} ${OBJECTDIR}/fsm/fsm_mode.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/fsm/fsm_mode.o   fsm/fsm_mode.c 
	@${DEP_GEN} -d ${OBJECTDIR}/fsm/fsm_mode.o 
	@${FIXDEPS} "${OBJECTDIR}/fsm/fsm_mode.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button/button.o: button/button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/button" 
	@${RM} ${OBJECTDIR}/button/button.o.d 
	@${RM} ${OBJECTDIR}/button/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button/button.o   button/button.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button/button.o 
	@${FIXDEPS} "${OBJECTDIR}/button/button.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/fsm/fsm_display.o: fsm/fsm_display.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/fsm" 
	@${RM} ${OBJECTDIR}/fsm/fsm_display.o.d 
	@${RM} ${OBJECTDIR}/fsm/fsm_display.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/fsm/fsm_display.o   fsm/fsm_display.c 
	@${DEP_GEN} -d ${OBJECTDIR}/fsm/fsm_display.o 
	@${FIXDEPS} "${OBJECTDIR}/fsm/fsm_display.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/fsm/fsm_warning.o: fsm/fsm_warning.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/fsm" 
	@${RM} ${OBJECTDIR}/fsm/fsm_warning.o.d 
	@${RM} ${OBJECTDIR}/fsm/fsm_warning.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/fsm/fsm_warning.o   fsm/fsm_warning.c 
	@${DEP_GEN} -d ${OBJECTDIR}/fsm/fsm_warning.o 
	@${FIXDEPS} "${OBJECTDIR}/fsm/fsm_warning.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/pwm/pwm.o: pwm/pwm.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/pwm" 
	@${RM} ${OBJECTDIR}/pwm/pwm.o.d 
	@${RM} ${OBJECTDIR}/pwm/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/pwm/pwm.o   pwm/pwm.c 
	@${DEP_GEN} -d ${OBJECTDIR}/pwm/pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/pwm/pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/EMS_PIC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_SIMULATOR=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/EMS_PIC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/EMS_PIC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/EMS_PIC.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
