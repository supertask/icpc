#! /usr/bin/sh

TARGET="/etc/hosts"
DATA="127.0.0.1 rhodon.u-aizu.ac.jp"
MESSAGE="Enter the command in the terminal !!"
COMMAND="ssh -L 8080:rhodon.u-aizu.ac.jp:8080 ユーザー名@cc2000.kyoto-su.ac.jp"

if [ -n "`cat ${TARGET} | grep "#${DATA}"`" ]; then
	echo "コメントアウト解除します."
	sed -i -e "s/#${DATA}/${DATA}/g" ${TARGET}
	echo "${MESSAGE}\n${COMMAND}"
elif [ -n "`cat ${TARGET} | grep "${DATA}"`" ]; then
	echo "該当箇所をコメントアウトします."
	sed -i -e "s/${DATA}/#${DATA}/g" ${TARGET}
	echo "#${DATA}"
else
	echo "hostファイルを書き換えます。"
	echo ${DATA} >> ${TARGET}
	echo "${MESSAGE}\n${COMMAND}"
fi

### Copyright (C) 2014 KENGO IMAE All Rights Reserved. ###
