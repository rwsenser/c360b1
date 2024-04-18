Version: 2024-04-18

Here we describe the installation process for our c/360 C compiler and run-time system.  It can be used to execute C programs with legacy IBM 360-370 hardware.  The C language became popular after the reign of the 360 computers.

This C compiler is a C99 cross compiler, which executes on standard Windows hardware.  The input C program is compiled into a standard mainframe Assembler program.  All of the C run-time modules are embedded in the resulting Assembler program.  This compiler has been heavily tested under Windows 10 and the resulting Assembler code works with the common MVT and MVS assemblers.  The included C test programs have been run under Hercules-based MVS 3.8. 

This is not intended to be a commercial-grade tool.  It uses the public-domain gccmvs.exe C99 compiler and the supplied C run time does not support all common C functions.  See the included c360guide.pdf document for more information. 

Listed below are the c/360 general installation steps, performed on the Windows PC.

A good pre-install step is to review the c/360 Guide.  It it about 10 pages in length, presented mostly in an outline format.

Notice that the run-time modules are not pre-installed on the S/360 (emulator).  Once the assembler code from the Expander step is produced, it is copied to the S/360 (emulator), compiled, linked and executed.

Installation Steps:

1) Download Github Project(Beta version: https://github.com/rwsenser/c360b1)

2) Decide which IBM mainframe emulator(s) to use

    We tend to first test with z390 and then with a Hercules-based system.

3) Customize Scripts (bat files) for PC use

   This normally amounts to updateing PATH variable in the setPath.bat file. 

4) Be certain that a recent version of Python3 is installed to support the c360expand.py script.  Python version 3.12 is known to work -- somewhat older version are likely to work as well.

5) Run the Installation Verification Programs on the S/360 emulator.  Successful execution of these programs shows that the compiler and run-time system are working.

Enjoy! We have produced several small C applications with this tool chain and they function as expected. In one case, a 64-line C program resulted in 2,309 lines of Assembler!

These items below are copied from the Installation Verification Programs Section of the c/360 Guide; the Guide shows how to use the scripts customized above.

For those who have not reviewed the c/360 Guide, here is some additional quick-start information

A. c/360 Environment

Listed here are the PC components that makeup the C compiler environment.  Note that the Expander, light-weight Run-Time Library, Scripts and Programs were generated specifically for this c/360 environment.  The Installation Verification Programs (IVPs) can be executed to show that the C compiler is functioning correctly.

1) Compiler: Pre-existing gccmvs.exe Cross Compiler(Windows version)
2) Expander: c360expand.py
3) C Run Time: Run-Time Library for S/360 and MVT 
4) Assembler(s) used: MVT Assembler (run in emulator) and optional z390 Emulator Tool (run on PC)
5) Specialized "Build" Scripts (Windows "doxxxxxx.bat" files)
6) Test and IVP Programs 

B. Helpful Tools
1) z390
This tool has worked well on our Windows 10 PC. We usually test a newly compiled program first with z390 before moving the code to a Hercules-based emulator.  z390 is not perfect but we find it very useful.
2) webMVT
This is a web-based S360 MVT emulator, which utilizes the Hercules emulator, created by the author.  This MVT runs entirely in the brower and permits the uploading of new programs.
3) Notepad++
Just a very useful editor, especially when working with a mixture of source-code types.
