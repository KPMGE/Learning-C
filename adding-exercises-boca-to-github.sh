# /bin/sh

# Program to add several exercises from the boca to github automaticly

clear
echo "---------- Addding Exercises from BOCA to github ----------\n"
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
