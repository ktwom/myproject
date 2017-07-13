# C for mysql
if you use cJSon
slowly
how to gcc 
cgi mode(it can run in Aapche CGI-BIN):
gcc -o cMysql.cgi $(mysql_config --cflags) cMysql.c $(mysql_config --libs) -lm

if you use the cJSON
gcc -o cMysql.cgi $(mysql_config --cflags) cMysql.c cJSON.c $(mysql_config --libs) -lm
