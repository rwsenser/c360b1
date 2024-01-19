* PDPPUTS
* SEE LICENSE AT END OF FILE
*
* option set in PDPOPTS
        CSECT
@@PUTS  EQU    *
        STM 14,12,12(13)
        LR  12,15
        USING @@PUTS,12
		MVC   @@BUFF,@@CLEAR
        L     2,88(13)     FROM C STACK
* COPY C-STRING TO OUTPUT BUFF		
		LA    3,@@BUFF+1  SKIP FIRST CHAR (old top of form...)
		LA    4,120(0,0)
		SR    5,5
* R2 ADDR OF INPUT, R3 ADDR OF OUTPUT, R4 MAX LEN/LCV, R5 IS ZERO		
@@MLOOP CR    4,5
        BE    @@MDONE     BUFF IS FULL
        CLI   0(2),X'00'
        BE    @@MDONE     FOUND C-STYLE END-OF-STRING
        MVC   0(1,3),0(2) MOVE CHAR
        LA    3,1(3,0)
        LA    2,1(2,0)
		S     4,=F'1'     SEEMS CLUMSY
        B     @@MLOOP
@@MDONE  EQU   *  
		LA    2,@@WTOBF      *** temp fix @@BUFF	 		
        LR 14,13
        LA 13,@@SAVEAR
        ST 13,8(14)
        ST 14,4(13)
* pick puts destination
* 0: SYSPRINT
* 1: WTO		
* temp fix
		LA    4,@@PUTDST
		CR    4,5
		BNE   @@DOWTO
*
        LA    2,4(2)          SKIP OVER WTO PREFIX
        OPEN  (SYSPRINT,(OUTPUT))
        PUT   SYSPRINT,(2)
        CLOSE SYSPRINT
		B     @@DONWTO
@@DOWTO EQU   *
        WTO   MF=(E,(2))
@@DONWTO EQU  *
* end temp		
        XR    15,15
        L     13,4(13)
        L     14,12(13)
        LM    0,12,20(13)
        BR 14
        LTORG
		DC  CL4'CLRR'
@@CLEAR DC  121CL1' '
        DC  CL4'BUFF'
@@WTOBF DS  0F
        DC  H'79'
        DC  H'0'		
@@BUFF  DS  CL121		
@@SAVEAR DS 18F
        PRINT NOGEN
*234567890123456789012345678901234567890123456789012345678901234567890
*        1         2         3         4         5         6         7
SYSPRINT DCB DDNAME=SYSPRINT,DSORG=PS,MACRF=PM,LRECL=121,RECFM=FBA,    X
               BLKSIZE=121
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
* end of pdpputs.cpy
