#/bin/sh
dir=`pwd`
export dir
exe=`basename $dir`
cd $dir/$exe
$dir/$exe/$exe
