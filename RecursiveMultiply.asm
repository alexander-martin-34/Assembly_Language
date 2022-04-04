.data
mc: .asciiz "\nEnter the multiplicand: "
mp: .asciiz "\nEnter the multiplier: "
 

main:
.text
li $v0,4
la $a0,mc 
syscall
li $v0,5
syscall 
move $t1,$v0 

li $v0,4
la $a0,mp 
syscall
li $v0,5
syscall 
move $t2,$v0 
move $a0,$t1 
move $a1,$t2 

jal multiply

move $t0,$v0
li $v0,1
move $a0,$t1
syscall

li $v0,11
li $a0,'*'
syscall
li $v0,1
move $a0,$t2
syscall
li $v0,11
li $a0,'='
syscall
li $v0,1
move $a0,$t0
syscall
li $v0,10
syscall

multiply:
bne $a1, 0, recurse  
move $v0, $a1
jr $ra

recurse:
sub $sp, $sp, 12
sw $ra, 0($sp)
sw $a0, 4($sp)
sw $a1, 8($sp)
addiu $a1, $a1, -1 
jal multiply
lw $a1, 4($sp)
add $v0, $v0, $a1
lw $ra, 0($sp)
addi $sp, $sp, 12
jr $ra