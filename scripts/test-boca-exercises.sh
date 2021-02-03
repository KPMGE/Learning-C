#!/bin/sh	

# Schell script to test Boca exercises	
# Because we know, this BOCA is a shit 	
# welcome lol	

clear	
# verifying if the user have figlet installed	
isInstalledFiglet=$(which figlet)	

if [ "${isInstalledFiglet}" = "" ]; then	
  echo "you don't have figlet installed in your device, do you want to install it?(y/n)"	
  read choice	

  if [ "${choice}" = "y" ]; then	
    sudo apt-get install figlet	
    clear	
  fi	
fi	

# verifying if the user have cowsay installed	
isInstalledCowsay=$(which cowsay)	

if [ "${isInstalledCowsay}" = "" ]; then	
  echo "you don't have cowsay installed in your device, do you want to install it?(y/n)"	
  read choice	

  if [ "${choice}" = "y" ]; then	
    sudo apt-get install cowsay	
    clear	
  fi	
fi	

# displaying instructions	
clear	
figlet "Test Boca Exercises"	
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
cp ${programName}.zip $HOME	
cd $HOME	
unzip ${programName}.zip	
rm ${programName}.pdf	
rm ${programName}.zip	

# copying file .c to home	
cd $wayFile	
cp ${programName}.c $HOME	

# renaming files for input and moving them to home directory	
cd $HOME/input	
for loop in 1 2 3; do	
  mv test_$loop input$loop	
  mv input$loop $HOME	
done	
cd ..	
rm -rf input	

# renaming files for output and moving them to home directory	
cd $HOME/output	
for loop in 1 2 3; do	
  mv test_$loop output$loop	
  mv output$loop $HOME	
done	
cd ..	
rm -rf output	

# compilating program	
cd $HOME	
gcc ${programName}.c -o compiledProgram -lm 	

# testing program	
clear 	
echo "For program ${programName}.c, it was generated these results:"	
for loop in 1 2 3;do 	
  ./compiledProgram < input$loop > outputProgram$loop	
  echo "\n\nTest $loop\n"	
  diff outputProgram$loop output$loop	
done	

# removing test files	
rm compiledProgram ${programName}.c	
for loop in 1 2 3;do	
  rm input$loop output$loop outputProgram$loop 	
done	

# displaying message	
echo "\n"	
cowsay "good work guy"	
