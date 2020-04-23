#!/bin/bash
if [ -d /home/linux/file-dir ]
then
	echo -n "是否要删除 file-dir  [Y/N]? "
	read fchose
	case $fchose in
		Y|y|Yes|YES|yes)
			rm ~/file-dir -rf
			mkdir ~/file-dir
		;;
		N|n|NO|no|No)
			echo "退出"
			exit 1
		;;
	esac

else
	mkdir ~/file-dir
fi

if [ -d /home/linux/dir-dir ]
then
	echo -n "是否要删除 dir-dir  [Y/N]? "
	read dchose
	case $dchose in
		Y|y|Yes|YES|yes)
			rm ~/dir-dir -rf
			mkdir ~/dir-dir
		;;
		N|n|NO|no|No)
			echo "退出"
			exit 1
		;;
esac

else
	mkdir ~/dir-dir
fi

read -p "请输入一个路径" ll
if [ -d $ll ]
then
	for cc in `ls $ll`
	do
		if [ -f $cc ]
		then
			((fcount++))
			cp $cc ~/file-dir
		fi

		if [ -d $cc ]
		then
			((dcount++))
			cp $cc ~/dir-dir -r
		fi
	done
else
	echo "输入的路径不正确，请重试"
fi

echo "拷贝的文件的个数$fcount"
echo "拷贝的目录的个数$dcount"




















