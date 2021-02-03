# /bin/sh

# Program to add several exercises from the boca to github automaticly

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

# displaying a simple boilerplate
clear
figlet "Addding Exercises to github"

# reading way to files that it'll be added
echo "Enter way to exercises that you want to add: "
read wayExercises
echo "How much exercises do you want to add to github? "
read qtdExercises

# reading exercises and adding them to github
cont=0
cd ${wayExercises}
while [ ${cont} -lt ${qtdExercises} ]; do
  echo "Enter exercise name(without extension): "
  read programName
  git add ${programName}.c 
  git commit -m "Adding exercise ${programName} - BOCA"
  cont=$(($cont + 1))
done
git push

# displaying final message
clear
cowsay "all done guy!, your exercises were added to github"
