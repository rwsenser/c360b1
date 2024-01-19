* PDPTOP
* SEE LICENSE AT END OF FILE
*
* OPTIONS set in PDPOPTS
* NOTICE: Due to limits with the MVT assembler, the
*         width of &CINDEX (over 1!!) can cause errors
*         so the labels using &CINDEX have been made
*         very short!
*
         MACRO
&NAME    PDPPRLG &CINDEX=,&FRAME=,&BASER=,&ENTRY=
* add ENTRY if requested
.IF      AIF   ('&ENTRY' NE 'YES').FI
         ENTRY &NAME 
.FI      ANOP
&NAME    EQU   *
         STM   14,12,12(13)
         LR     14,13           14 holds old-savearea addr
*VV		 
         BALR  12,0
         USING *,12   
* RISKY and this needs optimization, remove A5 kludge...
* notice that R12 is changed and NOT restored
         STM   1,5,@@A5&CINDEX
         L     2,=A(@@STAREA)			 
         USING @@STCTL,2		 
         LA    1,&FRAME
		 LA    1,20(1)       A LITTLE SLOP CAN HELP!
*        LA    13,@@SAR&CINDEX    * SAVEAREA
         L     5,@@STPTR      GET AVAIL ADDR, NEW SA ADDR	 
		 LR    3,5            COMP NEW PTR IN 3
		 AR    3,1
* check for stack overflow 
         L     4,@@STTOP 
         CR    3,4
         BL    @@OX&CINDEX 
* stack overflow!
         LM    1,5,@@A5&CINDEX
         WTO   '* STACK OVERFLOW, ABEND U0999 ...'
		 ABEND 999
@@OX&CINDEX EQU *
		 ST    3,@@STPTR       UPDATE AVAIL PTR
         L     3,@@STLVL		 
         A     3,=F'1'
         ST    3,@@STLVL
		 LR    13,5            NEW SAVEAREA LIVE NOW!
* finish links...
         ST    13,8(14)      13 has new sa ad, save in old sav
         ST    14,4(13)      14 has old sa ad, save in new sav
* OPTIONAL DEBUG, MARK LEVEL IN 1ST WORD OF SAVEAREA
*.IF2     AIF   ('&RTRACE' EQ 'YES').FI2
		 SR    1,1
		 LA    2,@@RTRACE(0,0)
		 CR    1,2		 
		 BNE   @@RN&CINDEX
* Put printable char in SAVEAREA first word		 
         A     3,=X'000000F0'		 
 		 ST    3,0(13)	
@@RN&CINDEX EQU *			 
*.FI2     ANOP		 
		 LM    1,5,@@A5&CINDEX
         DROP  2
*^^	  
         B     @@SK&CINDEX
         LTORG
@@A5&CINDEX DS 6F
* @@SAR&CINDEX DS 18F
         DS     255F       * fix this
@@SK&CINDEX EQU *
         MEND
*
* NOTICE: Due to limits with the MVT assembler, the
* GBLC operation can NOT BE USED.  So, the &SYSNDX is
* used to generate unique labels.  Problem is that the
* value of &SYSNDX is 4 chars wide.  So, labels in the
* PDPEPIL macro are limited to 2 chars:
*   Example @@XXNNNN where XX is the label name and NNNN
*   is the value from &SYSNDX
*
	 MACRO
&NAME    PDPEPIL
         LCLC   &CINDEX
&CINDEX  SETC   '&SYSNDX'           was '&RWSINDEX'          
         BALR  12,0
         USING *,12   
         L      12,=A(@@EPILC)
         BR     12
* cut here
* coded moved out of macro to avoild MVT assm F issues!
* end cut here
         MEND
*
* put here
         LCLA   &CINDEX
&CINDEX  SETA   1
         CSECT
@@EPILC  BALR  12,0
         USING *,12
* RISKY and this needs optimization, remove A15 kludge...
         STM   1,5,@@AA&CINDEX
         L     2,=A(@@STAREA)
         USING @@STCTL,2
         L     3,@@STLVL
         S     3,=F'1'
         ST    3,@@STLVL
         SR    4,4
         CR    3,4       IF LEVEL 0, RESET STACK
         BE    @@RR&CINDEX         
         LR    3,13    Verify R13 before change stack ptr
         L     4,@@STBASE
         CR    3,4        
         BL    @@BA&CINDEX
         L     4,@@STTOP
         CR    3,4
         BH    @@BA&CINDEX  
* it's OK
         B     @@OK&CINDEX
@@AA&CINDEX DS 6F         
@@BA&CINDEX EQU *
* stack corruption!
         LM    1,5,@@AA&CINDEX
         WTO   '* STACK CORRUPT, ABEND U0998 ...'
         ABEND 998 
* this needs to be cleaned up....
@@RR&CINDEX  EQU *
         L     3,@@STBASE
         ST    3,@@STPTR
         B     @@FI&CINDEX
@@OK&CINDEX EQU * 
         LR    3,13
         ST    3,@@STPTR
@@FI&CINDEX EQU *
         DROP  2 
         L     13,4(13)      follow back chain         
         L     14,12(13)     get return address
         LM    0,12,20(13)
         BR 14
		 LTORG               added
* model:
*         L     13,4(13)
*         L     14,12(13)
*         LM    0,12,20(13)
*         BR 14
* end put here
@@STCTL  DSECT
@@STTAG  DS    CL4
@@STPTR  DS    F 
@@STBASE DS    F
@@STTOP  DS    F 
@@STLVL  DS    F
         ENTRY @@STAREA
         CSECT
** TODO add option to have a setable stack size		 
** TODO have size of stack set from size field		 
@@STAREA DS    6F         ROOM FOR DSECT
         DS    5120CL1
	     COPY PDPOPTS
		 COPY PDPPUTS
         COPY PDPGETS
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
* end of pdptop.cpy
