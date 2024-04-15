Listed below are the c/360 general installation steps, mostly performed on the Windows PC.

A good pre-install step is to review the c/360 Guide.  It it about 10 pages in length, presented mostly in an outline format.

Notice that the run-time modules are not pre-installed on the S/360 (emulator).  Once the assembler code from the Expander step is produced, it is copied to the S/360 (emulator) and executed.

Installation Steps:

1) Download Github Project (Beta version: https://github.com/rwsenser/c360b1)

2) Decide which IBM mainframe emulator(s) to use

We tend to first test with z390 and then with a Hercules-based system.

3) Customize Scripts (bat files) for PC use

4) Be certain the a recent version of Python3 is installed to support the c360expand.py script.

This normally amounts to changing PATH in the \textbf{setPath.bat} file. 

5) Run the Installation Verification Programs on the s/360 emulator.

Enjoy! We have produced several small C applications with this tool chain and they function as expected. In one case, a 64-line C program resulted in 2,309 lines of Assembler!

These items below are  copied from the Installation Verification Programs Section of the c/360 Guide; the Guide shows how to use the scripts customized above.

For those who have not reviewed the c/360 Guide, here is some additional quick-start information

A. c/360 Environment

Listed here are the PC components that makeup the C compiler environment.  Note that the Expander, light-weight Run-Time Library, Scripts and Programs were generated specifically for this environment.  The Installation Verification Programs (IVPs) can be executed to show that the C compiler is functioning correctly.

1) Compiler: Preexisting gccmvs.exe Cross Compiler(Windows version)
2) Expander: c360expand.py
3) C Run Time: Run-Time Library for S/360 and MVT 
4) Assembler(s): MVT Assembler and optional z390 Emulator Tool
5) Specialized "Build" Scripts (Windows "doxxxxxx.bat" files)
6) Test and IVP Programs 

B. Helpful Tools
1) z390
This tool has worked well on our Windows 10 PC. We usually test a newly compiled program first with z390 before moving the code to a Hercules-based emulator.  z390 is not perfect but we find it very useful.
2) webMVT
This is a web-based S360 MVT emulator, which utilizes the Hercules emulator, created by the author.  This MVT runs entirely in the brower and permits the uploading of new programs.
3) Notepad++
Just a very useful editor, especially when working with a mixture of source-code types.
