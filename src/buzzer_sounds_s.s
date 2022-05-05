    .data
buzzerCycle: .word 0
    .text
    .balign
    .global get_buzzer_cycle
jmp_table:   .word case0
            .word case1
            .word case2
            .word case3
            .word case4
            .word case5
            .word case6
            .word case7

get_buzzer_cycle:
    mov &buzzerCycle, r12
    add r12, r12
    mov jmp_table(r12), r0

case0:
    mov #7644, &buzzerCycle
    jmp end_case
case1:
    mov #6810, &buzzerCycle
    jmp end_case
case2:
    mov #6067, &buzzerCycle
    jmp end_case
case3:
    mov #5727, &buzzerCycle
    jmp end_case
case4:
    mov #5102, &buzzerCycle
    jmp end_case
case5:
    mov #4545, &buzzerCycle
    jmp end_case
case6:
    mov #4049, &buzzerCycle
    jmp end_case
case7:
    mov #3822, buzzerCycle
end_case:	
    mov &buzzerCycle, r12
    pop r0
