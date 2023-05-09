在Vscode中读取中文txt文件的时候出现乱码，原因是因为windows默认使用GBK编码而Mac是UTF-8编码，需要使用mac自带的命令--iconv
例如：iconv -f GBK -t UTF-8 /Users/wangyingjing/Downloads/SQL课程数据源/2.4/订购明细20110901.txt > /Users/wangyingjing/Desktop/订购明细20110901.txt
参考：https://www.jianshu.com/p/ac6aa4c09595
可以使用目录下的GBK2UTF8.sh实现转化
