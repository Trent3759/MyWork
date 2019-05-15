# An example MIPSbot program that shows controlling MIPSbot's velocity
# and orientation.


.data
datapts: .word
    # Start Texas datapoints
    0, 100, 100,   # Don't leave a track while headed to this point
    1, 150, 100, #top line of T
    0, 125, 100, #move back to middle of T
    1, 125, 180, 
    
    0, 220, 100, #move over for S
    1, 170, 100, #draw top line
    1, 170, 140, #draw line down
    1, 220, 140, #draw middle horizontal line
    1, 220, 180, #draw line down
    1, 170, 180, #draw bottom line
    
    0, 200, 200, #move off initials

    0, -1, -1   # Flag for finished with data points
.text

  # Register usage:
  # $s0 Xs: X start value for current segment
  # $s1 Xc: X current value for current segment
  # $s2 Xg: X goal value for current segment (end point)
  # $s3 Ys: Y start value for current segment
  # $s4 Yc: Y current value for current segment
  # $s5 Yg: Y goal value for current segment (end point)
  # $s6 Boolean: leave a track from (Xs,Ys) to (Xg,Yg) 1:true, 0:false
  # $s7 Address of 3-value point set from memory

  # $a0 -- address for memory-mapped IO heading value  0xffff8010
  # $a1 -- address for memory-mapped IO "leave a track" value  0xffff8020;
  # $a2 -- address for memory-mapped IO "Where are we X" value   0xffff8030;
  # $a3 -- address for memory-mapped IO "Where are we Y" value    0xffff8040;
  # $v0 -- address for memory-mapped IO "Move" value    0xffff8050;
  lui $a0, 0xffff
  ori $a0, $a0, 0x8010
  addi $a1, $a0, 0x10
  addi $a2, $a1, 0x10
  addi $a3, $a2, 0x10
  addi $v0, $a3, 0x10
  addi $t1, $zero, 1  # Known value for "true" for boolean values

  lw $s0, 0($a2)  # Find initial bot (X,Y) location
  lw $s3, 0($a3)
  
  la $s7, datapts
  
start:

  lw $s6, 0($s7) #  \
  lw $s2, 4($s7) #   > Three values for this line segment
  lw $s5, 8($s7) #  /
  
  ble $s2, $zero, end  # Flag for end of data is a negative X datapoint
  
  addi $s7, $s7, 12  # increment address by three words for next set of data points
  
  sw $s6, 0($a1) # Set leave-track MMIO value
moveX:
  beq $s0, $s2, moveY # if (Xs == Xg) No X movement
  blt $s0, $s2, elseX # if (Xs < Xg) goto else part
    # Here we know that (Xs > Xg), so X movement will be 270 degrees.
    li	$t0, 270   # angle of movement
    sw $t0, 0($a0) # Set angle-movement MMIO value
    sw $t1, 0($v0) # Set "move/don't move" MMIO value to "move"
    busyX1:
      lw $s1, 0($a2)  # Read X current value
      ble $s1, $s2, moveY # if (Xc <= Xg) X movement is finished
      j busyX1
  elseX:
    # Here we know that (Xs <= Xg), so X movement will be 90 degrees.
    li	$t0, 90   # angle of movement
    sw $t0, 0($a0) # Set angle-movement MMIO value
    sw $t1, 0($v0) # Set "move/don't move" MMIO value to "move"
    busyX2:
      lw $s1, 0($a2)  # Read X current value
      bge $s1, $s2, moveY # if (Xc >= Xg) X movement is finished
      j busyX2

moveY:
  beq $s3, $s5, loopend # if (Ys == Yg) No Y movement
  blt $s3, $s5, elseY # if (Ys < Yg) goto else part
    # Here we know that (Ys > Yg), so Y movement will be 0 degrees.
    li	$t0, 0   # angle of movement
    sw $t0, 0($a0) # Set angle-movement MMIO value
    sw $t1, 0($v0) # Set "move/don't move" MMIO value to "move"
    busyY1:
      lw $s4, 0($a3)  # Read Y current value
      ble $s4, $s5, loopend # if (Yc <= Yg) Y movement is finished
      j busyY1
  elseY:
    # Here we know that (Ys <= Yg), so Y movement will be 180 degrees.
    li	$t0, 180   # angle of movement
    sw $t0, 0($a0) # Set angle-movement MMIO value
    sw $t1, 0($v0) # Set "move/don't move" MMIO value to "move"
    busyY2:
      lw $s4, 0($a3)  # Read Y current value
      bge $s4, $s5, loopend # if (Yc >= Yg) Y movement is finished
      j busyY2

loopend:
  sw $zero, 0($a1) # clear leave-track MMIO value
  add $s0, $zero, $s2  # Update for next loop: prev. X goal becomes next X start
  add $s3, $zero, $s5  # Update for next loop: prev. Y goal becomes next Y start
  j logotop

end:
  sw $zero, 0($v0) # Set "move/don't move" MMIO value to "don't move"

