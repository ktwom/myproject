#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
//#include "cJSON.h"

//发生错误时，输出错误信息，关闭连接，退出程序
void error_quit(const char *str, MYSQL *connection)
{
    fprintf(stderr, "%s : %d: %s\n",
        str, mysql_errno(connection),
        mysql_error(connection));
    if( connection != NULL )
        mysql_close(connection);
    exit(1);
}
int main(int argc, char *argv[])
{

    MYSQL *my_con = malloc( sizeof(MYSQL) );
    MYSQL_RES *my_res;
    MYSQL_FIELD *my_field;
    MYSQL_ROW my_row;
    int rows, i;
    int res;
    //cJSON *root,*fld;    //声明一个cJSON数据
    //char *data = NULL;
    printf("Content-Type: text/html\n\n");
    //连接数据库
    mysql_init(my_con);
    my_con = mysql_real_connect(my_con, "localhost", "root", "erptest.cn",
        "test", 0, NULL, CLIENT_FOUND_ROWS);
    if( NULL == my_con )
        error_quit("Connection fail", my_con);
    if (mysql_set_character_set(my_con, "utf8")) {
            fprintf ( stderr , "错误, %s/n" , mysql_error(my_con)) ;
        }
    //获取整个表的内容
    res = mysql_query(my_con, "select * from shoptoc_area");
    if( res != 0 )
        error_quit("Select fail", my_con);
    my_res = mysql_store_result(my_con);
    if( NULL == my_res )
        error_quit("Get result fail", my_con);

    //获取表的列数
    rows = mysql_num_fields(my_res);
    //获取并输出表头
    my_field = mysql_fetch_fields(my_res);
    //输出整个表的内容
    // root = cJSON_CreateArray();
     printf("[");
    while( 1 )
    {

        my_row = mysql_fetch_row(my_res);
           if( NULL == my_row ){
             printf("{}");
             break;
           }



//           cJSON_AddItemToArray(root,fld=cJSON_CreateObject());
//           for(i=0; i<rows; i++)
//          {
//              cJSON_AddStringToObject(fld, my_field[i].name,my_row[i]);
//          }
        printf("{");
       for(i=0; i<rows; i++)
        {
            printf(" \"%s\":\"%s\" ", my_field[i].name,my_row[i]);
            if(i!=rows-1)
                printf(",");
        }
        printf("},");

    }
    printf("]");
   // data = cJSON_Print(root);//将JSON转换成char数组并返回
   // cJSON_Delete(root);
    //printf("%s\n",data);    //释放空间，关闭连接
    mysql_free_result(my_res);
    mysql_close(my_con);
    free(my_con);
    return 0;
}
