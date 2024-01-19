* PDPMAIN
*
* SEE LICENSE AT END OF FILE
*
        DS   0F		
@@MAIN EQU * 
         STM   14,12,12(13) 
		 USING @@MAIN,15
		 USING @@STCTL,14
         L     14,=A(@@STAREA)
		 LA    1,20(14)       SKIP OVER CONTROL FIELDS
*                             20 is 5 F fields		 
         MVC   @@STTAG,=C'STCK'
         ST    1,@@STPTR
         ST    1,@@STBASE
*         LA    1,@@STSIZE(0,1)
         A     1,@@STSIZE
         ST    1,@@STTOP
         SR    1,1
         ST    1,@@STLVL        
         LM    14,12,12(13)
		 B     @@PAST
@@STSIZE DC    F'5120'	     This must match actual size of stack!	 
		 LTORG
@@PAST   EQU   *
		 DROP  14
		 DROP  15  
*
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
* end of pdpmain.cpy
