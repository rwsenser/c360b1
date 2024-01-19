#
# c360expand.py: used with s360 to expand COPYbooks become using assembler on mainframe
#
# SEE LICENSE AT END OF THIS FILE
#
#  author: RWSenser
#    data: 2023-12-26
# version: 2
#
# usage: <pgm>.py -i <inputfile> -o <outputfile>
#
# 2023-12-28: add code to list actual long labels
#
import sys, getopt
import os.path
from datetime import datetime

# get copybook contents
def loadbook(name, path):
    if len(path) > 0:
       name = path + '\\' + name
    content = loadfile(name + ".cpy")
    return content

# simple parse to find opcode and option
def loadfile(name):
   if os.path.isfile(name) == False:
      print("error: file missing: " + name)
      exit()
   with open(name, "r") as f:
      content = f.readlines()
   return content
 
# break out the first 3 tokens, separator is " "
# ignore comment lines 
def parse(line):
   if line[0] != '*':
      if line[0] == ' ':
          line = '!' + line[1:]   # brutal but impactful
      line = ' '.join(line.split()) # remove multiple spaces  
      tokens = line.split(" ", 3)
   else:
      tokens = ['']
   return tokens

def main(argv):
   inputfile = ''
   outputfile = ''
   bookpath = ''
   dupdict = { }
   print("c360expand:") 
   opts, args = getopt.getopt(argv,"hi:o:b:",["ifile=","ofile=","bpath="])
   for opt, arg in opts:
      if opt == '-h':
         print ('<pgm>.py -i <inputfile> -o <outputfile> -b <bookpath>')
         sys.exit()
      elif opt in ("-i", "--ifile"):
         inputfile = arg
      elif opt in ("-o", "--ofile"):
         outputfile = arg
      elif opt in ("-b", "--path"):
         bookpath = arg
         
   if inputfile == outputfile:
      print("error: file names are equal!")
      exit()   
   content = loadfile(inputfile)
   print(str(len(content)) + " source lines read")
   # trim trailing spaces (white space)
   for i in range(0,len(content)):
       content[i] = content[i].rstrip() + '\n'
    # TODO: move BHR processing into its own loop...   
# process up to 100 COPYs
   copycnt = 0
   recodecnt = 0
   for cnt in range(0,100):
      warncnt = 0
      done = True   
      for i in range(0, len(content)):
         line = content[i]
         tokens = parse(line)
         if tokens[0] == '!':    #  dirty but effective!
             tokens[0] = ' '
         # print(str(i) + ":" + str(tokens))  # DEBUG
         # process COPYs, BHRs and check for long labels
         if len(tokens) > 1:  
            # labels longer than 8 can be an issue with 360 assembler         
            if len(tokens[0]) > 8 and tokens[0].startswith("@@") == False:         
               warncnt += 1
               dupdict[i+1] = tokens[0]               
            if tokens[0].casefold() == "COPY".casefold():
               done = False
               content[i] = "* " + content[i]
               j = i + 1
               content[j:j] = loadbook(tokens[1], bookpath)
               copycnt += 1
            elif tokens[1].casefold() == "COPY".casefold():
               done = False
               content[i] = "* " + content[i]
               j = i + 1
               content[j:j] = loadbook(tokens[2], bookpath)
               copycnt += 1
            elif tokens[1].casefold() == "BHR".casefold():
               done = False
               content[i] = "** recoded ** " + content[i]
               j = i + 1
               content[j:j] = tokens[0] + "   BCR 2," + tokens[2] + '\n'
               recodecnt += 1   
      if done:
        break
   # end of for 
   
   # add timestamp to output file
   content.append("* time: " + str(datetime.now()) + " COPYbooks: " + str(copycnt) + " warnings: " + str(warncnt))    
   
   # write output file, give counts, etc
   print(str(copycnt) + " COPYbooks processed") 
   print(str(recodecnt) + " instructions recoded")
   print(str(warncnt) + " warnings (long labels)") 
   # list first 10 dups
   cnt = 0
   for line in dupdict:
       cnt += 1
       if cnt > 9:
           print("....")
           break
       label = dupdict[line]
       print(label)
   # output file  
   with open(outputfile, "w") as f:
      f.writelines(content)
      
   print(str(len(content)) + " source lines written") 
   print("processing completed")   
      
if __name__ == "__main__":
   main(sys.argv[1:])
#
"""
MIT License

Copyright (c) 2024 rwsenser

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
"""