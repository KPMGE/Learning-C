#!/bin/sh

# Schell script to test Boca exercises
# Because we know, this BOCA is a shit 
# welcome lol

#creating folder for tests
mkdir tests

# displaying instructions
echo "\n---------- Shell Script to test Boca Exercises ----------"
echo "NOTE: you must be in the $HOME directory\n"

# reading data
echo "Enter the program that you want to test (without extension):"
read programName
echo "Enter the way to file .c that you want to test:"
read wayFile
echo "Enter the way to file .zip from Boca:"
read wayZip

# copy file zip and unpacking it 
cd $wayZip
cp ${programName}.zip ~
cd ~
unzip ${programName}.zip
rm ${programName}.pdf
rm ${programName}.zip

# copying file .c to home
cd $wayFile
cp ${programName}.c ~/tests

# renaming files for input and moving them to tests folder
cd ~/input
for loop in 1 2 3; do
  mv test_$loop input$loop
  mv input$loop ~/tests
done
cd ..
rm -rf input

# renaming files for output and moving them to tests folder
cd ~/output
for loop in 1 2 3; do
  mv test_$loop output$loop
  mv output$loop ~/tests
done
cd ..
rm -rf output

# compilating program
cd ~/tests
gcc ${programName}.c -o compiledProgram -lm 

# testing program
echo "For program $programName, it was generated these results:\n" >> errors.txt
for loop in 1 2 3;do 
  ./compiledProgram < input$loop > outputProgram$loop
  echo "\nTest $loop\n\n" >> errors.txt
  diff outputProgram$loop output$loop  >> errors.txt
done

# removing test files
rm compiledProgram ${programName}.c
for loop in 1 2 3;do
  rm input$loop output$loop outputProgram$loop 
done

# displaying message
echo "\nAlright, you can see erros in the 'tests' folder"
