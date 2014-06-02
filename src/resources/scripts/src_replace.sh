#/bin/bash
#
#
#
if [ "$1" == "" ] || [ "$2" == "" ] || [ "$3" == "" ];
then
	echo "------------------------------------------------------------------"
	echo
	echo "You should provide three arguments: ./src_replace.sh [1] [2] [3]"
	echo
	echo "Where,"
	echo "[1] = The src folder path."
	echo "[2] = The pattern to look for."
	echo "[3] = The pattern for replace to."
	echo
	echo "------------------------------------------------------------------"
	exit
else
	if [ -e $1 ];
	then
		find $1 -type f -name "*.cpp" -exec sed -i "s/$2/$3/g" {} \;
		exit
	else
		echo "------------------------------------------------------------------"
		echo
		echo "$1 does not exist!"
		echo
		echo "------------------------------------------------------------------"
		exit
	fi
fi
