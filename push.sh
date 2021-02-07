#!/bin/sh
set -x
cleanother(){
RMOBJF="*.pro.user *.Debug *.Release Makefile .qmake.stash"
RMOBJD="debug release build*-Debug"
for file in $RMOBJF
do
	find . -type f -name "$file" | xargs rm -fr 
done
for dir in $RMOBJD
do
	find . -type d -name "$dir" | xargs rm -fr 
done
}
cleanother
git add *
git commit -m "`date` push $1"
<<<<<<< HEAD
git push origin master
=======
git push origin master
>>>>>>> eb7d70d6f787a4e32adf1c6b7447d14359cd0061
