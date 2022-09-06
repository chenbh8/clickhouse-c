#include <clickhouse/client.h>
// #include "ngx_palloc.h"

void array_test()
{
    char **p = malloc(sizeof(char**));
    char * test = malloc(32);
    p[0] = test;
    strcpy(p[0], "fsdfd000");
    *(p[0]+5) = '\0';
    p[1] = test+6;

    strcpy(p[1], "fsdf1111");
    printf(p[0]);
    printf("\n");
    printf(p[1]);
}

void pool_test()
{
    ngx_pool_t* p = ngx_create_pool(1024);
    ck_rows_t *r = (ck_rows_t*)ngx_palloc(p, sizeof(ck_rows_t));
    r->data = (char**)ngx_palloc(p, sizeof(char**)*2);
    r->data[0] = (char*)ngx_palloc(p, 8);
    strcpy(r->data[0], "0000");
    *(r->data[0]+4) = '\0';

    printf(r->data[0]);
    printf("\n");

    r->data[1] = (char*)ngx_palloc(p, 8);
    strcpy(r->data[1], "11111");
    *(r->data[1]+5) = '\0';

    printf(r->data[0]);
    printf("\n");
    printf(r->data[1]);

}

int main() 
{
    printf("start\n");
    // array_test();
    // pool_test();
    char *query = "select toString(count(*)) from t2  limit 90000";
    ngx_pagesize = getpagesize();
    Client* cli = ck_init();
    ck_res_t* res = ck_select(cli, query);

    ck_rows_t *cur = res->rows;
    int i = 0;
    while (cur != NULL)
    {
        i++;
        printf("rows%d:", i);
        printf(cur->data[0]);
        // printf(" ");
        // printf(cur->data[1]);
        printf(" \n");
        cur = cur->next;
    }

    printf("\nrows:%d", res->nums);

    



    // ngx_pool_t *res = ngx_create_pool(32);

    // char *test = (char*)ngx_palloc(res, 8);
    // strcpy(test, "12\n");
    // printf(test);
    return 0;
}