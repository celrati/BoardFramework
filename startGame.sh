clear

echo "########### frameWork v0.2 #############"
echo "##        start           ...    ######"
echo "######################################"


find . -type f -name "*.o" -exec rm -f {} \;  # to delete all .o from the project
make clean # clean the project from all the .o files
make # make the project 


echo "###   start games ##"

cd Graphics
echo "###   start Graphics engine ...   ##"
#python start.py &
cd ..
echo "###     start Game engine ...     ##"
clear
./run
