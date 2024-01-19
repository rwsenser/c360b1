* PDPGETSS
*
* SEE LICENSE AT END OF FILE
*
* TODO:  ADD CALL BACK TO CLOSE FILE!
*
        CSECT
@@GETS  EQU    *
        STM   14,12,12(13)
        LR    12,15
        USING @@GETS,12
* DIRTY INTERFACE!        
        L     2,100(13)     FROM C STACK (looked at generated code!)
* RECEIVING BUUFER MUST BE AT LEAST 81 CHARS WIDE
* R2 ADDR OF RECEIVING BUFFER
        LR 14,13
        LA 13,@@SAVEA2
        ST 13,8(14)
        ST 14,4(13)
        CLI   @@OFLAG,C'O'
        BE    @@DONE
        MVI   @@OFLAG,C'O'
        OPEN  (SYSIN,(INPUT))
@@DONE  LA  11,80(0,0)
        GET   SYSIN,(2)
        MVI   80(2),0    INSERT NULL TERMINATOR
@@CONT  EQU   *
*       CLOSE SYSIN       QUICK & DIRTY FIX      
*       XR    15,15
        LR    15,11
        L     13,4(13)
        L     14,12(13)
        LM    0,12,20(13)
        BR 14
* LAND HERE AT EOF
@@EOF   SR    11,11
        MVI   0(2),0     INSERT NULL TERMINATOR
        B     @@CONT       
        LTORG
@@SAVEA2 DS 18F
@@LEN    DS F
@@OFLAG  DC CL1'C'
        PRINT NOGEN
*234567890123456789012345678901234567890123456789012345678901234567890
*        1         2         3         4         5         6         7
SYSIN   DCB DDNAME=SYSIN,DSORG=PS,MACRF=GM,LRECL=80,RECFM=F,           X
               BLKSIZE=80,EODAD=@@EOF
*  RECRM=FT for ASCII, FECFM=F for EBCDIC               
	PRINT GEN
* MIT License
*
* Copyright (c) 2024 rwsenser
*
* Permission is hereby granted, free of charge, to any person 
* obtaining a copy of this software and associated documentation 
* files (the "Software"), to deal in the Software without 
* restriction, including without limitation the rightsto use,
*  copy, modify, merge, publish, distribute, sublicense, and/or 
* sell copies of the Software, and to permit persons to whom 
* the Software is furnished to do so, subject to the following 
* conditions:
*
* The above copyright notice and this permission notice shall be 
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
* OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
* HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
* DEALINGS IN THE SOFTWARE.    
* end of pdpgets.cpy
