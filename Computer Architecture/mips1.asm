    .data
InArr:  .word   0x0eeeeeee
    .text
    .globl main   
main:
    li  $s2,0x0eeeeeee
    li  $s3,0
    li  $s4, 8

loop:
    ror $s2,$s2,4   # $s2 = $s2 >>4
    sw  $s2,InArr  # InArr(0) = $s2
    addi $s4, $s4,-1
    bne $s4,$zero,loop    # until i==0
    
    
    li  $v0,10      # System(exit)
    
    syscall
